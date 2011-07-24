<?php

/**
 * @file
 * favourite entity information and functions
 */

/******************************************************************************
 * Entity functions
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
 *   An array of favourite objects, indexed by wid or FALSE if no favourites found
 * 
 * @see entity_load()
 */
function favourite_load($wid, $conditions = array(), $reset = FALSE) {
  $favourite = favourite_load_multiple(array($wid), $conditions, $reset);
  return reset($favourite);
}

/**
 * Load multiple favourites
 *
 * @param $wids
 *   An array of favourite IDs.
 * @param $conditions
 *   An array of conditions to favourite against the {favourite} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of favourite objects, indexed by wid or FALSE if no favourites found
 *
 * @see entity_load()
 */
function favourite_load_multiple($wids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('favourite', $wids, $conditions, $reset);
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