<?php

/**
 * @file
 * Exposing matches to views
 */

/**
 * Implements hook_views_data()
 */
function twoofakind_com_au_views_data() { 

  $data = array();
  
  // favourites
  _twoofakind_com_au_views_data_favourites($data);
  
  // matches
//  _twoofakind_com_au_views_data_matches($data);
  
  // recent views
//  _twoofakind_com_au_views_data_recent_views($data);
  
  // winks
//  _twoofakind_com_au_views_data_winks($data);
  
  return $data;
}

/**
 * Expose favourites table to views
 *
 * @param $data
 *   data array to be given to views
 * 
 * @see hook_views_data()
 */
function _twoofakind_com_au_views_data_favourites(&$data) {
  
  // common fields
  $data_common = array(
    'table' => array(),
    'fid' => array(
      'title' => t('Fid'),
      'help' => t('The Favourite ID'),
      'field' => array(
        'handler' => 'views_handler_field_node',
        'click sortable' => TRUE,
      ),
    ),
    'uid' => array(
      'title' => t('Uid of favourite-er'),
      'help' => t('User id of person marking the other as a favourite')
    ),
    'favourite_uid' => array(
      'title' => t('User id of Favourite-ee'),
      'help' => t('User id of person being marked as favourite'),
    ),
    'created' => array(
      'title' => t('Created'),
      'help' => t('The date this Favourite was created.'),
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
      'title' => t('Viewed by Favourite recipient'),
      'help' => t('Has this Favourite been viewed by the Favourite recipient?'),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
        'label' => t('Viewed by Favourite recipient'),
        'type' => 'yes-no',
        // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
        'use equal' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    )
  );
  
  // favourites
  $data['favourites'] = $data_common;
  $data['favourites']['table']['group'] = t('Favourite-er');
  $data['favourites']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'favourite_uid',
      'table' => 'favourites'
    )
  );
  $data['favourites']['uid_current'] = array(
    'real field' => 'uid',
    'title' => t('Favourite-er is logged in user'),
    'help' => t('Filter results so the current user is the Favourite-er'),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
  );
  
  // favourites received
  $data['favourites_received'] = $data_common;
  $data['favourites_received']['table']['group'] = t('Favourite-ee');
  $data['favourites_received']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'table' => 'favourites'
    )
  );
  $data['favourites_received']['uid_current'] = array(
    'real field' => 'favourite_uid',
    'title' => t('Favourite-ee is logged in user'),
    'help' => t('Filter results so the current user is the Favourite-ee'),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
  );
  
}

/**
 * Expose matches table to views
 *
 * @param $data
 *   data array to be given to views
 * 
 * @see hook_views_data()
 */
function _twoofakind_com_au_views_data_matches(&$data) {
  
  // matches
  $data['matches'] = array(
    'table' => array(
      'group' => t('Match'),
      'base' => array(
        'field' => 'mid',
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
  );
  
}

/**
 * Expose recent views table to views
 *
 * @param $data
 *   data array to be given to views
 * 
 * @see hook_views_data()
 */
function _twoofakind_com_au_views_data_recent_views(&$data) {
  
  // recent_views
  $data['recent_views'] = array(
    'table' => array(
      'group' => t('Recent View'),
      'base' => array(
        'field' => 'vid',
        'title' => t('Recent View'),
        'help' => t('Recent views of one user to another'),
        'weight' => 102,
      ),
    ),
    'vid' => array(
      'group' => t('Recent View'),
      'title' => t('Vid'),
      'help' => t('The Recent View ID'),
      'field' => array(
        'handler' => 'views_handler_field_node',
        'click sortable' => TRUE,
      ),
    ),
    'uid' => array(
      'group' => t('Recent View'),
      'title' => t('Uid of Recent Viewer'),
      'help' => t('User id of the Recent Viewer'),
      'relationship' => array(
        'base' => 'users',
        'field' => 'uid',
        'left_field' => 'uid',
        'left_table' => 'users',
        'handler' => 'views_handler_relationship',
        'label' => t('Recent Viewer'),
      ),
    ),
    'uid_current' => array(
      'real field' => 'uid',
      'group' => t('Recent View'),
      'title' => t('Recent Viewer is logged in user'),
      'help' => t('Filter results so the current user is the Recent Viewer'),
      'filter' => array(
        'handler' => 'views_handler_filter_user_current',
      ),
    ),
    'recent_view_uid' => array(
      'group' => t('Recent View'),
      'title' => t('User id of user recently viewed'),
      'help' => t('User id of user recently viewed'),
      'relationship' => array(
        'base' => 'users',
        'field' => 'recent_view_uid',
        'left_field' => 'uid',
        'left_table' => 'users',
        'handler' => 'views_handler_relationship',
        'label' => t('Recently Viewed'),
      ),
    ),
    'recent_view_uid_current' => array(
      'real field' => 'recent_view_uid',
      'group' => t('Recent View'),
      'title' => t('User recently viewed is logged in user'),
      'help' => t('Filter results so that only the current user is the user recently viewed'),
      'filter' => array(
        'handler' => 'views_handler_filter_user_current',
      ),
    ),
    'created' => array(
      'group' => t('Recent View'),
      'title' => t('Created'),
      'help' => t('The date the user was viewed.'),
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
      'group' => t('Recent View'),
      'title' => t('Viewed by Recently Viewed'),
      'help' => t('Has this Recent View been viewed / acknolowedged by the user recently viewed?'),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
        'label' => t('Viewed by user recently viewed'),
        'type' => 'yes-no',
        // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
        'use equal' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    )
  );
  
}

/**
 * Expose winks table to views
 *
 * @param $data
 *   data array to be given to views
 * 
 * @see hook_views_data()
 */
function _twoofakind_com_au_views_data_winks(&$data) {
  
  // winks
  $data['winks'] = array(
    'table' => array(
      'group' => t('Wink'),
      'base' => array(
        'field' => 'wid',
        'title' => t('Wink'),
        'help' => t('Winks between users'),
        'weight' => 101,
      ),
    ),
    'wid' => array(
      'group' => t('Wink'),
      'title' => t('Wid'),
      'help' => t('The Wink ID'),
      'field' => array(
        'handler' => 'views_handler_field_node',
        'click sortable' => TRUE,
      ),
    ),
    'uid' => array(
      'group' => t('Wink'),
      'title' => t('Uid of Winker'),
      'help' => t('User id of the Winker'),
      'relationship' => array(
        'base' => 'users',
        'field' => 'uid',
        'left_field' => 'uid',
        'left_table' => 'users',
        'handler' => 'views_handler_relationship',
        'label' => t('Winker'),
      ),
    ),
    'uid_current' => array(
      'real field' => 'uid',
      'group' => t('Wink'),
      'title' => t('Winker is logged in user'),
      'help' => t('Filter results so the current user is the Winker'),
      'filter' => array(
        'handler' => 'views_handler_filter_user_current',
      ),
    ),
    'wink_uid' => array(
      'group' => t('Wink'),
      'title' => t('User id of Wink recipient'),
      'help' => t('User id of Wink recipient'),
      'relationship' => array(
        'base' => 'users',
        'field' => 'wink_uid',
        'left_field' => 'uid',
        'left_table' => 'users',
        'handler' => 'views_handler_relationship',
        'label' => t('Wink recipient'),
      ),
    ),
    'wink_uid_current' => array(
      'real field' => 'wink_uid',
      'group' => t('Wink'),
      'title' => t('Wink recipient is logged in user'),
      'help' => t('Filter results so that only the current user is the Wink recipient'),
      'filter' => array(
        'handler' => 'views_handler_filter_user_current',
      ),
    ),
    'created' => array(
      'group' => t('Wink'),
      'title' => t('Created'),
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
    'viewed' => array(
      'group' => t('Wink'),
      'title' => t('Viewed by Wink recipient'),
      'help' => t('Has this Wink been viewed by the Wink recipient?'),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
        'label' => t('Viewed by Wink recipient'),
        'type' => 'yes-no',
        // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
        'use equal' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    )
  );
  
}