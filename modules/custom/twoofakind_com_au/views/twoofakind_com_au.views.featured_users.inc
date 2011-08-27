<?php

/**
 * @file
 * Featured users view
 */

/**
 * @see hook_views_default_views()
 */
function _twoofakind_com_au_views_default_views_featured_users() {

$view = new view;
$view->name = 'featured_users';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'Featured users';
$view->core = 7;
$view->api_version = '3.0-alpha1';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Featured users';
$handler->display->display_options['css_class'] = 'views-page-users';
$handler->display->display_options['use_more'] = TRUE;
$handler->display->display_options['use_more_always'] = TRUE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access user profiles';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
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
);
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'ds';
$handler->display->display_options['row_options']['view_mode'] = 'user_list';
$handler->display->display_options['row_options']['alternating'] = 0;
$handler->display->display_options['row_options']['grouping'] = 0;
$handler->display->display_options['row_options']['advanced'] = 0;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = FALSE;
$handler->display->display_options['empty']['area']['content'] = '<h3>No featured users were found</h3>
<p>Send us a message via the <a href="/contact-us" title="say hello and maybe we\'ll feature you">contact</a> page and maybe we\'ll feature you.</p>';
$handler->display->display_options['empty']['area']['format'] = 'html_full';
$handler->display->display_options['empty']['area']['tokenize'] = 0;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
$handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim'] = 0;
$handler->display->display_options['fields']['name']['alter']['html'] = 0;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
$handler->display->display_options['fields']['name']['link_to_user'] = 1;
$handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
/* Sort criterion: Featured Users: Created */
$handler->display->display_options['sorts']['featured_user_created']['id'] = 'featured_user_created';
$handler->display->display_options['sorts']['featured_user_created']['table'] = 'featured_users';
$handler->display->display_options['sorts']['featured_user_created']['field'] = 'featured_user_created';
$handler->display->display_options['sorts']['featured_user_created']['order'] = 'DESC';
$handler->display->display_options['sorts']['featured_user_created']['exposed'] = TRUE;
$handler->display->display_options['sorts']['featured_user_created']['expose']['label'] = 'Date featured';
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
/* Filter criterion: Featured Users: Uid of Featured user */
$handler->display->display_options['filters']['featured_user_uid']['id'] = 'featured_user_uid';
$handler->display->display_options['filters']['featured_user_uid']['table'] = 'featured_users';
$handler->display->display_options['filters']['featured_user_uid']['field'] = 'featured_user_uid';
$handler->display->display_options['filters']['featured_user_uid']['operator'] = '>';
$handler->display->display_options['filters']['featured_user_uid']['value']['value'] = '1';
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

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'views-page-users';
$handler->display->display_options['path'] = 'featured-users';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'ds';
$handler->display->display_options['row_options']['view_mode'] = 'user_list';
$handler->display->display_options['row_options']['alternating'] = 0;
$handler->display->display_options['row_options']['grouping'] = 0;
$handler->display->display_options['row_options']['advanced'] = 0;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Featured Users: Created */
$handler->display->display_options['sorts']['featured_user_created']['id'] = 'featured_user_created';
$handler->display->display_options['sorts']['featured_user_created']['table'] = 'featured_users';
$handler->display->display_options['sorts']['featured_user_created']['field'] = 'featured_user_created';
$handler->display->display_options['sorts']['featured_user_created']['relationship'] = 'featured_user_uid';
$handler->display->display_options['sorts']['featured_user_created']['order'] = 'DESC';
$handler->display->display_options['block_description'] = 'Featured users';

return $view;

}