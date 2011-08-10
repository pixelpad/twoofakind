<?php

/**
 * @file
 * Exposing matches to views
 */

/**
 * Implements hook_views_data_alter()
 */
function twoofakind_com_au_views_data_alter(&$data) { 

  // alter the date of birth table field definition
  // modify the filter from the normal numeric to our new version
  $data['field_data_field_date_of_birth']['field_date_of_birth_value']['filter']['handler'] = 'twoofakind_com_au_handler_filter_datetime_age';

}

/**
 * Implements hook_views_data()
 */
function twoofakind_com_au_views_data() { 

  $data = array();
  
  // favourites
  _twoofakind_com_au_views_data_favourites($data);
  
  // featured users
  _twoofakind_com_au_views_data_featured_users($data);
  
  // matches
  _twoofakind_com_au_views_data_matches($data);
  
  // recent views
  _twoofakind_com_au_views_data_recent_views($data);
  
  // winks
  _twoofakind_com_au_views_data_winks($data);
  
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
      'title' => t('Uid of Favourite-ee'),
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
  $data['favourites']['table']['group'] = t('Favourites');
  $data['favourites']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'favourite_uid',
      'table' => 'favourites'
    )
  );
  $data['favourites']['favourite_uid']['relationship'] = array(
    'base' => 'users',
    'field' => 'favourite_uid',
    'left_field' => 'uid',
    'left_table' => 'users',
    'handler' => 'views_handler_relationship',
    'label' => t('Favourite-ee'),
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
  $data['favourites_received']['table']['group'] = t('Favourites received');
  $data['favourites_received']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'table' => 'favourites'
    )
  );
  $data['favourites_received']['uid']['relationship'] = array(
    'base' => 'users',
    'field' => 'uid',
    'left_field' => 'uid',
    'left_table' => 'users',
    'handler' => 'views_handler_relationship',
    'label' => t('Favourite-er'),
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
 * Expose featured users table to views
 *
 * @param $data
 *   data array to be given to views
 * 
 * @see hook_views_data()
 */
function _twoofakind_com_au_views_data_featured_users(&$data) {
  
  // common fields
  $data['featured_users'] = array(
    'table' => array(
      'group' => t('Featured Users'),
      'join' => array(
        'users' => array(
          'left_field' => 'uid',
          'field' => 'featured_user_uid',
          'table' => 'featured_users'
        )
      )
    ),
    'fid' => array(
      'title' => t('Fid'),
      'help' => t('The Featured user ID'),
      'field' => array(
        'handler' => 'views_handler_field_node',
        'click sortable' => TRUE,
      ),
    ),
    'uid' => array(
      'title' => t('Uid of Featurer-er'),
      'help' => t('User id of person marking the other as a featured_user')
    ),
    'featured_user_uid' => array(
      'title' => t('Uid of Featured user'),
      'help' => t('User id of person being marked as featured_user'),
      'relationship' => array(
        'base' => 'users',
        'field' => 'featured_user_uid',
        'left_field' => 'uid',
        'left_table' => 'users',
        'handler' => 'views_handler_relationship',
        'label' => t('Featured user'),
      ),
    ),
    'created' => array(
      'title' => t('Created'),
      'help' => t('The date this Featured user record was created.'),
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
    )
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
  
  // common fields
  $data_common = array(
    'table' => array(),
    'mid' => array(
      'title' => t('Mid'),
      'help' => t('The Match ID'),
      'field' => array(
        'handler' => 'views_handler_field_node',
        'click sortable' => TRUE,
      ),
    ),
    'uid' => array(
      'title' => t('Uid of Match-er'),
      'help' => t('User id of person making the match')
    ),
    'match_uid' => array(
      'title' => t('Uid of Match-ee'),
      'help' => t('User id of person being marked as a match'),
    ),
    'created' => array(
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
      'title' => t('Viewed by Match-er'),
      'help' => t('Has this Match been viewed by the Matcher?'),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
        'label' => t('Viewed by Match-er'),
        'type' => 'yes-no',
        // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
        'use equal' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'viewed_match_uid' => array(
      'title' => t('Viewed by Match-ee'),
      'help' => t('Has this Match been viewed by the Matchee?'),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
        'label' => t('Viewed by Match-ee'),
        'type' => 'yes-no',
        // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
        'use equal' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    )
  );
  
  // matches
  $data['matches'] = $data_common;
  $data['matches']['table']['group'] = t('Matches');
  $data['matches']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'match_uid',
      'table' => 'matches'
    )
  );
  $data['matches']['match_uid']['relationship'] = array(
    'base' => 'users',
    'field' => 'match_uid',
    'left_field' => 'uid',
    'left_table' => 'users',
    'handler' => 'views_handler_relationship',
    'label' => t('Match-ee'),
  );
  $data['matches']['uid_current'] = array(
    'real field' => 'uid',
    'title' => t('Match-er is logged in user'),
    'help' => t('Filter results so the current user is the Match-er'),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
  );
  
  // matches received
  $data['matches_received'] = $data_common;
  $data['matches_received']['table']['group'] = t('Matches received');
  $data['matches_received']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'table' => 'matches'
    )
  );
  $data['matches_received']['uid']['relationship'] = array(
    'base' => 'users',
    'field' => 'uid',
    'left_field' => 'uid',
    'left_table' => 'users',
    'handler' => 'views_handler_relationship',
    'label' => t('Match-er'),
  );
  $data['matches_received']['uid_current'] = array(
    'real field' => 'match_uid',
    'title' => t('Match-ee is logged in user'),
    'help' => t('Filter results so the current user is the Match-ee'),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
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
  
  // common fields
  $data_common = array(
    'table' => array(),
    'vid' => array(
      'title' => t('Vid'),
      'help' => t('The Recent View ID'),
      'field' => array(
        'handler' => 'views_handler_field_node',
        'click sortable' => TRUE,
      ),
    ),
    'uid' => array(
      'title' => t('Uid of View-er'),
      'help' => t('User id of person viewing')
    ),
    'recent_view_uid' => array(
      'title' => t('Uid of View-ee'),
      'help' => t('User id of person being viewed'),
    ),
    'created' => array(
      'title' => t('Created'),
      'help' => t('The date this user was viewed.'),
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
      'title' => t('Noticed by View-ee'),
      'help' => t('The View-ee has noticed they have been viewed'),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
        'label' => t('Noticed by View-ee'),
        'type' => 'yes-no',
        // use boolean_field = 1 instead of boolean_field <> 0 in WHERE statment
        'use equal' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    )
  );
  
  // recent views
  $data['recent_views'] = $data_common;
  $data['recent_views']['table']['group'] = t('Recent views');
  $data['recent_views']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'recent_view_uid',
      'table' => 'recent_views'
    )
  );
  $data['recent_views']['recent_view_uid']['relationship'] = array(
    'base' => 'users',
    'field' => 'recent_view_uid',
    'left_field' => 'uid',
    'left_table' => 'users',
    'handler' => 'views_handler_relationship',
    'label' => t('View-ee'),
  );
  $data['recent_views']['uid_current'] = array(
    'real field' => 'uid',
    'title' => t('View-er is logged in user'),
    'help' => t('Filter results so the current user is the View-er'),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
  );
  
  // recent_views received
  $data['recent_views_received'] = $data_common;
  $data['recent_views_received']['table']['group'] = t('Recent views received');
  $data['recent_views_received']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'table' => 'recent_views'
    )
  );
  $data['recent_views_received']['uid']['relationship'] = array(
    'base' => 'users',
    'field' => 'uid',
    'left_field' => 'uid',
    'left_table' => 'users',
    'handler' => 'views_handler_relationship',
    'label' => t('View-er'),
  );
  $data['recent_views_received']['uid_current'] = array(
    'real field' => 'recent_view_uid',
    'title' => t('View-ee is logged in user'),
    'help' => t('Filter results so the current user is the View-ee'),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
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
  
  // common fields
  $data_common = array(
    'table' => array(),
    'wid' => array(
      'title' => t('Wid'),
      'help' => t('The Wink ID'),
      'field' => array(
        'handler' => 'views_handler_field_node',
        'click sortable' => TRUE,
      ),
    ),
    'uid' => array(
      'title' => t('Uid of Wink-er'),
      'help' => t('User id of person winking')
    ),
    'wink_uid' => array(
      'title' => t('Uid of Wink-ee'),
      'help' => t('User id of person being winked at'),
    ),
    'created' => array(
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
  
  // winks
  $data['winks'] = $data_common;
  $data['winks']['table']['group'] = t('Winks');
  $data['winks']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'wink_uid',
      'table' => 'winks'
    )
  );
  $data['winks']['wink_uid']['relationship'] = array(
    'base' => 'users',
    'field' => 'wink_uid',
    'left_field' => 'uid',
    'left_table' => 'users',
    'handler' => 'views_handler_relationship',
    'label' => t('Wink-ee'),
  );
  $data['winks']['uid_current'] = array(
    'real field' => 'uid',
    'title' => t('Wink-er is logged in user'),
    'help' => t('Filter results so the current user is the Wink-er'),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
  );
  
  // winks received
  $data['winks_received'] = $data_common;
  $data['winks_received']['table']['group'] = t('Winks received');
  $data['winks_received']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'table' => 'winks'
    )
  );
  $data['winks_received']['uid']['relationship'] = array(
    'base' => 'users',
    'field' => 'uid',
    'left_field' => 'uid',
    'left_table' => 'users',
    'handler' => 'views_handler_relationship',
    'label' => t('Wink-er'),
  );
  $data['winks_received']['uid_current'] = array(
    'real field' => 'wink_uid',
    'title' => t('Wink-ee is logged in user'),
    'help' => t('Filter results so the current user is the Wink-ee'),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
    ),
  );
  
}