<?php

/**
 * @file
 * Admin functions
 * 
 * @todo
 *   Would be good to implement a redirect from the boxes  blocks
 *   section for non-admins when they get directed there. i.e. they
 *   should always be bumped back to our admin screen
 * 
 * @todo
 *   Would also be nice to lay this admin screen out a little nicer
 *   now we've got quite a few boxes going on...
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
 * 
 * @todo
 *   Would it simply be better to grab a list of boxes
 *   by using one of the boxes functions. it all depends
 *   on whether or not all boxes should be editable or
 *   not I guess.
 */
function _twoofakind_com_au_boxes_menu(&$items) {
  
  // Box editing page / tab
  $items['admin/content/boxes'] = array(
    'title' => 'Box content',
    'description' => 'Administer box based content e.g. home page, welcome message, access denied message, and the footer',
    'page callback' => 'twoofakind_com_au_admin_menu_block_page',
    'access arguments' => array('administer nodes'),
    'file' => 'includes/twoofakind_com_au.boxes.inc',
    'type' => MENU_LOCAL_TASK
  );
  $common = array(
    'page callback' => '_twoofakind_com_au_boxes_menu_redirect',
    'page arguments'   => array(3),
    'access arguments' => array('administer nodes'),
    'file' => 'includes/twoofakind_com_au.boxes.inc'
  );
  
  // boxes for editing
  $boxes = array(
    'home_banner_left' => array(
      'title' => 'Home banner left',
      'description' => 'Edit the content that appears below the slideshow on the left on the home page when not logged in'
    ),
    'home_banner_right' => array(
      'title' => 'Home banner right',
      'description' => 'Edit the content that appears below the slideshow on the right on the home page when not logged in'
    ),
    'welcome' => array(
      'title' => 'Home banner welcome',
      'description' => 'Edit the welcome message on the home page when not logged in'
    ),
    'login_welcome' => array(
      'title' => 'Initial login Welcome message',
      'description' => 'Edit the content that is displayed to a user when they first log in'
    ),
    'footer_partners' => array(
      'title' => 'Footer : Partners',
      'description' => 'Edit the partners content that appears in the footer'
    ),
    'footer_social' => array(
      'title' => 'Footer : Social',
      'description' => 'Edit the social links content that appears in the footer'
    ),
    'footer_contact' => array(
      'title' => 'Footer : Contact',
      'description' => 'Edit the contact content that appears in the footer'
    ),
    'footer_copyright' => array(
      'title' => 'Footer : Copyright',
      'description' => 'Edit the copyright content that appears below the footer'
    ),
    'user_edit_profile' => array(
      'title' => 'Profile edit screen : Profile',
      'description' => 'Edit the content that appears above the profile section on the user edit screen'
    ),
    'user_edit_match' => array(
      'title' => 'Profile edit screen : Match criteria',
      'description' => 'Edit the content that appears above the match criteria section on the user edit screen'
    ),
    'user_edit_account' => array(
      'title' => 'Profile edit screen : Account details',
      'description' => 'Edit the content that appears above the Account details section on the user edit screen'
    ),
    'member_dashboard_left' => array(
      'title' => 'Member dashboard left',
      'description' => 'Edit the content that appears below the slideshow on the left on the home page when logged in'
    ),
    'member_dashboard_right' => array(
      'title' => 'Member dashboard right',
      'description' => 'Edit the content that appears below the slideshow on the left on the home page when logged in'
    ),
    'member_dashboard_welcome' => array(
      'title' => 'Member dashboard welcome',
      'description' => 'Edit the welcome message on the home page when logged in'
    ),
    'access_denied' => array(
      'title' => 'Page : Access Denied',
      'description' => 'Edit the content found on the access denied page'
    ),
    'page_not_found' => array(
      'title' => 'Page : Page not found',
      'description' => 'Edit the content found on the page not found page'
    ),
    'page_messages' => array(
      'title' => 'Page : messages',
      'description' => 'Edit the content found on the messages page'
    ),
    'page_matches' => array(
      'title' => 'Page : my matches',
      'description' => 'Edit the content found on the my matches page'
    ),
    'page_matches_me' => array(
      'title' => 'Page : who I match',
      'description' => 'Edit the content found on the who I match page'
    ),
    'page_winks_received' => array(
      'title' => 'Page : winks received',
      'description' => 'Edit the content found on the winks received page'
    ),
    'page_winks' => array(
      'title' => 'Page : winked at',
      'description' => 'Edit the content found on the winked at page'
    ),
    'page_favourites' => array(
      'title' => 'Page : favourites',
      'description' => 'Edit the content found on the favourites page'
    ),
    'page_recent_views' => array(
      'title' => 'Page : recents views',
      'description' => 'Edit the content found on the recent views page'
    ),
    'page_whos_online' => array(
      'title' => 'Page : who\'s online',
      'description' => 'Edit the content found on the who\'s online page'
    )
  );
  
  // add them to the menu
  foreach ($boxes as $box_machine_name => $data) {
    $path = 'admin/content/boxes/' . $box_machine_name;
    $items[$path] = array(
      'title' => $data['title'],
      'description' => $data['description']
    );
    $items[$path] += $common;
  }

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
function _twoofakind_com_au_boxes_menu_redirect($box_machine_name = NULL) {
  
  $default_destination = 'admin/content/boxes';
  
  // check if they have permission
  // and make sure they do not have an eating disorder
  if (empty($box_machine_name)) {
    drupal_set_message('No box provided', 'error');
  }
  else {
    $redirect = 'admin/structure/block/manage/boxes/%s/configure';
    $redirect = sprintf($redirect, $box_machine_name);
  }
  
  // add default destination
  $options = array();
  if ($redirect != $default_destination) {
    $options['query'] = array('destination' => $default_destination);
  }
  
  // go to
  drupal_goto($redirect, $options);
  
}