<?php


function unitebusiness_form_system_theme_settings_alter(&$form, $form_state) {

  $form['advansed_theme_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advansed Theme Settings'),
  );

  $form['advansed_theme_settings']['skin'] = array(
    '#type' => 'select',
    '#title' => t('Theme Skin'),
    '#default_value' => theme_get_setting('skin'),
    '#options' => array (
      0 => t('Skin 1'),
	  1 => t('Skin 2'),
	  2 => t('Skin 3'),
	  3 => t('Skin 4'),
	  4 => t('Skin 5'),
    ),
  );
  
  $form['advansed_theme_settings']['slide_shows'] = array(
    '#type' => 'select',
    '#title' => t('Slide Shows'),
    '#default_value' => theme_get_setting('slide_shows'),
    '#options' => array (
      0 => t('Cycle'),
	  1 => t('Gallery'),
    ),
  );
}
