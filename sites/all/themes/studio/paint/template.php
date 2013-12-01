<?php
// $Id: template.php,v 1.2 2009/04/16 17:29:53 zarabadoo Exp $

/**
 * Implmentation of hook_preprocess().
 * 
 * This will check for include files based on template file hooks and load them 
 * if they exist. These files do processing and can them push variables for 
 * output to the required template file.
 * 
 * @param $vars
 * @param $hook
 * @return Array
 */
function paint_preprocess(&$vars, $hook) {
  if(is_file(drupal_get_path('theme', 'paint') . '/preprocess/preprocess-' . str_replace('_', '-', $hook) . '.inc')) {
    include(drupal_get_path('theme', 'paint') . '/preprocess/preprocess-' . str_replace('_', '-', $hook) . '.inc');
  }
}