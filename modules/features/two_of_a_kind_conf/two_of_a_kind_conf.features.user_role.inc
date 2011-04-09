<?php
/**
 * @file
 * two_of_a_kind_conf.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function two_of_a_kind_conf_user_default_roles() {
  $roles = array();

  // Exported role: Administrator
  $roles['Administrator'] = array(
    'name' => 'Administrator',
    'weight' => '2',
  );

  // Exported role: Editor
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => '3',
  );

  return $roles;
}
