<?php

// we have to add our own css here so it overwrites the previous
drupal_add_css(path_to_theme().'/css/twoofakind-custom-style.css', array('group' => CSS_THEME));

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