<?php
/**
 * @file
 * dating_suite.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function dating_suite_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => 1);
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function dating_suite_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favourite".
  $flags['favourite'] = array(
    'content_type' => 'user',
    'title' => 'Favourite',
    'global' => '0',
    'types' => array(),
    'flag_short' => 'Favourite [user:name]',
    'flag_long' => 'Add [user:name] to your favourites',
    'flag_message' => '[user:name] has been added to your favourites',
    'unflag_short' => 'Un-Favourite [user:name]',
    'unflag_long' => 'Remove [user:name] from your favourites',
    'unflag_message' => '[user:name] has been removed from your favourites',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
      ),
      'unflag' => array(
        0 => '2',
      ),
    ),
    'show_on_profile' => 1,
    'access_uid' => 'others',
    'module' => 'dating_suite',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implementation of hook_node_info().
 */
function dating_suite_node_info() {
  $items = array(
    'success_story' => array(
      'name' => t('Success story'),
      'base' => 'node_content',
      'description' => t('Stories of success'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
