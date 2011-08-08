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


$slide = theme_get_setting('slide_shows');

if (!$slide or $slide == 0) { 
	drupal_add_js('
    
Drupal.behaviors.slideshow = function(context) {
  
  if ($(\'#Slides\').length > 0) {
    $(\'#Slides\').cycle({ 
      fx: \'scrollHorz\',
      speed: 750,
      timeout: 6000, 
      randomizeEffects: false, 
      easing: \'easeOutCubic\',
      next:   \'.slideNext\', 
      prev:   \'.slidePrev\',
      pager:  \'#slidePager\',
      cleartypeNoBg: true
    });
  }

};

	', 'inline');
}

if ($slide == 1) { 
	drupal_add_js($path . '/js/galleryview/jquery.timers-1.1.2.js');
	drupal_add_js($path . '/js/galleryview/jquery.galleryview-2.0-pack.js');
	drupal_add_js('
    
Drupal.behaviors.slideshow = function(context) {

  if ($(\'#GalleryView\').length > 0) {
    $(\'#GalleryView\').galleryView({
      show_panels: true,
      show_filmstrip: true,
      panel_width: 938,
      panel_height: 340,
      frame_width: 87,
      frame_height: 45,
      frame_gap: 8,
      pointer_size: 16,
      pause_on_hover: true,
      filmstrip_position: \'bottom\',
      overlay_position: \'bottom\',
      nav_theme: \'dark\',
      transition_speed: 800,
      transition_interval: 4000
    });
  }
      
};
    
	', 'inline');
	drupal_add_css($path . '/css/galleryview.min.css', array('group' => CSS_THEME, 'browsers' => array('IE' => true, '!IE' => true), 'preprocess' => FALSE));
} 

drupal_add_css($path . '/css/ie-only.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lt IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
drupal_add_css($path . '/css/ie-only-all-versions.css', array('group' => CSS_THEME, 'browsers' => array('IE' => true, '!IE' => FALSE), 'preprocess' => FALSE));

//drupal_add_js($path . '/js/pngFix.min.js');
//drupal_add_js('$(document).ready(function(){$(document.body).supersleight();}); ', 'inline');

