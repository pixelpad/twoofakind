<?php
/**
 * @file
 * simple_site_benefit.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function simple_site_benefit_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_simple_site_benefit';
  $strongarm->value = '';
  $export['additional_settings__active_tab_simple_site_benefit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_simple_site_benefit';
  $strongarm->value = array();
  $export['menu_options_simple_site_benefit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_simple_site_benefit';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_simple_site_benefit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_simple_site_benefit';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_simple_site_benefit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_simple_site_benefit';
  $strongarm->value = '1';
  $export['node_preview_simple_site_benefit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_simple_site_benefit';
  $strongarm->value = 0;
  $export['node_submitted_simple_site_benefit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_simple_site_benefit';
  $strongarm->value = '[current-page:page-title] | Benefit | [site:name] | [site:slogan]';
  $export['page_title_type_simple_site_benefit'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_simple_site_benefit_showfield';
  $strongarm->value = 0;
  $export['page_title_type_simple_site_benefit_showfield'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_simple_site_benefit_pattern';
  $strongarm->value = 'benefit/[node:title]';
  $export['pathauto_node_simple_site_benefit_pattern'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_simple_site_benefit';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_simple_site_benefit'] = $strongarm;

  return $export;
}
