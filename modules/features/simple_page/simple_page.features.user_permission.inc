<?php
/**
 * @file
 * simple_page.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function simple_page_user_default_permissions() {
  $permissions = array();

  // Exported permission: create simple_page content
  $permissions['create simple_page content'] = array(
    'name' => 'create simple_page content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any simple_page content
  $permissions['delete any simple_page content'] = array(
    'name' => 'delete any simple_page content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own simple_page content
  $permissions['delete own simple_page content'] = array(
    'name' => 'delete own simple_page content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any simple_page content
  $permissions['edit any simple_page content'] = array(
    'name' => 'edit any simple_page content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own simple_page content
  $permissions['edit own simple_page content'] = array(
    'name' => 'edit own simple_page content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
