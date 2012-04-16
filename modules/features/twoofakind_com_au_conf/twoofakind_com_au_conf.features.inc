<?php
/**
 * @file
 * twoofakind_com_au_conf.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function twoofakind_com_au_conf_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
