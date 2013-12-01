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


if($vars['block']->region == 'right'){
  // dsm($vars);
  switch ($vars['block']->bid){
    case 500:
      // WHAT'S HAPPENING NOW
      $vars['title'] .= '<span class="firstblock-bird"></span>';
      break;
    case 505:
      // BIRDS EYE VIEW
      $vars['title'] .= '<span class="firstblock-bird"></span>';
      break;
    case 502:
      // BIRDS OF A FEATHER
      $vars['title'] .= '<span class="firstblock-bird"></span>';
      break;
  }
}


$vars['block']->subject = module_invoke('typogrify', 'filter', 'process', null, 3, $vars['block']->subject);

// add jquery_ui accordian for blog archive
if($vars['module'] == 'views' && $vars['delta'] == 'Birdfeed-block_2'){
	if(module_exists('jquery_ui')){
		jquery_ui_add(array('ui.accordion', 'effects.core'));
		drupal_add_js(path_to_theme() .'/js/blog-archive-accordian.jquery.js', 'theme');
		$vars['scripts'] = drupal_get_js();
	}
}
$vars['scripts'] = drupal_get_js();

// kpr($vars);