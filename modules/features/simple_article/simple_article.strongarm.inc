<?php
/**
 * @file
 * simple_article.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function simple_article_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_simple_article';
  $strongarm->value = 'edit-scheduler';
  $export['additional_settings__active_tab_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_simple_article';
  $strongarm->value = 0;
  $export['comment_anonymous_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_simple_article';
  $strongarm->value = 1;
  $export['comment_default_mode_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_simple_article';
  $strongarm->value = '50';
  $export['comment_default_per_page_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_simple_article';
  $strongarm->value = 1;
  $export['comment_form_location_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_simple_article';
  $strongarm->value = '0';
  $export['comment_preview_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_simple_article';
  $strongarm->value = '2';
  $export['comment_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_simple_article';
  $strongarm->value = 1;
  $export['comment_subject_field_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_simple_article';
  $strongarm->value = array();
  $export['menu_options_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_simple_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_simple_article';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_simple_article';
  $strongarm->value = '1';
  $export['node_preview_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_simple_article';
  $strongarm->value = 1;
  $export['node_submitted_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_simple_article';
  $strongarm->value = '[current-page:page-title] | News | [site:slogan] | [site:name]';
  $export['page_title_type_simple_article'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_simple_article_showfield';
  $strongarm->value = 0;
  $export['page_title_type_simple_article_showfield'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_simple_article_pattern';
  $strongarm->value = 'news/[node:title]';
  $export['pathauto_node_simple_article_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_simple_article';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_simple_article'] = $strongarm;

  return $export;
}
