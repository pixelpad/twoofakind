<?php

/**
 * @file
 * User search view
 */

/**
 * @see hook_views_default_views()
 */
function _twoofakind_com_au_views_default_views_user_search() {

$view = new view;
$view->name = 'user_search';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'User Search';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Search for matches';
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'time_per_user';
$handler->display->display_options['cache']['results_lifespan'] = '21600';
$handler->display->display_options['cache']['output_lifespan'] = '21600';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
$handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
$handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
$handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'sort' => array(
    'bef_format' => 'default',
    'combine' => 0,
    'reset' => 0,
    'reset_label' => '',
  ),
  'name' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
  ),
  'field_date_of_birth_value' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
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
  'picture' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => 0,
      'bef_collapsible' => 0,
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
  'field_headline_value' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
  ),
  'field_self_summary_value' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
  ),
  'field_friend_summary_value' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
  ),
  'field_passionate_about_value' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
  ),
);
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'ds';
$handler->display->display_options['row_options']['view_mode'] = 'user_list';
$handler->display->display_options['row_options']['alternating'] = 0;
$handler->display->display_options['row_options']['grouping'] = 0;
$handler->display->display_options['row_options']['advanced'] = 0;
$handler->display->display_options['exposed_block'] = TRUE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = FALSE;
$handler->display->display_options['empty']['area']['content'] = '<h3 class="search-no-results">No matches were found for <strong>those particular search criteria</strong></h3>
<p><a href="http://twoofakind.com.au/user-search" title="Twoofakind.com.au - find your Jewish pair">Twoofakind.com.au</a> uses your <a href="/user/edit/profile" title="Edit your profile">profile</a> and <a href="/user/edit/match" title="Edit your match criteria">match</a> information to automatically filter the <a href="/user-search" title="Search for your Jewish pair">search</a> for you. This may sometimes result in less search results than you expect. That\'s OK, you can :</p>
<ul>
<li><a href="/clear-search" title="Clear your search criteria NOW!" class="clear-action">Clear your search criteria</a> and browse through everybody\'s profile</li>
<li><a href="/user/edit/match" title="Edit your match criteria NOW!">Edit your match criteria</a> and open up your search a little</li>
</ul>
<h3><a href="/clear-search" title="Clear your search criteria NOW!" class="clear-action">Clear your search criteria</a> and browse all of our users!</h3>';
$handler->display->display_options['empty']['area']['format'] = 'html_full';
$handler->display->display_options['empty']['area']['tokenize'] = 0;
/* Field: User: Uid */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'users';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
$handler->display->display_options['fields']['uid']['label'] = '';
$handler->display->display_options['fields']['uid']['exclude'] = TRUE;
$handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['uid']['alter']['external'] = 0;
$handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
$handler->display->display_options['fields']['uid']['alter']['html'] = 0;
$handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
$handler->display->display_options['fields']['uid']['hide_empty'] = 0;
$handler->display->display_options['fields']['uid']['empty_zero'] = 0;
$handler->display->display_options['fields']['uid']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['uid']['link_to_user'] = 0;
/* Field: User: Picture */
$handler->display->display_options['fields']['picture']['id'] = 'picture';
$handler->display->display_options['fields']['picture']['table'] = 'users';
$handler->display->display_options['fields']['picture']['field'] = 'picture';
$handler->display->display_options['fields']['picture']['label'] = '';
$handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['picture']['alter']['make_link'] = 1;
$handler->display->display_options['fields']['picture']['alter']['path'] = 'user/[uid]';
$handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['picture']['alter']['external'] = 0;
$handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['picture']['alter']['alt'] = 'Find out more about this user';
$handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
$handler->display->display_options['fields']['picture']['alter']['html'] = 0;
$handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
$handler->display->display_options['fields']['picture']['hide_empty'] = 0;
$handler->display->display_options['fields']['picture']['empty_zero'] = 0;
$handler->display->display_options['fields']['picture']['hide_alter_empty'] = 0;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name']['alter']['external'] = 0;
$handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
$handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim'] = 0;
$handler->display->display_options['fields']['name']['alter']['html'] = 0;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
$handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['name']['link_to_user'] = 1;
$handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
/* Field: User: My tagline */
$handler->display->display_options['fields']['field_headline']['id'] = 'field_headline';
$handler->display->display_options['fields']['field_headline']['table'] = 'field_data_field_headline';
$handler->display->display_options['fields']['field_headline']['field'] = 'field_headline';
$handler->display->display_options['fields']['field_headline']['label'] = '';
$handler->display->display_options['fields']['field_headline']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_headline']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_headline']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_headline']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_headline']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_headline']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_headline']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_headline']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_headline']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_headline']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_headline']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_headline']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_headline']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_headline']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_headline']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_headline']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_headline']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_headline']['field_api_classes'] = 0;
/* Field: User: Sex */
$handler->display->display_options['fields']['field_sex']['id'] = 'field_sex';
$handler->display->display_options['fields']['field_sex']['table'] = 'field_data_field_sex';
$handler->display->display_options['fields']['field_sex']['field'] = 'field_sex';
$handler->display->display_options['fields']['field_sex']['label'] = '';
$handler->display->display_options['fields']['field_sex']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_sex']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_sex']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_sex']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_sex']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_sex']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_sex']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_sex']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_sex']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_sex']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_sex']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_sex']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_sex']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_sex']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_sex']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_sex']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_sex']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_sex']['field_api_classes'] = 0;
/* Field: User: Suburb */
$handler->display->display_options['fields']['field_match_user_location']['id'] = 'field_match_user_location';
$handler->display->display_options['fields']['field_match_user_location']['table'] = 'field_data_field_match_user_location';
$handler->display->display_options['fields']['field_match_user_location']['field'] = 'field_match_user_location';
$handler->display->display_options['fields']['field_match_user_location']['label'] = '';
$handler->display->display_options['fields']['field_match_user_location']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_match_user_location']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_match_user_location']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_match_user_location']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_match_user_location']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_match_user_location']['field_api_classes'] = 0;
/* Field: User: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'users';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Registered for';
$handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['created']['alter']['external'] = 0;
$handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['created']['alter']['trim'] = 0;
$handler->display->display_options['fields']['created']['alter']['html'] = 0;
$handler->display->display_options['fields']['created']['element_label_colon'] = 0;
$handler->display->display_options['fields']['created']['element_default_classes'] = 1;
$handler->display->display_options['fields']['created']['hide_empty'] = 0;
$handler->display->display_options['fields']['created']['empty_zero'] = 0;
$handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['created']['date_format'] = 'raw time ago';
/* Field: User: Last login */
$handler->display->display_options['fields']['login']['id'] = 'login';
$handler->display->display_options['fields']['login']['table'] = 'users';
$handler->display->display_options['fields']['login']['field'] = 'login';
$handler->display->display_options['fields']['login']['label'] = 'Last logged in';
$handler->display->display_options['fields']['login']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['login']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['login']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['login']['alter']['external'] = 0;
$handler->display->display_options['fields']['login']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['login']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['login']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['login']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['login']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['login']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['login']['alter']['trim'] = 0;
$handler->display->display_options['fields']['login']['alter']['html'] = 0;
$handler->display->display_options['fields']['login']['element_label_colon'] = 0;
$handler->display->display_options['fields']['login']['element_default_classes'] = 1;
$handler->display->display_options['fields']['login']['hide_empty'] = 0;
$handler->display->display_options['fields']['login']['empty_zero'] = 0;
$handler->display->display_options['fields']['login']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['login']['date_format'] = 'time ago';
/* Field: Privatemsg: Send Privatemsg link */
$handler->display->display_options['fields']['privatemsg_link']['id'] = 'privatemsg_link';
$handler->display->display_options['fields']['privatemsg_link']['table'] = 'users';
$handler->display->display_options['fields']['privatemsg_link']['field'] = 'privatemsg_link';
$handler->display->display_options['fields']['privatemsg_link']['label'] = '';
$handler->display->display_options['fields']['privatemsg_link']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['privatemsg_link']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['privatemsg_link']['return'] = 1;
/* Sort criterion: User: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'users';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['sorts']['created']['exposed'] = TRUE;
$handler->display->display_options['sorts']['created']['expose']['label'] = 'Date registered';
/* Sort criterion: User: Last login */
$handler->display->display_options['sorts']['login']['id'] = 'login';
$handler->display->display_options['sorts']['login']['table'] = 'users';
$handler->display->display_options['sorts']['login']['field'] = 'login';
$handler->display->display_options['sorts']['login']['order'] = 'DESC';
$handler->display->display_options['sorts']['login']['exposed'] = TRUE;
$handler->display->display_options['sorts']['login']['expose']['label'] = 'Last login';
/* Sort criterion: User: Name */
$handler->display->display_options['sorts']['name']['id'] = 'name';
$handler->display->display_options['sorts']['name']['table'] = 'users';
$handler->display->display_options['sorts']['name']['field'] = 'name';
$handler->display->display_options['sorts']['name']['exposed'] = TRUE;
$handler->display->display_options['sorts']['name']['expose']['label'] = 'Username';
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: User: Name (raw) */
$handler->display->display_options['filters']['name']['id'] = 'name';
$handler->display->display_options['filters']['name']['table'] = 'users';
$handler->display->display_options['filters']['name']['field'] = 'name';
$handler->display->display_options['filters']['name']['operator'] = 'word';
$handler->display->display_options['filters']['name']['group'] = 0;
$handler->display->display_options['filters']['name']['exposed'] = TRUE;
$handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
$handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['identifier'] = 'name_search';
$handler->display->display_options['filters']['name']['expose']['required'] = 0;
$handler->display->display_options['filters']['name']['expose']['remember'] = 1;
$handler->display->display_options['filters']['name']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Date of birth (field_date_of_birth) */
$handler->display->display_options['filters']['field_date_of_birth_value']['id'] = 'field_date_of_birth_value';
$handler->display->display_options['filters']['field_date_of_birth_value']['table'] = 'field_data_field_date_of_birth';
$handler->display->display_options['filters']['field_date_of_birth_value']['field'] = 'field_date_of_birth_value';
$handler->display->display_options['filters']['field_date_of_birth_value']['operator'] = 'between';
$handler->display->display_options['filters']['field_date_of_birth_value']['group'] = 0;
$handler->display->display_options['filters']['field_date_of_birth_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['operator_id'] = 'field_date_of_birth_value_op';
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['label'] = 'Aged between';
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['operator'] = 'field_date_of_birth_value_op';
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['identifier'] = 'field_date_of_birth_value';
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['remember'] = 1;
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Sex (field_sex) */
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
/* Filter criterion: Location: City */
$handler->display->display_options['filters']['city']['id'] = 'city';
$handler->display->display_options['filters']['city']['table'] = 'location';
$handler->display->display_options['filters']['city']['field'] = 'city';
$handler->display->display_options['filters']['city']['operator'] = 'word';
$handler->display->display_options['filters']['city']['group'] = 0;
$handler->display->display_options['filters']['city']['exposed'] = TRUE;
$handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
$handler->display->display_options['filters']['city']['expose']['label'] = 'Suburb';
$handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
$handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
$handler->display->display_options['filters']['city']['expose']['required'] = 0;
$handler->display->display_options['filters']['city']['expose']['remember'] = 1;
$handler->display->display_options['filters']['city']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Picture */
$handler->display->display_options['filters']['picture']['id'] = 'picture';
$handler->display->display_options['filters']['picture']['table'] = 'users';
$handler->display->display_options['filters']['picture']['field'] = 'picture';
$handler->display->display_options['filters']['picture']['value'] = 'All';
$handler->display->display_options['filters']['picture']['group'] = 0;
$handler->display->display_options['filters']['picture']['exposed'] = TRUE;
$handler->display->display_options['filters']['picture']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['picture']['expose']['label'] = 'Has picture';
$handler->display->display_options['filters']['picture']['expose']['use_operator'] = FALSE;
$handler->display->display_options['filters']['picture']['expose']['operator'] = 'picture_op';
$handler->display->display_options['filters']['picture']['expose']['identifier'] = 'picture';
$handler->display->display_options['filters']['picture']['expose']['remember'] = 1;
$handler->display->display_options['filters']['picture']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Star sign (field_star_sign) */
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
/* Filter criterion: User: Personality (field_personality) */
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
/* Filter criterion: User: Eye colour (field_eye_colour) */
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
/* Filter criterion: User: Hair colour (field_hair_colour) */
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
/* Filter criterion: User: Height (field_height) */
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
/* Filter criterion: User: Body type (field_body_type) */
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
/* Filter criterion: User: Religious affiliation (field_relig_affiliation) */
$handler->display->display_options['filters']['field_relig_affiliation_value']['id'] = 'field_relig_affiliation_value';
$handler->display->display_options['filters']['field_relig_affiliation_value']['table'] = 'field_data_field_relig_affiliation';
$handler->display->display_options['filters']['field_relig_affiliation_value']['field'] = 'field_relig_affiliation_value';
$handler->display->display_options['filters']['field_relig_affiliation_value']['group'] = 0;
$handler->display->display_options['filters']['field_relig_affiliation_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['operator_id'] = 'field_relig_affiliation_value_op';
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['label'] = 'Religious affiliation';
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['operator'] = 'field_relig_affiliation_value_op';
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['identifier'] = 'field_relig_affiliation_value';
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['remember'] = 1;
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['reduce'] = 0;
/* Filter criterion: User: Do you keep kosher? (field_kosher) */
$handler->display->display_options['filters']['field_kosher_value_1']['id'] = 'field_kosher_value_1';
$handler->display->display_options['filters']['field_kosher_value_1']['table'] = 'field_data_field_kosher';
$handler->display->display_options['filters']['field_kosher_value_1']['field'] = 'field_kosher_value';
$handler->display->display_options['filters']['field_kosher_value_1']['group'] = 0;
$handler->display->display_options['filters']['field_kosher_value_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['operator_id'] = 'field_kosher_value_1_op';
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['label'] = 'Kosher';
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['operator'] = 'field_kosher_value_1_op';
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['identifier'] = 'field_kosher_value';
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['remember'] = 1;
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['reduce'] = 0;
/* Filter criterion: User: Are you a smoker? (field_smoker) */
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
/* Filter criterion: User: Drinking habits (field_drinking) */
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
/* Filter criterion: User: Do you have kids (field_have_kids) */
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
/* Filter criterion: User: My tagline (field_headline) */
$handler->display->display_options['filters']['field_headline_value']['id'] = 'field_headline_value';
$handler->display->display_options['filters']['field_headline_value']['table'] = 'field_data_field_headline';
$handler->display->display_options['filters']['field_headline_value']['field'] = 'field_headline_value';
$handler->display->display_options['filters']['field_headline_value']['operator'] = 'word';
$handler->display->display_options['filters']['field_headline_value']['group'] = 0;
$handler->display->display_options['filters']['field_headline_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_headline_value']['expose']['operator_id'] = 'field_headline_value_op';
$handler->display->display_options['filters']['field_headline_value']['expose']['label'] = 'Their tagline';
$handler->display->display_options['filters']['field_headline_value']['expose']['operator'] = 'field_headline_value_op';
$handler->display->display_options['filters']['field_headline_value']['expose']['identifier'] = 'field_headline_value';
$handler->display->display_options['filters']['field_headline_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_headline_value']['expose']['remember'] = 1;
$handler->display->display_options['filters']['field_headline_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: My self-summary (field_self_summary) */
$handler->display->display_options['filters']['field_self_summary_value']['id'] = 'field_self_summary_value';
$handler->display->display_options['filters']['field_self_summary_value']['table'] = 'field_data_field_self_summary';
$handler->display->display_options['filters']['field_self_summary_value']['field'] = 'field_self_summary_value';
$handler->display->display_options['filters']['field_self_summary_value']['operator'] = 'word';
$handler->display->display_options['filters']['field_self_summary_value']['group'] = 0;
$handler->display->display_options['filters']['field_self_summary_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_self_summary_value']['expose']['operator_id'] = 'field_self_summary_value_op';
$handler->display->display_options['filters']['field_self_summary_value']['expose']['label'] = 'Their self summary';
$handler->display->display_options['filters']['field_self_summary_value']['expose']['operator'] = 'field_self_summary_value_op';
$handler->display->display_options['filters']['field_self_summary_value']['expose']['identifier'] = 'field_self_summary_value';
$handler->display->display_options['filters']['field_self_summary_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_self_summary_value']['expose']['remember'] = 1;
$handler->display->display_options['filters']['field_self_summary_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: My friends describe me as (field_friend_summary) */
$handler->display->display_options['filters']['field_friend_summary_value']['id'] = 'field_friend_summary_value';
$handler->display->display_options['filters']['field_friend_summary_value']['table'] = 'field_data_field_friend_summary';
$handler->display->display_options['filters']['field_friend_summary_value']['field'] = 'field_friend_summary_value';
$handler->display->display_options['filters']['field_friend_summary_value']['operator'] = 'word';
$handler->display->display_options['filters']['field_friend_summary_value']['group'] = 0;
$handler->display->display_options['filters']['field_friend_summary_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['operator_id'] = 'field_friend_summary_value_op';
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['label'] = 'Friends describe them as';
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['operator'] = 'field_friend_summary_value_op';
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['identifier'] = 'field_friend_summary_value';
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['remember'] = 1;
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: I am passionate about (field_passionate_about) */
$handler->display->display_options['filters']['field_passionate_about_value']['id'] = 'field_passionate_about_value';
$handler->display->display_options['filters']['field_passionate_about_value']['table'] = 'field_data_field_passionate_about';
$handler->display->display_options['filters']['field_passionate_about_value']['field'] = 'field_passionate_about_value';
$handler->display->display_options['filters']['field_passionate_about_value']['operator'] = 'word';
$handler->display->display_options['filters']['field_passionate_about_value']['group'] = 0;
$handler->display->display_options['filters']['field_passionate_about_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['operator_id'] = 'field_passionate_about_value_op';
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['label'] = 'Is passionate about';
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['operator'] = 'field_passionate_about_value_op';
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['identifier'] = 'field_passionate_about_value';
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['remember'] = 1;
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Roles */
$handler->display->display_options['filters']['rid']['id'] = 'rid';
$handler->display->display_options['filters']['rid']['table'] = 'users_roles';
$handler->display->display_options['filters']['rid']['field'] = 'rid';
$handler->display->display_options['filters']['rid']['operator'] = 'not';
$handler->display->display_options['filters']['rid']['value'] = array(
  3 => '3',
  4 => '4',
);
$handler->display->display_options['filters']['rid']['reduce_duplicates'] = 1;

/* Display: User Search Page */
$handler = $view->new_display('page', 'User Search Page', 'page_user_search');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'views-page-users';
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['path'] = 'user-search';

/* Display: Matches cron */
$handler = $view->new_display('page', 'Matches cron', 'matches_cron');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'views-page-users';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'uid' => 'uid',
  'picture' => 'picture',
  'name' => 'name',
  'field_headline' => 'field_headline',
  'field_sex' => 'field_sex',
  'field_match_user_location' => 'field_match_user_location',
  'created' => 'created',
  'login' => 'login',
  'privatemsg_link' => 'privatemsg_link',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'uid' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'picture' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'field_headline' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'field_sex' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'field_match_user_location' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'created' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'login' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'privatemsg_link' => array(
    'align' => '',
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 0;
$handler->display->display_options['style_options']['empty_table'] = 0;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['exposed_block'] = TRUE;
$handler->display->display_options['defaults']['empty'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: User: Uid */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'users';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
$handler->display->display_options['fields']['uid']['label'] = 'ID';
$handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['uid']['alter']['external'] = 0;
$handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
$handler->display->display_options['fields']['uid']['alter']['html'] = 0;
$handler->display->display_options['fields']['uid']['element_label_colon'] = 0;
$handler->display->display_options['fields']['uid']['element_default_classes'] = 1;
$handler->display->display_options['fields']['uid']['hide_empty'] = 0;
$handler->display->display_options['fields']['uid']['empty_zero'] = 0;
$handler->display->display_options['fields']['uid']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['uid']['link_to_user'] = 0;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: User: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'users';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['sorts']['created']['expose']['label'] = 'Date registered';
$handler->display->display_options['sorts']['created']['granularity'] = 'hour';
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: User: Name (raw) */
$handler->display->display_options['filters']['name']['id'] = 'name';
$handler->display->display_options['filters']['name']['table'] = 'users';
$handler->display->display_options['filters']['name']['field'] = 'name';
$handler->display->display_options['filters']['name']['operator'] = 'word';
$handler->display->display_options['filters']['name']['group'] = 0;
$handler->display->display_options['filters']['name']['exposed'] = TRUE;
$handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['label'] = 'Username';
$handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
$handler->display->display_options['filters']['name']['expose']['identifier'] = 'name_search';
$handler->display->display_options['filters']['name']['expose']['required'] = 0;
$handler->display->display_options['filters']['name']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Date of birth (field_date_of_birth) */
$handler->display->display_options['filters']['field_date_of_birth_value']['id'] = 'field_date_of_birth_value';
$handler->display->display_options['filters']['field_date_of_birth_value']['table'] = 'field_data_field_date_of_birth';
$handler->display->display_options['filters']['field_date_of_birth_value']['field'] = 'field_date_of_birth_value';
$handler->display->display_options['filters']['field_date_of_birth_value']['operator'] = 'between';
$handler->display->display_options['filters']['field_date_of_birth_value']['group'] = 0;
$handler->display->display_options['filters']['field_date_of_birth_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['operator_id'] = 'field_date_of_birth_value_op';
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['label'] = 'Aged between';
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['operator'] = 'field_date_of_birth_value_op';
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['identifier'] = 'field_date_of_birth_value';
$handler->display->display_options['filters']['field_date_of_birth_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Sex (field_sex) */
$handler->display->display_options['filters']['field_sex_value']['id'] = 'field_sex_value';
$handler->display->display_options['filters']['field_sex_value']['table'] = 'field_data_field_sex';
$handler->display->display_options['filters']['field_sex_value']['field'] = 'field_sex_value';
$handler->display->display_options['filters']['field_sex_value']['group'] = 0;
$handler->display->display_options['filters']['field_sex_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_sex_value']['expose']['operator_id'] = 'field_sex_value_op';
$handler->display->display_options['filters']['field_sex_value']['expose']['label'] = 'Sex';
$handler->display->display_options['filters']['field_sex_value']['expose']['operator'] = 'field_sex_value_op';
$handler->display->display_options['filters']['field_sex_value']['expose']['identifier'] = 'field_sex_value';
$handler->display->display_options['filters']['field_sex_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_sex_value']['expose']['reduce'] = 0;
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
$handler->display->display_options['filters']['city']['expose']['required'] = 0;
$handler->display->display_options['filters']['city']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Picture */
$handler->display->display_options['filters']['picture']['id'] = 'picture';
$handler->display->display_options['filters']['picture']['table'] = 'users';
$handler->display->display_options['filters']['picture']['field'] = 'picture';
$handler->display->display_options['filters']['picture']['group'] = 0;
$handler->display->display_options['filters']['picture']['exposed'] = TRUE;
$handler->display->display_options['filters']['picture']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['picture']['expose']['label'] = 'Has picture';
$handler->display->display_options['filters']['picture']['expose']['use_operator'] = FALSE;
$handler->display->display_options['filters']['picture']['expose']['operator'] = 'picture_op';
$handler->display->display_options['filters']['picture']['expose']['identifier'] = 'picture';
$handler->display->display_options['filters']['picture']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Star sign (field_star_sign) */
$handler->display->display_options['filters']['field_star_sign_value']['id'] = 'field_star_sign_value';
$handler->display->display_options['filters']['field_star_sign_value']['table'] = 'field_data_field_star_sign';
$handler->display->display_options['filters']['field_star_sign_value']['field'] = 'field_star_sign_value';
$handler->display->display_options['filters']['field_star_sign_value']['group'] = 0;
$handler->display->display_options['filters']['field_star_sign_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_star_sign_value']['expose']['operator_id'] = 'field_star_sign_value_op';
$handler->display->display_options['filters']['field_star_sign_value']['expose']['label'] = 'Star sign';
$handler->display->display_options['filters']['field_star_sign_value']['expose']['operator'] = 'field_star_sign_value_op';
$handler->display->display_options['filters']['field_star_sign_value']['expose']['identifier'] = 'field_star_sign_value';
$handler->display->display_options['filters']['field_star_sign_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_star_sign_value']['expose']['reduce'] = 0;
/* Filter criterion: User: Personality (field_personality) */
$handler->display->display_options['filters']['field_personality_value']['id'] = 'field_personality_value';
$handler->display->display_options['filters']['field_personality_value']['table'] = 'field_data_field_personality';
$handler->display->display_options['filters']['field_personality_value']['field'] = 'field_personality_value';
$handler->display->display_options['filters']['field_personality_value']['group'] = 0;
$handler->display->display_options['filters']['field_personality_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_personality_value']['expose']['operator_id'] = 'field_personality_value_op';
$handler->display->display_options['filters']['field_personality_value']['expose']['label'] = 'Personality';
$handler->display->display_options['filters']['field_personality_value']['expose']['operator'] = 'field_personality_value_op';
$handler->display->display_options['filters']['field_personality_value']['expose']['identifier'] = 'field_personality_value';
$handler->display->display_options['filters']['field_personality_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_personality_value']['expose']['reduce'] = 0;
/* Filter criterion: User: Eye colour (field_eye_colour) */
$handler->display->display_options['filters']['field_eye_colour_value']['id'] = 'field_eye_colour_value';
$handler->display->display_options['filters']['field_eye_colour_value']['table'] = 'field_data_field_eye_colour';
$handler->display->display_options['filters']['field_eye_colour_value']['field'] = 'field_eye_colour_value';
$handler->display->display_options['filters']['field_eye_colour_value']['group'] = 0;
$handler->display->display_options['filters']['field_eye_colour_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_eye_colour_value']['expose']['operator_id'] = 'field_eye_colour_value_op';
$handler->display->display_options['filters']['field_eye_colour_value']['expose']['label'] = 'Eye colour';
$handler->display->display_options['filters']['field_eye_colour_value']['expose']['operator'] = 'field_eye_colour_value_op';
$handler->display->display_options['filters']['field_eye_colour_value']['expose']['identifier'] = 'field_eye_colour_value';
$handler->display->display_options['filters']['field_eye_colour_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_eye_colour_value']['expose']['reduce'] = 0;
/* Filter criterion: User: Hair colour (field_hair_colour) */
$handler->display->display_options['filters']['field_hair_colour_value']['id'] = 'field_hair_colour_value';
$handler->display->display_options['filters']['field_hair_colour_value']['table'] = 'field_data_field_hair_colour';
$handler->display->display_options['filters']['field_hair_colour_value']['field'] = 'field_hair_colour_value';
$handler->display->display_options['filters']['field_hair_colour_value']['group'] = 0;
$handler->display->display_options['filters']['field_hair_colour_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_hair_colour_value']['expose']['operator_id'] = 'field_hair_colour_value_op';
$handler->display->display_options['filters']['field_hair_colour_value']['expose']['label'] = 'Hair colour';
$handler->display->display_options['filters']['field_hair_colour_value']['expose']['operator'] = 'field_hair_colour_value_op';
$handler->display->display_options['filters']['field_hair_colour_value']['expose']['identifier'] = 'field_hair_colour_value';
$handler->display->display_options['filters']['field_hair_colour_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_hair_colour_value']['expose']['reduce'] = 0;
/* Filter criterion: User: Height (field_height) */
$handler->display->display_options['filters']['field_height_value']['id'] = 'field_height_value';
$handler->display->display_options['filters']['field_height_value']['table'] = 'field_data_field_height';
$handler->display->display_options['filters']['field_height_value']['field'] = 'field_height_value';
$handler->display->display_options['filters']['field_height_value']['group'] = 0;
$handler->display->display_options['filters']['field_height_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_height_value']['expose']['operator_id'] = 'field_height_value_op';
$handler->display->display_options['filters']['field_height_value']['expose']['label'] = 'Height';
$handler->display->display_options['filters']['field_height_value']['expose']['operator'] = 'field_height_value_op';
$handler->display->display_options['filters']['field_height_value']['expose']['identifier'] = 'field_height_value';
$handler->display->display_options['filters']['field_height_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_height_value']['expose']['reduce'] = 0;
/* Filter criterion: User: Body type (field_body_type) */
$handler->display->display_options['filters']['field_body_type_value']['id'] = 'field_body_type_value';
$handler->display->display_options['filters']['field_body_type_value']['table'] = 'field_data_field_body_type';
$handler->display->display_options['filters']['field_body_type_value']['field'] = 'field_body_type_value';
$handler->display->display_options['filters']['field_body_type_value']['group'] = 0;
$handler->display->display_options['filters']['field_body_type_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_body_type_value']['expose']['operator_id'] = 'field_body_type_value_op';
$handler->display->display_options['filters']['field_body_type_value']['expose']['label'] = 'Body type';
$handler->display->display_options['filters']['field_body_type_value']['expose']['operator'] = 'field_body_type_value_op';
$handler->display->display_options['filters']['field_body_type_value']['expose']['identifier'] = 'field_body_type_value';
$handler->display->display_options['filters']['field_body_type_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_body_type_value']['expose']['reduce'] = 0;
/* Filter criterion: User: Religious affiliation (field_relig_affiliation) */
$handler->display->display_options['filters']['field_relig_affiliation_value']['id'] = 'field_relig_affiliation_value';
$handler->display->display_options['filters']['field_relig_affiliation_value']['table'] = 'field_data_field_relig_affiliation';
$handler->display->display_options['filters']['field_relig_affiliation_value']['field'] = 'field_relig_affiliation_value';
$handler->display->display_options['filters']['field_relig_affiliation_value']['group'] = 0;
$handler->display->display_options['filters']['field_relig_affiliation_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['operator_id'] = 'field_relig_affiliation_value_op';
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['label'] = 'Religious affiliation';
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['operator'] = 'field_relig_affiliation_value_op';
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['identifier'] = 'field_relig_affiliation_value';
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_relig_affiliation_value']['expose']['reduce'] = 0;
/* Filter criterion: User: Do you keep kosher? (field_kosher) */
$handler->display->display_options['filters']['field_kosher_value_1']['id'] = 'field_kosher_value_1';
$handler->display->display_options['filters']['field_kosher_value_1']['table'] = 'field_data_field_kosher';
$handler->display->display_options['filters']['field_kosher_value_1']['field'] = 'field_kosher_value';
$handler->display->display_options['filters']['field_kosher_value_1']['group'] = 0;
$handler->display->display_options['filters']['field_kosher_value_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['operator_id'] = 'field_kosher_value_1_op';
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['label'] = 'Kosher';
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['operator'] = 'field_kosher_value_1_op';
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['identifier'] = 'field_kosher_value';
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_kosher_value_1']['expose']['reduce'] = 0;
/* Filter criterion: User: Are you a smoker? (field_smoker) */
$handler->display->display_options['filters']['field_smoker_value']['id'] = 'field_smoker_value';
$handler->display->display_options['filters']['field_smoker_value']['table'] = 'field_data_field_smoker';
$handler->display->display_options['filters']['field_smoker_value']['field'] = 'field_smoker_value';
$handler->display->display_options['filters']['field_smoker_value']['group'] = 0;
$handler->display->display_options['filters']['field_smoker_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_smoker_value']['expose']['operator_id'] = 'field_smoker_value_op';
$handler->display->display_options['filters']['field_smoker_value']['expose']['label'] = 'Smoking';
$handler->display->display_options['filters']['field_smoker_value']['expose']['operator'] = 'field_smoker_value_op';
$handler->display->display_options['filters']['field_smoker_value']['expose']['identifier'] = 'field_smoker_value';
$handler->display->display_options['filters']['field_smoker_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_smoker_value']['expose']['reduce'] = 0;
/* Filter criterion: User: Drinking habits (field_drinking) */
$handler->display->display_options['filters']['field_drinking_value']['id'] = 'field_drinking_value';
$handler->display->display_options['filters']['field_drinking_value']['table'] = 'field_data_field_drinking';
$handler->display->display_options['filters']['field_drinking_value']['field'] = 'field_drinking_value';
$handler->display->display_options['filters']['field_drinking_value']['group'] = 0;
$handler->display->display_options['filters']['field_drinking_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_drinking_value']['expose']['operator_id'] = 'field_drinking_value_op';
$handler->display->display_options['filters']['field_drinking_value']['expose']['label'] = 'Drinking';
$handler->display->display_options['filters']['field_drinking_value']['expose']['operator'] = 'field_drinking_value_op';
$handler->display->display_options['filters']['field_drinking_value']['expose']['identifier'] = 'field_drinking_value';
$handler->display->display_options['filters']['field_drinking_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_drinking_value']['expose']['reduce'] = 0;
/* Filter criterion: User: Do you have kids (field_have_kids) */
$handler->display->display_options['filters']['field_have_kids_value']['id'] = 'field_have_kids_value';
$handler->display->display_options['filters']['field_have_kids_value']['table'] = 'field_data_field_have_kids';
$handler->display->display_options['filters']['field_have_kids_value']['field'] = 'field_have_kids_value';
$handler->display->display_options['filters']['field_have_kids_value']['group'] = 0;
$handler->display->display_options['filters']['field_have_kids_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_have_kids_value']['expose']['operator_id'] = 'field_have_kids_value_op';
$handler->display->display_options['filters']['field_have_kids_value']['expose']['label'] = 'Kids';
$handler->display->display_options['filters']['field_have_kids_value']['expose']['operator'] = 'field_have_kids_value_op';
$handler->display->display_options['filters']['field_have_kids_value']['expose']['identifier'] = 'field_have_kids_value';
$handler->display->display_options['filters']['field_have_kids_value']['expose']['multiple'] = 1;
$handler->display->display_options['filters']['field_have_kids_value']['expose']['reduce'] = 0;
/* Filter criterion: User: My tagline (field_headline) */
$handler->display->display_options['filters']['field_headline_value']['id'] = 'field_headline_value';
$handler->display->display_options['filters']['field_headline_value']['table'] = 'field_data_field_headline';
$handler->display->display_options['filters']['field_headline_value']['field'] = 'field_headline_value';
$handler->display->display_options['filters']['field_headline_value']['operator'] = 'word';
$handler->display->display_options['filters']['field_headline_value']['group'] = 0;
$handler->display->display_options['filters']['field_headline_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_headline_value']['expose']['operator_id'] = 'field_headline_value_op';
$handler->display->display_options['filters']['field_headline_value']['expose']['label'] = 'Their headline';
$handler->display->display_options['filters']['field_headline_value']['expose']['operator'] = 'field_headline_value_op';
$handler->display->display_options['filters']['field_headline_value']['expose']['identifier'] = 'field_headline_value';
$handler->display->display_options['filters']['field_headline_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_headline_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: My self-summary (field_self_summary) */
$handler->display->display_options['filters']['field_self_summary_value']['id'] = 'field_self_summary_value';
$handler->display->display_options['filters']['field_self_summary_value']['table'] = 'field_data_field_self_summary';
$handler->display->display_options['filters']['field_self_summary_value']['field'] = 'field_self_summary_value';
$handler->display->display_options['filters']['field_self_summary_value']['operator'] = 'word';
$handler->display->display_options['filters']['field_self_summary_value']['group'] = 0;
$handler->display->display_options['filters']['field_self_summary_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_self_summary_value']['expose']['operator_id'] = 'field_self_summary_value_op';
$handler->display->display_options['filters']['field_self_summary_value']['expose']['label'] = 'Their self summary';
$handler->display->display_options['filters']['field_self_summary_value']['expose']['operator'] = 'field_self_summary_value_op';
$handler->display->display_options['filters']['field_self_summary_value']['expose']['identifier'] = 'field_self_summary_value';
$handler->display->display_options['filters']['field_self_summary_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_self_summary_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: My friends describe me as (field_friend_summary) */
$handler->display->display_options['filters']['field_friend_summary_value']['id'] = 'field_friend_summary_value';
$handler->display->display_options['filters']['field_friend_summary_value']['table'] = 'field_data_field_friend_summary';
$handler->display->display_options['filters']['field_friend_summary_value']['field'] = 'field_friend_summary_value';
$handler->display->display_options['filters']['field_friend_summary_value']['operator'] = 'word';
$handler->display->display_options['filters']['field_friend_summary_value']['group'] = 0;
$handler->display->display_options['filters']['field_friend_summary_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['operator_id'] = 'field_friend_summary_value_op';
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['label'] = 'Friends describe them as';
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['operator'] = 'field_friend_summary_value_op';
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['identifier'] = 'field_friend_summary_value';
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_friend_summary_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: I am passionate about (field_passionate_about) */
$handler->display->display_options['filters']['field_passionate_about_value']['id'] = 'field_passionate_about_value';
$handler->display->display_options['filters']['field_passionate_about_value']['table'] = 'field_data_field_passionate_about';
$handler->display->display_options['filters']['field_passionate_about_value']['field'] = 'field_passionate_about_value';
$handler->display->display_options['filters']['field_passionate_about_value']['operator'] = 'word';
$handler->display->display_options['filters']['field_passionate_about_value']['group'] = 0;
$handler->display->display_options['filters']['field_passionate_about_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['operator_id'] = 'field_passionate_about_value_op';
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['label'] = 'Is passionate about';
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['operator'] = 'field_passionate_about_value_op';
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['identifier'] = 'field_passionate_about_value';
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_passionate_about_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Roles */
$handler->display->display_options['filters']['rid']['id'] = 'rid';
$handler->display->display_options['filters']['rid']['table'] = 'users_roles';
$handler->display->display_options['filters']['rid']['field'] = 'rid';
$handler->display->display_options['filters']['rid']['operator'] = 'not';
$handler->display->display_options['filters']['rid']['value'] = array(
  3 => '3',
  4 => '4',
);
$handler->display->display_options['filters']['rid']['reduce_duplicates'] = 1;
$handler->display->display_options['path'] = 'user-search-matches-cron';

return $view;

}