<?php
/**
 * @file
 * verdant_share_7.features.inc
 */

/**
 * Implements hook_node_info().
 */
function verdant_share_7_node_info() {
  $items = array(
    'share_ride' => array(
      'name' => t('Share Ride'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_views_api().
 */
function verdant_share_7_views_api() {
  return array(
    'api' => '3.0',
  );
}
