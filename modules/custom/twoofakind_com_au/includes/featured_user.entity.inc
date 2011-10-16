<?php

/**
 * @file
 * featured_user entity information and functions
 */

/**
 * Required constants
 */

if (!defined('TWOOFAKIND_PATH_FEATURED_USER')) {
  define('TWOOFAKIND_PATH_FEATURED_USER', 'feature_user');
  define('TWOOFAKIND_TITLE_FEATURED_USER', 'Feature %s');
  define('TWOOFAKIND_MSG_FEATURED_USER', '%s has been Featured');
  define('TWOOFAKIND_PATH_UNFEATURED_USER', 'unfeature_user');
  define('TWOOFAKIND_TITLE_UNFEATURED_USER', 'UnFeature %s');
  define('TWOOFAKIND_MSG_UNFEATURED_USER', '%s has been UnFeatured');
}

/******************************************************************************
 * Menu functions
 ******************************************************************************/

/**
 * Add featured_user menu items
 *
 * @param $items
 *   Menu items array
 * 
 * @see hook_menu()
 */
function _featured_user_menu(&$items) {

  $items[TWOOFAKIND_PATH_FEATURED_USER . '/%/%user'] = array(
    'title'             => 'Feature user',
    'description'       => 'Feature this user',
    'page callback'     => '_featured_user_feature',
    'page arguments'    => array(1,2),
    'access callback'   => 'user_access',
    'access arguments'  => array('access user profiles'),
    'type'              => MENU_CALLBACK,
    'file'              => 'includes/featured_user.entity.inc',
  );
  $items[TWOOFAKIND_PATH_UNFEATURED_USER . '/%/%user'] = array(
    'title'             => 'UnFeature user',
    'description'       => 'UnFeature this user',
    'page callback'     => '_featured_user_unfeature',
    'page arguments'    => array(1,2),
    'access callback'   => 'user_access',
    'access arguments'  => array('access user profiles'),
    'type'              => MENU_CALLBACK,
    'file'              => 'includes/featured_user.entity.inc',
  );
}

/**
 * Create a featured_user
 * 
 * @todo
 *   This and the unfeatured_user function should be refactored and merged
 *
 * @param $featured_user_uid
 *   The uid of the user being featured_user-ed
 * 
 * @return
 *   The entity or FALSE
 */
function _featured_user_feature($type = 'ajax', $featured_user_user = FALSE) {

  // defaults
  $link = '';
  $redirect = '<front>';
  $message = 'Featured user failed';
  $status = 'error';

  // if js is enabled and this is an ajax request
  if ($type == 'ajax') {
    
    // did we find a user?
    if ($featured_user_user) {

      // we did, add featured_user record
      // send an unfeatured_user link back in place of the featured_user link
      // also send a notification
      
      // create featured_user
      if (featured_user_create($featured_user_user->uid) !== FALSE) {

        // all went well

        // build response message
        $message = sprintf(TWOOFAKIND_MSG_FEATURED_USER, $featured_user_user->name);
        
        // build unfeatured_user link
        $link = _twoofakind_com_au_user_ajax_link($featured_user_user, TWOOFAKIND_PATH_UNFEATURED_USER, TWOOFAKIND_TITLE_UNFEATURED_USER);

      }
      
    }
    else {
      
      // we didn't find one
      // send an error response back
      
      // create a message and wrap it in a span
      $message = 'User not found';
      
    }

    // ajax response
    _twoofakind_com_au_user_ajax_response($featured_user_user, 'featured_user', $message, $link);
    
  }
  else {
    
    // js is not enabled. this is a fallback response
    
    // did we find a user?
    if ($featured_user_user) {
      
      // create featured_user
      if (featured_user_create($featured_user_user->uid)) {
        
        // all good
        
        // message
        $message = sprintf(TWOOFAKIND_MSG_FEATURED_USER, $featured_user_user->name);
        $status = 'status';
        
        // redirect
        $redirect = 'user/' . $featured_user_user->uid;
        
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
 * Remove a featured_user
 * 
 * @todo
 *   This and the featured_user function should be refactored and merged
 *
 * @param $featured_user_uid
 *   The uid of the user being unfeatured_user-ed
 * 
 * @return
 *   The entity or FALSE
 */
function _featured_user_unfeature($type = 'ajax', $featured_user_user = FALSE) {

  // defaults
  $link = '';
  $redirect = '<front>';
  $message = 'UnFeatured user failed';
  $status = 'error';
  
  
  // if js is enabled and this is an ajax request
  if ($type == 'ajax') {
    
    // did we find a user?
    if ($featured_user_user) {

      // we did, remove featured_user record
      // send a featured_user link back in place of the unfeatured_user link
      // also send a notification
      
      // remove featured_user
      if (featured_user_delete($featured_user_user->uid) !== FALSE) {

        // all went well

        // build response message
        $message = sprintf(TWOOFAKIND_MSG_UNFEATURED_USER, $featured_user_user->name);
        
        // build featured_user link
        $link = _twoofakind_com_au_user_ajax_link($featured_user_user, TWOOFAKIND_PATH_FEATURED_USER, TWOOFAKIND_TITLE_FEATURED_USER);

      }
      
    }
    else {
      
      // we didn't find one
      // send an error response back
      
      // create a message and wrap it in a span
      $message = 'User not found';
      
    }

    // ajax response
    _twoofakind_com_au_user_ajax_response($featured_user_user, 'featured_user', $message, $link);
    
  }
  else {
    
    // js is not enabled. this is a fallback response
    
    // did we find a user?
    if ($featured_user_user) {
      
      // remove featured_user
      if (featured_user_delete($featured_user_user->uid) !== FALSE) {
        
        // all good
        
        // message
        $message = sprintf(TWOOFAKIND_MSG_UNFEATURED_USER, $featured_user_user->name);
        $status = 'status';
        
        // redirect
        $redirect = 'user/' . $featured_user_user->uid;
        
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
 * Load a featured_user
 *
 * @param $id
 *   Id of featured_user
 * @param $conditions
 *   Conditions you would like to specify
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of featured_user objects, indexed by fid or FALSE if no featured_users found
 * 
 * @see entity_load()
 */
function featured_user_load($fid, $conditions = array(), $reset = FALSE) {
  $featured_user = featured_user_load_multiple(array($fid), $conditions, $reset);
  return reset($featured_user);
}

/**
 * Load multiple featured_users
 *
 * @param $fids
 *   An array of featured_user IDs.
 * @param $conditions
 *   An array of conditions to featured_user against the {featured_user} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of featured_user objects, indexed by fid or FALSE if no featured_users found
 *
 * @see entity_load()
 */
function featured_user_load_multiple($fids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('featured_user', $fids, $conditions, $reset);
}

/**
 * Load all featured_users
 *
 * @param $conditions
 *   An array of conditions to featured_user against the {featured_user} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of featured_user objects, indexed by pid or FALSE if no featured_users found
 *
 * @see entity_load()
 */
function featured_user_load_all($conditions = array(), $reset = FALSE) {
  return featured_user_load_multiple(FALSE, $conditions, $reset);
}

/******************************************************************************
 * CRUD functions
 ******************************************************************************/

/**
 * Create a featured_user
 *
 * @param $featured_user_uid
 *   The uid of the user being featured_user-ed
 * 
 * @return
 *   The entity or FALSE
 */
function featured_user_create($featured_user_uid) {

  global $user;

  // double check that a featured_user doesn't already exist
  $featured_user_id = featured_user_is_featured_user($featured_user_uid);
  if ($featured_user_id !== FALSE) {
    
    // load the entity and return it
    $entity = featured_user_load($featured_user_id);
    return $entity;
  }
  
  $container = array(
    'uid' => $user->uid,
    'featured_user_uid' => $featured_user_uid
  );
  $entity = entity_create('featured_user', $container);
  if($entity) {
    entity_get_controller('featured_user')->save($entity);
    return $entity;
  }  
  return FALSE;
  
}

/**
 * Remove a featured_user
 *
 * @param $featured_user_uid
 *   The uid of the user being unfeatured_user-ed
 * 
 * @return
 *   The entity or FALSE
 */
function featured_user_delete($featured_user_uid) {
  
  // look to see if featured_user exists
  // and thereby grabbing the id
  $featured_user_id = featured_user_is_featured_user($featured_user_uid);
  if ($featured_user_id !== FALSE) {
    // delete
    return entity_delete('featured_user', $featured_user_id);
  }

  return FALSE;
  
}

/******************************************************************************
 * Callback functions
 ******************************************************************************/

/**
 * Entity uri callback.
 */
function featured_user_uri($featured_user) {
  return array(
    'path' => 'user/' . $featured_user->featured_user_uid,
  );
}

/******************************************************************************
 * Utility functions
 ******************************************************************************/

/**
 * Has this user been featured_userd
 * 
 * @param $featured_user_uid
 *   User id to check
 * 
 * @return
 *   Return Id of first featured_user returned or FALSE
 */
function featured_user_is_featured_user($featured_user_uid) {
  
  global $user;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want featured_users
  $query->entityCondition('entity_type', 'featured_user', '=');

  // match featured_user_uid and current uid
  $query->propertyCondition('uid', $user->uid, '=');
  $query->propertyCondition('featured_user_uid', $featured_user_uid, '=');
  
  // execute
  $result = $query->execute();

  // return result
  if (isset($result['featured_user']) && count($result['featured_user'])) {
    return key($result['featured_user']);
  }
  
  return FALSE;
}

/******************************************************************************
 * Display Suite functions
 ******************************************************************************/

/**
 * Theme field for featured_user DS field
 *
 * @param $field
 *   The field to be output
 *
 * @return 
 *   The rendered field
 *
 * @see hook_ds_fields_info()
 */
function theme_ds_featured_user_field($field) {
  
  if (!user_access('administer users')) {
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
  
  // work out if this person has already been featured_userd
  if (featured_user_is_featured_user($entity_id)) {
    $link_text = TWOOFAKIND_TITLE_UNFEATURED_USER;
    $path_key = 'unfeature_user_path';
  } else {
    $link_text = TWOOFAKIND_TITLE_FEATURED_USER;
    $path_key = 'feature_user_path';
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
    $feature_user_path = $field['properties'][$path_key];
  } else {
    $feature_user_path = FALSE;
  }
  
  // no path no link
  if (empty($feature_user_path)) {
    return;
  }
  
  // finalise path
  $path = $feature_user_path . '/' . $entity_id;
  
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
  $output = "<div id=\"featured_user-$entity_id\">$output</div>";

  return $output;
  
}