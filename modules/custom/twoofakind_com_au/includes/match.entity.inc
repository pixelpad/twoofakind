<?php

/**
 * @file
 * Match entity information and functions
 */

/******************************************************************************
 * Entity functions
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
 * Count un-viewed matches for logged in user
 * 
 * @return
 *   An integer equal to the number of unviewed matches for currently logged in user
 */
function match_count_matches() {
  
  global $user;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want matches
  $query->entityCondition('entity_type', 'match', '=');

  // we want matches for currently logged in user
  $query->propertyCondition('uid', $user->uid, '=');
  $query->propertyCondition('viewed', '0', '=');
  
  // execute
  $result = $query->execute();

  // return result
  if (isset($result['match'])) {
    return count($result['match']);
  }
  
  return 0;
}