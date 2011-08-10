<?php

/**
 * @file
 * Admin functions
 */

/******************************************************************************
 * Menu functions
 ******************************************************************************/

/**
 * Add admin menu items
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
    'page callback' => '_twoofakind_com_au_nodequeue_menu_redirect',
    'access arguments' => array('manipulate queues'),
    'file' => 'includes/twoofakind_com_au.nodequeue.inc',
    'type' => MENU_LOCAL_TASK
  );

}

/**
 * Redirect to the right places
 *
 * @param $items
 *   Menu items array
 * 
 * @see hook_menu()
 */
function _twoofakind_com_au_nodequeue_menu_redirect($item = NULL) {

  drupal_goto('admin/structure/nodequeue/1/view/1');
  
}