<?php
/**
 * @file
 * verdant_share_7.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function verdant_share_7_views_default_views() {
  $views = array();

  // Exported view: verdant_module_rideshare
  $view = new view;
  $view->name = 'verdant_module_rideshare';
  $view->description = 'Rideshare View';
  $view->tag = 'share';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Share the Ride';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['latfield'] = 'picture';
  $handler->display->display_options['style_options']['lonfield'] = 'picture';
  $handler->display->display_options['style_options']['markerfield'] = 'picture';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['exposed_block'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'text';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['empty'] = FALSE;
  $handler->display->display_options['header']['text']['content'] = 'Click on a heading such as "Arrive" to sort by that column.  Or use the last column to prioritize matches for the next time you come back to this page.  <strong>Match by:</strong>: <a href="?flagged_favorites=All&unflagged_remove=0" 
			title="All shares except those you have removed" >All</a> | <a href="?flagged_favorites=All&unflagged_remove=0&date_filter[min][date]=2010-06-14&date_filter[min][time]=20%3A30&date_filter[max][date]=2010-06-15&date_filter[max][time]=00:30" 
			title="" >Match My Arrival -- 4 hour window</a> | <a href="?flagged_favorites=All&unflagged_remove=0&date_filter_depart[min][date]=2010-06-25&date_filter_depart[min][time]=06%3A31&date_filter_depart[max][date]=2010-06-25&date_filter_depart[max][time]=10%3A31" 
			title="" >Match My Departure  -- 4 hour window</a> | <a href="?flagged_favorites=All&unflagged_remove=0&date_filter_depart[min][date]=2010-06-25&date_filter_depart[min][time]=06%3A31&date_filter_depart[max][date]=2010-06-25&date_filter_depart[max][time]=10%3A31&date_filter[min][date]=2010-06-14&date_filter[min][time]=20%3A30&date_filter[max][date]=2010-06-15&date_filter[max][time]=00:30" 
			title="" >Matches</a> | <a href="?flagged_favorites=1&unflagged_remove=0" 
			title="" >Favorites Only</a> | <a href="?flagged_favorites=All&unflagged_remove=1" style="font-size: .9em;"
			title="" >Check Previously Removed</a> | <a href="javascript: var obj= document.getElementById(views-exposed-form-verdant-module-generated-rideshare-page-2); obj.style.visibility = \'invisible\'">Power Options</a>';
  $handler->display->display_options['header']['text']['format'] = 'filtered_html';
  $handler->display->display_options['header']['text']['tokenize'] = 0;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['text']['id'] = 'text';
  $handler->display->display_options['footer']['text']['table'] = 'views';
  $handler->display->display_options['footer']['text']['field'] = 'area';
  $handler->display->display_options['footer']['text']['empty'] = TRUE;
  $handler->display->display_options['footer']['text']['content'] = 'Sort your search: by default, the favorite and remove flags are used to sort, followed by distance.  You can override this by clicking table headers for distance, last update, or alphabetizing the names.

Update your search: if you don\'t find a match, check that your post is up to date and click <em>save</em>.  Clicking save even if you don\'t make changes will let others know your post is fresh.';
  $handler->display->display_options['footer']['text']['format'] = 'filtered_html';
  $handler->display->display_options['footer']['text']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['text']['id'] = 'area';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = FALSE;
  $handler->display->display_options['empty']['text']['content'] = '<div class="message verdant-message">There are no matches for your current search choices.  <br/>Expand your selection choices above, or come back later.</div>';
  $handler->display->display_options['empty']['text']['format'] = '2';
  /* Relationship: Flags: share_prefer */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'Favorite?';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'share_prefer';
  /* Relationship: Flags: share_remove */
  $handler->display->display_options['relationships']['flag_content_rel_1']['id'] = 'flag_content_rel_1';
  $handler->display->display_options['relationships']['flag_content_rel_1']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel_1']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel_1']['label'] = 'Remove?';
  $handler->display->display_options['relationships']['flag_content_rel_1']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel_1']['flag'] = 'share_remove';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  /* Field: User: Link to contact page */
  $handler->display->display_options['fields']['contact']['id'] = 'contact';
  $handler->display->display_options['fields']['contact']['table'] = 'users';
  $handler->display->display_options['fields']['contact']['field'] = 'contact';
  $handler->display->display_options['fields']['contact']['relationship'] = 'uid';
  $handler->display->display_options['fields']['contact']['label'] = 'Contact';
  $handler->display->display_options['fields']['contact']['exclude'] = TRUE;
  $handler->display->display_options['fields']['contact']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['contact']['alter']['text'] = '<div class="contact-share">[contact]</div>';
  $handler->display->display_options['fields']['contact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['contact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['contact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact']['text'] = 'contact';
  $handler->display->display_options['fields']['contact']['link_display'] = 'icon';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Contact';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[picture] 
[name] 
[contact] ';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  /* Field: Content: All taxonomy terms */
  $handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['fields']['term_node_tid']['label'] = 'Vehicle';
  $handler->display->display_options['fields']['term_node_tid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['term_node_tid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['limit'] = 1;
  $handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
    'means_of_transit' => 'means_of_transit',
    'tags' => 0,
  );
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops_1']['id'] = 'ops_1';
  $handler->display->display_options['fields']['ops_1']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops_1']['field'] = 'ops';
  $handler->display->display_options['fields']['ops_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['fields']['ops_1']['label'] = 'Sort';
  $handler->display->display_options['fields']['ops_1']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['ops_1']['alter']['text'] = '+&nbsp;[ops] 
<br>-&nbsp;[ops_1] ';
  $handler->display->display_options['fields']['ops_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ops_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops_1']['hide_alter_empty'] = 1;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_description']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_description']['field_api_classes'] = 0;
  /* Field: User: Link to contact page */
  $handler->display->display_options['fields']['contact_1']['id'] = 'contact_1';
  $handler->display->display_options['fields']['contact_1']['table'] = 'users';
  $handler->display->display_options['fields']['contact_1']['field'] = 'contact';
  $handler->display->display_options['fields']['contact_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['contact_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['contact_1']['alter']['text'] = '<div class="contact-share">[contact]</div>';
  $handler->display->display_options['fields']['contact_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['contact_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['contact_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['contact_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['contact_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['contact_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['contact_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['contact_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['contact_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['contact_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['contact_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['contact_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['contact_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['contact_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['contact_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['contact_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['contact_1']['text'] = 'Contact';
  $handler->display->display_options['fields']['contact_1']['link_display'] = 'icon';
  /* Sort criterion: Flags: Flagged time */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'flag_content';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['sorts']['timestamp']['granularity'] = 'year';
  /* Sort criterion: Flags: Flagged time */
  $handler->display->display_options['sorts']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['sorts']['timestamp_1']['table'] = 'flag_content';
  $handler->display->display_options['sorts']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['sorts']['timestamp_1']['granularity'] = 'year';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'share_ride' => 'share_ride',
  );
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flag_content';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = 'All';
  $handler->display->display_options['filters']['flagged']['exposed'] = TRUE;
  $handler->display->display_options['filters']['flagged']['expose']['label'] = 'Favorites';
  $handler->display->display_options['filters']['flagged']['expose']['identifier'] = 'flagged_favorites';
  $handler->display->display_options['filters']['flagged']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['flagged']['expose']['remember'] = 1;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged_1']['id'] = 'flagged_1';
  $handler->display->display_options['filters']['flagged_1']['table'] = 'flag_content';
  $handler->display->display_options['filters']['flagged_1']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged_1']['relationship'] = 'flag_content_rel_1';
  $handler->display->display_options['filters']['flagged_1']['value'] = '0';
  $handler->display->display_options['filters']['flagged_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['flagged_1']['expose']['label'] = 'Removed';
  $handler->display->display_options['filters']['flagged_1']['expose']['identifier'] = 'unflagged_remove';
  $handler->display->display_options['filters']['flagged_1']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['flagged_1']['expose']['remember'] = 1;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Arrive';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter_arrive';
  $handler->display->display_options['filters']['date_filter']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'hour';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node_data_field_arrival_time.field_arrival_time_value' => 'node_data_field_arrival_time.field_arrival_time_value',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Departure';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_depart';
  $handler->display->display_options['filters']['date_filter_1']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['date_filter_1']['granularity'] = 'hour';
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node_data_field_departure_time.field_departure_time_value' => 'node_data_field_departure_time.field_departure_time_value',
  );
  $handler->display->display_options['filters']['date_filter_1']['date_method'] = 'AND';

  /* Display: Chart */
  $handler = $view->new_display('page', 'Chart', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'picture' => 'picture',
    'name' => 'name',
    'contact' => 'contact',
    'city' => 'city',
    'distance' => 'distance',
    'tid' => 'tid',
    'ops' => 'ops',
    'ops_1' => 'ops_1',
    'body' => 'body',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'picture' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'contact' => array(
      'separator' => '',
    ),
    'city' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'distance' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'tid' => array(
      'separator' => '',
    ),
    'ops' => array(
      'separator' => '',
    ),
    'ops_1' => array(
      'separator' => '',
    ),
    'body' => array(
      'separator' => '',
    ),
    'changed' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'share/ride/chart';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Rideshare Chart';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: Map */
  $handler = $view->new_display('page', 'Map', 'page_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['macro'] = '[gmap markers=drupal::37.68382032669382,-122.4382321536541 |width=98%|height=480px|control=Large |type=Map    ]    ';
  $handler->display->display_options['style_options']['markers'] = 'taxonomy';
  $handler->display->display_options['style_options']['markertype'] = 'purple';
  $handler->display->display_options['style_options']['latfield'] = 'picture';
  $handler->display->display_options['style_options']['lonfield'] = 'picture';
  $handler->display->display_options['style_options']['markerfield'] = 'picture';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['empty'] = TRUE;
  $handler->display->display_options['header']['text']['content'] = '<?php
$filter_links = verdant_share_date_filter();
?>


<strong>Step 1</strong>: Create a rideshare post in the left sidebar.  That post will automatically set your defaults when you search.<br />
<strong>Step 2</strong>: Use the map to skim for a match, or the chart for marking many as "favorites," or "remove" non-matches.

<p><div id="rideshare_map_key" style="display: inline; "><strong>Key</strong>:&nbsp;&nbsp;&nbsp;<img src="http://greeneventsguide.org/swsea/sites/greeneventsguide.org.swsea/modules/gmap/markers/small/bred.png">Rider&nbsp;&nbsp;&nbsp;<img src="http://greeneventsguide.org/swsea/sites/greeneventsguide.org.swsea/modules/gmap/markers/small/orange.png">Either Ride or Drive&nbsp;&nbsp;&nbsp;<img src="http://greeneventsguide.org/swsea/sites/greeneventsguide.org.swsea/modules/gmap/markers/small/yellow.png">Driver&nbsp;&nbsp;&nbsp;<img src="http://greeneventsguide.org/swsea/sites/greeneventsguide.org.swsea/modules/gmap/markers/small/green.png">Bus/Bike/Walk group</div>

	<p><strong>Match:</strong> <?php print $filter_links[0]; ?>
';
  $handler->display->display_options['header']['text']['format'] = '3';
  $handler->display->display_options['path'] = 'share/ride/map';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Rideshare Map';

  $views[$view->name] = $view;

  return $views;
}
