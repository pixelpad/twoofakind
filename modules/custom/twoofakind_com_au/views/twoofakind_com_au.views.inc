<?php

/**
 * @file
 * Exposing matches to views
 */


/**
 * Implements hook_views_data()
 */
function twoofakind_com_au_views_data() { 

  $data = array(
    'matches' => array(
      'table' => array(
        'group' => t('Match'),
        'base' => array(
          'field' => 'wid',
          'title' => t('Match'),
          'help' => t('Matches between users'),
          'weight' => 100,
        ),
      ),
      'mid' => array(
        'group' => t('Match'),
        'title' => t('Mid'),
        'help' => t('The Match ID'),
        'field' => array(
          'handler' => 'views_handler_field_node',
          'click sortable' => TRUE,
        ),
      ),
      'uid' => array(
        'group' => t('Match'),
        'title' => t('User id for Matcher'),
        'help' => t('User id of the Matcher'),
        'relationship' => array(
          'base' => 'users',
          'field' => 'uid',
          'left_field' => 'uid',
          'left_table' => 'users',
          'handler' => 'views_handler_relationship',
          'label' => t('Matcher'),
        ),
      ),
      'uid_current' => array(
        'real field' => 'uid',
        'group' => t('Match'),
        'title' => t('Matcher is logged in user'),
        'help' => t('Filter results so the current user is the Matcher'),
        'filter' => array(
          'handler' => 'views_handler_filter_user_current',
        ),
      ),
      'match_uid' => array(
        'group' => t('Match'),
        'title' => t('User id of Matchee'),
        'help' => t('User id of Matchee'),
        'relationship' => array(
          'base' => 'users',
          'field' => 'match_uid',
          'left_field' => 'uid',
          'left_table' => 'users',
          'handler' => 'views_handler_relationship',
          'label' => t('Matchee'),
        ),
      ),
      'match_uid_current' => array(
        'real field' => 'match_uid',
        'group' => t('Match'),
        'title' => t('Matchee is logged in user'),
        'help' => t('Filter results so that only the current user is the Matchee'),
        'filter' => array(
          'handler' => 'views_handler_filter_user_current',
        ),
      ),
      'created' => array(
        'group' => t('Match'),
        'title' => t('Created'),
        'help' => t('The date this Match was created.'),
        'field' => array(
          'handler' => 'views_handler_field_date',
          'click sortable' => TRUE,
        ),
        'sort' => array(
          'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
      ),
      'viewed_uid' => array(
        'group' => t('Match'),
        'title' => t('Viewed by Matcher'),
        'help' => t('Has this Match been viewed by the Matcher?'),
        'field' => array(
          'handler' => 'views_handler_field_boolean',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_boolean_operator',
          'label' => t('Viewed by Matcher'),
          'type' => 'yes-no',
          // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
          'use equal' => TRUE,
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),
      'viewed_match_uid' => array(
        'group' => t('Match'),
        'title' => t('Viewed by Matchee'),
        'help' => t('Has this Match been viewed by the Matchee?'),
        'field' => array(
          'handler' => 'views_handler_field_boolean',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_boolean_operator',
          'label' => t('Viewed by Matchee'),
          'type' => 'yes-no',
          // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
          'use equal' => TRUE,
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      )
    ),
  );
  
  return $data;
}