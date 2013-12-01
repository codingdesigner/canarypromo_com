<?php
// $Id: theme-custom.inc,v 1.3 2009/04/20 17:15:16 zarabadoo Exp $

/**
 * Creates a set of stylesheets only visible by various versions of Internet
 * Explorer. You can add a single stylesheet for all versions of IE and all
 * media, or you can provide an array covering multiple versions of the browser
 * and various media types.
 *
 * The structure of the array is as follows:
 *
 *  - The condition as the key. (i.e., 'lt IE 7')
 *    - Media type as the key. (i.e., 'all' or 'screen')
 *      - The path to the stylesheet. The path to the stylsheet is relative to
 *        the base_path() of the site. Do not add a preceding slash as the
 *        system will take care of that for you.
 *        (i.e., 'sites/all/canvas/css/ie.css')
 *
 * @return
 * @param $styles Object
 */
function canvas_ie_styles($styles){
  $output = '';
  if(is_array($styles)) {
    foreach($styles as $condition => $sheets) {
      $output .= theme('ie_conditional', $condition, $sheets);
    }
  }
  elseif(is_string($styles)) {
    $sheets[all] = $styles;
    $output .= theme('ie_conditional', $condition, $sheets);
  }

  return $output;
}

/**
 * Returns a conditional statement for Internet Explorer browsers.
 *
 * @return
 * @param $condition Object
 * @param $sheets Object
 */
function canvas_ie_conditional($condition, $sheets) {
  $output = '<!--[if ' . $condition . ']>' . "\n";
  foreach($sheets as $media => $files) {
    $output .= theme('stylesheet_media', $media, $files);
  }
  $output .= '<![endif]-->' . "\n";

  return $output;
}

/**
 * Return a set of stylesheet head links grouped by media type.
 *
 * @return
 * @param $media Object
 * @param $sheets Object
 */
function canvas_stylesheet_media($media, $sheets) {
  $output = '';
  foreach($sheets as $sheet) {
    $output .= theme('stylesheet_link', $media, $sheet);
  }
  return $output;
}

/**
 * Returns a formatted stylesheet link for the head of a page.
 *
 * @return
 * @param $media Object
 * @param $sheet Object
 */
function canvas_stylesheet_link($media, $sheet) {
  return '  <link type="text/css" rel="stylesheet" media="' . $media . '" href="' . base_path() . $sheet . '" />' ."\n";
}

function canvas_id_safe($string) {
  // Replace with dashes anything that isn't A-Z, numbers, dashes, or underscores.
  $string = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $string));
  // If the first character is not a-z, add 'n' in front.
  if (!ctype_lower($string{0})) { // Don't use ctype_alpha since its locale aware.
    $string = 'id' . $string;
  }
  return $string;
}

/**
 * Create a string of attributes form a provided array.
 * 
 * @param $attributes
 * @return string
 */
function canvas_render_attributes($attributes) {
  if($attributes) {
    $items = array();
    foreach($attributes as $attribute => $data) {
      if(is_array($data)) {
        $data = implode(' ', $data);
      }
      $items[] = $attribute . '="' . $data . '"';
    }
    $output = ' ' . implode(' ', $items);
  }
  return $output;
}
