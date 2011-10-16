<?php

/**
 * @file
 * wink entity information and functions
 */

/**
 * Required constants
 */

if (!defined('TWOOFAKIND_PATH_WINK')) {
  define('TWOOFAKIND_PATH_WINK', 'wink');
  define('TWOOFAKIND_TITLE_WINK', 'Wink at %s');
  define('TWOOFAKIND_MSG_WINK', 'Winked at %s');
  define('TWOOFAKIND_MSG_WINKED', 'Too many winks at %s');
}

/******************************************************************************
 * Menu functions
 ******************************************************************************/

/**
 * Add wink menu items
 *
 * @param $items
 *   Menu items array
 * 
 * @see hook_menu()
 */
function _wink_menu(&$items) {

  $items[TWOOFAKIND_PATH_WINK . '/%/%user'] = array(
    'title'             => 'Wink',
    'description'       => 'Wink at this user',
    'page callback'     => '_wink_wink',
    'page arguments'    => array(1,2),
    'access callback'   => 'user_access',
    'access arguments'  => array('access user profiles'),
    'type'              => MENU_CALLBACK,
//    'file'              => 'includes/wink.entity.inc',
  );
}

/**
 * Create a wink
 *
 * @param $wink_uid
 *   The uid of the user being wink-ed at
 * 
 * @return
 *   The entity or FALSE
 */
function _wink_wink($type = 'ajax', $wink_user = FALSE) {

  // defaults
  $link = '';
  $redirect = '<front>';
  $message = t('Wink failed');
  $status = 'error';

  // if js is enabled and this is an ajax request
  if ($type == 'ajax') {
    // did we find a user?
    if ($wink_user) {
      
      // check if we have winked enough
      // for today
      if (wink_has_winked($wink_user->uid) !== FALSE) {
        $message = t(sprintf(TWOOFAKIND_MSG_WINKED, $wink_user->name));
      }
      elseif (wink_create($wink_user->uid) !== FALSE) {
        // all went well
        // build response message
        $message = sprintf(TWOOFAKIND_MSG_WINK, $wink_user->name);
      }
    }
    else {
      // we didn't find one
      // send an error response back
      // create a message and wrap it in a span
      $message = 'User not found';
    }
    // ajax response
    _twoofakind_com_au_user_ajax_response($wink_user, 'wink', $message);
  }
  else {
    // js is not enabled. this is a fallback response
    // did we find a user?
    if ($wink_user) {
      if (wink_has_winked($wink_user->uid) !== FALSE) {
        $message = t(sprintf(TWOOFAKIND_MSG_WINKED, $wink_user->name));
      }
      elseif (wink_create($wink_user->uid)) {
        // all good
        // message
        $message = sprintf(TWOOFAKIND_MSG_WINK, $wink_user->name);
        $status = 'status';
        // redirect
        $redirect = 'user/' . $wink_user->uid;
      }
    }
    else {
      // message
      $message = 'User not found';
    }
    
    // set message and redirect
    _twoofakind_com_au_user_nojs_response($message, $redirect, $status);
    return;
  }
}

/******************************************************************************
 * Load functions
 ******************************************************************************/

/**
 * Load a wink
 *
 * @param $id
 *   Id of wink
 * @param $conditions
 *   Conditions you would like to specify
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of wink objects, indexed by wid or FALSE if no winks found
 * 
 * @see entity_load()
 */
function wink_load($wid, $conditions = array(), $reset = FALSE) {
  $wink = wink_load_multiple(array($wid), $conditions, $reset);
  return reset($wink);
}

/**
 * Load multiple winks
 *
 * @param $wids
 *   An array of wink IDs.
 * @param $conditions
 *   An array of conditions to wink against the {wink} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of wink objects, indexed by wid or FALSE if no winks found
 *
 * @see entity_load()
 */
function wink_load_multiple($wids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('wink', $wids, $conditions, $reset);
}

/**
 * Load all winks
 *
 * @param $conditions
 *   An array of conditions to wink against the {wink} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of wink objects, indexed by pid or FALSE if no winks found
 *
 * @see entity_load()
 */
function wink_load_all($conditions = array(), $reset = FALSE) {
  return wink_load_multiple(FALSE, $conditions, $reset);
}

/**
 * Load winks from current user to account
 * 
 * @param $wink_uid
 *   User id to check
 * 
 * @return
 *   Return array of wink entities
 */
function wink_load_from_current_to_account($wink_uid) {
  
  global $user;
  
  return wink_load_from_winker_winkee($user->uid, $wink_uid);
}

/**
 * Load winks from account to current user
 * 
 * @param $wink_uid
 *   User id to check
 * 
 * @return
 *   Return array of wink entities
 */
function wink_load_from_account_to_current($wink_uid) {
  
  global $user;
  
  return wink_load_from_winker_winkee($wink_uid, $user->uid);
}

/**
 * Load winks from winker to winkee
 * 
 * @param $winker_uid
 *   Uid of winker
 * 
 * @param $winkee_uid
 *   Uid of winkee
 * 
 * @return
 *   Return array of wink entities
 */
function wink_load_from_winker_winkee($winker_uid, $winkee_uid) {
  
  global $user;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want favourites
  $query->entityCondition('entity_type', 'wink', '=');

  // match favourite_uid and current uid
  $query->propertyCondition('uid', $winker_uid, '=');
  $query->propertyCondition('wink_uid', $winkee_uid, '=');

  // execute
  $result = $query->execute();

  // return result
  if (isset($result['wink']) && count($result['wink'])) {
      return wink_load_multiple(array_keys($result['wink']));
  }
  
  return array();
}

/******************************************************************************
 * CRUD functions
 ******************************************************************************/

/**
 * Create a wink
 *
 * @param $wink_uid
 *   The uid of the user being wink-ed at
 * 
 * @return
 *   The entity or FALSE
 * 
 * @todo
 *   Work out how to dynamically grab the $cid for cache clearing
 */
function wink_create($wink_uid) {

  global $user;

  // double check that someone hasn't winked within minimum
  // allowable timeframe or max times etc
  $wink_id = wink_has_winked($wink_uid);
  if ($wink_id !== FALSE) {
    
    // load the entity and return it
    $entity = wink_load($wink_id);
    return $entity;
  }
  
  $container = array(
    'uid' => $user->uid,
    'wink_uid' => $wink_uid
  );
  $entity = entity_create('wink', $container);
  if($entity) {
    entity_get_controller('wink')->save($entity);
    
    // clear the cache here
    // there should be a function call here to return the cid
    // I spent about an hour but couldn't figure it out quickly
    // to do for later
    cache_clear_all('ctools_export:views_view:winks', 'cache_views');
    cache_clear_all('ctools_export:views_view:winks_received', 'cache_views');
    
    return $entity;
  }  
  return FALSE;
  
}

/**
 * Update a wink
 *
 * @param $wink
 *   The wink being updated
 * 
 * @return
 *   The entity or FALSE
 */
function wink_update($wink) {
  
  if($wink) {
    entity_get_controller('wink')->save($wink);
    return $wink;
  }  
  return FALSE;
  
}

/******************************************************************************
 * Count functions
 ******************************************************************************/

/**
 * Count un-viewed winks when logged in user is winker
 * 
 * @return
 *   An integer equal to the number of unviewed winks for winker
 */
function wink_count_winker_unviewed_winks() {
  
  return wink_count_unviewed_winks('uid');
}

/**
 * Count un-viewed winks when logged in user is winkee
 * 
 * @return
 *   An integer equal to the number of unviewed winks for winkee
 */
function wink_count_winkee_unviewed_winks() {
  
  return wink_count_unviewed_winks('wink_uid');
}

/**
 * Count un-viewed winks for winker or winkee
 * 
 * @param $field_viewed
 *   Which viewed field to count on
 * 
 * @return
 *   An integer equal to the number of unviewed winks for currently logged in user
 */
function wink_count_unviewed_winks($field_uid = 'uid') {
  
  global $user;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want winks
  $query->entityCondition('entity_type', 'wink', '=');

  // we want winks for currently logged in user
  // determine the field based on the viewed field
  $query->propertyCondition($field_uid, $user->uid, '=');
  $query->propertyCondition('viewed', '0', '=');
  
  // execute
  $result = $query->execute();

  // return result
  if (isset($result['wink'])) {
    return count($result['wink']);
  }
  
  return 0;
}

/******************************************************************************
 * Callback functions
 ******************************************************************************/

/**
 * Entity uri callback.
 */
function wink_uri($wink) {
  return array(
    'path' => 'user/' . $wink->wink_uid,
  );
}

/******************************************************************************
 * Utility functions
 ******************************************************************************/

/**
 * Has this user been winked at recently or too many times
 * 
 * @param $wink_uid
 *   User id to check
 * 
 * @return
 *   Return Id of winker returned or FALSE
 * 
 * @todo
 *   would be nice to put max winks etc in variable
 */
function wink_has_winked($wink_uid) {
  
  global $user;
  
  // these things should be in a variable
  $max_winks_in_a_day = 3;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want favourites
  $query->entityCondition('entity_type', 'wink', '=');

  // match favourite_uid and current uid
  $query->propertyCondition('uid', $user->uid, '=');
  $query->propertyCondition('wink_uid', $wink_uid, '=');
  $query->propertyCondition('wink_created', date('Y:m:d 00:00:00'), '>');

  // execute
  $result = $query->execute();

  // return result
  if (isset($result['wink'])) {
    if (count($result['wink']) > $max_winks_in_a_day) {
      return key($result['wink']);
    }
  }
  
  return FALSE;
}

/******************************************************************************
 * Display Suite functions
 ******************************************************************************/

/**
 * Theme field for wink DS field
 *
 * @param $field
 *   The field to be output
 *
 * @return 
 *   The rendered field
 *
 * @see hook_ds_fields_info()
 */
function theme_ds_wink_field($field) {
  
  if (!user_access('access user profiles')) {
    return '';
  }
  
  // initialise output
  $output = '';
  
  // entity id
  if (isset($field['properties']['entity_id_key']) && isset($field['entity']->{$field['properties']['entity_id_key']})) {
    $entity_id = $field['entity']->{$field['properties']['entity_id_key']};
  } else {
    $entity_id = FALSE;
  }
  
  // no id no link
  if (empty($entity_id)) {
    return;
  }

  // Put together text for link
  if (isset($field['properties']['entity_render_key']) && isset($field['entity']->{$field['properties']['entity_render_key']})) {
    $render = $field['entity']->{$field['properties']['entity_render_key']};
  } else {
    $render = FALSE;
  }

  // no output no link
  if (empty($render)) {
    return;
  }
  
  // path
  if (isset($field['properties']['wink_path'])) {
    $wink_path = $field['properties']['wink_path'];
  } else {
    $wink_path = FALSE;
  }
  
  // no path no link
  if (empty($wink_path)) {
    return;
  }
  
  // finalise path
  $path = $wink_path . '/' . $entity_id;
  
  // options
  $options = array(
    'attributes' => array(
      'title' => sprintf(TWOOFAKIND_TITLE_WINK, $render),
      'class' => array('use-ajax')
    )
  );

  // put it all together
  $output = l('Wink', $path, $options);
  
  // wrap it in a div
  $output = "<div id=\"wink-$entity_id\">$output</div>";

  return $output;
  
}