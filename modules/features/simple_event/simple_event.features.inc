<?php
/**
 * @file
 * simple_event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function simple_event_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function simple_event_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function simple_event_node_info() {
  $items = array(
    'simple_event' => array(
      'name' => t('Simple Event'),
      'base' => 'node_content',
      'description' => t('Basic event content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
