<?php

/**
 * @file
 * Admin functions
 */

/******************************************************************************
 * Menu functions
 ******************************************************************************/

/**
 * Alter admin items
 * 
 * @see hook_menu_alter().
 */
function _twoofakind_com_au_admin_menu_alter(&$items) {
  
  // people
  if (isset($items['admin/people'])) {
    
    $items['admin/people/create']['page callback'] = $items['admin/people']['page callback'];
    $items['admin/people/create']['file'] = $items['admin/people']['file'];
    
    $items['admin/people']['page callback'] = 'views_page';
    $items['admin/people']['page arguments'] = array('people', 'page');
    $items['admin/people']['access callback'] = 'views_access';
    $items['admin/people']['access arguments'] = array(
      array(
        'views_check_perm',
        array('administer users')
      )
    );
    $items['admin/people']['load arguments'] = array('people', 'page', '%index');
    unset($items['admin/people']['file']);
    unset($items['admin/people']['module']);
  }
  
}

/**
 * Redirect to the right places
 *
 * @param $items
 *   Menu items array
 * 
 * @see hook_menu()
 */
function _twoofakind_com_au_admin_menu_redirect($redirect) {

  drupal_goto($redirect);
  
}