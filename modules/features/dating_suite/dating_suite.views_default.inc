<?php
/**
 * @file
 * dating_suite.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function dating_suite_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'user_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User Search';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Search';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'sort' => array(
      'bef_format' => 'bef',
      'combine' => 1,
      'reset' => 0,
      'reset_label' => '',
    ),
    'field_sex_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'city' => array(
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
    'field_star_sign_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_personality_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_eye_colour_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_hair_colour_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_height_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_body_type_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_relig_affiliation_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_kosher_value_1' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_smoker_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_drinking_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_have_kids_value' => array(
      'bef_format' => 'bef_ul',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['exposed_block'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No matches were found based on your criteria.</p>
';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'User joined';
  $handler->display->display_options['sorts']['created']['granularity'] = 'day';
  /* Sort criterion: Fields: Date of Birth (field_dob) */
  $handler->display->display_options['sorts']['field_dob_value']['id'] = 'field_dob_value';
  $handler->display->display_options['sorts']['field_dob_value']['table'] = 'field_data_field_dob';
  $handler->display->display_options['sorts']['field_dob_value']['field'] = 'field_dob_value';
  $handler->display->display_options['sorts']['field_dob_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_dob_value']['expose']['label'] = 'Date of Birth';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Location: City */
  $handler->display->display_options['filters']['city']['id'] = 'city';
  $handler->display->display_options['filters']['city']['table'] = 'location';
  $handler->display->display_options['filters']['city']['field'] = 'city';
  $handler->display->display_options['filters']['city']['operator'] = 'word';
  $handler->display->display_options['filters']['city']['group'] = 0;
  $handler->display->display_options['filters']['city']['exposed'] = TRUE;
  $handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
  $handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
  $handler->display->display_options['filters']['city']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['city']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['city']['expose']['multiple'] = FALSE;
  /* Filter criterion: Fields: Sex (field_sex) */
  $handler->display->display_options['filters']['field_sex_value']['id'] = 'field_sex_value';
  $handler->display->display_options['filters']['field_sex_value']['table'] = 'field_data_field_sex';
  $handler->display->display_options['filters']['field_sex_value']['field'] = 'field_sex_value';
  $handler->display->display_options['filters']['field_sex_value']['group'] = 0;
  $handler->display->display_options['filters']['field_sex_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sex_value']['expose']['operator_id'] = 'field_sex_value_op';
  $handler->display->display_options['filters']['field_sex_value']['expose']['label'] = 'Sex';
  $handler->display->display_options['filters']['field_sex_value']['expose']['operator'] = 'field_sex_value_op';
  $handler->display->display_options['filters']['field_sex_value']['expose']['identifier'] = 'field_sex_value';
  $handler->display->display_options['filters']['field_sex_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_sex_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_sex_value']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Star sign (field_star_sign) */
  $handler->display->display_options['filters']['field_star_sign_value']['id'] = 'field_star_sign_value';
  $handler->display->display_options['filters']['field_star_sign_value']['table'] = 'field_data_field_star_sign';
  $handler->display->display_options['filters']['field_star_sign_value']['field'] = 'field_star_sign_value';
  $handler->display->display_options['filters']['field_star_sign_value']['group'] = 0;
  $handler->display->display_options['filters']['field_star_sign_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_star_sign_value']['expose']['operator_id'] = 'field_star_sign_value_op';
  $handler->display->display_options['filters']['field_star_sign_value']['expose']['label'] = 'Star sign';
  $handler->display->display_options['filters']['field_star_sign_value']['expose']['operator'] = 'field_star_sign_value_op';
  $handler->display->display_options['filters']['field_star_sign_value']['expose']['identifier'] = 'field_star_sign_value';
  $handler->display->display_options['filters']['field_star_sign_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_star_sign_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_star_sign_value']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Personality (field_personality) */
  $handler->display->display_options['filters']['field_personality_value']['id'] = 'field_personality_value';
  $handler->display->display_options['filters']['field_personality_value']['table'] = 'field_data_field_personality';
  $handler->display->display_options['filters']['field_personality_value']['field'] = 'field_personality_value';
  $handler->display->display_options['filters']['field_personality_value']['group'] = 0;
  $handler->display->display_options['filters']['field_personality_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_personality_value']['expose']['operator_id'] = 'field_personality_value_op';
  $handler->display->display_options['filters']['field_personality_value']['expose']['label'] = 'Personality';
  $handler->display->display_options['filters']['field_personality_value']['expose']['operator'] = 'field_personality_value_op';
  $handler->display->display_options['filters']['field_personality_value']['expose']['identifier'] = 'field_personality_value';
  $handler->display->display_options['filters']['field_personality_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_personality_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_personality_value']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Eye colour (field_eye_colour) */
  $handler->display->display_options['filters']['field_eye_colour_value']['id'] = 'field_eye_colour_value';
  $handler->display->display_options['filters']['field_eye_colour_value']['table'] = 'field_data_field_eye_colour';
  $handler->display->display_options['filters']['field_eye_colour_value']['field'] = 'field_eye_colour_value';
  $handler->display->display_options['filters']['field_eye_colour_value']['group'] = 0;
  $handler->display->display_options['filters']['field_eye_colour_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_eye_colour_value']['expose']['operator_id'] = 'field_eye_colour_value_op';
  $handler->display->display_options['filters']['field_eye_colour_value']['expose']['label'] = 'Eye colour';
  $handler->display->display_options['filters']['field_eye_colour_value']['expose']['operator'] = 'field_eye_colour_value_op';
  $handler->display->display_options['filters']['field_eye_colour_value']['expose']['identifier'] = 'field_eye_colour_value';
  $handler->display->display_options['filters']['field_eye_colour_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_eye_colour_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_eye_colour_value']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Hair colour (field_hair_colour) */
  $handler->display->display_options['filters']['field_hair_colour_value']['id'] = 'field_hair_colour_value';
  $handler->display->display_options['filters']['field_hair_colour_value']['table'] = 'field_data_field_hair_colour';
  $handler->display->display_options['filters']['field_hair_colour_value']['field'] = 'field_hair_colour_value';
  $handler->display->display_options['filters']['field_hair_colour_value']['group'] = 0;
  $handler->display->display_options['filters']['field_hair_colour_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hair_colour_value']['expose']['operator_id'] = 'field_hair_colour_value_op';
  $handler->display->display_options['filters']['field_hair_colour_value']['expose']['label'] = 'Hair colour';
  $handler->display->display_options['filters']['field_hair_colour_value']['expose']['operator'] = 'field_hair_colour_value_op';
  $handler->display->display_options['filters']['field_hair_colour_value']['expose']['identifier'] = 'field_hair_colour_value';
  $handler->display->display_options['filters']['field_hair_colour_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_hair_colour_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_hair_colour_value']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Height (field_height) */
  $handler->display->display_options['filters']['field_height_value']['id'] = 'field_height_value';
  $handler->display->display_options['filters']['field_height_value']['table'] = 'field_data_field_height';
  $handler->display->display_options['filters']['field_height_value']['field'] = 'field_height_value';
  $handler->display->display_options['filters']['field_height_value']['group'] = 0;
  $handler->display->display_options['filters']['field_height_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_height_value']['expose']['operator_id'] = 'field_height_value_op';
  $handler->display->display_options['filters']['field_height_value']['expose']['label'] = 'Height';
  $handler->display->display_options['filters']['field_height_value']['expose']['operator'] = 'field_height_value_op';
  $handler->display->display_options['filters']['field_height_value']['expose']['identifier'] = 'field_height_value';
  $handler->display->display_options['filters']['field_height_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_height_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_height_value']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Body type (field_body_type) */
  $handler->display->display_options['filters']['field_body_type_value']['id'] = 'field_body_type_value';
  $handler->display->display_options['filters']['field_body_type_value']['table'] = 'field_data_field_body_type';
  $handler->display->display_options['filters']['field_body_type_value']['field'] = 'field_body_type_value';
  $handler->display->display_options['filters']['field_body_type_value']['group'] = 0;
  $handler->display->display_options['filters']['field_body_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_body_type_value']['expose']['operator_id'] = 'field_body_type_value_op';
  $handler->display->display_options['filters']['field_body_type_value']['expose']['label'] = 'Body type';
  $handler->display->display_options['filters']['field_body_type_value']['expose']['operator'] = 'field_body_type_value_op';
  $handler->display->display_options['filters']['field_body_type_value']['expose']['identifier'] = 'field_body_type_value';
  $handler->display->display_options['filters']['field_body_type_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_body_type_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_body_type_value']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Religious affiliation (field_relig_affiliation) */
  $handler->display->display_options['filters']['field_relig_affiliation_value']['id'] = 'field_relig_affiliation_value';
  $handler->display->display_options['filters']['field_relig_affiliation_value']['table'] = 'field_data_field_relig_affiliation';
  $handler->display->display_options['filters']['field_relig_affiliation_value']['field'] = 'field_relig_affiliation_value';
  $handler->display->display_options['filters']['field_relig_affiliation_value']['group'] = 0;
  $handler->display->display_options['filters']['field_relig_affiliation_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['operator_id'] = 'field_relig_affiliation_value_op';
  $handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['label'] = 'Religion';
  $handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['operator'] = 'field_relig_affiliation_value_op';
  $handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['identifier'] = 'field_relig_affiliation_value';
  $handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Do you keep kosher? (field_kosher) */
  $handler->display->display_options['filters']['field_kosher_value_1']['id'] = 'field_kosher_value_1';
  $handler->display->display_options['filters']['field_kosher_value_1']['table'] = 'field_data_field_kosher';
  $handler->display->display_options['filters']['field_kosher_value_1']['field'] = 'field_kosher_value';
  $handler->display->display_options['filters']['field_kosher_value_1']['group'] = 0;
  $handler->display->display_options['filters']['field_kosher_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_kosher_value_1']['expose']['operator_id'] = 'field_kosher_value_1_op';
  $handler->display->display_options['filters']['field_kosher_value_1']['expose']['label'] = 'Kosher';
  $handler->display->display_options['filters']['field_kosher_value_1']['expose']['operator'] = 'field_kosher_value_1_op';
  $handler->display->display_options['filters']['field_kosher_value_1']['expose']['identifier'] = 'field_kosher_value_1';
  $handler->display->display_options['filters']['field_kosher_value_1']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_kosher_value_1']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_kosher_value_1']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Are you a smoker? (field_smoker) */
  $handler->display->display_options['filters']['field_smoker_value']['id'] = 'field_smoker_value';
  $handler->display->display_options['filters']['field_smoker_value']['table'] = 'field_data_field_smoker';
  $handler->display->display_options['filters']['field_smoker_value']['field'] = 'field_smoker_value';
  $handler->display->display_options['filters']['field_smoker_value']['group'] = 0;
  $handler->display->display_options['filters']['field_smoker_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_smoker_value']['expose']['operator_id'] = 'field_smoker_value_op';
  $handler->display->display_options['filters']['field_smoker_value']['expose']['label'] = 'Smoking';
  $handler->display->display_options['filters']['field_smoker_value']['expose']['operator'] = 'field_smoker_value_op';
  $handler->display->display_options['filters']['field_smoker_value']['expose']['identifier'] = 'field_smoker_value';
  $handler->display->display_options['filters']['field_smoker_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_smoker_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_smoker_value']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Drinking habits (field_drinking) */
  $handler->display->display_options['filters']['field_drinking_value']['id'] = 'field_drinking_value';
  $handler->display->display_options['filters']['field_drinking_value']['table'] = 'field_data_field_drinking';
  $handler->display->display_options['filters']['field_drinking_value']['field'] = 'field_drinking_value';
  $handler->display->display_options['filters']['field_drinking_value']['group'] = 0;
  $handler->display->display_options['filters']['field_drinking_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_drinking_value']['expose']['operator_id'] = 'field_drinking_value_op';
  $handler->display->display_options['filters']['field_drinking_value']['expose']['label'] = 'Drinking';
  $handler->display->display_options['filters']['field_drinking_value']['expose']['operator'] = 'field_drinking_value_op';
  $handler->display->display_options['filters']['field_drinking_value']['expose']['identifier'] = 'field_drinking_value';
  $handler->display->display_options['filters']['field_drinking_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_drinking_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_drinking_value']['expose']['reduce'] = 0;
  /* Filter criterion: Fields: Do you have kids (field_have_kids) */
  $handler->display->display_options['filters']['field_have_kids_value']['id'] = 'field_have_kids_value';
  $handler->display->display_options['filters']['field_have_kids_value']['table'] = 'field_data_field_have_kids';
  $handler->display->display_options['filters']['field_have_kids_value']['field'] = 'field_have_kids_value';
  $handler->display->display_options['filters']['field_have_kids_value']['group'] = 0;
  $handler->display->display_options['filters']['field_have_kids_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_have_kids_value']['expose']['operator_id'] = 'field_have_kids_value_op';
  $handler->display->display_options['filters']['field_have_kids_value']['expose']['label'] = 'Kids';
  $handler->display->display_options['filters']['field_have_kids_value']['expose']['operator'] = 'field_have_kids_value_op';
  $handler->display->display_options['filters']['field_have_kids_value']['expose']['identifier'] = 'field_have_kids_value';
  $handler->display->display_options['filters']['field_have_kids_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_have_kids_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_have_kids_value']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_user_search');
  $handler->display->display_options['path'] = 'user-search';
  $translatables['user_search'] = array(
    t('Master'),
    t('Matches'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('<p>No matches were found based on your criteria.</p>
'),
    t('User joined'),
    t('Date of Birth'),
    t('City'),
    t('Sex'),
    t('Star sign'),
    t('Personality'),
    t('Eye colour'),
    t('Hair colour'),
    t('Height'),
    t('Body type'),
    t('Religion'),
    t('Kosher'),
    t('Smoking'),
    t('Drinking'),
    t('Kids'),
    t('Page'),
  );
  $export['matches'] = $view;

  $view = new view;
  $view->name = 'user_favourites';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User favourites';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My favourites';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Flags: favourite */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'favourite';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Sort criterion: Flags: Flagged time */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'flag_content';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['sorts']['timestamp']['granularity'] = 'minute';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'profile/favourites';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'favourites_block');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'menu';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['block_description'] = 'My Favourites';
  $translatables['user_favourites'] = array(
    t('Master'),
    t('My favourites'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('flag'),
    t('Page'),
    t('Block'),
    t('My Favourites'),
  );
  $export['user_favourites'] = $view;

  return $export;
}
