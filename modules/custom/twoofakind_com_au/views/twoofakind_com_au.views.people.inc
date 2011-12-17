<?php

/**
 * @file
 * People view
 */

/**
 * @see hook_views_default_views()
 */
function _twoofakind_com_au_views_default_views_people() {

$view = new view;
$view->name = 'people';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'People';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'People';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'administer users';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
$handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
$handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'status' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => 0,
      'bef_collapsible' => 0,
      'bef_filter_description' => '',
    ),
  ),
  'field_date_of_birth_value' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
  ),
  'field_sex_value' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => 0,
      'bef_collapsible' => 0,
      'bef_filter_description' => '',
    ),
  ),
  'city' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
  ),
);
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '500';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'views_bulk_operations' => 'views_bulk_operations',
  'name' => 'name',
  'field_name_first' => 'field_name_first',
  'field_name_last' => 'field_name_first',
  'mail' => 'mail',
  'status' => 'status',
  'created' => 'created',
  'access' => 'access',
  'edit_node' => 'edit_node',
  'field_date_of_birth' => 'field_date_of_birth',
  'field_date_of_birth_1' => 'field_date_of_birth',
);
$handler->display->display_options['style_options']['default'] = 'created';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
  ),
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'field_name_first' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '&nbsp;',
  ),
  'field_name_last' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'mail' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'status' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
  ),
  'access' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
  ),
  'edit_node' => array(
    'align' => '',
    'separator' => '',
  ),
  'field_date_of_birth' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '<br />',
  ),
  'field_date_of_birth_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 1;
$handler->display->display_options['style_options']['order'] = 'desc';
$handler->display->display_options['style_options']['empty_table'] = 0;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = FALSE;
$handler->display->display_options['header']['area']['format'] = 'html_full';
$handler->display->display_options['header']['area']['tokenize'] = 0;
/* Field: User: Bulk operations */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
  'twoofakind_com_au_unblock_user_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'system_block_ip_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'twoofakind_com_au_abusive_user_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'user_block_user_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'twoofakind_com_au_deactivate_user_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'views_bulk_operations_delete_item' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'system_message_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'views_bulk_operations_script_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'flag_user_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'views_bulk_operations_user_roles_action' => array(
    'selected' => 0,
    'use_queue' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'twoofakind_com_au_notify_admin_of_abusive_user_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
    'settings' => array(
      'url' => '',
    ),
  ),
  'twoofakind_com_au_reactivate_user_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'system_goto_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'system_send_email_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
);
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Username';
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
$handler->display->display_options['fields']['name']['element_label_colon'] = 0;
$handler->display->display_options['fields']['name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
$handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['name']['link_to_user'] = 1;
$handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
/* Field: User: First name */
$handler->display->display_options['fields']['field_name_first']['id'] = 'field_name_first';
$handler->display->display_options['fields']['field_name_first']['table'] = 'field_data_field_name_first';
$handler->display->display_options['fields']['field_name_first']['field'] = 'field_name_first';
$handler->display->display_options['fields']['field_name_first']['label'] = 'Name';
$handler->display->display_options['fields']['field_name_first']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_name_first']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_name_first']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_name_first']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_name_first']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_name_first']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_name_first']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_name_first']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_name_first']['field_api_classes'] = 0;
/* Field: User: Last name */
$handler->display->display_options['fields']['field_name_last']['id'] = 'field_name_last';
$handler->display->display_options['fields']['field_name_last']['table'] = 'field_data_field_name_last';
$handler->display->display_options['fields']['field_name_last']['field'] = 'field_name_last';
$handler->display->display_options['fields']['field_name_last']['label'] = '';
$handler->display->display_options['fields']['field_name_last']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_name_last']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_name_last']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_name_last']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_name_last']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_name_last']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_name_last']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_name_last']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_name_last']['field_api_classes'] = 0;
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['label'] = 'Email';
$handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['mail']['alter']['external'] = 0;
$handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
$handler->display->display_options['fields']['mail']['alter']['html'] = 0;
$handler->display->display_options['fields']['mail']['element_label_colon'] = 0;
$handler->display->display_options['fields']['mail']['element_default_classes'] = 1;
$handler->display->display_options['fields']['mail']['hide_empty'] = 0;
$handler->display->display_options['fields']['mail']['empty_zero'] = 0;
$handler->display->display_options['fields']['mail']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['mail']['link_to_user'] = 0;
/* Field: User: Date of birth */
$handler->display->display_options['fields']['field_date_of_birth']['id'] = 'field_date_of_birth';
$handler->display->display_options['fields']['field_date_of_birth']['table'] = 'field_data_field_date_of_birth';
$handler->display->display_options['fields']['field_date_of_birth']['field'] = 'field_date_of_birth';
$handler->display->display_options['fields']['field_date_of_birth']['label'] = 'DOB / Age';
$handler->display->display_options['fields']['field_date_of_birth']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_date_of_birth']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['settings'] = array(
  'format_type' => 'short',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
$handler->display->display_options['fields']['field_date_of_birth']['field_api_classes'] = 0;
/* Field: User: Date of birth */
$handler->display->display_options['fields']['field_date_of_birth_1']['id'] = 'field_date_of_birth_1';
$handler->display->display_options['fields']['field_date_of_birth_1']['table'] = 'field_data_field_date_of_birth';
$handler->display->display_options['fields']['field_date_of_birth_1']['field'] = 'field_date_of_birth';
$handler->display->display_options['fields']['field_date_of_birth_1']['label'] = 'Age';
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_date_of_birth_1']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['type'] = 'age';
$handler->display->display_options['fields']['field_date_of_birth_1']['settings'] = array(
  'format_type' => 'long',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
$handler->display->display_options['fields']['field_date_of_birth_1']['field_api_classes'] = 0;
/* Field: User: Active */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'users';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['status']['alter']['external'] = 0;
$handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['status']['alter']['trim'] = 0;
$handler->display->display_options['fields']['status']['alter']['html'] = 0;
$handler->display->display_options['fields']['status']['element_label_colon'] = 0;
$handler->display->display_options['fields']['status']['element_default_classes'] = 1;
$handler->display->display_options['fields']['status']['hide_empty'] = 0;
$handler->display->display_options['fields']['status']['empty_zero'] = 0;
$handler->display->display_options['fields']['status']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: User: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'users';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Member for';
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
/* Field: User: Last access */
$handler->display->display_options['fields']['access']['id'] = 'access';
$handler->display->display_options['fields']['access']['table'] = 'users';
$handler->display->display_options['fields']['access']['field'] = 'access';
$handler->display->display_options['fields']['access']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['access']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['access']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['access']['alter']['external'] = 0;
$handler->display->display_options['fields']['access']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['access']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['access']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['access']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['access']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['access']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['access']['alter']['trim'] = 0;
$handler->display->display_options['fields']['access']['alter']['html'] = 0;
$handler->display->display_options['fields']['access']['element_label_colon'] = 0;
$handler->display->display_options['fields']['access']['element_default_classes'] = 1;
$handler->display->display_options['fields']['access']['hide_empty'] = 0;
$handler->display->display_options['fields']['access']['empty_zero'] = 0;
$handler->display->display_options['fields']['access']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['access']['date_format'] = 'raw time ago';
/* Field: User: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'users';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
$handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
$handler->display->display_options['fields']['edit_node']['element_label_colon'] = 0;
$handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
$handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
$handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
$handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 0;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 'All';
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['exposed'] = TRUE;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
$handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
$handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
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
$handler->display->display_options['filters']['field_sex_value']['expose']['reduce'] = 0;
/* Filter criterion: Location: City */
$handler->display->display_options['filters']['city']['id'] = 'city';
$handler->display->display_options['filters']['city']['table'] = 'location';
$handler->display->display_options['filters']['city']['field'] = 'city';
$handler->display->display_options['filters']['city']['operator'] = 'contains';
$handler->display->display_options['filters']['city']['group'] = 0;
$handler->display->display_options['filters']['city']['exposed'] = TRUE;
$handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
$handler->display->display_options['filters']['city']['expose']['label'] = 'City';
$handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
$handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
$handler->display->display_options['filters']['city']['expose']['required'] = 0;
$handler->display->display_options['filters']['city']['expose']['multiple'] = FALSE;
/* Filter criterion: Not anonymous */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'users';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['ui_name'] = 'Not anonymous';
$handler->display->display_options['filters']['created']['operator'] = '>';
$handler->display->display_options['filters']['created']['value']['value'] = '1980-01-01 00:00:00';
$handler->display->display_options['filters']['created']['group'] = 0;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/people/custom';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'List';
$handler->display->display_options['menu']['description'] = 'Custom user list';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: CSV */
$handler = $view->new_display('views_data_export', 'CSV', 'csv');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 1;
$handler->display->display_options['style_options']['quote'] = 1;
$handler->display->display_options['style_options']['trim'] = 1;
$handler->display->display_options['style_options']['replace_newlines'] = 1;
$handler->display->display_options['style_options']['newline_replacement'] = '\\n';
$handler->display->display_options['style_options']['header'] = 1;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Username';
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
$handler->display->display_options['fields']['name']['element_label_colon'] = 0;
$handler->display->display_options['fields']['name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
$handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['name']['link_to_user'] = 1;
$handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
/* Field: User: First name */
$handler->display->display_options['fields']['field_name_first']['id'] = 'field_name_first';
$handler->display->display_options['fields']['field_name_first']['table'] = 'field_data_field_name_first';
$handler->display->display_options['fields']['field_name_first']['field'] = 'field_name_first';
$handler->display->display_options['fields']['field_name_first']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_name_first']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_name_first']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_name_first']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_name_first']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_name_first']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_name_first']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_name_first']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_name_first']['field_api_classes'] = 0;
/* Field: User: Last name */
$handler->display->display_options['fields']['field_name_last']['id'] = 'field_name_last';
$handler->display->display_options['fields']['field_name_last']['table'] = 'field_data_field_name_last';
$handler->display->display_options['fields']['field_name_last']['field'] = 'field_name_last';
$handler->display->display_options['fields']['field_name_last']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_name_last']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_name_last']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_name_last']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_name_last']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_name_last']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_name_last']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_name_last']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_name_last']['field_api_classes'] = 0;
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['mail']['alter']['external'] = 0;
$handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
$handler->display->display_options['fields']['mail']['alter']['html'] = 0;
$handler->display->display_options['fields']['mail']['element_label_colon'] = 0;
$handler->display->display_options['fields']['mail']['element_default_classes'] = 1;
$handler->display->display_options['fields']['mail']['hide_empty'] = 0;
$handler->display->display_options['fields']['mail']['empty_zero'] = 0;
$handler->display->display_options['fields']['mail']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['mail']['link_to_user'] = 0;
/* Field: User: Active */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'users';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['label'] = 'Status';
$handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['status']['alter']['external'] = 0;
$handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['status']['alter']['trim'] = 0;
$handler->display->display_options['fields']['status']['alter']['html'] = 0;
$handler->display->display_options['fields']['status']['element_label_colon'] = 0;
$handler->display->display_options['fields']['status']['element_default_classes'] = 1;
$handler->display->display_options['fields']['status']['hide_empty'] = 0;
$handler->display->display_options['fields']['status']['empty_zero'] = 0;
$handler->display->display_options['fields']['status']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: User: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'users';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Member for';
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
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: User: Last access */
$handler->display->display_options['fields']['access']['id'] = 'access';
$handler->display->display_options['fields']['access']['table'] = 'users';
$handler->display->display_options['fields']['access']['field'] = 'access';
$handler->display->display_options['fields']['access']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['access']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['access']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['access']['alter']['external'] = 0;
$handler->display->display_options['fields']['access']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['access']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['access']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['access']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['access']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['access']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['access']['alter']['trim'] = 0;
$handler->display->display_options['fields']['access']['alter']['html'] = 0;
$handler->display->display_options['fields']['access']['element_label_colon'] = 0;
$handler->display->display_options['fields']['access']['element_default_classes'] = 1;
$handler->display->display_options['fields']['access']['hide_empty'] = 0;
$handler->display->display_options['fields']['access']['empty_zero'] = 0;
$handler->display->display_options['fields']['access']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['access']['date_format'] = 'short';
$handler->display->display_options['path'] = 'admin/people/custom.csv';
$handler->display->display_options['displays'] = array(
  'page' => 'page',
  'page_find_individual' => 'page_find_individual',
  'page_all_filters' => 'page_all_filters',
  'page_site_interaction' => 'page_site_interaction',
  'default' => 0,
);

/* Display: XLS */
$handler = $view->new_display('views_data_export', 'XLS', 'xls');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_xls';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 1;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Username';
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
$handler->display->display_options['fields']['name']['element_label_colon'] = 0;
$handler->display->display_options['fields']['name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
$handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['name']['link_to_user'] = 1;
$handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
/* Field: User: First name */
$handler->display->display_options['fields']['field_name_first']['id'] = 'field_name_first';
$handler->display->display_options['fields']['field_name_first']['table'] = 'field_data_field_name_first';
$handler->display->display_options['fields']['field_name_first']['field'] = 'field_name_first';
$handler->display->display_options['fields']['field_name_first']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_name_first']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_name_first']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_name_first']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_name_first']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_name_first']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_name_first']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_name_first']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_name_first']['field_api_classes'] = 0;
/* Field: User: Last name */
$handler->display->display_options['fields']['field_name_last']['id'] = 'field_name_last';
$handler->display->display_options['fields']['field_name_last']['table'] = 'field_data_field_name_last';
$handler->display->display_options['fields']['field_name_last']['field'] = 'field_name_last';
$handler->display->display_options['fields']['field_name_last']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_name_last']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_name_last']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_name_last']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_name_last']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_name_last']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_name_last']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_name_last']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_name_last']['field_api_classes'] = 0;
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['mail']['alter']['external'] = 0;
$handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
$handler->display->display_options['fields']['mail']['alter']['html'] = 0;
$handler->display->display_options['fields']['mail']['element_label_colon'] = 0;
$handler->display->display_options['fields']['mail']['element_default_classes'] = 1;
$handler->display->display_options['fields']['mail']['hide_empty'] = 0;
$handler->display->display_options['fields']['mail']['empty_zero'] = 0;
$handler->display->display_options['fields']['mail']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['mail']['link_to_user'] = 0;
/* Field: User: Active */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'users';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['label'] = 'Status';
$handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['status']['alter']['external'] = 0;
$handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['status']['alter']['trim'] = 0;
$handler->display->display_options['fields']['status']['alter']['html'] = 0;
$handler->display->display_options['fields']['status']['element_label_colon'] = 0;
$handler->display->display_options['fields']['status']['element_default_classes'] = 1;
$handler->display->display_options['fields']['status']['hide_empty'] = 0;
$handler->display->display_options['fields']['status']['empty_zero'] = 0;
$handler->display->display_options['fields']['status']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: User: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'users';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Member for';
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
$handler->display->display_options['fields']['created']['date_format'] = 'short';
/* Field: User: Last access */
$handler->display->display_options['fields']['access']['id'] = 'access';
$handler->display->display_options['fields']['access']['table'] = 'users';
$handler->display->display_options['fields']['access']['field'] = 'access';
$handler->display->display_options['fields']['access']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['access']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['access']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['access']['alter']['external'] = 0;
$handler->display->display_options['fields']['access']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['access']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['access']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['access']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['access']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['access']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['access']['alter']['trim'] = 0;
$handler->display->display_options['fields']['access']['alter']['html'] = 0;
$handler->display->display_options['fields']['access']['element_label_colon'] = 0;
$handler->display->display_options['fields']['access']['element_default_classes'] = 1;
$handler->display->display_options['fields']['access']['hide_empty'] = 0;
$handler->display->display_options['fields']['access']['empty_zero'] = 0;
$handler->display->display_options['fields']['access']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['access']['date_format'] = 'short';
$handler->display->display_options['path'] = 'admin/people/custom.xls';
$handler->display->display_options['displays'] = array(
  'page' => 'page',
  'page_find_individual' => 'page_find_individual',
  'page_all_filters' => 'page_all_filters',
  'page_site_interaction' => 'page_site_interaction',
  'default' => 0,
);

/* Display: Find an individual */
$handler = $view->new_display('page', 'Find an individual', 'page_find_individual');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'People : Find an individual';
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear';
$handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
$handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 0;
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'uid' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => 0,
      'bef_collapsible' => 0,
      'bef_filter_description' => '',
    ),
  ),
  'mail' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
  ),
  'field_name_first_value' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
  ),
  'field_name_last_value' => array(
    'more_options' => array(
      'bef_filter_description' => '',
    ),
  ),
);
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['value'] = '';
$handler->display->display_options['filters']['uid']['group'] = 0;
$handler->display->display_options['filters']['uid']['exposed'] = TRUE;
$handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['label'] = 'Username';
$handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
$handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
$handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;
/* Filter criterion: User: E-mail */
$handler->display->display_options['filters']['mail']['id'] = 'mail';
$handler->display->display_options['filters']['mail']['table'] = 'users';
$handler->display->display_options['filters']['mail']['field'] = 'mail';
$handler->display->display_options['filters']['mail']['operator'] = 'contains';
$handler->display->display_options['filters']['mail']['group'] = 0;
$handler->display->display_options['filters']['mail']['exposed'] = TRUE;
$handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
$handler->display->display_options['filters']['mail']['expose']['label'] = 'Email';
$handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
$handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
$handler->display->display_options['filters']['mail']['expose']['required'] = 0;
$handler->display->display_options['filters']['mail']['expose']['multiple'] = FALSE;
/* Filter criterion: Not anonymous */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'users';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['ui_name'] = 'Not anonymous';
$handler->display->display_options['filters']['created']['operator'] = '>';
$handler->display->display_options['filters']['created']['value']['value'] = '1980-01-01 00:00:00';
$handler->display->display_options['filters']['created']['group'] = 0;
/* Filter criterion: User: First name (field_name_first) */
$handler->display->display_options['filters']['field_name_first_value']['id'] = 'field_name_first_value';
$handler->display->display_options['filters']['field_name_first_value']['table'] = 'field_data_field_name_first';
$handler->display->display_options['filters']['field_name_first_value']['field'] = 'field_name_first_value';
$handler->display->display_options['filters']['field_name_first_value']['operator'] = 'contains';
$handler->display->display_options['filters']['field_name_first_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_name_first_value']['expose']['operator_id'] = 'field_name_first_value_op';
$handler->display->display_options['filters']['field_name_first_value']['expose']['label'] = 'First name';
$handler->display->display_options['filters']['field_name_first_value']['expose']['operator'] = 'field_name_first_value_op';
$handler->display->display_options['filters']['field_name_first_value']['expose']['identifier'] = 'field_name_first_value';
$handler->display->display_options['filters']['field_name_first_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_name_first_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Last name (field_name_last) */
$handler->display->display_options['filters']['field_name_last_value']['id'] = 'field_name_last_value';
$handler->display->display_options['filters']['field_name_last_value']['table'] = 'field_data_field_name_last';
$handler->display->display_options['filters']['field_name_last_value']['field'] = 'field_name_last_value';
$handler->display->display_options['filters']['field_name_last_value']['operator'] = 'contains';
$handler->display->display_options['filters']['field_name_last_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_name_last_value']['expose']['operator_id'] = 'field_name_last_value_op';
$handler->display->display_options['filters']['field_name_last_value']['expose']['label'] = 'Last name';
$handler->display->display_options['filters']['field_name_last_value']['expose']['operator'] = 'field_name_last_value_op';
$handler->display->display_options['filters']['field_name_last_value']['expose']['identifier'] = 'field_name_last_value';
$handler->display->display_options['filters']['field_name_last_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_name_last_value']['expose']['multiple'] = FALSE;
$handler->display->display_options['path'] = 'admin/people/find-individual';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Find an individual';
$handler->display->display_options['menu']['description'] = 'Custom user list';
$handler->display->display_options['menu']['weight'] = '1';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: All filters */
$handler = $view->new_display('page', 'All filters', 'page_all_filters');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'People : All filters';
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['exposed'] = TRUE;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
$handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
$handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
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
$handler->display->display_options['filters']['field_sex_value']['expose']['reduce'] = 0;
/* Filter criterion: Location: City */
$handler->display->display_options['filters']['city']['id'] = 'city';
$handler->display->display_options['filters']['city']['table'] = 'location';
$handler->display->display_options['filters']['city']['field'] = 'city';
$handler->display->display_options['filters']['city']['operator'] = 'contains';
$handler->display->display_options['filters']['city']['group'] = 0;
$handler->display->display_options['filters']['city']['exposed'] = TRUE;
$handler->display->display_options['filters']['city']['expose']['operator_id'] = 'city_op';
$handler->display->display_options['filters']['city']['expose']['label'] = 'City';
$handler->display->display_options['filters']['city']['expose']['operator'] = 'city_op';
$handler->display->display_options['filters']['city']['expose']['identifier'] = 'city';
$handler->display->display_options['filters']['city']['expose']['required'] = 0;
$handler->display->display_options['filters']['city']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Last access */
$handler->display->display_options['filters']['access']['id'] = 'access';
$handler->display->display_options['filters']['access']['table'] = 'users';
$handler->display->display_options['filters']['access']['field'] = 'access';
$handler->display->display_options['filters']['access']['operator'] = '<=';
$handler->display->display_options['filters']['access']['value']['type'] = 'offset';
$handler->display->display_options['filters']['access']['group'] = 0;
$handler->display->display_options['filters']['access']['exposed'] = TRUE;
$handler->display->display_options['filters']['access']['expose']['operator_id'] = 'access_op';
$handler->display->display_options['filters']['access']['expose']['label'] = 'Last access was prior to';
$handler->display->display_options['filters']['access']['expose']['operator'] = 'access_op';
$handler->display->display_options['filters']['access']['expose']['identifier'] = 'access';
$handler->display->display_options['filters']['access']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Last access */
$handler->display->display_options['filters']['access_1']['id'] = 'access_1';
$handler->display->display_options['filters']['access_1']['table'] = 'users';
$handler->display->display_options['filters']['access_1']['field'] = 'access';
$handler->display->display_options['filters']['access_1']['group'] = 0;
$handler->display->display_options['filters']['access_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['access_1']['expose']['operator_id'] = 'access_1_op';
$handler->display->display_options['filters']['access_1']['expose']['label'] = 'New users';
$handler->display->display_options['filters']['access_1']['expose']['operator'] = 'access_1_op';
$handler->display->display_options['filters']['access_1']['expose']['identifier'] = 'access_new';
$handler->display->display_options['filters']['access_1']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['value'] = '';
$handler->display->display_options['filters']['uid']['group'] = 0;
$handler->display->display_options['filters']['uid']['exposed'] = TRUE;
$handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['label'] = 'Username';
$handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
$handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
$handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;
/* Filter criterion: User: E-mail */
$handler->display->display_options['filters']['mail']['id'] = 'mail';
$handler->display->display_options['filters']['mail']['table'] = 'users';
$handler->display->display_options['filters']['mail']['field'] = 'mail';
$handler->display->display_options['filters']['mail']['operator'] = 'contains';
$handler->display->display_options['filters']['mail']['group'] = 0;
$handler->display->display_options['filters']['mail']['exposed'] = TRUE;
$handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
$handler->display->display_options['filters']['mail']['expose']['label'] = 'Email';
$handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
$handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
$handler->display->display_options['filters']['mail']['expose']['required'] = 0;
$handler->display->display_options['filters']['mail']['expose']['multiple'] = FALSE;
/* Filter criterion: User: First name (field_name_first) */
$handler->display->display_options['filters']['field_name_first_value']['id'] = 'field_name_first_value';
$handler->display->display_options['filters']['field_name_first_value']['table'] = 'field_data_field_name_first';
$handler->display->display_options['filters']['field_name_first_value']['field'] = 'field_name_first_value';
$handler->display->display_options['filters']['field_name_first_value']['operator'] = 'contains';
$handler->display->display_options['filters']['field_name_first_value']['group'] = 0;
$handler->display->display_options['filters']['field_name_first_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_name_first_value']['expose']['operator_id'] = 'field_name_first_value_op';
$handler->display->display_options['filters']['field_name_first_value']['expose']['label'] = 'First name';
$handler->display->display_options['filters']['field_name_first_value']['expose']['operator'] = 'field_name_first_value_op';
$handler->display->display_options['filters']['field_name_first_value']['expose']['identifier'] = 'field_name_first_value';
$handler->display->display_options['filters']['field_name_first_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_name_first_value']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Last name (field_name_last) */
$handler->display->display_options['filters']['field_name_last_value']['id'] = 'field_name_last_value';
$handler->display->display_options['filters']['field_name_last_value']['table'] = 'field_data_field_name_last';
$handler->display->display_options['filters']['field_name_last_value']['field'] = 'field_name_last_value';
$handler->display->display_options['filters']['field_name_last_value']['operator'] = 'contains';
$handler->display->display_options['filters']['field_name_last_value']['group'] = 0;
$handler->display->display_options['filters']['field_name_last_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_name_last_value']['expose']['operator_id'] = 'field_name_last_value_op';
$handler->display->display_options['filters']['field_name_last_value']['expose']['label'] = 'Last name';
$handler->display->display_options['filters']['field_name_last_value']['expose']['operator'] = 'field_name_last_value_op';
$handler->display->display_options['filters']['field_name_last_value']['expose']['identifier'] = 'field_name_last_value';
$handler->display->display_options['filters']['field_name_last_value']['expose']['required'] = 0;
$handler->display->display_options['filters']['field_name_last_value']['expose']['multiple'] = FALSE;
/* Filter criterion: Not anonymous */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'users';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['ui_name'] = 'Not anonymous';
$handler->display->display_options['filters']['created']['operator'] = '>';
$handler->display->display_options['filters']['created']['value']['value'] = '1980-01-01 00:00:00';
$handler->display->display_options['filters']['created']['group'] = 0;
$handler->display->display_options['path'] = 'admin/people/all-filters';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'All filters';
$handler->display->display_options['menu']['description'] = 'Custom user list';
$handler->display->display_options['menu']['weight'] = '3';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Site interaction */
$handler = $view->new_display('page', 'Site interaction', 'page_site_interaction');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'People : Site interaction';
$handler->display->display_options['enabled'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['exposed'] = TRUE;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
$handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
$handler->display->display_options['filters']['status']['expose']['remember'] = 1;
$handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Last access */
$handler->display->display_options['filters']['access']['id'] = 'access';
$handler->display->display_options['filters']['access']['table'] = 'users';
$handler->display->display_options['filters']['access']['field'] = 'access';
$handler->display->display_options['filters']['access']['operator'] = '<=';
$handler->display->display_options['filters']['access']['value']['type'] = 'offset';
$handler->display->display_options['filters']['access']['group'] = 0;
$handler->display->display_options['filters']['access']['exposed'] = TRUE;
$handler->display->display_options['filters']['access']['expose']['operator_id'] = 'access_op';
$handler->display->display_options['filters']['access']['expose']['label'] = 'Last access was prior to';
$handler->display->display_options['filters']['access']['expose']['operator'] = 'access_op';
$handler->display->display_options['filters']['access']['expose']['identifier'] = 'access';
$handler->display->display_options['filters']['access']['expose']['remember'] = 1;
$handler->display->display_options['filters']['access']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Last access */
$handler->display->display_options['filters']['access_1']['id'] = 'access_1';
$handler->display->display_options['filters']['access_1']['table'] = 'users';
$handler->display->display_options['filters']['access_1']['field'] = 'access';
$handler->display->display_options['filters']['access_1']['group'] = 0;
$handler->display->display_options['filters']['access_1']['exposed'] = TRUE;
$handler->display->display_options['filters']['access_1']['expose']['operator_id'] = 'access_1_op';
$handler->display->display_options['filters']['access_1']['expose']['label'] = 'New users';
$handler->display->display_options['filters']['access_1']['expose']['operator'] = 'access_1_op';
$handler->display->display_options['filters']['access_1']['expose']['identifier'] = 'access_new';
$handler->display->display_options['filters']['access_1']['expose']['multiple'] = FALSE;
/* Filter criterion: Not anonymous */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'users';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['ui_name'] = 'Not anonymous';
$handler->display->display_options['filters']['created']['operator'] = '>';
$handler->display->display_options['filters']['created']['value']['value'] = '1980-01-01 00:00:00';
$handler->display->display_options['filters']['created']['group'] = 0;
$handler->display->display_options['path'] = 'admin/people/site-interaction';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Site interaction';
$handler->display->display_options['menu']['description'] = 'Custom user list';
$handler->display->display_options['menu']['weight'] = '2';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: New */
$handler = $view->new_display('page', 'New', 'page_new');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'People : New applicants';
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Last access */
$handler->display->display_options['filters']['access_1']['id'] = 'access_1';
$handler->display->display_options['filters']['access_1']['table'] = 'users';
$handler->display->display_options['filters']['access_1']['field'] = 'access';
$handler->display->display_options['filters']['access_1']['value']['value'] = '0';
$handler->display->display_options['filters']['access_1']['group'] = 0;
$handler->display->display_options['filters']['access_1']['expose']['operator_id'] = 'access_1_op';
$handler->display->display_options['filters']['access_1']['expose']['label'] = 'New users';
$handler->display->display_options['filters']['access_1']['expose']['operator'] = 'access_1_op';
$handler->display->display_options['filters']['access_1']['expose']['identifier'] = 'access_new';
$handler->display->display_options['filters']['access_1']['expose']['multiple'] = FALSE;
/* Filter criterion: Not anonymous */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'users';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['ui_name'] = 'Not anonymous';
$handler->display->display_options['filters']['created']['operator'] = '>';
$handler->display->display_options['filters']['created']['value']['value'] = '1980-01-01 00:00:00';
$handler->display->display_options['filters']['created']['group'] = 0;
/* Filter criterion: User: Created date */
$handler->display->display_options['filters']['created_1']['id'] = 'created_1';
$handler->display->display_options['filters']['created_1']['table'] = 'users';
$handler->display->display_options['filters']['created_1']['field'] = 'created';
$handler->display->display_options['filters']['created_1']['operator'] = '>';
$handler->display->display_options['filters']['created_1']['value']['value'] = '2011-10-01 00:00:00';
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '0';
$handler->display->display_options['filters']['status']['exposed'] = TRUE;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
$handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
$handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Roles */
$handler->display->display_options['filters']['rid']['id'] = 'rid';
$handler->display->display_options['filters']['rid']['table'] = 'users_roles';
$handler->display->display_options['filters']['rid']['field'] = 'rid';
$handler->display->display_options['filters']['rid']['operator'] = 'not';
$handler->display->display_options['filters']['rid']['value'] = array(
  7 => '7',
);
$handler->display->display_options['filters']['rid']['reduce_duplicates'] = 0;
$handler->display->display_options['path'] = 'admin/people/new-applicants';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'New';
$handler->display->display_options['menu']['description'] = 'Custom user list';
$handler->display->display_options['menu']['weight'] = '2';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Inactive */
$handler = $view->new_display('page', 'Inactive', 'page_inactive');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'People : Inactive';
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = FALSE;
$handler->display->display_options['header']['area']['content'] = '<p>To view users who have been inactive for more than 4 months enter -4 months in the filter below.</p>
<p>To view users who have been inactive for more than 3 months enter -3 months in the filter below.</p>
<p><strong>It would be advisable to deactivate those users who have been inactive for over 4 months prior to emailing those who have been inactive for only 3.</strong></p>';
$handler->display->display_options['header']['area']['format'] = 'html_full';
$handler->display->display_options['header']['area']['tokenize'] = 0;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
$handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
$handler->display->display_options['filters']['status']['expose']['remember'] = 1;
$handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
/* Filter criterion: User: Last access */
$handler->display->display_options['filters']['access']['id'] = 'access';
$handler->display->display_options['filters']['access']['table'] = 'users';
$handler->display->display_options['filters']['access']['field'] = 'access';
$handler->display->display_options['filters']['access']['operator'] = '<=';
$handler->display->display_options['filters']['access']['value']['value'] = '-4 months';
$handler->display->display_options['filters']['access']['value']['type'] = 'offset';
$handler->display->display_options['filters']['access']['group'] = 0;
$handler->display->display_options['filters']['access']['exposed'] = TRUE;
$handler->display->display_options['filters']['access']['expose']['operator_id'] = 'access_op';
$handler->display->display_options['filters']['access']['expose']['label'] = 'Last access was prior to';
$handler->display->display_options['filters']['access']['expose']['operator'] = 'access_op';
$handler->display->display_options['filters']['access']['expose']['identifier'] = 'access';
$handler->display->display_options['filters']['access']['expose']['multiple'] = FALSE;
/* Filter criterion: Not anonymous */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'users';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['ui_name'] = 'Not anonymous';
$handler->display->display_options['filters']['created']['operator'] = '>';
$handler->display->display_options['filters']['created']['value']['value'] = '1980-01-01 00:00:00';
$handler->display->display_options['filters']['created']['group'] = 0;
/* Filter criterion: User: Last access */
$handler->display->display_options['filters']['access_1']['id'] = 'access_1';
$handler->display->display_options['filters']['access_1']['table'] = 'users';
$handler->display->display_options['filters']['access_1']['field'] = 'access';
$handler->display->display_options['filters']['access_1']['operator'] = '!=';
$handler->display->display_options['filters']['access_1']['value']['value'] = '0';
$handler->display->display_options['path'] = 'admin/people/inactive';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Inactive';
$handler->display->display_options['menu']['description'] = 'Custom user list';
$handler->display->display_options['menu']['weight'] = '2';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Abusive */
$handler = $view->new_display('page', 'Abusive', 'page_abusive');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'People : Abusive users';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Flags: abusive_user */
$handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
$handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
$handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
$handler->display->display_options['relationships']['flag_content_rel']['label'] = 'abusive_user';
$handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'abusive_user';
$handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: User: Bulk operations */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
  'twoofakind_com_au_unblock_user_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'system_block_ip_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'twoofakind_com_au_abusive_user_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'user_block_user_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'twoofakind_com_au_deactivate_user_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'views_bulk_operations_delete_item' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'system_message_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'views_bulk_operations_script_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'views_bulk_operations_user_roles_action' => array(
    'selected' => 0,
    'use_queue' => 1,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'twoofakind_com_au_notify_admin_of_abusive_user_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'views_bulk_operations_argument_selector_action' => array(
    'selected' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'twoofakind_com_au_reactivate_user_action' => array(
    'selected' => 1,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'system_goto_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
  'system_send_email_action' => array(
    'selected' => 0,
    'use_queue' => 0,
    'skip_confirmation' => 0,
    'override_label' => 0,
    'label' => '',
  ),
);
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
$handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'Username';
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
$handler->display->display_options['fields']['name']['element_label_colon'] = 0;
$handler->display->display_options['fields']['name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
$handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['name']['link_to_user'] = 1;
$handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
/* Field: User: First name */
$handler->display->display_options['fields']['field_name_first']['id'] = 'field_name_first';
$handler->display->display_options['fields']['field_name_first']['table'] = 'field_data_field_name_first';
$handler->display->display_options['fields']['field_name_first']['field'] = 'field_name_first';
$handler->display->display_options['fields']['field_name_first']['label'] = 'Name';
$handler->display->display_options['fields']['field_name_first']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_name_first']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_name_first']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_name_first']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_name_first']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_name_first']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_name_first']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_name_first']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_name_first']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_name_first']['field_api_classes'] = 0;
/* Field: User: Last name */
$handler->display->display_options['fields']['field_name_last']['id'] = 'field_name_last';
$handler->display->display_options['fields']['field_name_last']['table'] = 'field_data_field_name_last';
$handler->display->display_options['fields']['field_name_last']['field'] = 'field_name_last';
$handler->display->display_options['fields']['field_name_last']['label'] = '';
$handler->display->display_options['fields']['field_name_last']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_name_last']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_name_last']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_name_last']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_name_last']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_name_last']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_name_last']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_name_last']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_name_last']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_name_last']['field_api_classes'] = 0;
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['label'] = 'Email';
$handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['mail']['alter']['external'] = 0;
$handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
$handler->display->display_options['fields']['mail']['alter']['html'] = 0;
$handler->display->display_options['fields']['mail']['element_label_colon'] = 0;
$handler->display->display_options['fields']['mail']['element_default_classes'] = 1;
$handler->display->display_options['fields']['mail']['hide_empty'] = 0;
$handler->display->display_options['fields']['mail']['empty_zero'] = 0;
$handler->display->display_options['fields']['mail']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['mail']['link_to_user'] = 0;
/* Field: User: Date of birth */
$handler->display->display_options['fields']['field_date_of_birth']['id'] = 'field_date_of_birth';
$handler->display->display_options['fields']['field_date_of_birth']['table'] = 'field_data_field_date_of_birth';
$handler->display->display_options['fields']['field_date_of_birth']['field'] = 'field_date_of_birth';
$handler->display->display_options['fields']['field_date_of_birth']['label'] = 'DOB / Age';
$handler->display->display_options['fields']['field_date_of_birth']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_date_of_birth']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_date_of_birth']['settings'] = array(
  'format_type' => 'short',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
$handler->display->display_options['fields']['field_date_of_birth']['field_api_classes'] = 0;
/* Field: User: Date of birth */
$handler->display->display_options['fields']['field_date_of_birth_1']['id'] = 'field_date_of_birth_1';
$handler->display->display_options['fields']['field_date_of_birth_1']['table'] = 'field_data_field_date_of_birth';
$handler->display->display_options['fields']['field_date_of_birth_1']['field'] = 'field_date_of_birth';
$handler->display->display_options['fields']['field_date_of_birth_1']['label'] = 'Age';
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['alter']['html'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_date_of_birth_1']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_date_of_birth_1']['type'] = 'age';
$handler->display->display_options['fields']['field_date_of_birth_1']['settings'] = array(
  'format_type' => 'long',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
$handler->display->display_options['fields']['field_date_of_birth_1']['field_api_classes'] = 0;
/* Field: User: Active */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'users';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['status']['alter']['external'] = 0;
$handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['status']['alter']['trim'] = 0;
$handler->display->display_options['fields']['status']['alter']['html'] = 0;
$handler->display->display_options['fields']['status']['element_label_colon'] = 0;
$handler->display->display_options['fields']['status']['element_default_classes'] = 1;
$handler->display->display_options['fields']['status']['hide_empty'] = 0;
$handler->display->display_options['fields']['status']['empty_zero'] = 0;
$handler->display->display_options['fields']['status']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: User: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'users';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Member for';
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
/* Field: User: Last access */
$handler->display->display_options['fields']['access']['id'] = 'access';
$handler->display->display_options['fields']['access']['table'] = 'users';
$handler->display->display_options['fields']['access']['field'] = 'access';
$handler->display->display_options['fields']['access']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['access']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['access']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['access']['alter']['external'] = 0;
$handler->display->display_options['fields']['access']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['access']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['access']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['access']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['access']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['access']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['access']['alter']['trim'] = 0;
$handler->display->display_options['fields']['access']['alter']['html'] = 0;
$handler->display->display_options['fields']['access']['element_label_colon'] = 0;
$handler->display->display_options['fields']['access']['element_default_classes'] = 1;
$handler->display->display_options['fields']['access']['hide_empty'] = 0;
$handler->display->display_options['fields']['access']['empty_zero'] = 0;
$handler->display->display_options['fields']['access']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['access']['date_format'] = 'raw time ago';
/* Field: User: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'users';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
$handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
$handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
$handler->display->display_options['fields']['edit_node']['element_label_colon'] = 0;
$handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
$handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
$handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
$handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 0;
/* Field: User: Admin notes */
$handler->display->display_options['fields']['field_admin_notes']['id'] = 'field_admin_notes';
$handler->display->display_options['fields']['field_admin_notes']['table'] = 'field_data_field_admin_notes';
$handler->display->display_options['fields']['field_admin_notes']['field'] = 'field_admin_notes';
$handler->display->display_options['fields']['field_admin_notes']['label'] = 'Notes';
$handler->display->display_options['fields']['field_admin_notes']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['alter']['external'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['alter']['max_length'] = '150';
$handler->display->display_options['fields']['field_admin_notes']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['field_admin_notes']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['field_admin_notes']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['alter']['trim'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['alter']['html'] = 1;
$handler->display->display_options['fields']['field_admin_notes']['element_label_colon'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['element_default_classes'] = 1;
$handler->display->display_options['fields']['field_admin_notes']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['hide_alter_empty'] = 0;
$handler->display->display_options['fields']['field_admin_notes']['group_rows'] = 1;
$handler->display->display_options['fields']['field_admin_notes']['delta_limit'] = '1';
$handler->display->display_options['fields']['field_admin_notes']['delta_offset'] = '0';
$handler->display->display_options['fields']['field_admin_notes']['delta_reversed'] = 1;
$handler->display->display_options['fields']['field_admin_notes']['field_api_classes'] = 0;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Not anonymous */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'users';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['ui_name'] = 'Not anonymous';
$handler->display->display_options['filters']['created']['operator'] = '>';
$handler->display->display_options['filters']['created']['value']['value'] = '1980-01-01 00:00:00';
$handler->display->display_options['filters']['created']['group'] = 0;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '1';
$handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
$handler->display->display_options['filters']['status']['expose']['use_operator'] = FALSE;
$handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
$handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
$handler->display->display_options['filters']['status']['expose']['multiple'] = FALSE;
$handler->display->display_options['path'] = 'admin/people/abusive';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Abusive';
$handler->display->display_options['menu']['description'] = 'Custom user list';
$handler->display->display_options['menu']['weight'] = '20';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Reactivate */
$handler = $view->new_display('page', 'Reactivate', 'page_reactivate');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'People : To reactivate';
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Not anonymous */
$handler->display->display_options['filters']['created']['id'] = 'created';
$handler->display->display_options['filters']['created']['table'] = 'users';
$handler->display->display_options['filters']['created']['field'] = 'created';
$handler->display->display_options['filters']['created']['ui_name'] = 'Not anonymous';
$handler->display->display_options['filters']['created']['operator'] = '>';
$handler->display->display_options['filters']['created']['value']['value'] = '1980-01-01 00:00:00';
$handler->display->display_options['filters']['created']['group'] = 0;
/* Filter criterion: User: Roles */
$handler->display->display_options['filters']['rid']['id'] = 'rid';
$handler->display->display_options['filters']['rid']['table'] = 'users_roles';
$handler->display->display_options['filters']['rid']['field'] = 'rid';
$handler->display->display_options['filters']['rid']['operator'] = 'and';
$handler->display->display_options['filters']['rid']['value'] = array(
  6 => '6',
  7 => '7',
);
$handler->display->display_options['filters']['rid']['reduce_duplicates'] = 1;
/* Filter criterion: User: Active */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'users';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = '0';
$handler->display->display_options['path'] = 'admin/people/reactivate';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Reactivate';
$handler->display->display_options['menu']['description'] = 'Custom user list';
$handler->display->display_options['menu']['weight'] = '20';
$handler->display->display_options['tab_options']['weight'] = '0';

return $view;

}