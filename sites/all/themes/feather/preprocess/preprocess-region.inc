<?php
// $Id: preprocess-region.inc,v 1.3 2009/04/20 17:15:17 zarabadoo Exp $
// Add extra classes for the left and right sidebars.
if($vars['region']->name == 'left' || $vars['region']->name == 'right'){
  $vars['region_attributes']['class'][] = 'column';
  $vars['region_attributes']['class'][] = 'sidebar';
  $vars['region_attributes']['class'][] = 'clear-block';
}

// Process the classes and ids into a string.
$vars['attributes'] = theme('render_attributes', $vars['region_attributes']);