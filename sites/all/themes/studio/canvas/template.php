<?php
// $Id: template.php,v 1.2 2009/04/16 17:29:51 zarabadoo Exp $

/**
 * Implementation of hook_theme().
 *
 * @return
 */
function canvas_theme() {
  return array(
    // Custom theme functions.
    'id_safe' => array(
      'arguments' => array('string'),
      'file' => 'functions/theme-custom.inc',
    ),
    'node_content' => array(
      'arguments' => array('node' => NULL),
      'template' => 'node-content',
    ),
    'ie_conditional' => array(
      'arguments' => array('conditional' => NULL, 'sheets' => array()),
      'file' => 'functions/theme-custom.inc',
    ),
    'ie_styles' => array(
      'arguments' => array('styles' => NULL),
      'file' => 'functions/theme-custom.inc',
    ),
    'region' => array(
      'arguments' => array(
        'region' => NULL,
      ),
      'pattern' => 'region_',
      'path' => drupal_get_path('theme', 'canvas') . '/templates/custom',
      'template' => 'region',
    ),
    'render_attributes' => array(
      'arguments' => array('attributes'),
      'file' => 'functions/theme-custom.inc',
    ),
    'stylesheet_link' => array(
      'arguments' => array('media' => NULL, 'sheet' => NULL),
      'file' => 'functions/theme-custom.inc',
    ),
    'stylesheet_media' => array(
      'arguments' => array('media' => NULL, 'sheets' => array()),
      'file' => 'functions/theme-custom.inc',
    ),
    // Themes being overridden.
    'blocks' => array(
      'arguments' => array('region' => NULL),
      'file' => 'functions/theme-overrides.inc',
    ),
    'form_element' => array(
      'arguments' => array(
        'element' => NULL,
        'value' => NULL,
      ),
      'file' => 'functions/theme-overrides.inc',
    ),
    'item_list' => array(
      'arguments' => array(
        'items' => array(),
        'title' => NULL,
        'type' => 'ul',
        'attributes' => NULL,
      ),
      'file' => 'functions/theme-overrides.inc',
    ),
		//use content-NODETYPE.tpl.php to theme content variable
    'content' => array(
      'arguments' => array(
        'vars' => NULL,
      ),
      'pattern' => 'content_',
      'path' => drupal_get_path('theme', 'canvas') . '/templates/custom',
      'template' => 'content',
    ),
  );
}

/**
 * Implementation of hook_preprocess()
 * 
 * This function checks to see if a hook has a preprocess file associated with 
 * it, and if so, loads it.
 * 
 * @param $vars
 * @param $hook
 * @return Array
 */
function canvas_preprocess(&$vars, $hook) {
  if(is_file(drupal_get_path('theme', 'canvas') . '/preprocess/preprocess-' . str_replace('_', '-', $hook) . '.inc')) {
    include('preprocess/preprocess-' . str_replace('_', '-', $hook) . '.inc');
  }
}

/**
 * Implementation of hook_preprocess.
 * 
 * Since it is difficult to properly determine the path of a theme and subthemes 
 * when the system is offline, the specific preprocess funtion for the 
 * maintenance_page hook is called directly.
 * 
 * @param $vars
 * @return Array
 */
function canvas_preprocess_maintenance_page(&$vars) {
  $vars['body_attributes']['id'] = 'maintenance-page';
  
  $vars['body_attributes']['class'][] = $vars['body_classes'];
  
  $vars['attributes'] = theme('render_attributes', $vars['body_attributes']);
}
