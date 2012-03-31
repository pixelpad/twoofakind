<?php
/**
 * @file
 * simple_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function simple_page_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function simple_page_node_info() {
  $items = array(
    'simple_page' => array(
      'name' => t('Simple Page'),
      'base' => 'node_content',
      'description' => t('Basic page of content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
