<?php

// we have to add our own css here so it overwrites the previous
// @TODO - there will be a better method than this, find it!
drupal_add_css(path_to_theme().'/css/twoofakind-custom-style.css', array('group' => CSS_THEME));

/*
 * implements template_preprocess_page
 * 
 * We want to add some JS if within user edit screen
 */
function twoofakind_custom_preprocess_page(&$variables) {
  
  if (in_array('page__user__edit', $variables['theme_hook_suggestions'])) {
    drupal_add_js(drupal_get_path('theme', 'twoofakind_custom') . '/js/jquery.FormNavigate.js', 'file');
  }
  
}

/*
 * implements theme_menu_tree__menu_user_major_actions
 * 
 * @see theme_menu_tree
 */
function twoofakind_custom_menu_tree__menu_user_major_actions($variables) {
  return '<div id="block-menu-user-major-actions"><ul>' . $variables['tree'] . '</ul></div>';
}

/*
 * implements theme_menu_link__menu_user_major_actions
 * 
 * @see theme_menu_link
 */
function twoofakind_custom_menu_link__menu_user_major_actions($variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  
  // add some localised options
  if (!isset($element['#localized_options']['attributes'])) {
    $element['#localized_options']['attributes'] = array();
  }
  if (!isset($element['#localized_options']['attributes']['class'])) {
    $element['#localized_options']['attributes']['class'] = array();
  }
  $element['#localized_options']['attributes']['class'][] = 'btn';
  $element['#localized_options']['html'] = TRUE;
  
  $output = l('<span>' . $element['#title'] . '</span>', $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/*
 * implements theme_menu_tree__menu_footer_other
 * 
 * @see theme_menu_tree
 */
function twoofakind_custom_menu_tree__menu_footer_other($variables) {
  return '<div id="block-menu-footer-other"><ul>' . $variables['tree'] . '</ul></div>';
}

/**
 * Process variables for user-profile.tpl.php.
 *
 * The $variables array contains the following arguments:
 * - $account
 *
 * @see user-profile.tpl.php
 */
function twoofakind_custom_preprocess_user_picture(&$variables) {

  $account = $variables['account'];
  
  // modify the user_picture variable
  if (isset($account->content['view_mode']) && $account->content['view_mode']['#markup'] == 'full') {
    
    // only if the view_mode is full
  
    // init variable
    $variables['user_picture_alternate'] = '';

    // generate relevant image style paths
    if (isset($account->picture->uri) && !empty($account->picture->uri)) {
      
      $url_profile_main = image_style_url('profile_main', $account->picture->uri);
      $url_large = image_style_url('large', $account->picture->uri);

      // build image
      $attributes = array(
        'alt' => $account->name,
        'title' => $account->name
      );
      $image = theme('image', array('path' => $url_profile_main, 'attributes' => $attributes));

      // build link
      $options = array(
        'attributes' => array(
          'class' => array(
            'active',
            'colorbox',
            'imagefield',
            'imagefield-imagelink'
          ),
          'rel' => 'gallery-nid',
          'title' => $account->name
        ),
        'html' => TRUE
      );
      $link = l($image, $url_large, $options);

      // replace current content with your own link
      // replacing the user_picture doesn't always work
      $variables['user_picture'] = $link;
      // NOTE - if it doesn't alternate variables won't work
      // only user_picture and account are passed to the template file
//      $variables['user_picture_alternate'] = $link;
      // so, you can use this if the first one doesn't work
//      $variables['account']->content['user_picture_alternate'] = $link;

    }
    
  }
  
}

/**
 * Theme buttons for this template
 */
//function twoofakind_custom_button($variables) {
//
//  $element = $variables['element'];
//  element_set_attributes($element, array('id', 'name', 'value'));
//
//  $output = array();
//  $output[] = '<button value="' . $element['#value'] . '" type="submit" class="form-submit btn" id="' . $element['#id'] . '">';
//  $output[] = '<span style="margin-top: -1px;">' . $element['#value'] . '</span>';
//  $output[] = '</button>';
//
//  return implode("\n", $output);
//}