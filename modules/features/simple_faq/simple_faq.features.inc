<?php
/**
 * @file
 * simple_faq.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function simple_faq_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function simple_faq_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function simple_faq_node_info() {
  $items = array(
    'faq' => array(
      'name' => t('Simple FAQ'),
      'base' => 'node_content',
      'description' => t('A frequently asked question and its answer in its simple form.'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  return $items;
}
