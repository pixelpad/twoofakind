<?php

/**
 * @file
 * recent_view entity information and functions
 */

/******************************************************************************
 * Load functions
 ******************************************************************************/

/**
 * Load a recent_view
 *
 * @param $id
 *   Id of recent_view
 * @param $conditions
 *   Conditions you would like to specify
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of recent_view objects, indexed by vid or FALSE if no recent_views found
 * 
 * @see entity_load()
 */
function recent_view_load($vid, $conditions = array(), $reset = FALSE) {
  $recent_view = recent_view_load_multiple(array($vid), $conditions, $reset);
  return reset($recent_view);
}

/**
 * Load multiple recent_views
 *
 * @param $vids
 *   An array of recent_view IDs.
 * @param $conditions
 *   An array of conditions to recent_view against the {recent_view} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of recent_view objects, indexed by vid or FALSE if no recent_views found
 *
 * @see entity_load()
 */
function recent_view_load_multiple($vids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('recent_view', $vids, $conditions, $reset);
}

/**
 * Load all recent_views
 *
 * @param $conditions
 *   An array of conditions to recent_view against the {recent_view} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * 
 * @return
 *   An array of recent_view objects, indexed by pid or FALSE if no recent_views found
 *
 * @see entity_load()
 */
function recent_view_load_all($conditions = array(), $reset = FALSE) {
  return recent_view_load_multiple(FALSE, $conditions, $reset);
}

/******************************************************************************
 * CRUD functions
 ******************************************************************************/

/**
 * Create a recent_view
 *
 * @param $recent_view_uid
 *   The uid of the user being view-ed
 * 
 * @return
 *   The entity or FALSE
 */
function recent_view_create($recent_view_uid) {

  global $user;
  
  // don't add a recent view for yourself
  if ($user->uid == $recent_view_uid) {
    return;
  }
  
  // no need to check if one exists or not
  // can view as many times as they like
  
  $container = array(
    'uid' => $user->uid,
    'recent_view_uid' => $recent_view_uid
  );
  $entity = entity_create('recent_view', $container);
  if($entity) {
    entity_get_controller('recent_view')->save($entity);
    return $entity;
  }  
  return FALSE;
  
}

/******************************************************************************
 * Count functions
 ******************************************************************************/

/**
 * Count un-viewed recent_views when logged in user is recent_viewer
 * 
 * @return
 *   An integer equal to the number of unviewed recent_views for recent_viewer
 */
function recent_view_count_recent_viewer_unviewed_recent_views() {
  
  return recent_view_count_unviewed_recent_views('uid');
}

/**
 * Count un-viewed recent_views when logged in user is recent_viewee
 * 
 * @return
 *   An integer equal to the number of unviewed recent_views for recent_viewee
 */
function recent_view_count_recent_viewee_unviewed_recent_views() {
  
  return recent_view_count_unviewed_recent_views('recent_view_uid');
}

/**
 * Count un-viewed recent_views for recent_viewer or recent_viewee
 * 
 * @param $field_viewed
 *   Which viewed field to count on
 * 
 * @return
 *   An integer equal to the number of unviewed recent_views for currently logged in user
 */
function recent_view_count_unviewed_recent_views($field_uid = 'uid') {
  
  global $user;
  
  // set up the query   
  $query = new EntityFieldQuery();
  // we only want recent_views
  $query->entityCondition('entity_type', 'recent_view', '=');

  // we want recent_views for currently logged in user
  // determine the field based on the viewed field
  $query->propertyCondition($field_uid, $user->uid, '=');
  $query->propertyCondition('viewed', '0', '=');
  
  // execute
  $result = $query->execute();

  // return result
  if (isset($result['recent_view'])) {
    return count($result['recent_view']);
  }
  
  return 0;
}

/******************************************************************************
 * Callback functions
 ******************************************************************************/

/**
 * Entity uri callback.
 */
function recent_view_uri($recent_view) {
  return array(
    'path' => 'user/' . $recent_view->recent_view_uid,
  );
}