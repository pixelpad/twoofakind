<?php
/**
 * @file
 * two_of_a_kind.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function two_of_a_kind_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}
