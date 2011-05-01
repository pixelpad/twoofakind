<?php
/**
 * @file
 * two_of_a_kind_conf.box.inc
 */

/**
 * Implementation of hook_default_box().
 */
function two_of_a_kind_conf_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'welcome';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Welcome block';
  $box->options = array(
    'body' => array(
      'value' => '<h1 class="headline">Welcome to <strong>Two of a Kind</strong>, find your <strong>Jewish pair</strong></h1>
<p class="impact">Suspendisse quis nibh et enim convallis tempor sit amet suscipit lorem. Phasellus cursus bibendum odio, nec feugiat dui venenatis id. In scelerisque felis ac augue feugiat suscipit. Nulla aliquam tristique felis, vitae commodo mauris consectetur ac. Aliquam vestibulum ligula sed lectus malesuada elementum. Duis dolor metus, pretium eget pellentesque eu, gravida vel risus.</p>
',
      'format' => 'html_full',
    ),
  );
  $export['welcome'] = $box;

  return $export;
}
