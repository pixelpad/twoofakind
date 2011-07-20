<?php

/**
 * @file
 * Providing extra functionality for the Model UI via views.
 */


/**
 * Implements hook_views_data()
 */
function wink_views_data() { 

  $data = array(
    'wink' => array(
      'table' => array(
        'group' => t('Wink from'),
        'base' => array(
          'field' => 'wid',
          'title' => t('Wink from'),
          'help' => t('Wink from a user'),
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
      'wid' => array(
        'group' => t('Wink from'),
        'title' => t('Wid'),
        'help' => t('The wink ID of the wink.'), // The help that appears on the UI,
        // Information for displaying the nid
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
      'user_from_id' => array(
        'group' => t('Wink from'),
        'title' => t('User from ID'),
        'help' => t('The Uid of the User this Wink is from.'),
        'relationship' => array(
          'base' => 'users',
          'field' => 'user_from_id',
          'left_field' => 'uid',
          'left_table' => 'users',
          'handler' => 'views_handler_relationship',
          'label' => t('User from ID'),
        ),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
//        'filter' => array(
//          'handler' => 'views_handler_filter_numeric',
//        ),
//        'sort' => array(
//          'handler' => 'views_handler_sort',
//        ),
      ),
      'user_to_id' => array(
        'group' => t('Wink from'),
        'title' => t('User to ID'),
        'help' => t('The Uid of the User this Wink is to.'),
//        'relationship' => array(
//          'base' => 'users',
//          'field' => 'user_to_id',
//          'left_field' => 'uid',
//          'left_table' => 'users',
//          'handler' => 'views_handler_relationship',
//          'label' => t('User to ID'),
//        ),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
        'filter' => array(
          'handler' => 'views_handler_filter_user_current',
        ),
//        'sort' => array(
//          'handler' => 'views_handler_sort',
//        ),
      ),
      'date_of_wink' => array(
        'group' => t('Wink from'),
        'title' => t('Date of Wink'),
        'help' => t('The date this Wink was created.'),
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
      'historic' => array(
        'group' => t('Wink from'),
        'title' => t('Historic'),
        'help' => t('Has this Wink been viewed?'),
        'field' => array(
          'handler' => 'views_handler_field_boolean',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_boolean_operator',
          'label' => t('Historic'),
          'type' => 'yes-no',
          // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
          'use equal' => TRUE,
        ),
//        'sort' => array(
//          'handler' => 'views_handler_sort',
//        ),
      )
    ),
  );
  
  return $data;
}