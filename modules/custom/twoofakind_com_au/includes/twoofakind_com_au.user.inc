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

  // Request reactivation
  $items['user/%user/reactivate'] = array(
    'title' => 'Reactivate account',
    'page callback' => 'twoofakind_com_au_user_reactivate',
    'page arguments' => array(1),
    'access callback' => TRUE,
    'file' => 'includes/twoofakind_com_au.user.inc',
  );

  // Mark as abusive and block
  $items['user/%user/abusive'] = array(
    'title' => 'Block abusive user',
    'page callback' => 'twoofakind_com_au_user_abusive',
    'page arguments' => array(1),
    'access arguments' => array('administer user profiles'),
    'file' => 'includes/twoofakind_com_au.user.inc',
  );

  // ADMIN

  // user emails admin screen
  $items['admin/config/people/email_templates'] = array(
    'title' => 'Account email templates',
    'description' => 'Manage the emails that are sent to your users',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('twoofakind_com_au_user_email_templates_settings'),
    'access arguments' => array('administer users'),
    'type' => MENU_NORMAL_ITEM,
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

/**
 * Reactivate user
 *
 * @see hook_menu()
 */
function twoofakind_com_au_user_reactivate($account) {

  $edit = array();
  $role_reactivate = user_role_load_by_name('Reactivate');
  if (!$role_reactivate) {
    // role doesn't exist - boo
    // set message and redirect
    drupal_set_message('Your request for reactivation could not be processed at this time, please try again later.', 'error');
    drupal_goto('<front>');
    return;
  }

  // add reactivate role
  $account->roles[$role_reactivate->rid] = $role_reactivate->name;
  $edit['roles'] = $account->roles;

  // add a note to the account indicating they would like to reactivate
  $langid = _object_language($account);
  if (
      !isset($account->{TWOOFAKIND_COM_AU_FIELD_NAME_ADMIN_NOTES})
      || empty($account->{TWOOFAKIND_COM_AU_FIELD_NAME_ADMIN_NOTES})
  ) {
    $account->{TWOOFAKIND_COM_AU_FIELD_NAME_ADMIN_NOTES} = array(
      $langcode => array()
    );
  }
  $account->{TWOOFAKIND_COM_AU_FIELD_NAME_ADMIN_NOTES}[$langid][] = array(
    'value' => date('F jS Y') . ' - ' . t('User requested reactivation')
  );
  $edit[TWOOFAKIND_COM_AU_FIELD_NAME_ADMIN_NOTES] = $account->{TWOOFAKIND_COM_AU_FIELD_NAME_ADMIN_NOTES};

  // save account
  $account = user_save($account, $edit);

  // set message and redirect
  drupal_set_message('Your request for reactivation has been processed, please keep an eye on your email account for confirmation.', 'status');
  drupal_goto('<front>');

}

/**
 * Block abusive user
 *
 * @see hook_menu()
 */
function twoofakind_com_au_user_abusive($account) {

  // determine if destination has been provided
  $params = drupal_get_query_parameters();
  $destination = 'admin'; // default
  if (isset($params['destination'])) {
    $destination = $params['destination'];
  }

  // if no account given then throw up a message
  // and redirect
  if (!$account) {
    drupal_set_message(t('Could not find user to mark as abusive'), 'error');
    drupal_goto($destination);
  }

  // use the action that exists
  twoofakind_com_au_abusive_user_action($account);

  // set message and redirect
  drupal_set_message(
    t(
      'User @username marked as abusive - they have been notified and blocked',
      array(
        '@username' => $account->name
      )
    ),
    'status'
  );
  drupal_goto($destination);

}

/******************************************************************************
 * Settings functions
 ******************************************************************************/

/**
 * Implementation of hook_settings().
 */
function twoofakind_com_au_user_email_templates_settings() {

  // init form
  $form = array();

  // include user module admin functions
  module_load_include('inc', 'user', 'user.admin');

  // grab current templates from user module
  $form_user_admin_settings = user_admin_settings();

  // set up vertical tabs for our form
  $form['email'] = array(
    '#type' => 'vertical_tabs',
  );
  $email_token_help = t('Available variables are: [site:name], [site:url], [user:name], [user:mail], [site:login-url], [site:url-brief], [user:edit-url], [user:one-time-login-url], [user:cancel-url].');

  // email field groups (vertical tabs)
  $fieldgroups_emails_current = array(
    'email_admin_created',
    'email_pending_approval',
//    'email_no_approval_required', // removed for this project as it is unrequired
    'email_password_reset',
    'email_activated',
    'email_cancel_confirm',
  );

  // grab the current email field groups and
  // add to our own form
  foreach ($fieldgroups_emails_current as $fieldgroup) {
    $form[$fieldgroup] = $form_user_admin_settings[$fieldgroup];
  }

  // make some minor changes to the form
  $form['email_pending_approval']['#title'] = t('Welcome');
  $form['email_activated']['#title'] = t('Account approved');

  // add some of our own emails
  // use the pending approval as a base
  $email_template_fieldset = $form['email_password_reset'];
  $email_template_subject = $email_template_fieldset['user_mail_password_reset_subject'];
  unset($email_template_fieldset['user_mail_password_reset_subject']);
  $email_template_body = $email_template_fieldset['user_mail_password_reset_body'];
  unset($email_template_fieldset['user_mail_password_reset_body']);

  // add the custom emails
  $emails_custom = _twoofakind_com_au_custom_email_templates();
  foreach ($emails_custom as $key => $data) {
    $form['email_' . $key] = $email_template_fieldset;
    $form['email_' . $key]['#title'] = t($data['title']);
    $form['email_' . $key]['#description'] = t($data['description']) . ' ' . $email_token_help;
    // subject
    $form['email_' . $key]['user_mail_' . $key . '_subject'] = $email_template_subject;
    $form['email_' . $key]['user_mail_' . $key . '_subject']['#default_value'] = _twoofakind_com_au_user_mail_text($key . '_subject', NULL, array(), FALSE);
    // body
    $form['email_' . $key]['user_mail_' . $key . '_body'] = $email_template_body;
    $form['email_' . $key]['user_mail_' . $key . '_body']['#default_value'] = _twoofakind_com_au_user_mail_text($key . '_body', NULL, array(), FALSE);
  }

  return system_settings_form($form);
}

/**
 * Returns a mail string for a variable name.
 *
 * Duplicate of _user_mail_text but for our custom email templates
 *
 * Used by user_mail() and the settings forms to retrieve strings.
 *
 * @see _user_mail_text()
 */
function _twoofakind_com_au_user_mail_text($key, $language = NULL, $variables = array(), $replace = TRUE) {
  $langcode = isset($language) ? $language->language : NULL;

  if ($admin_setting = variable_get('user_mail_' . $key, FALSE)) {
    // An admin setting overrides the default string.
    $text = $admin_setting;
  }
  else {

    // No override, return default string.
    $key_parts = explode('_', $key);
    $data_key = array_pop($key_parts);
    $key = implode('_', $key_parts);
    $text = _twoofakind_com_au_custom_email_templates($key, $data_key);
    if (!is_string($text)) {
      $text = t('Mail text not found');
    }
    $text = t($text, array(), array('langcode' => $langcode));

  }

  if ($replace) {
    // We do not sanitize the token replacement, since the output of this
    // replacement is intended for an e-mail message, not a web browser.
    return token_replace($text, $variables, array('language' => $language, 'callback' => 'user_mail_tokens', 'sanitize' => FALSE));
  }

  return $text;
}

/**
 * Current custom email templates
 *
 * @param string $key
 *  Pass a key if you only want info from one of the custom emails
 *
 * @param string $data_key
 *  Pass a data_key if you only want one section of the data
 *
 * @return none
 */
function _twoofakind_com_au_custom_email_templates($key = NULL, $data_key = NULL) {

  $emails_custom = array(
    'abusive_user' => array(
      'title' => 'Abusive user',
      'description' => 'Edit the e-mail message sent to members when they have been blocked due to being marked as abusive.',
      'subject' => 'Account details for [user:name] at [site:name] (blocked)',
      'body' => "[user:name],

It has been reported and confirmed that you have been abusing other users at [site:name].

Your account on [site:name] has been blocked.

--  [site:name] team"
    ),
    'deactivate_user' => array(
      'title' => 'Deactivate user',
      'description' => 'Edit the e-mail message sent to members when they have been blocked due to inactivity.',
      'subject' => 'Account details for [user:name] at [site:name] (blocked)',
      'body' => "[user:name],

You have not been active on the site for more than 3 months, we are temporarily deactivating your account.

You are welcome to reactivate at any time by simply accessing [site:name] and requesting reactivation.

Your account on [site:name] has been blocked until then.

--  [site:name] team"
    ),
    'reactivate_user' => array(
      'title' => 'Reactivate user',
      'description' => 'Edit the e-mail message sent to members when they are reactivated.',
      'subject' => 'Account details for [user:name] at [site:name] (activated)',
      'body' => "[user:name],

Your reactivation has been approved at [site:name].

Your account on [site:name] has been activated.

--  [site:name] team"
    ),
  );

  $return = $emails_custom;
  if (!empty($key) && isset($emails_custom[$key])) {
    $return = $emails_custom[$key];
    if (!empty($data_key) && isset($return[$data_key])) {
      $return = $return[$data_key];
    }
  }

  return $return;

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

/**
 * Render the profile completion block
 *
 * Outputs the percentage completion of someones profile
 *
 * @return
 *   A completed block array with subject and content
 */
function _twoofakind_com_au_block_profile_completion() {

  global $user;

  // grab the rest of the fields
  $user = user_load($user->uid);

  // init vars
  $remaining_titles = array();
  $remaining_weights = array();

  // grab all groups used in the form
  $field_groups_all = field_group_info_groups('user', 'user', 'form');
  // however we only want those items in the first tab group
  $field_group_names_process = $field_groups_all['group_tabs']->children;
  foreach ($field_group_names_process as $group_machine_name) {

    // grab the group
    $group = $field_groups_all[$group_machine_name];

    $fragment_id = sprintf('user_user_form_%1$s', $group_machine_name);

    // determine whether or not this group has been edited or not
    $group_remaining = TRUE;
    // we only need one of the fields to have been edited
    // this is our current measure of completion
    foreach ($group->children as $field_name) {
      // check if this field has a value
      if (isset($user->{$field_name}) && !empty($user->{$field_name})) {
        // technically this should be enough
        // we'll double check
        if (
          is_array($user->{$field_name})
          && array_key_exists(LANGUAGE_NONE, $user->{$field_name})
          && empty($user->{$field_name}[LANGUAGE_NONE])
        ) {
          // it's still empty
            continue;
        }
        // we've got "A" value for "A" field so this group is "Complete"
        // by our (current) standards
        $group_remaining = FALSE;
        break;
      }
    }

    // if this group remains add it to the list
    if ($group_remaining) {
      $remaining_weights[$group->weight] = $fragment_id;
      $remaining_titles[$fragment_id] = $group->label;
    }
  }

  // work out if we are not complete
  $count_total = count($field_group_names_process);
  $count_remaining = count($remaining_weights);

  // if we have nothing remaining display nothing
  if (!$count_remaining) {
    return;
  }

  // otherwise determine the percentage
  $percent_complete = 100 - ceil($count_remaining / $count_total * 100);

  // sort the remaining
  ksort($remaining_weights);
  // grab the top fragment
  reset($remaining_weights);
  $fragment_next = current($remaining_weights);
  // grab the title
  $fragment_next_title = $remaining_titles[$fragment_next];
  // build the next link
  $url = sprintf('user/%1$d/edit', $user->uid, $fragment_next);
  $link = l(
    $fragment_next_title,
    $url,
    array(
      'title' => 'Next step : ' . $fragment_next_title,
      'fragment' => $fragment_next,
      'query' => array(
        'destination' => current_path()
      )
    )
  );

  // build the block
  $block_title = t('Your profile is <strong>@per%</strong> complete', array('@per' => $percent_complete));
  if (FALSE) {
    $block = array(
      'subject' => $block_title,
      'content' => '<p class="profile-completion-next-step">Next step : ' . $link . '</p>'
    );
    }
  else {
    $block = array(
      'subject' => '',
      'content' => '<h2>' . $block_title . '</h2>'
        . '<p class="profile-completion-next-step">Next step : ' . $link . '</p>'
    );
  }
  // here we could add a link to the FAQ
//  $link = l(t('Click here to learn more'), 'help/complete-my-profile', array('title' => 'Click here to learn more about completing your profile'));
//  $block['subject'] .= '<p class="profile-completion-more-info">' . $link . '</p>';

  // wrap the block content
  // this should be in a template or preprocess function (please move it)
  $block['content'] = sprintf('<div id="profile-completion">%1$s</div>', $block['content']);

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