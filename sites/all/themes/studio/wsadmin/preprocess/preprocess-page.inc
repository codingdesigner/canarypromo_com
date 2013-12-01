<?php
/**
 * Implementation of the preprocess function.
 *
 * @return $vars
 * @param $vars Object
 */
// Create classes for the body tag based on the number of sidebars.
switch(TRUE) {
  case($vars['left']):
    $vars['body_attributes']['class'][] = 'left-sidebar';
    break;
  default:
    $vars['body_attributes']['class'][] = 'no-sidebars';
    break;
}

// Crunch all our body tag's attributes into a single string.
$vars['attributes'] = theme('render_attributes', $vars['body_attributes']);

// Append Internet Explorer specific stylesheets to the $styles variable.
$vars['ie_styles'] = array(
  'lt IE 7' => array(
    'screen, projector' => array(
      path_to_theme() . '/css/lte-ie7.css',
    ),
  ),
);

$vars['styles'] .= theme('ie_styles', $vars['ie_styles']);

