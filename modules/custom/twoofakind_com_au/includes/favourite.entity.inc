<?php

/**
 * @file
 * wink entity information and functions
 */

/******************************************************************************
 * Entity functions
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