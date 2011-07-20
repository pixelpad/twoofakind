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
//        'join' => array(
//          'users' => array(
//            'table' => 'wink',
//            'field' => 'user_from_id',
//            'left_table' => 'users',
//            'left_field' => 'uid'
//          )
//        )
      ),
      'mid' => array(
        'group' => t('Match'),
        'title' => t('Mid'),
        'help' => t('The Match ID'),
        'field' => array(
          'handler' => 'views_handler_field_node',
          'click sortable' => TRUE,
        ),
        // Information for accepting a nid as a filter
//        'filter' => array(
//          'handler' => 'views_handler_filter_numeric',
//        ),
        // Information for sorting on a nid.
//        'sort' => array(
//          'handler' => 'views_handler_sort',
//        ),
        // Information for accepting a nid as an argument
//        'argument' => array(
//          'handler' => 'views_handler_argument_node_nid',
//          'name field' => 'title', // the field to display in the summary.
//          'numeric' => TRUE,
//          'validate type' => 'nid',
//        ),
      ),
      'uid' => array(
        'group' => t('Match'),
        'title' => t('User id for Matchee'),
        'help' => t('User id that we\'re finding matches for'),
        'relationship' => array(
          'base' => 'users',
          'field' => 'uid',
          'left_field' => 'uid',
          'left_table' => 'users',
          'handler' => 'views_handler_relationship',
          'label' => t('Matchee'),
        ),
//        'field' => array(
//          'handler' => 'views_handler_field_numeric',
//          'click sortable' => TRUE,
//         ),
//        'filter' => array(
//          'handler' => 'views_handler_filter_numeric',
//        ),
//        'sort' => array(
//          'handler' => 'views_handler_sort',
//        ),
      ),
      'uid_current' => array(
        'real field' => 'uid',
        'group' => t('Match'),
        'title' => t('Matchee is logged in user'),
        'help' => t('Filter results so that only the current user is the matchee'),
//        'field' => array(
//          'handler' => 'views_handler_field_numeric',
//          'click sortable' => TRUE,
//         ),
        'filter' => array(
          'handler' => 'views_handler_filter_user_current',
        ),
//        'sort' => array(
//          'handler' => 'views_handler_sort',
//        ),
      ),
      'match_uid' => array(
        'group' => t('Match'),
        'title' => t('User id of Match'),
        'help' => t('User id of matches found'),
        'relationship' => array(
          'base' => 'users',
          'field' => 'match_uid',
          'left_field' => 'uid',
          'left_table' => 'users',
          'handler' => 'views_handler_relationship',
          'label' => t('Match'),
        ),
//        'field' => array(
//          'handler' => 'views_handler_field_numeric',
//          'click sortable' => TRUE,
//         ),
//        'filter' => array(
//          'handler' => 'views_handler_filter_numeric',
//        ),
//        'sort' => array(
//          'handler' => 'views_handler_sort',
//        ),
      ),
      'match_uid_current' => array(
        'real field' => 'match_uid',
        'group' => t('Match'),
        'title' => t('Match is logged in user'),
        'help' => t('Filter results so that only the current user is the match'),
//        'field' => array(
//          'handler' => 'views_handler_field_numeric',
//          'click sortable' => TRUE,
//         ),
        'filter' => array(
          'handler' => 'views_handler_filter_user_current',
        ),
//        'sort' => array(
//          'handler' => 'views_handler_sort',
//        ),
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
      'viewed' => array(
        'group' => t('Match'),
        'title' => t('Viewed'),
        'help' => t('Has this Match been viewed?'),
        'field' => array(
          'handler' => 'views_handler_field_boolean',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_boolean_operator',
          'label' => t('Viewed'),
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