<?php
/**
 * @file
 * verdant_share_7.features.inc
 */

/**
 * Implements hook_views_api().
 */
function verdant_share_7_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function verdant_share_7_node_info() {
  $items = array(
    'share_ride' => array(
      'name' => t('Share Ride'),
      'base' => 'node_content',
      'description' => t('Keep your post up to date!  Even if you have no changes to make, clicking "save" every few days lets others know you\'re ad is up to date.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
