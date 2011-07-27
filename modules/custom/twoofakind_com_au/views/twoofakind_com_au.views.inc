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
      'title' => t('Uid of Viewer'),
      'help' => t('User id of person viewing')
    ),
    'recent_view_uid' => array(
      'title' => t('User id of View-ee'),
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
  $data['recent_views']['table']['group'] = t('View-er');
  $data['recent_views']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'recent_view_uid',
      'table' => 'recent_views'
    )
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
  $data['recent_views_received']['table']['group'] = t('View-ee');
  $data['recent_views_received']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'table' => 'recent_views'
    )
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
      'title' => t('Uid of wink-er'),
      'help' => t('User id of person winking')
    ),
    'wink_uid' => array(
      'title' => t('User id of Wink-ee'),
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
  $data['winks']['table']['group'] = t('Wink-er');
  $data['winks']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'wink_uid',
      'table' => 'winks'
    )
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
  $data['winks_received']['table']['group'] = t('Wink-ee');
  $data['winks_received']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
      'table' => 'winks'
    )
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