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
function _twoofakind_com_au_admin_menu(&$items) {

  // Home page editing
  // Home page main admin page
  $items['admin/content/boxes'] = array(
    'title' => 'Box content',
    'description' => 'Administer box based content e.g. home page, welcome message, access denied message, and the footer',
    'page callback' => 'twoofakind_com_au_admin_menu_block_page',
    'access arguments' => array('administer nodes'),
    'file' => 'includes/twoofakind_com_au.admin.inc',
    'type' => MENU_LOCAL_TASK
  );
  $common = array(
    'page callback' => '_twoofakind_com_au_admin_menu_redirect',
    'page arguments'   => array(3),
    'access arguments' => array('administer nodes'),
    'file' => 'includes/twoofakind_com_au.admin.inc'
  );
  // Home banner left box
  $items['admin/content/boxes/home_banner_left'] = array(
    'title' => 'Home banner left',
    'description' => 'Edit the content that appears below the logo on the home page',
  );
  $items['admin/content/boxes/home_banner_left'] += $common;
  // Home banner right box
  $items['admin/content/boxes/home_banner_right'] = array(
    'title' => 'Home banner right',
    'description' => 'Edit the content that appears below the search form on the home page',
  );
  $items['admin/content/boxes/home_banner_right'] += $common;
  // Home banner welcome box
  $items['admin/content/boxes/welcome'] = array(
    'title' => 'Home banner welcome',
    'description' => 'Edit the content that appears below the home banner left on the home page',
  );
  $items['admin/content/boxes/welcome'] += $common;
  // Welcome message upon login
  $items['admin/content/boxes/login_welcome'] = array(
    'title' => 'Initial login Welcome message',
    'description' => 'Edit the content that is displayed to a user when they first log in',
  );
  $items['admin/content/boxes/login_welcome'] += $common;
  // Footer partners
  $items['admin/content/boxes/footer_partners'] = array(
    'title' => 'Footer : Partners',
    'description' => 'Edit the partners content that appears in the footer',
  );
  $items['admin/content/boxes/footer_partners'] += $common;
  // Footer social
  $items['admin/content/boxes/footer_social'] = array(
    'title' => 'Footer : Social',
    'description' => 'Edit the social links content that appears in the footer',
  );
  $items['admin/content/boxes/footer_social'] += $common;
  // Footer contact
  $items['admin/content/boxes/footer_contact'] = array(
    'title' => 'Footer : Contact',
    'description' => 'Edit the contact content that appears in the footer',
  );
  $items['admin/content/boxes/footer_contact'] += $common;
  // Footer Copyright
  $items['admin/content/boxes/footer_copyright'] = array(
    'title' => 'Footer : Copyright',
    'description' => 'Edit the copyright content that appears below the footer',
  );
  $items['admin/content/boxes/footer_copyright'] += $common;

}

/**
 * DUPLICATE OF SYSTEM FUNCTION
 * 
 * Provide a single block from the administration menu as a page.
 *
 * This function is often a destination for these blocks.
 * For example, 'admin/structure/types' needs to have a destination to be valid
 * in the Drupal menu system, but too much information there might be
 * hidden, so we supply the contents of the block.
 *
 * @return
 *   The output HTML.
 */
function twoofakind_com_au_admin_menu_block_page() {
  $item = menu_get_item();

  // sneaky hack to allow a MENU_LOCAL_TASK tab to use system_admin_menu_block function
  $item['tab_root'] = $item['path'];
  
  if ($content = system_admin_menu_block($item)) {
    $output = theme('admin_block_content', array('content' => $content));
  }
  else {
    $output = t('You do not have any administrative items.');
  }
  return $output;
}

/**
 * Redirect to the right places
 *
 * @param $items
 *   Menu items array
 * 
 * @see hook_menu()
 */
function _twoofakind_com_au_admin_menu_redirect($item = NULL) {
  
  $default_destination = 'admin/content/boxes';
  
  switch ($item) {
    
    case 'home_banner_left' :
    case 'home_banner_right' :
    case 'welcome' :
    case 'login_welcome' :
    case 'footer_partners' :
    case 'footer_social' :
    case 'footer_contact' :
    case 'footer_copyright' :
      $redirect = "admin/structure/block/manage/boxes/$item/configure";
      break;

    default :
      // redirect back to main home page admin screen
      $redirect = $default_destination;
      break;
  }
  
  // add default destination
  $options = array();
  if ($redirect != $default_destination) {
    $options['query'] = array('destination' => $default_destination);
  }
  
  // go to
  drupal_goto($redirect, $options);
  
}