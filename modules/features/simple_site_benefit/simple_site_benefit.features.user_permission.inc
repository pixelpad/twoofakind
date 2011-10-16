<?php
/**
 * @file
 * simple_site_benefit.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function simple_site_benefit_user_default_permissions() {
  $permissions = array();

  // Exported permission: create simple_site_benefit content
  $permissions['create simple_site_benefit content'] = array(
    'name' => 'create simple_site_benefit content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any simple_site_benefit content
  $permissions['delete any simple_site_benefit content'] = array(
    'name' => 'delete any simple_site_benefit content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own simple_site_benefit content
  $permissions['delete own simple_site_benefit content'] = array(
    'name' => 'delete own simple_site_benefit content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any simple_site_benefit content
  $permissions['edit any simple_site_benefit content'] = array(
    'name' => 'edit any simple_site_benefit content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own simple_site_benefit content
  $permissions['edit own simple_site_benefit content'] = array(
    'name' => 'edit own simple_site_benefit content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
