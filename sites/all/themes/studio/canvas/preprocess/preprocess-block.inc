<?php
// $Id: preprocess-block.inc,v 1.3 2009/04/20 18:55:22 zarabadoo Exp $

/**
 * Implementation of theme_preprocess_HOOK().
 * Passes variables to the block templates.
 *
 * @return $vars
 */

// Simplify the content output in the tpl file by giving variables simpler 
// names like the other bits of content in Drupal.
$vars['title'] = $vars['block']->subject;
$vars['content'] = $vars['block']->content;
$vars['module'] = $vars['block']->module;
$vars['delta'] = $vars['block']->delta;
$vars['region'] = $vars['block']->region;

// Prepare the variables that will store the attributes while being processed.
if(!$vars['block']->attributes) {
  $vars['block_attributes'] = array();
}
else {
  $vars['block_attributes'] = $vars['block']->attributes;
}

$vars['block_attributes']['class'][] = 'block';

// Add an id for specific block styling.
$vars['block_attributes']['id'] = 'block-' . $vars['module'] . '-' . $vars['delta'];

// Add a class to allow for styling of blocks in a specific region.
$vars['block_attributes']['class'][] = $vars['region'] . '-region';

// Add a class to allow for styling of blocks produced by a specific module. 
$vars['block_attributes']['class'][] = $vars['module'] . '-block';

// Add a class to allow for specific styling of odd and even blocks.
$vars['block_attributes']['class'][] = $vars['zebra'];

// Make block containers self-clearing.
$vars['block_attributes']['class'][] = 'clear-block';

// Crunch all attributes into a single string to be added to the block 
// container. 
$vars['attributes'] = theme('render_attributes', $vars['block_attributes']);
