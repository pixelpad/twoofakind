<?php
/**
 * @file
 * two_of_a_kind_conf.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function two_of_a_kind_conf_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration pages
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(),
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(),
  );

  // Exported permission: access contextual links
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'contextual',
  );

  // Exported permission: access dashboard
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: access overlay
  $permissions['access overlay'] = array(
    'name' => 'access overlay',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'overlay',
  );

  // Exported permission: access site in maintenance mode
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
  );

  // Exported permission: access site map
  $permissions['access site map'] = array(
    'name' => 'access site map',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'site_map',
  );

  // Exported permission: access site reports
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
  );

  // Exported permission: access site-wide contact form
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      0 => 'Administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'contact',
  );

  // Exported permission: access toolbar
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'toolbar',
  );

  // Exported permission: access user contact forms
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: administer actions
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
  );

  // Exported permission: administer blocks
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: administer boxes
  $permissions['administer boxes'] = array(
    'name' => 'administer boxes',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'boxes',
  );

  // Exported permission: administer contact forms
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: administer content types
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
  );

  // Exported permission: administer filters
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
  );

  // Exported permission: administer menu
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: administer modules
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
  );

  // Exported permission: administer nodes
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: administer page titles
  $permissions['administer page titles'] = array(
    'name' => 'administer page titles',
    'roles' => array(),
  );

  // Exported permission: administer pathauto
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(),
  );

  // Exported permission: administer permissions
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
  );

  // Exported permission: administer redirects
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(),
  );

  // Exported permission: administer search
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(),
  );

  // Exported permission: administer shortcuts
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(),
  );

  // Exported permission: administer site configuration
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
  );

  // Exported permission: administer software updates
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
  );

  // Exported permission: administer taxonomy
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
  );

  // Exported permission: administer url aliases
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(),
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'user',
  );

  // Exported permission: block IP addresses
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
  );

  // Exported permission: bypass node access
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
  );

  // Exported permission: cancel account
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: change own username
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: create url aliases
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(),
  );

  // Exported permission: customize shortcut links
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(),
  );

  // Exported permission: delete revisions
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
  );

  // Exported permission: edit boxes
  $permissions['edit boxes'] = array(
    'name' => 'edit boxes',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'boxes',
  );

  // Exported permission: notify of path changes
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(),
  );

  // Exported permission: revert revisions
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
  );

  // Exported permission: search content
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: select account cancellation method
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
  );

  // Exported permission: set page title
  $permissions['set page title'] = array(
    'name' => 'set page title',
    'roles' => array(),
  );

  // Exported permission: switch shortcut sets
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(),
  );

  // Exported permission: use advanced search
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: use text format html_full
  $permissions['use text format html_full'] = array(
    'name' => 'use text format html_full',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format html_minimal
  $permissions['use text format html_minimal'] = array(
    'name' => 'use text format html_minimal',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: view date repeats
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'date',
  );

  // Exported permission: view own unpublished content
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
  );

  // Exported permission: view the administration theme
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
  );

  return $permissions;
}
