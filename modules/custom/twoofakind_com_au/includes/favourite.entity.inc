<?php

/**
 * @file
 * favourite entity information and functions
 */

/**
 * Required constants
 */

if (!defined('TWOOFAKIND_PATH_FAVOURITE')) {
  define('TWOOFAKIND_PATH_FAVOURITE', 'favourite');
  define('TWOOFAKIND_TITLE_FAVOURITE', 'Favourite %s');
  define('TWOOFAKIND_MSG_FAVOURITE', '%s has been Favourited');
  define('TWOOFAKIND_PATH_UNFAVOURITE', 'unfavourite');
  define('TWOOFAKIND_TITLE_UNFAVOURITE', 'UnFavourite %s');
  define('TWOOFAKIND_MSG_UNFAVOURITE', '%s has been UnFavourited');
}

/******************************************************************************
 * Menu functions
 ******************************************************************************/

/**
 * Add favourite menu items
 *
 * @param $items
 *   Menu items array
 * 
 * @see hook_menu()
 */
function _favourite_menu(&$items) {

  $items[TWOOFAKIND_PATH_FAVOURITE . '/%/%user'] = array(
    'title'             => 'Favourite',
    'description'       => 'Favourite this user',
    'page callback'     => '_favourite_favourite',
    'page arguments'    => array(1,2),
    'access callback'   => 'user_access',
    'access arguments'  => array('access user profiles'),
    'type'              => MENU_CALLBACK,
//    'file'              => 'includes/favourite.entity.inc',
  );
  $items[TWOOFAKIND_PATH_UNFAVOURITE . '/%/%user'] = array(
    'title'             => 'UnFavourite',
    'description'       => 'UnFavourite this user',
    'page callback'     => '_favourite_unfavourite',
    'page arguments'    => array(1,2),
    'access callback'   => 'user_access',
    'access arguments'  => array('access user profiles'),
    'type'              => MENU_CALLBACK,
//    'file'              => 'includes/favourite.entity.inc',
  );
}

/**
 * Create a favourite
 * 
 * @todo
 *   This and the unfavourite function should be refactored and merged
 *
 * @param $favourite_uid
 *   The uid of the user being favourite-ed
 * 
 * @return
 *   The entity or FALSE
 */
function _favourite_favourite($type = 'ajax', $favourite_user = FALSE) {

  // defaults
  $link = '';
  $redirect = '<front>';
  $message = 'Favourite failed';
  $status = 'error';

  // if js is enabled and this is an ajax request
  if ($type == 'ajax') {
    // did we find a user?
    if ($favourite_user) {
      // we did, add favourite record
      // send an unfavourite link back in place of the favourite link
      // also send a notification
      // create favourite
      if (favourite_create($favourite_user->uid) !== FALSE) {
        // all went well
        // build response message
        $message = sprintf(TWOOFAKIND_MSG_FAVOURITE, $favourite_user->name);
        // build unfavourite link
        $link = _twoofakind_com_au_user_ajax_link($favourite_user, TWOOFAKIND_PATH_UNFAVOURITE, TWOOFAKIND_TITLE_UNFAVOURITE);
      }
    }
    else {
      // we didn't find one
      // send an error response back
      // create a message and wrap it in a span
      $message = 'User not found'; 
    }
    // ajax response
    _twoofakind_com_au_user_ajax_response($favourite_user, 'favourite', $message, $link);
  }
  else {
    // js is not enabled. this is a fallback response
    // did we find a user?
    if ($favourite_user) {
      // create favourite
      if (favourite_create($favourite_user->uid)) {
        // all good
        // message
        $message = sprintf(TWOOFAKIND_MSG_FAVOURITE, $favourite_user->name);
        $status = 'status';
        // redirect
        $redirect = 'user/' . $favourite_user->uid;
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

/**
 * Remove a favourite
 * 
 * @todo
 *   This and the favourite function should be refactored and merged
 *
 * @param $favourite_uid
 *   The uid of the user being unfavourite-ed
 * 
 * @return
 *   The entity or FALSE
 */
function _favourite_unfavourite($type = 'ajax', $favourite_user = FALSE) {

  // defaults
  $link = '';
  $redirect = '<front>';
  $message = 'UnFavourite failed';
  $status = 'error';
  
  // if js is enabled and this is an ajax request
  if ($type == 'ajax') {
    // did we find a user?
    if ($favourite_user) {
      // we did, remove favourite record
      // send a favourite link back in place of the unfavourite link
      // also send a notification
      // remove favourite
      if (favourite_delete($favourite_user->uid) !== FALSE) {
        // all went well
        // build response message
        $message = sprintf(TWOOFAKIND_MSG_UNFAVOURITE, $favourite_user->name);
        // build favourite link
        $link = _twoofakind_com_au_user_ajax_link($favourite_user, TWOOFAKIND_PATH_FAVOURITE, TWOOFAKIND_TITLE_FAVOURITE);
      }
    }
    else {
      // we didn't find one
      // send an error response back
      // create a message and wrap it in a span
      $message = 'User not found';
    }
    // ajax response
    _twoofakind_com_au_user_ajax_response($favourite_user, 'favourite', $message, $link);
  }
  else {
    // js is not enabled. this is a fallback response
    // did we find a user?
    if ($favourite_user) {
      // remove favourite
      if (favourite_delete($favourite_user->uid) !== FALSE) {
        // all good
        // message
        $message = sprintf(TWOOFAKIND_MSG_UNFAVOURITE, $favourite_user->name);
        $status = 'status';
        // redirect
        $redirect = 'user/' . $favourite_user->uid;
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
 * Load a favourite
 *
 * @param $id
 *   Id of favourite
 * @param $conditions
 *   Conditions you would like to specify
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of favourite objects, indexed by fid or FALSE if no favourites found
 * 
 * @see entity_load()
 */
function favourite_load($fid, $conditions = array(), $reset = FALSE) {
  $favourite = favourite_load_multiple(array($fid), $conditions, $reset);
  return reset($favourite);
}

/**
 * Load multiple favourites
 *
 * @param $fids
 *   An array of favourite IDs.
 * @param $conditions
 *   An array of conditions to favourite against the {favourite} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of favourite objects, indexed by fid or FALSE if no favourites found
 *
 * @see entity_load()
 */
function favourite_load_multiple($fids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('favourite', $fids, $conditions, $reset);
}

/**
 * Load all favourites
 *
 * @param $conditions
 *   An array of conditions to favourite against the {favourite} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of favourite objects, indexed by pid or FALSE if no favourites found
 *
 * @see entity_load()
 */
function favourite_load_all($conditions = array(), $reset = FALSE) {
  return favourite_load_multiple(FALSE, $conditions, $reset);
}

/******************************************************************************
 * CRUD functions
 ******************************************************************************/

/**
 * Create a favourite
 *
 * @param $favourite_uid
 *   The uid of the user being favourite-ed
 * 
 * @return
 *   The entity or FALSE
 */
function favourite_create($favourite_uid) {

  global $user;

  // double check that a favourite doesn't already exist
  $favourite_id = favourite_is_favourite($favourite_uid);
  if ($favourite_id !== FALSE) {
    
    // load the entity and return it
    $entity = favourite_load($favourite_id);
    return $entity;
  }
  
  $container = array(
    'uid' => $user->uid,
    'favourite_uid' => $favourite_uid
  );
  $entity = entity_create('favourite', $container);
  if($entity) {
    entity_get_controller('favourite')->save($entity);
    return $entity;
  }  
  return FALSE;
  
}

/**
 * Remove a favourite
 *
 * @param $favourite_uid
 *   The uid of the user being unfavourite-ed
 * 
 * @return
 *   The entity or FALSE
 */
function favourite_delete($favourite_uid) {
  
  // look to see if favourite exists
  // and thereby grabbing the id
  $favourite_id = favourite_is_favourite($favourite_uid);
  if ($favourite_id !== FALSE) {
    // delete
    return entity_delete('favourite', $favourite_id);
  }

  return FALSE;
  
}

/******************************************************************************
 * Count functions
 ******************************************************************************/

/**
 * Count un-viewed favourites when logged in user is favourite-er
 * 
 * @return
 *   An integer equal to the number of unviewed favourites for favourite-er
 */
function favourite_count_favouriteer_unviewed_favourites() {
  
  return favourite_count_unviewed_favourites('uid');
}

/**
 * Count un-viewed favourites when logged in user is favourite-ee
 * 
 * @return
 *   An integer equal to the number of unviewed favourites for favourite-ee
 */
function favourite_count_favouriteee_unviewed_favourites() {
  
  return favourite_count_unviewed_favourites('favourite_uid');
}

/**
 * Count un-viewed favourites for favourite-er or favourite-ee
 * 
 * @param $field_viewed
 *   Which viewed field to count on
 * 
 * @return
 *   An integer equal to the number of unviewed favourites for currently logged in user
 */
function favourite_count_unviewed_favourites($field_uid = 'uid') {
  
  global $user;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want favourites
  $query->entityCondition('entity_type', 'favourite', '=');

  // we want favourites for currently logged in user
  // determine the field based on the viewed field
  $query->propertyCondition($field_uid, $user->uid, '=');
  $query->propertyCondition('viewed', '0', '=');
  
  // execute
  $result = $query->execute();

  // return result
  if (isset($result['favourite'])) {
    return count($result['favourite']);
  }
  
  return 0;
}

/******************************************************************************
 * Callback functions
 ******************************************************************************/

/**
 * Entity uri callback.
 */
function favourite_uri($favourite) {
  return array(
    'path' => 'user/' . $favourite->favourite_uid,
  );
}

/******************************************************************************
 * Utility functions
 ******************************************************************************/

/**
 * Has this user been favourited
 * 
 * @param $favourite_uid
 *   User id to check
 * 
 * @return
 *   Return Id of first favourite returned or FALSE
 */
function favourite_is_favourite($favourite_uid) {
  
  global $user;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want favourites
  $query->entityCondition('entity_type', 'favourite', '=');

  // match favourite_uid and current uid
  $query->propertyCondition('uid', $user->uid, '=');
  $query->propertyCondition('favourite_uid', $favourite_uid, '=');
  
  // execute
  $result = $query->execute();

  // return result
  if (isset($result['favourite']) && count($result['favourite'])) {
    return key($result['favourite']);
  }
  
  return FALSE;
}

/******************************************************************************
 * Display Suite functions
 ******************************************************************************/

/**
 * Theme field for favourite DS field
 *
 * @param $field
 *   The field to be output
 *
 * @return 
 *   The rendered field
 *
 * @see hook_ds_fields_info()
 */
function theme_ds_favourite_field($field) {
  
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
  
  // work out if this person has already been favourited
  if (favourite_is_favourite($entity_id)) {
    $link_text = TWOOFAKIND_TITLE_UNFAVOURITE;
    $path_key = 'unfavourite_path';
  } else {
    $link_text = TWOOFAKIND_TITLE_FAVOURITE;
    $path_key = 'favourite_path';
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
  if (isset($field['properties'][$path_key])) {
    $favourite_path = $field['properties'][$path_key];
  } else {
    $favourite_path = FALSE;
  }
  
  // no path no link
  if (empty($favourite_path)) {
    return;
  }
  
  // finalise path
  $path = $favourite_path . '/' . $entity_id;
  
  // options
  $options = array(
    'attributes' => array(
      'title' => sprintf($link_text, $render),
      'class' => array('use-ajax')
    )
  );

  // put it all together
  $output = l(sprintf($link_text, ''), $path, $options);
  
  // wrap it in a div
  $output = "<div id=\"favourite-$entity_id\">$output</div>";

  return $output;
  
}