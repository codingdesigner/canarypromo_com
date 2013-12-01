<?php
/* $Id: preprocess-page.inc,v 1.2 2009/04/16 17:29:54 zarabadoo Exp $ */

/**
 * Implementation of the preprocess function.
 *
 * @return $vars
 * @param $vars Object
 */
//set pretitle
switch(TRUE){
	case($vars['node']->type == 'press_mention'):
	  $vars['pre_title'] = 'Press Mention';
	  break;
	case($vars['node']->type == 'event'):
	  $vars['pre_title'] = 'Event';
	  break;
	case($vars['node']->type == 'press_release'):
	  $vars['pre_title'] = 'Press Release';
	  break;
	case($vars['node']->type == 'testimonial'):
	  $vars['pre_title'] = 'Testimonial';
	  break;
	case($vars['node']->type == 'blog'):
	  $vars['pre_title'] = 'Birdfeed';
	  break;
  case($vars['node']->type == 'case_study'):
	  $vars['pre_title'] = 'Case Study';
	  break;
}

// set subtitle
if(strlen($vars['node']->field_subtitle[0]['value']) > 0){
	$vars['subtitle'] = $vars['node']->field_subtitle[0]['value'];
}

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

// // set body classes based on pretitles and subtitles
// switch(TRUE){
// 	case($vars['pre_title'] && $vars['subtitle']):
// 	  $vars['body_attributes']['class'][] = 'pretitle-subtitle';
// 	  break;
// 	case($vars['pre_title']):
// 	  $vars['body_attributes']['class'][] = 'pretitle';
// 	  break;
// 	case($vars['subtitle']):
// 	  $vars['body_attributes']['class'][] = 'subtitle';
// 	  break;
// }


// check for 'featureimage' block and set body id to style tall and short headers
if(strstr($vars['featureimage'], '<img')){
	$vars['body_attributes']['class'][] = 'has-featureimage';
}else{
	$vars['body_attributes']['class'][] = 'no-featureimage';
	unset($vars['featureimage']);
}
//kpr($vars);

// check to see if this pages uses panels
if(strpos($vars['content'], 'panel-2col')){
	$vars['body_attributes']['class'][] = 'panel-2col';
}

// check for a long title and set a body class
if(strlen($vars['title']) > 55){
  $vars['body_attributes']['class'][] = 'long-title';
}


// Crunch all our body tag's attributes into a single string.
$vars['attributes'] = theme('render_attributes', $vars['body_attributes']);

// Append Internet Explorer specific stylesheets to the $styles variable.
$vars['ie_styles'] = array(
  'IE' => array(
    'screen' => array(
      path_to_theme() . '/css/ie.css',
    ),
  ),
  'lte IE 6' => array(
    'screen' => array(
      path_to_theme() . '/css/ie6.css',
    ),
  ),
);
$vars['styles'] .= theme('ie_styles', $vars['ie_styles']);


// Use Typogrify on titles
$vars['old_title'] = $vars['title'];
$vars['title'] = module_invoke('typogrify', 'filter', 'process', null, 3, $vars['title']);

// set a link (to the blog) for the page title on the front page
if(feather_in_array('page-front', $vars['template_files'])){
  $options = array(
    'html' => TRUE,
  );
  $vars['title'] = l($vars['title'], 'birdfeed', $options);
}

// kpr($vars);