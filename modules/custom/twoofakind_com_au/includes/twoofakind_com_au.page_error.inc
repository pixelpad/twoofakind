<?php

/**
 * @file
 * page_error functions
 * 
 * @todo it would be better if this module defined it's own permission for these
 * pages and automatically allowed anonymous and authenticated users access to
 * them. Otherwise you'll end up in a pvt. website and no access denied screen.
 * 
 * @todo would also be nice to automatically create the boxes
 * 
 * @todo would also be nice to modify the error variables upon install
 */

/**
 * Required constants
 */

if (!defined('TWOOFAKIND_PATH_ACCESS_DENIED')) {
  define('TWOOFAKIND_PATH_ACCESS_DENIED', 'access_denied');
  define('TWOOFAKIND_PATH_PAGE_NOT_FOUND', 'page_not_found');
}

/******************************************************************************
 * Menu functions
 ******************************************************************************/

/**
 * Add page_error menu items
 *
 * @param $items
 *   Menu items array
 * 
 * @see hook_menu()
 */
function _twoofakind_com_au_page_error_menu(&$items) {

  // Access denied
  $items[TWOOFAKIND_PATH_ACCESS_DENIED] = array(
    'title' => 'Access Denied',
    'description' => 'Access denied error page',
    'page callback' => '_twoofakind_com_au_page_error_menu_page',
    'page arguments'   => array(TWOOFAKIND_PATH_ACCESS_DENIED),
    'access arguments' => array('access content'),
    'file' => 'includes/twoofakind_com_au.page_error.inc'
  );
  // Page not found
  $items[TWOOFAKIND_PATH_PAGE_NOT_FOUND] = array(
    'title' => 'Page not found',
    'description' => 'Page not found error page',
    'page callback' => '_twoofakind_com_au_page_error_menu_page',
    'page arguments'   => array(TWOOFAKIND_PATH_PAGE_NOT_FOUND),
    'access arguments' => array('access content'),
    'file' => 'includes/twoofakind_com_au.page_error.inc'
  );

}

/**
 * Error page
 *
 * @param $items
 *   Menu items array
 * 
 * @see hook_menu()
 */
function _twoofakind_com_au_page_error_menu_page($type = TWOOFAKIND_PATH_PAGE_NOT_FOUND) {

  // set up some basic defaults
  $defaults = array(
    TWOOFAKIND_PATH_ACCESS_DENIED => array(
      'subject' => 'Access Denied',
      'content' => '<p>You are not authorised to access this page.<p>'
    ),
    TWOOFAKIND_PATH_PAGE_NOT_FOUND => array(
      'subject' => 'Page not found',
      'content' => '<p>The requested page could not be found.<p>'
    )
  );
  
  // grab box if one exists
  $box = boxes_block_view($type);
  if ($box) {
    $box_title = $box['subject'];
    $box_content = $box['content'];
  } else {
    if (!array_key_exists($type, $defaults)) {
      $type = TWOOFAKIND_PATH_PAGE_NOT_FOUND;
    }
    $box_title = $defaults[$type]['subject'];
    $box_content = $defaults[$type]['content'];
  }
  
  // title
  drupal_set_title($box_title);
  
  // return
  return $box_content;
  
}