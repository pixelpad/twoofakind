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
 *   An array of match objects, indexed by rid or FALSE if no matches found
 * 
 * @see entity_load()
 */
function match_load($rid, $conditions = array(), $reset = FALSE) {
  $match = match_load_multiple(array($rid), $conditions, $reset);
  return reset($match);
}

/**
 * Load multiple matches
 *
 * @param $rids
 *   An array of match IDs.
 * @param $conditions
 *   An array of conditions to match against the {match} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of match objects, indexed by rid or FALSE if no matches found
 *
 * @see entity_load()
 */
function match_load_multiple($rids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('match', $rids, $conditions, $reset);
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