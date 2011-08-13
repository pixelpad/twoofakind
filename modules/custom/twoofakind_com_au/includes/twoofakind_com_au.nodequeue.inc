<?php

/**
 * @file
 * nodequeue functions
 */

module_load_include('inc', 'twoofakind_com_au', 'includes/twoofakind_com_au.admin');

/******************************************************************************
 * Menu functions
 ******************************************************************************/

/**
 * Add nodequeue menu items
 *
 * @param $items
 *   Menu items array
 * 
 * @see hook_menu()
 */
function _twoofakind_com_au_nodequeue_menu(&$items) {

  // Slideshow editing page
  $items['admin/content/slideshow'] = array(
    'title' => 'Slideshow',
    'description' => 'Administer slideshow content',
    'page callback' => '_twoofakind_com_au_admin_menu_redirect',
    'page arguments'   => array('admin/structure/nodequeue/1/view/1'),
    'access arguments' => array('manipulate queues'),
    'file' => 'includes/twoofakind_com_au.nodequeue.inc',
    'type' => MENU_LOCAL_TASK
  );

}

/**
 * Alter nodequeue items
 * 
 * @see hook_menu_alter().
 */
function _twoofakind_com_au_nodequeue_menu_alter(&$items) {
  
  // change nodequeue tab title
  if (isset($items['node/%node/nodequeue'])) {
    $items['node/%node/nodequeue']['title arguments']['@tab'] = 'Slideshow';
  }
  
}