<?php
/**
 * @file
 * simple_article.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function simple_article_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function simple_article_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => 3.0);
  }
}

/**
 * Implementation of hook_node_info().
 */
function simple_article_node_info() {
  $items = array(
    'simple_article' => array(
      'name' => t('Simple Article'),
      'base' => 'node_content',
      'description' => t('Basic article content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
