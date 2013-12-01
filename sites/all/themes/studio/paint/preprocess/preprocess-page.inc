<?php
/* $Id: preprocess-page.inc,v 1.2 2009/04/16 17:29:54 zarabadoo Exp $ */

/**
 * Implementation of the preprocess function.
 *
 * @return $vars
 * @param $vars Object
 */
// Create classes for the body tag based on the number of sidebars.
switch(TRUE) {
  case($vars['left'] && $vars['right']):
    $vars['body_attributes']['class'][] = 'both-sidebars';
    break;
  case($vars['left']):
    $vars['body_attributes']['class'][] = 'left-sidebar';
    break;
  case($vars['right']):
    $vars['body_attributes']['class'][] = 'right-sidebar';
    break;
  default:
    $vars['body_attributes']['class'][] = 'no-sidebars';
    break;
}

// Crunch all our body tag's attributes into a single string.
$vars['attributes'] = theme('render_attributes', $vars['body_attributes']);

// Append Internet Explorer specific stylesheets to the $styles variable.
$vars['ie_styles'] = array(
  'lte IE 6' => array(
    'screen' => array(
      path_to_theme() . '/css/lte-ie6.css',
    ),
  ),
);
$vars['styles'] .= theme('ie_styles', $vars['ie_styles']);
