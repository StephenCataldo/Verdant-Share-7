<?php
// $Id: $

/********** The rideshare view *****************************************/


// Oy.  Lots of errors in a randomish way when this module loaded before
// 	that one.  Do we need to do this here, or in .install ?
module_load_include('inc', 'node', 'node.pages');
module_load_include('inc', 'verdant_share', 'verdant_share_flags'); 


/**********  Most code below here focuses on the Share profile *********/

// Create a Content Profile block for roomshare
/**
 * Implementation of hook_block() from D6, now D7
 *
 *  Do we want to set the region?
 */
function verdant_share_block_info() {
	$blocks['rideshares'] = array(
		'info' => t('Ride Share Profile Block'),
		//'status' => 1, // Most modules do not provide an initial value
		'cache' => DRUPAL_NO_CACHE, // !!!???
		'visibility' => BLOCK_VISIBILITY_LISTED,
		'pages' => "share/ride/*
	share/ride",
);
	return $blocks; // Array ( [rideshare] => Array ( [info] => Ride Share Profile Block [status] => 1 [cache] => -1 [visibility] => 1 [pages] => share/ride/* share/ride ) )

}
function verdant_share_block_view($delta = '') {
	switch ($delta) {
		case 'rideshares': 
			if(user_access('post rideshare')){

				$type = 'share_ride';
				global $user;
				$account = $user;
				$blocks['subject'] = t('My RideShare');
				global $user;
				$form_id = 'share_ride_node_form'; // item_node_form
				$share_node;

	//@ToDo rewrite this copied code

				// Get $nid of user's share_ride, if they entered one
				$query = new EntityFieldQuery;
				$result = $query
					->entityCondition('entity_type', 'node')
					->propertyCondition('type', $type)
					->propertyCondition('uid', $user->uid)
					->execute();

				if (!empty($result['node'])) {
					//--> Yes, they already have a post 
					// @ToDo change this function to one that assumes there
					//	is only one matching node.  Or, deal with multiple results
					//  if we decide on multiple posts per person.
					$nodes = node_load_multiple(array_keys($result['node']));
					//print_r($nodes[1]);  a
					//returns: An array of node objects indexed by nid.
				}
				
				if ( isset($nodes) && $share_node = array_shift($nodes) ) {
				}
				else {   // Create new share post
					$share_node = (object) array(
						// This would be a good place to create the title, then just hide it.	
						// Get this error: Undefined property: stdClass::$name in verdant_share_block_view()
						// for name line, when loading chart with no post created yet.
						//  ... oh, that's for anon user. @ToDo simplify this section
						//  for anon users
						//
						// Are we creating a post when they load the rideshare page
						//  before they hit submit?  @ToDo/explore
						'uid' => $user->uid, 
						'name' => $user->name,
						'type' => 'share_ride',
						'language' => LANGUAGE_NONE   // or und
					);
				}

				$printable_form = drupal_get_form($form_id, $share_node);
				$blocks['content'] =  'Your post will act as your search parameters:' .
					'<div id="verdant_rideshare">' . 
					drupal_render($printable_form) .
					'</div>';
			} elseif (isset($user)) {
				$blocks['content'] = t("You do not have permission to post a rideshare");
			} else {
				// The user isn't logged in.  This is just a message and an extra
				//  login block.
				// It's ok to remove the drupal_render form or otherwise change text here	
				$blocks['title'] = "Your Rideshare Post";
				$blocks['content'] =
				  t("Please sign in to create a rideshare post.
					Your post will make it easier to search other people's posts:") .
					'<br/><br/>' .
					drupal_render(drupal_get_form('user_login_block')); 
			}

			return $blocks;
				


			case '2': 
				$type = 'share_flight';
				global $user;
				$account = $user;
				$blocks['subject'] = t("My Flight & Taxi Info");
				$blocks['content'] =  //'Entry form available soon.';

					content_profile_page_edit($type, $account);
				 return $blocks;
			}
}




/**
 *	function verdant_share_menu
 *   The main pages have their urls create in the view -- easy for users 
 *	  to change
 *   Right now just the admin's settings configuration menu is set here. 
 */


function verdant_share_menu() {
	$items = array();

	// ref: http://drupal.org/node/206761
	// structure? config? what should the parent be?
	$items['admin/structure/rideshare'] = array(
		'title' => t('VerdantShare: Ride-share'),
		'description' => t('Settings for the rideshare module'),
		'page callback' => 'drupal_get_form',
		'page arguments' => array('verdant_share_admin'), // function here
			// @ToDo -- do we need to validate?  Create...
			//  verdant_share_admin_validate($form, &$form_state)
		'access arguments' => array('access administration pages'),
		'type' => MENU_NORMAL_ITEM,
	);


	/* LETTING_THE_VIEW_CREATE_THE_MENUS_verdant_share_menu_NOT_USED 
		The plan could change!  Or just erase this soon.

	//Carpool map page  
	$items['share/ride/map'] = array(
		'title' => 'Rideshare Map',
		'description' => 'Post, or search the map for a rideshare',
		'page callback' => 'verdant_share_map_page',
		'access arguments' => array('access content'), //!!! reimplement? 
		'type' => MENU_NORMAL_ITEM
	);

	$items['share/ride/chart'] = array(
		'title' => 'Rideshare Chart',
		'description' => 'Post, or use the chart to sort possible rides',
		'page callback' => 'verdant_share_chart_page',  // CHANGE !!!!! :s /map/chart
		'access arguments' => array('access content'), //!!! reimplement? 
		'type' => MENU_NORMAL_ITEM
	); 
	*/

	return $items;
}

/******* Views: api, load it, and internal functions to fill exposed forms *******/

/**
 * Implementation of hook_views_api
 */
// This hook simply tells views that this module supports Views API 2
function verdant_share_views_api() {
		return array(
			'api' => 2,
			//'path' => drupal_get_path('module', 'verdant_share') . '/.'; 
					// Don't need if the *inc files are in this directory, they are.
		);
}

/**
 * function verdant_content_profile_load
 * based on content_profile's function
 */
function verdant_content_profile_load($type = 'share_ride') {
	global $user;

	// Get $nid of user's share_ride, if they entered one
	$query = new EntityFieldQuery;
	$result = $query
		->entityCondition('entity_type', 'node')
		->propertyCondition('type', $type)
		->propertyCondition('uid', $user->uid)
		->execute();

	if (!empty($result['node'])) {
		//--> Yes, they already have a post 
		// @ToDo change this function to one that assumes there
		//	is only one matching node.  Or, deal with multiple results
		//  if we decide on multiple posts per person.
		$nodes = node_load_multiple(array_keys($result['node']));
		return array_shift($nodes);
	}
	return null;
}	


/**
 *	verdant_share_date_filter is called from the view, and returns
 *	text for a line of links that simulate filling in the exposed options.
 *
 *	- Note that the exposed options are there, hidden via css, and exposing
 *	them lets you see what is happening.  It should be fine to expose them
 *  if you think that would be a "feature."
 *	- The Date module seems broken for exposed filters.  Search for the word
 *	'horrible' in the text below.  Others seem to be playing with the problems
 *	of exposed filters for date, and I didn't dig deeply, just trying to get
 *	everything in place here for now.
 *	- Timezones hacked, there must be a better way, search for $tz_offset !!!
 *	- Need to code in if the user hasn't entered a date !!!
 *	- Eventually, would like to give the admin more control, or the user,
 *	for example changing the acceptable time window. See MOVE_TO_SETTINGS
 *	- Might also add power-user options, though version has absorbed most of
 *	what I intended to do in power-options
 */
function verdant_share_date_filter() {
	/* Get the user's content_profile for share_ride */
	$type = 'share_ride';
	$ride_share = verdant_content_profile_load($type);

  if ($ride_share) {   //--> yes, there is a user with a post	
		// MOVE_TO_SETTINGS
		$timediameter = 4;  /* diameter of window -- hours, intended for text.  Not used yet, is it? */
		$time = 30 * $timediameter; // 1 hour diameter = 30 minute radius
			/* "radius" in minutes -- they must be leaving within $time minutes of me */


		$date_format_string = "Y-m-d\TH:i:s";  //!!!! not sure what \T is

		//--- ARRIVAL window ---//
		$arrival = $ride_share->field_arrival_time['und'][0]['value'];

		/* warning/help/TO-DO for future:
		 *	Dates are doing very weird things *
		 *  the field_arrival_time doesn't seem to match the date I just entered,
		 *  and then format_date throws it off again, in the same direction (later)
		 *  Found help here, but it looks like a kludge: 
		 *		http://drupal.org/node/355394
		 */
		$tz_offset = strtotime(date("M d Y H:i")) - strtotime(gmdate("M d Y H:i"));
		$arrival_stamp = strtotime( $arrival ) + $tz_offset; 


		// arrive after beginning of window
		$arrival_stamp_early = $arrival_stamp - $time * 60; 
		$arrival_early = date($date_format_string, $arrival_stamp_early);
		$arrival_min_date = date('Y-m-d', $arrival_stamp_early);
		$arrival_min_time = date('H\%3\Ai', $arrival_stamp_early);  // note: put html tranform into date function 16:43 is 16%3A43

		// arrive before late end of window -- DATES IS BROKEN!!!
		// I want to get the rest of the module working, see if dates
		// gets fixed.  I get the sense people are working on this, and
		// have no idea what's wrong... but it seems to require a date to be
		// a day later, rather than an hour later, to be "after"
		$arrival_stamp_late = $arrival_stamp + $time * 60;
		$arrival_late = date($date_format_string, $arrival_stamp_late);
		$arrival_max_date = date('Y-m-d', $arrival_stamp_late + 24 *3600); // horrible!!!
		$arrival_max_time = date('H\%3\Ai', $arrival_stamp_late);  // note: put html tranform into date function 16:43 is 16%3A43 ... probably didn't have to do that,nothing seemed to break.

		// and the fragment of the URL:
		$arrive_fragment = "date_filter_arrive[min][date]=$arrival_min_date&date_filter_arrive[min][time]=$arrival_min_time&date_filter_arrive[max][date]=$arrival_max_date&date_filter_arrive[max][time]=$arrival_max_time";


		
		//---  DEPARTURE window ---//
		$departure = $ride_share->field_departure_time['und'][0]['value'];
		$departure_stamp = strtotime( $departure)  + $tz_offset;

		// depart after beginning of window
		$departure_stamp_early = $departure_stamp - $time * 60; // seems to work ok
		$departure_early = date($date_format_string, $departure_stamp_early);
		$departure_min_date = date('Y-m-d', $departure_stamp_early);
		$departure_min_time = date('H\%3\Ai', $departure_stamp_early);  // :-) note: put html tranform into date function 16:43 is 16%3A43

		// depart before late end of window
		$departure_stamp_late = $departure_stamp + $time * 60 + /* horrible!!! */ + 3600 * 24;
		$departure_late = date($date_format_string, $departure_stamp_late);
		$departure_max_date = date('Y-m-d', $departure_stamp_late);
		$departure_max_time = date('H\%3\Ai', $departure_stamp_late);  // :-) note: put html tranform into date function 16:43 is 16%3A43

		// and the fragment of the URL:
		$depart_fragment = "date_filter_depart[min][date]=$departure_min_date&date_filter_depart[min][time]=$departure_min_time&date_filter_depart[max][date]=$departure_max_date&date_filter_depart[max][time]=$departure_max_time";

		//--- Some basic choice fragments: ---//
		$middlefavorites = "flagged_favorites=All&unflagged_remove=0";
		$favorites = "flagged_favorites=1&unflagged_remove=0";
		$check_removed = "flagged_favorites=All&unflagged_remove=1";

		//--- Get base url for chart or view, eg share/ride/map
		$base = 'share/ride/map'; //limited_url();
		
		//--- Create the links to pass to the view --//
		/* (note: also considered just passing the fragments, so could
			be edited in the view, that is an easy switch to make */
		$l_all = "<a href=\"/$base?$middlefavorites\" 
				title=\"All shares except those you have removed\" >Show All</a>";
		$l_arrive = "<a href=\"/$base?$middlefavorites&$arrive_fragment\" 
				title=\"See people arriving nearly the same time as you\" >By Arrival -- $timediameter hour window</a>";
		$l_depart = "<a href=\"/$base?$middlefavorites&$depart_fragment\" 
				title=\"See people departing nearly the same time as you\" >By Departure  -- $timediameter hour window</a>";
		$l_match = "<a href=\"/$base?$middlefavorites&$depart_fragment&$arrive_fragment\" 
				title=\"See people traveling at about the same times as you, both arrival and departure\" >Both Times</a>";
		$l_favs = "<a href=\"/$base?$favorites\" 
				title=\"Only see people clicked as favorites\" >Favorites Only</a>";
		$l_removed = "<a href=\"/$base?$check_removed\" style=\"font-size: .9em;\"
				title=\"Reconsider posts you've previously removed\" >Reconsider Removed</a>";
		
		$id = "views-exposed-form-verdant-module-generated-rideshare-page-2"; // !!!

		$quicklinks = "$l_all | $l_arrive | $l_depart | $l_match | $l_favs | $l_removed";

		return array($quicklinks);
	} else {  //---> No post!
		global $user;
		if ($user) {
			return array(t("Log in and create a post to see sorting options"));
		} else {
			return array(t("Create a post to see sorting options"));
		}
	}
}
 
 
	// Let users play with this (is that a good idea?)
	// $views[$view->name] = $view;



// Alter the form to point back at same page.
function verdant_share_form_alter(&$form, $form_state, $form_id) {

	if ( $form_id == 'share_ride_node_form') {
		// add some css ... might need this more often?
		drupal_add_css(drupal_get_path('module', 'verdant_share') .'/css/verdant_share_extra_style.css');
		// Redirect
		//not ABSOLUTELY positive this can't be tampered with, 
		//	$form['#redirect'] = $_GET['q']; 
		//	so hard code to be safe
		if ( $_GET['q'] == 'share/ride/map' ) {
			$form['#redirect'] = 'NOLONGERSEETHISRIGHTshare/ride/map';
			$form_state['redirect'] = 'NOLONGERSEETHISRIGHTshare/ride/map';

		} else {
			$form['#redirect'] = 'share/NOLONGERSEETHISRIGHTride/chart';
			$form_state['redirect'] = 'share/NOLONGERSEETHISRIGHTride/map';
		}
		// @ToDo warning: docs tell admin ok to change these URLS !!!

	
		// Redirects not working, try again:
		$form['actions']['submit']['#submit'][] = 'share_ride_submit';


		// Changing the form display ... some of this written in D6
		//  so look for b.s. that doesn't do anything
		//D6$form['body_field']['body']['#rows'] = 3;
		//D6$form['body_field']['teaser_include']['#access'] = FALSE;

		/*D7, these efforts fail...
		unset($form['field_description']['und'][0]['format']);
		unset($form['field_description']['und'][0]['#columns'][1]); // = format
			this sure looks good, removes the column, must not be it.
		 */
		//unset($form['body_field']['format']);
		$form['comment_settings']['#access'] = FALSE;
		$form['menu']['#access'] = FALSE;
		$form['path']['#access'] = false;
		$form['author']['#access'] = false;
		$form['options']['#access'] = false;
		$form['revision_information']['#access'] = false;
		// Want to remove long, lat boxes and some text

		// Keep form super-simple	 for users
		/*print "<pre>";
		//Thisisn't working yet.	
		print_r($form['field_description']['und'][0]['#columns']);
		print "</pre>";*/

		// !!! can this go to inc file?
		$form['locations'][0]['#collapsed'] = 0;

		//dsm($form['locations'] ); 

	}
}

/* function share_ride_submit 
 *  merely redirects back to same page
 *  See: http://drupal.org/node/1074616#comment-4183638
 */
function share_ride_submit($form, &$form_state) {
	$form_state['redirect'] = limited_url();

	// @ToDo warning: docs tell admin ok to change these URLS !!!
}

/* function limited_current_url		
 *  return current url from among limited set 
 */
function limited_url() {
	if ( $_GET['q'] == 'share/ride/map' ) {
		return 'share/ride/map';
	} else {
		return 'share/ride/chart';
	}
}



/* Views for matching times */
/* http://thedrupalblog.com/passing-date-ranges-view-arguments */
// define the db_rewrite_sql hook:
function NOT_USED_FOR_CARPOOLING_AT_THIS_TIME_HERE_FOR_REFERENCE_FOR_FUTURE_WORK_verdant_share_db_rewrite_sql($query, $primary_table = 'n', $primary_field = 'nid', $args = array()) {
  // search for the view
  if (is_object($args['view']) && $args['view']->name=='flight_connections') {
    // if there are no view arguments, don't bother continuing     
   	if (!is_array($args['view']->args)) return;

		// not sure if above is right... I'm getting no arg as an empty array
		//	which still sets is_array true
		//dsm(count($args['view']->args));
		if (count($args['view']->args) < 1 ) return;

		// the argument indicates which field to operate on, arrive, depart?
		$what = $args['view']->args[0]; // for example, arrival time.
		if ( $what == 'departure' ) {
			$field = 'field_departure_time';
		} elseif ( $what == 'arrival' ) {
			$field = 'field_arrival_time';
		} else {
			return;
		}


		// Find the start and end time for that field, for the current user
		global $user;
		$my_trip = content_profile_load('share_flight', $user->uid);
		//dsm($my_trip->{$field}[0][value]); // example: 2010-02-13 02:00:00
		$date = $my_trip->{$field}[0][value];
		$time = strtotime($date);  // seconds since 1970
		$endDate = date('Y-m-d H:m:s', $time + 7200); // add 2 hours
		$startDate =  date('Y-m-d H:m:s', $time - 7200); // subtract 2 hours
		//dsm(array("plus and minus two hours", $startDate, $endDate));


    // validate dates. exit function if issue -> cataldo: eh. 
							    //if (strlen($startDate) && !checkdate(date('m', strtotime($startDate)), date('d', strtotime($startDate)), date('Y', strtotime($startDate)))) return;
							    //if (strlen($endDate) && !checkdate(date('m', strtotime($endDate)), date('d', strtotime($endDate)), date('Y', strtotime($endDate)))) return;

		// create var for where clause
		$where = "";

		// define table alias
		//$tableAlias = 'node_data_field_departure_time_field_departure_time_value';
		$tableAlias = "content_field_" . $what . "_time";


		$where = " {$tableAlias}.field_$what" . "_time_value >= '$startDate' ";
	 	$where .= " and ";
		$where .= " {$tableAlias}.field_$what" . "_time_value <= '$endDate' ";

		//return array('join' => "inner join {content_type_share_flight} $tableAlias on node.vid = $tableAlias.vid and $where");

		return array('join' => "inner join {content_field_$what" . "_time} $tableAlias on node.vid = $tableAlias.vid and $where");

			

    //return array('join' => "inner join {content_field_$what" . "_time} $tableAlias on node.vid = $tableAlias.vid and $where");
  }

}

 /**
	* verdant_share_admin collects the module settings	
	*  use variable_get(... to get the variables set here
  */

function verdant_share_admin() {
	$form = array();
	$form['whatever'] = array(
		'#type' => 'location',
		'#title' => t('Event Location'),
		//'#default_value' => variable_get('onthisdate_maxdisp', 3),
		//'#size' => 2,
		//'#maxlength' => 2,
		'#description' => t("Where is everyone carpooling?"),
		'#required' => TRUE,
		);
/*	
	$form['whater'] = array(
		'#type' => 'locpick',
		'#title' => t('Event Location'),
		//'#default_value' => variable_get('onthisdate_maxdisp', 3),
		//'#size' => 2,
		//'#maxlength' => 2,
		'#description' => t("Where is everyone carpooling?"),
		'#required' => TRUE,
	);
	
//Location
$form['latitude'] = array(
'#type' => 'textfield',
'#title' => t('Latitude'),
'#prefix' => '<table height= \'30\' width=\'80%\'><tr><td width=\'100\'>',
'#suffix' => '</td>',
//'#default_value' => $latitude,
'#maxlength' => 64,
'#disabled' => 'true',
);

$form['longitude'] = array(
'#type' => 'textfield',
'#title' => t('Longitude'),
//'#default_value' =>$longitude,
'#maxlength' => 64,
//'#description' => $description,
'#prefix' => '<td>',
'#suffix' => '</td></tr></table>',
'#disabled' => 'true',
);

$map_macro = variable_get('gmap_user_map', '[gmap|id=usermap|center=0,30|control=Large|zoom=12|width=100%|height=400px]');
$form['gmap']['#value'] = gmap_set_location($map_macro, $form, array('latitude'=>'latitude','longitude'=>'longitude'));	
		 */
}
