<?php
/**
 * @file
 * dating_suite.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function dating_suite_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_match';
  $strongarm->value = 'edit-page-title';
  $export['additional_settings__active_tab_match'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_privatemsg_current_day';
  $strongarm->value = 'g:i a';
  $export['date_format_privatemsg_current_day'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_privatemsg_current_year';
  $strongarm->value = 'M j';
  $export['date_format_privatemsg_current_year'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_privatemsg_years';
  $strongarm->value = 'n/j/y';
  $export['date_format_privatemsg_years'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_success_story';
  $strongarm->value = '[current-page:page-title] | Success Story | [site:name] | [site:slogan]';
  $export['page_title_type_success_story'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_success_story_showfield';
  $strongarm->value = 0;
  $export['page_title_type_success_story_showfield'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_success_story_pattern';
  $strongarm->value = 'success/[node:title]';
  $export['pathauto_node_success_story_pattern'] = $strongarm;

  return $export;
}
