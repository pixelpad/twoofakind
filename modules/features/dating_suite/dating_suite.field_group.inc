<?php
/**
 * @file
 * dating_suite.field_group.inc
 */

/**
 * Implementation of hook_field_group_info().
 */
function dating_suite_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_appearance|user|user|form';
  $field_group->group_name = 'group_appearance';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Appearance',
    'weight' => '6',
    'children' => array(
      0 => 'field_body_type',
      1 => 'field_eye_colour',
      2 => 'field_hair_colour',
      3 => 'field_height',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Appearance',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_appearance|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|user|user|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '4',
    'children' => array(
      0 => 'field_dob',
      1 => 'field_headline',
      2 => 'field_personality',
      3 => 'field_sex',
      4 => 'field_star_sign',
      5 => 'field_user_location',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_basics|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_habits|user|user|form';
  $field_group->group_name = 'group_habits';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Habits',
    'weight' => '8',
    'children' => array(
      0 => 'field_drinking',
      1 => 'field_smoker',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Habits',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_habits|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_match_appearance|user|user|form';
  $field_group->group_name = 'group_match_appearance';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_match';
  $field_group->data = array(
    'label' => 'Match appearance',
    'weight' => '20',
    'children' => array(
      0 => 'field_match_eye_colour',
      1 => 'field_match_hair_colour',
      2 => 'field_match_height',
      3 => 'field_match_body_type',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Match appearance',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_match_appearance|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_match_basics|user|user|form';
  $field_group->group_name = 'group_match_basics';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_match';
  $field_group->data = array(
    'label' => 'Match basics',
    'weight' => '19',
    'children' => array(
      0 => 'field_match_sex',
      1 => 'field_match_star_sign',
      2 => 'field_match_personality',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Match basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_match_basics|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_match_habits|user|user|form';
  $field_group->group_name = 'group_match_habits';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_match';
  $field_group->data = array(
    'label' => 'Match habits',
    'weight' => '22',
    'children' => array(
      0 => 'field_match_smoker',
      1 => 'field_match_drinking',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_match_habits|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_match_relationships|user|user|form';
  $field_group->group_name = 'group_match_relationships';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_match';
  $field_group->data = array(
    'label' => 'Match relationships',
    'weight' => '23',
    'children' => array(
      0 => 'field_match_have_kids',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_match_relationships|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_match_religion|user|user|form';
  $field_group->group_name = 'group_match_religion';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs_match';
  $field_group->data = array(
    'label' => 'Match religion',
    'weight' => '21',
    'children' => array(
      0 => 'field_match_relig_affiliation',
      1 => 'field_match_kosher',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_match_religion|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|user|user|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Pics',
    'weight' => '5',
    'children' => array(
      0 => 'field_images',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_media|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_other|user|user|form';
  $field_group->group_name = 'group_other';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'The rest',
    'weight' => '10',
    'children' => array(
      0 => 'field_education',
      1 => 'field_industry',
      2 => 'field_languages',
      3 => 'field_other_language',
      4 => 'field_political',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'The rest',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_other|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_privacy|user|user|form';
  $field_group->group_name = 'group_privacy';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Privacy settings',
    'weight' => '3',
    'children' => array(
      0 => 'field_online',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_privacy|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relationships|user|user|form';
  $field_group->group_name = 'group_relationships';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Relationships',
    'weight' => '9',
    'children' => array(
      0 => 'field_have_kids',
      1 => 'field_have_pets',
      2 => 'field_other_pet',
      3 => 'field_relation_status',
      4 => 'field_want_kids',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Relationships',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_relationships|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_religion|user|user|form';
  $field_group->group_name = 'group_religion';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Religion',
    'weight' => '7',
    'children' => array(
      0 => 'field_kosher',
      1 => 'field_relig_affiliation',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Religion',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_religion|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs_match|user|user|form';
  $field_group->group_name = 'group_tabs_match';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs match',
    'weight' => '2',
    'children' => array(
      0 => 'group_match_basics',
      1 => 'group_match_appearance',
      2 => 'group_match_religion',
      3 => 'group_match_habits',
      4 => 'group_match_relationships',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => NULL,
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabs_match|user|user|form'] = $field_group;

  $field_group = new stdClass;
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|user|user|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_media',
      1 => 'group_basics',
      2 => 'group_religion',
      3 => 'group_habits',
      4 => 'group_relationships',
      5 => 'group_other',
      6 => 'group_appearance',
      7 => 'group_more',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabs|user|user|form'] = $field_group;

  return $export;
}
