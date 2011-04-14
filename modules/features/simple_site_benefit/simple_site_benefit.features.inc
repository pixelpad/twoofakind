<?php
/**
 * @file
 * simple_site_benefit.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function simple_site_benefit_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function simple_site_benefit_node_info() {
  $items = array(
    'simple_site_benefit' => array(
      'name' => t('Simple Site Benefit'),
      'base' => 'node_content',
      'description' => t('Basic advertising of what\'s cool about this site'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
