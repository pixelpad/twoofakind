<?php

/**
 * @file
 * Match entity information and functions
 */

/******************************************************************************
 * Load functions
 ******************************************************************************/

/**
 * Load a match
 *
 * @param $id
 *   Id of match
 * @param $conditions
 *   Conditions you would like to specify
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of match objects, indexed by mid or FALSE if no matches found
 * 
 * @see entity_load()
 */
function match_load($mid, $conditions = array(), $reset = FALSE) {
  $match = match_load_multiple(array($mid), $conditions, $reset);
  return reset($match);
}

/**
 * Load multiple matches
 *
 * @param $mids
 *   An array of match IDs.
 * @param $conditions
 *   An array of conditions to match against the {match} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of match objects, indexed by mid or FALSE if no matches found
 *
 * @see entity_load()
 */
function match_load_multiple($mids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('match', $mids, $conditions, $reset);
}

/**
 * Load all matches
 *
 * @param $conditions
 *   An array of conditions to match against the {match} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of match objects, indexed by pid or FALSE if no matches found
 *
 * @see entity_load()
 */
function match_load_all($conditions = array(), $reset = FALSE) {
  return match_load_multiple(FALSE, $conditions, $reset);
}

/**
 * Load matches from current user to
 * 
 * @param $match_uid
 *   User id to check
 * 
 * @return
 *   Return array of match entities
 */
function match_load_from_current_to_account($match_uid) {
  
  global $user;
  
  return match_load_from_matcher_matchee($user->uid, $match_uid);
}

/**
 * Load matches from user to current
 * 
 * @param $match_uid
 *   User id to check
 * 
 * @return
 *   Return array of match entities
 */
function match_load_from_account_to_current($match_uid) {
  
  global $user;
  
  return match_load_from_matcher_matchee($match_uid, $user->uid);
}

/**
 * Load matches from matcher to matchee
 * 
 * @param $matcher_uid
 *   Uid of matcher
 * 
 * @param $matchee_uid
 *   Uid of matchee
 * 
 * @return
 *   Return array of match entities
 */
function match_load_from_matcher_matchee($matcher_uid, $matchee_uid) {
  
  global $user;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want favourites
  $query->entityCondition('entity_type', 'match', '=');

  // match favourite_uid and current uid
  $query->propertyCondition('uid', $matcher_uid, '=');
  $query->propertyCondition('match_uid', $matchee_uid, '=');

  // execute
  $result = $query->execute();

  // return result
  if (isset($result['match']) && count($result['match'])) {
      return match_load_multiple(array_keys($result['match']));
  }
  
  return array();
}

/******************************************************************************
 * CRUD functions
 ******************************************************************************/

/**
 * Create a match
 *
 * @param $match_uid
 *   The uid of the user being match-ed
 * 
 * @return
 *   The entity or FALSE
 */
function match_create($match_uid) {

  global $user;

  // double check that a match doesn't already exist
  $match_id = match_is_match($match_uid);
  if ($match_id !== FALSE) {
    
    // load the entity and return it
    $entity = match_load($match_id);
    return $entity;
  }
  
  $container = array(
    'uid' => $user->uid,
    'match_uid' => $match_uid
  );
  $entity = entity_create('match', $container);
  if($entity) {
    entity_get_controller('match')->save($entity);
    return $entity;
  }  
  return FALSE;
  
}

/**
 * Update a match
 *
 * @param $match
 *   The match being updated
 * 
 * @return
 *   The entity or FALSE
 */
function match_update($match) {
  
  if($match) {
    entity_get_controller('match')->save($match);
    return $match;
  }  
  return FALSE;
  
}

/******************************************************************************
 * Count functions
 ******************************************************************************/

/**
 * Count un-viewed matches when logged in user is matcher
 * 
 * @return
 *   An integer equal to the number of unviewed matches for matcher
 */
function match_count_matcher_unviewed_matches() {
  
  return match_count_unviewed_matches('viewed_uid');
}

/**
 * Count un-viewed matches when logged in user is matchee
 * 
 * @return
 *   An integer equal to the number of unviewed matches for matchee
 */
function match_count_matchee_unviewed_matches() {
  
  return match_count_unviewed_matches('viewed_match_uid');
}

/**
 * Count un-viewed matches for matcher or matchee
 * 
 * @param $field_viewed
 *   Which viewed field to count on
 * 
 * @return
 *   An integer equal to the number of unviewed matches for currently logged in user
 */
function match_count_unviewed_matches($field_viewed = 'viewed_uid') {
  
  global $user;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want matches
  $query->entityCondition('entity_type', 'match', '=');

  // we want matches for currently logged in user
  // determine the field based on the viewed field
  $match_uid = str_replace('viewed_', '', $field_viewed);
  $query->propertyCondition($match_uid, $user->uid, '=');
  $query->propertyCondition($field_viewed, '0', '=');
  
  // execute
  $result = $query->execute();

  // return result
  if (isset($result['match'])) {
    return count($result['match']);
  }
  
  return 0;
}

/******************************************************************************
 * Callback functions
 ******************************************************************************/

/**
 * Entity uri callback.
 */
function match_uri($match) {
  return array(
    'path' => 'user/' . $match->match_uid,
  );
}

/******************************************************************************
 * Utility functions
 ******************************************************************************/

/**
 * Has this user been matched
 * 
 * @param $match_uid
 *   User id to check
 * 
 * @return
 *   Return Id of first match returned or FALSE
 */
function match_is_match($match_uid) {
  
  global $user;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want matches
  $query->entityCondition('entity_type', 'match', '=');

  // match match_uid and current uid
  $query->propertyCondition('uid', $user->uid, '=');
  $query->propertyCondition('match_uid', $match_uid, '=');
  
  // execute
  $result = $query->execute();

  // return result
  if (isset($result['match']) && count($result['match'])) {
    return key($result['match']);
  }
  
  return FALSE;
}