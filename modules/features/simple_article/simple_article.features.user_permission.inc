<?php
/**
 * @file
 * simple_article.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function simple_article_user_default_permissions() {
  $permissions = array();

  // Exported permission: create simple_article content
  $permissions['create simple_article content'] = array(
    'name' => 'create simple_article content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any simple_article content
  $permissions['delete any simple_article content'] = array(
    'name' => 'delete any simple_article content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own simple_article content
  $permissions['delete own simple_article content'] = array(
    'name' => 'delete own simple_article content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any simple_article content
  $permissions['edit any simple_article content'] = array(
    'name' => 'edit any simple_article content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own simple_article content
  $permissions['edit own simple_article content'] = array(
    'name' => 'edit own simple_article content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
