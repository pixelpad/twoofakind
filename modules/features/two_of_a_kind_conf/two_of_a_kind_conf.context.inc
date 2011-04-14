<?php
/**
 * @file
 * two_of_a_kind_conf.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function two_of_a_kind_conf_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'Home Anonymous';
  $context->description = 'Home page for anonymous users';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-slide_shows-block_1' => array(
          'module' => 'views',
          'delta' => 'slide_shows-block_1',
          'region' => 'slide_shows',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home page for anonymous users');
  t('home');
  $export['Home Anonymous'] = $context;

  return $export;
}
