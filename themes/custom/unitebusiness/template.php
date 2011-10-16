<?php
// $Id$

$style = theme_get_setting('skin');
$path = drupal_get_path('theme', 'unitebusiness');

switch ($style) {
	case 0:
		drupal_add_css($path.'/css/skins/skin-1.css', array('group' => CSS_THEME));
		break;
	case 1:
		drupal_add_css($path.'/css/skins/skin-2.css', array('group' => CSS_THEME));
		break;
	case 2:
		drupal_add_css($path.'/css/skins/skin-3.css', array('group' => CSS_THEME));
		break;
	case 3:
		drupal_add_css($path.'/css/skins/skin-4.css', array('group' => CSS_THEME));
		break;
	case 4:
		drupal_add_css($path.'/css/skins/skin-5.css', array('group' => CSS_THEME));
		break;
	default:
		drupal_add_css($path.'/css/skins/skin-1.css', array('group' => CSS_THEME));
}

drupal_add_css($path . '/css/ie-only.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lt IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
drupal_add_css($path . '/css/ie-only-all-versions.css', array('group' => CSS_THEME, 'browsers' => array('IE' => true, '!IE' => FALSE), 'preprocess' => FALSE));

//drupal_add_js($path . '/js/pngFix.min.js');
//drupal_add_js('$(document).ready(function(){$(document.body).supersleight();}); ', 'inline');

