<?php

/**
 * @file
 * User based functions
 */

/******************************************************************************
 * Menu functions
 ******************************************************************************/

/**
 * Add user menu items
 *
 * @param $items
 *   Menu items array
 * 
 * @see hook_menu()
 */
function _twoofakind_com_au_user_menu(&$items) {

  // View profile
  $items['user/view/profile'] = array(
    'title' => 'View profile',
    'description' => 'View your profile',
    'page callback' => 'twoofakind_com_au_user_menu_view',
    'access arguments' => array('access user profiles'),
    'file' => 'includes/twoofakind_com_au.user.inc',
  );
  
  // Edit profile
  $items['user/edit/profile'] = array(
    'title' => 'Edit profile',
    'description' => 'Edit your profile',
    'page callback' => 'twoofakind_com_au_user_menu_edit',
    'page arguments' => array('profile'),
    'access arguments' => array('access user profiles'),
    'file' => 'includes/twoofakind_com_au.user.inc',
  );
  
  // Edit match criteria
  $items['user/edit/match'] = array(
    'title' => 'Edit match criteria',
    'description' => 'Edit your match criteria',
    'page callback' => 'twoofakind_com_au_user_menu_edit',
    'page arguments' => array('match'),
    'access arguments' => array('access user profiles'),
    'file' => 'includes/twoofakind_com_au.user.inc',
  );

}

/**
 * Process user menu view items
 * 
 * @see hook_menu()
 */
function twoofakind_com_au_user_menu_view() {

  global $user;
  
  $path = sprintf('profile/%s', $user->name);
  
  drupal_goto($path);

}

/**
 * Process user menu edit items
 *
 * @param $type
 *   Menu type
 * 
 * @see hook_menu()
 */
function twoofakind_com_au_user_menu_edit($edit) {

  global $user;
  
  $path = sprintf('user/%d/edit', $user->uid);
  $options = array(
    'fragment' => $edit
  );
  
  drupal_goto($path, $options);

}

/******************************************************************************
 * Block functions
 ******************************************************************************/

/**
 * Render the profile block
 * 
 * Simple block that will output picture and links
 * 
 * @return
 *   A completed block array with subject and content
 */
function _twoofakind_com_au_block_profile() {
  
  global $user;
  
  $block = array();
  
  // empty subject
  $block['subject'] = $user->name;
  
  // initialise content
  $content = array(
    '<div class="block-user-profile">'
  );
  
  // grab the picture of the user
  $content[] = theme('user_picture', array('account' => $user));
  
  // grab the user profile menu
  $menu_minified = array();
  $options = array(
    'attributes' => array(
      'title' => ''
    )
  );
  $menu_items = menu_tree('menu-user-profile-block');
  foreach ($menu_items as $menu_item) {
    
    // only process actual menu items
    if (is_array($menu_item) && !array_key_exists('#title', $menu_item)) {
      continue;
    }
    
    if (isset($menu_item['#localized_options']['attributes']['title'])) {
      $options['attributes']['title'] = $menu_item['#localized_options']['attributes']['title'];
    } else {
      $options['attributes']['title'] = $menu_item['#title'];
    }
    $menu_minified[] = l($menu_item['#title'], $menu_item['#href'], $options);
  }
  
  // add the menu to the content
  $content[] = theme('item_list', array(
      'items' => $menu_minified,
      'type' => 'ul',
      'attrobutes' => array(
        'class' => 'menu'
      )
    )
  );
  
  // close surrounding div
  $content[] = '</div>';
  
  // finalise the content
  $block['content'] = implode("\n", $content);
  
  return $block;
  
}

/******************************************************************************
 * Form functions
 ******************************************************************************/

/**
 * Alter the user profile form
 * 
 * Adding some headings and text to user profile form
 * and collapsing (by default) the pvt messages fieldset
 * 
 * @param
 *   A form
 * 
 * @param
 *   And it's for  state
 */
function _twoofakind_com_au_form_user_profile_form(&$form, &$form_state) {
  
  global $user;

  // set up some basic defaults
  $defaults = array(
    'user_edit_profile' => array(
      'subject' => 'Your profile',
      'content' => '<p>Tell us a little bit more about you.<p>',
      'weight' => -1000
    ),
    'user_edit_account' => array(
      'subject' => 'Account details',
      'content' => '<p>Edit your username, password and all that official jazz.<p>',
      'weight' => 2
    ),
    'user_edit_match' => array(
      'subject' => 'What are you looking for in a partner?',
      'content' => '<p>Tell us a little bit more about the kind of person you would like to meet.<p>',
      'weight' => 1
    )
  );
  $title = '<h2><a name="%s">%s</a></h2>';

  // change the weight of some of the groups
  $form['#groups']['group_tabs']->weight = 0;
  $form['#groups']['group_tabs_match']->weight = 1;
  $form['account']['name']['#weight'] = -2000;
  
  // and locations
  if (isset($form['locations'])) {
    $form['locations']['#weight'] = -500;
  }
  
  // cycle through each of the above and insert them in to the form
  $index = 0;
  foreach ($defaults as $delta => $data) {
    
    // grab box if one exists
    $box = boxes_block_view($delta);
    if ($box) {
      $box_title = $box['subject'];
      $box_content = $box['content'];
    } else {
      $box_title = $data['subject'];
      $box_content = $data['content'];
    }
    
    // extract the anchor
    $anchor_parts = explode('_', $delta);
    $anchor = end($anchor_parts);
    
    // put it all together
    $markup = array();
    $markup[] = sprintf($title, $anchor, $box_title);
    $markup[] = $box_content;
    
    // build a form delta
    $form_delta = str_replace('user_edit_', 'user_edit_'.$index.'_', $delta);
    // add to form
    $form[$form_delta] = array(
      '#markup' => implode("\n", $markup),
      '#weight' => $data['weight']
    );
    
    ++$index;
  }
  
  // hide the cancel input and add a link instead
  drupal_add_css(drupal_get_path('module', 'twoofakind_com_au') . '/css/twoofakind_com_au.admin.css', 'file');
  $output = array(
    '<div id="user-cancel-link">'
  );
  $output[] = l('Cancel account', 'user/' . $user->uid . '/cancel', array('attributes' => array('title' => 'Cancel your account'), 'html' => TRUE));
  $form['actions']['cancel']['#prefix'] = implode("\n", $output);
  $form['actions']['cancel']['#suffix'] = '</div>';

  // collapse the pvt messages fieldset
  $form['privatemsg']['#collapsed'] = TRUE;
  
  // hide the admin notes section for non-admin users
  if (!user_access('administer users')) {
    $form['field_admin_notes']['#access'] = FALSE;
  }
}