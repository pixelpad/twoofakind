<?php
/**
 * @file
 * dating_suite.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function dating_suite_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer privatemsg settings
  $permissions['administer privatemsg settings'] = array(
    'name' => 'administer privatemsg settings',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: allow disabling privatemsg
  $permissions['allow disabling privatemsg'] = array(
    'name' => 'allow disabling privatemsg',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: create success_story content
  $permissions['create success_story content'] = array(
    'name' => 'create success_story content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any success_story content
  $permissions['delete any success_story content'] = array(
    'name' => 'delete any success_story content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own success_story content
  $permissions['delete own success_story content'] = array(
    'name' => 'delete own success_story content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete privatemsg
  $permissions['delete privatemsg'] = array(
    'name' => 'delete privatemsg',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: edit any success_story content
  $permissions['edit any success_story content'] = array(
    'name' => 'edit any success_story content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own success_story content
  $permissions['edit own success_story content'] = array(
    'name' => 'edit own success_story content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: read all private messages
  $permissions['read all private messages'] = array(
    'name' => 'read all private messages',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: read privatemsg
  $permissions['read privatemsg'] = array(
    'name' => 'read privatemsg',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
      2 => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: reply only privatemsg
  $permissions['reply only privatemsg'] = array(
    'name' => 'reply only privatemsg',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: select text format for privatemsg
  $permissions['select text format for privatemsg'] = array(
    'name' => 'select text format for privatemsg',
    'roles' => array(),
  );

  // Exported permission: use tokens in privatemsg
  $permissions['use tokens in privatemsg'] = array(
    'name' => 'use tokens in privatemsg',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: write privatemsg
  $permissions['write privatemsg'] = array(
    'name' => 'write privatemsg',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  return $permissions;
}
