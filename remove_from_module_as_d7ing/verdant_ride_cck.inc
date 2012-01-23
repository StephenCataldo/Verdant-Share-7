
/* well shit, cck export doesn't work at all:
http://drupal.org/node/338971
*/
$content['type']  = array (
  'name' => 'Share the Ride',
  'type' => 'share_ride',
  'description' => 'Keep your post up to date!  Even if you have no changes to make, clicking "save" every few days lets others know you\'re ad is up to date.',
  'title_label' => 'Quick Description',
  'body_label' => 'Details',
  'min_word_count' => '0',
  'help' => 'Describe your trip and maybe yourself.  If you don\'t want to be contacted with the contact form, how should people reach you?',
  'node_options' => 
  array (
    'status' => true,
    'promote' => true,
    'sticky' => false,
    'revision' => false,
  ),
  'old_type' => 'share_ride',
  'orig_type' => '',
  'module' => 'node',
  'custom' => '1',
  'modified' => '1',
  'locked' => '0',
  'content_profile_use' => 1,
  'comment' => '2',
  'comment_default_mode' => '4',
  'comment_default_order' => '1',
  'comment_default_per_page' => '50',
  'comment_controls' => '3',
  'comment_anonymous' => 0,
  'comment_subject_field' => '1',
  'comment_preview' => '1',
  'comment_form_location' => '0',
  'ant' => '1',
  'ant_pattern' => '<?php
		global $user;
		return \'Rideshare for \' . $user->name;
	?>',
  'ant_php' => 1,
);
$content['groups']  = array (
  0 => 
  array (
    'label' => 'Travel Times',
    'group_type' => 'standard',
    'settings' => 
    array (
      'form' => 
      array (
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => 
      array (
        'description' => '',
        'teaser' => 
        array (
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => 
        array (
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        4 => 
        array (
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '-3',
    'group_name' => 'group_travel_times',
  ),
);
$content['fields']  = array (
  0 => 
  array (
    'label' => 'Ride Request',
    'field_name' => 'field_ride_request',
    'type' => 'content_taxonomy',
    'widget_type' => 'content_taxonomy_options',
    'change' => 'Change basic information',
    'weight' => '-4',
    'show_depth' => 1,
    'group_parent' => '0',
    'description' => '',
    'default_value' => 
    array (
      0 => 
      array (
        'value' => NULL,
      ),
    ),
    'default_value_php' => '',
    'default_value_widget' => NULL,
    'group' => false,
    'required' => 1,
    'multiple' => '1',
    'save_term_node' => 1,
    'vid' => '1',
    'parent' => '0',
    'parent_php_code' => '',
    'depth' => '',
    'op' => 'Save field settings',
    'module' => 'content_taxonomy',
    'widget_module' => 'content_taxonomy_options',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'int',
        'not null' => false,
        'sortable' => false,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  1 => 
  array (
    'label' => 'Arrival Time',
    'field_name' => 'field_arrival_time',
    'type' => 'date',
    'widget_type' => 'date_popup',
    'change' => 'Change basic information',
    'weight' => '5',
    'default_value' => 'strtotime',
    'default_value2' => 'same',
    'default_value_code' => '14 October 2011 12:30',
    'default_value_code2' => '',
    'input_format' => 'm/d/Y - H:i',
    'input_format_custom' => '',
    'year_range' => '-0:+1',
    'increment' => '1',
    'advanced' => 
    array (
      'label_position' => 'above',
      'text_parts' => 
      array (
        'year' => 0,
        'month' => 0,
        'day' => 0,
        'hour' => 0,
        'minute' => 0,
        'second' => 0,
      ),
    ),
    'label_position' => 'above',
    'text_parts' => 
    array (
    ),
    'description' => '',
    'group' => 'group_travel_times', 
    'required' => 0,
    'multiple' => '0',
    'repeat' => 0,
    'todate' => '',
    'granularity' => 
    array (
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'default_format' => 'medium',
    'tz_handling' => 'site',
    'timezone_db' => 'UTC',
    'op' => 'Save field settings',
    'module' => 'date',
    'widget_module' => 'date',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'varchar',
        'length' => 20,
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
  2 => 
  array (
    'label' => 'Depart after Conference',
    'field_name' => 'field_departure_time',
    'type' => 'date',
    'widget_type' => 'date_popup',
    'change' => 'Change basic information',
    'weight' => '6',
    'default_value' => 'blank',
    'default_value2' => 'same',
    'default_value_code' => '16 October 2011 16:30',
    'default_value_code2' => '',
    'input_format' => 'm/d/Y - H:i',
    'input_format_custom' => '',
    'year_range' => '-3:+3',
    'increment' => '1',
    'advanced' => 
    array (
      'label_position' => 'above',
      'text_parts' => 
      array (
        'year' => 0,
        'month' => 0,
        'day' => 0,
        'hour' => 0,
        'minute' => 0,
        'second' => 0,
      ),
    ),
    'label_position' => 'above',
    'text_parts' => 
    array (
    ),
    'description' => '',
    'group' => 'group_travel_times',
    'required' => 0,
    'multiple' => '0',
    'repeat' => 0,
    'todate' => '',
    'granularity' => 
    array (
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'default_format' => 'medium',
    'tz_handling' => 'site',
    'timezone_db' => 'UTC',
    'op' => 'Save field settings',
    'module' => 'date',
    'widget_module' => 'date',
    'columns' => 
    array (
      'value' => 
      array (
        'type' => 'varchar',
        'length' => 20,
        'not null' => false,
        'sortable' => true,
        'views' => true,
      ),
    ),
    'display_settings' => 
    array (
      'label' => 
      array (
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
      4 => 
      array (
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
  ),
);
$content['extra']  = array (
  'title' => '-5',
  'body_field' => '0',
  'revision_information' => '2',
  'author' => '1',
  'options' => '3',
  'comment_settings' => '4',
  'menu' => '-1',
  'taxonomy' => '-2',
);

