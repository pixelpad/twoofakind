<?php
/**
 * @file
 * simple_event.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function simple_event_user_default_permissions() {
  $permissions = array();

  // Exported permission: create simple_event content
  $permissions['create simple_event content'] = array(
    'name' => 'create simple_event content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any simple_event content
  $permissions['delete any simple_event content'] = array(
    'name' => 'delete any simple_event content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own simple_event content
  $permissions['delete own simple_event content'] = array(
    'name' => 'delete own simple_event content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any simple_event content
  $permissions['edit any simple_event content'] = array(
    'name' => 'edit any simple_event content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own simple_event content
  $permissions['edit own simple_event content'] = array(
    'name' => 'edit own simple_event content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
