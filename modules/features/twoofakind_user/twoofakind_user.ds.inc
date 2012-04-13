<?php
/**
 * @file
 * twoofakind_user.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function twoofakind_user_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|default';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'ds_user_picture' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_picture_profile_main',
    ),
    'favourite' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'featured_user' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'wink' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'abusive_user_webform' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'privatemsg' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'age' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'location_city' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['user|user|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function twoofakind_user_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'group_actions',
        1 => 'field_headline',
        2 => 'favourite',
        3 => 'wink',
        4 => 'privatemsg',
        5 => 'featured_user',
        6 => 'abusive_user_webform',
      ),
      'left' => array(
        0 => 'ds_user_picture',
        1 => 'group_basics_one',
        2 => 'group_basics_two',
        3 => 'group_appearance',
        4 => 'field_relation_status',
        5 => 'field_star_sign',
        6 => 'group_religion',
        7 => 'field_height',
        8 => 'field_personality',
        9 => 'group_habits',
        10 => 'field_body_type',
        11 => 'group_relationships',
        12 => 'field_eye_colour',
        13 => 'group_other',
        14 => 'field_hair_colour',
        15 => 'age',
        16 => 'field_sex',
        17 => 'location_city',
        18 => 'field_relig_affiliation',
        19 => 'field_smoker',
        20 => 'field_kosher',
        21 => 'field_drinking',
        22 => 'field_have_kids',
        23 => 'field_want_kids',
        24 => 'field_have_pets',
        25 => 'field_other_pet',
        26 => 'field_education',
        27 => 'field_industry',
        28 => 'field_political',
        29 => 'field_languages',
        30 => 'field_other_language',
      ),
      'right' => array(
        0 => 'field_self_summary',
        1 => 'field_friend_summary',
        2 => 'field_passionate_about',
        3 => 'field_images',
      ),
    ),
    'fields' => array(
      'group_actions' => 'header',
      'field_headline' => 'header',
      'ds_user_picture' => 'left',
      'favourite' => 'header',
      'group_basics_one' => 'left',
      'wink' => 'header',
      'privatemsg' => 'header',
      'group_basics_two' => 'left',
      'group_appearance' => 'left',
      'featured_user' => 'header',
      'field_relation_status' => 'left',
      'field_star_sign' => 'left',
      'group_religion' => 'left',
      'field_height' => 'left',
      'field_personality' => 'left',
      'group_habits' => 'left',
      'field_body_type' => 'left',
      'abusive_user_webform' => 'header',
      'group_relationships' => 'left',
      'field_eye_colour' => 'left',
      'group_other' => 'left',
      'field_self_summary' => 'right',
      'field_hair_colour' => 'left',
      'field_friend_summary' => 'right',
      'field_passionate_about' => 'right',
      'age' => 'left',
      'field_images' => 'right',
      'field_sex' => 'left',
      'location_city' => 'left',
      'field_relig_affiliation' => 'left',
      'field_smoker' => 'left',
      'field_kosher' => 'left',
      'field_drinking' => 'left',
      'field_have_kids' => 'left',
      'field_want_kids' => 'left',
      'field_have_pets' => 'left',
      'field_other_pet' => 'left',
      'field_education' => 'left',
      'field_industry' => 'left',
      'field_political' => 'left',
      'field_languages' => 'left',
      'field_other_language' => 'left',
    ),
    'classes' => array(),
  );
  $export['user|user|default'] = $ds_layout;

  return $export;
}
