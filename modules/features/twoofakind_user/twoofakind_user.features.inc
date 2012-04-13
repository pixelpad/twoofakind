<?php
/**
 * @file
 * twoofakind_user.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function twoofakind_user_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function twoofakind_user_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function twoofakind_user_flag_default_flags() {
  $flags = array();
  // Exported flag: "Abusive user".
  $flags['abusive_user'] = array(
    'content_type' => 'user',
    'title' => 'Abusive user',
    'global' => '0',
    'types' => array(),
    'flag_short' => 'Report as abusive',
    'flag_long' => 'Report [user:name] as abusive',
    'flag_message' => '[user:name] marked as abusive',
    'unflag_short' => 'Cancel abusive report',
    'unflag_long' => 'Cancel abusive user report',
    'unflag_message' => 'Abusive report cancelled',
    'unflag_denied_text' => 'User reported as abusive',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '2',
        1 => '3',
        2 => '4',
      ),
      'unflag' => array(
        0 => '3',
        1 => '4',
      ),
    ),
    'show_on_profile' => 0,
    'access_uid' => 'others',
    'module' => 'twoofakind_user',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}
