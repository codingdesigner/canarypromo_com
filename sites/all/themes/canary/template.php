<?php
// $Id: template.php,v 1.17 2008/09/11 10:52:53 johnalbin Exp $

/**
 * @file
 * Contains theme override functions and preprocess functions for the theme.
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. You can add new regions for block content, modify
 *   or override Drupal's theme functions, intercept or make additional
 *   variables available to your theme, and create custom PHP logic. For more
 *   information, please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/theme-guide
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   The Drupal theme system uses special theme functions to generate HTML
 *   output automatically. Often we wish to customize this HTML output. To do
 *   this, we have to override the theme function. You have to first find the
 *   theme function that generates the output, and then "catch" it and modify it
 *   here. The easiest way to do it is to copy the original function in its
 *   entirety and paste it here, changing the prefix from theme_ to canary_.
 *   For example:
 *
 *     original: theme_breadcrumb()
 *     theme override: canary_breadcrumb()
 *
 *   where franklin is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_breadcrumb() function.
 *
 *   If you would like to override any of the theme functions used in Zen core,
 *   you should first look at how Zen core implements those functions:
 *     theme_breadcrumbs()      in zen/template.php
 *     theme_menu_item_link()   in zen/template.php
 *     theme_menu_local_tasks() in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called template suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node-forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions, please visit the Theme
 *   Developer's Guide on Drupal.org: http://drupal.org/node/223430
 *   For more information on template suggestions, please visit the Theme
 *   Developer's Guide on Drupal.org: http://drupal.org/node/223440 and
 *   http://drupal.org/node/190815#template-suggestions
 */


/*
 * Add any conditional stylesheets you will need for this sub-theme.
 *
 * To add stylesheets that ALWAYS need to be included, you should add them to
 * your .info file instead. Only use this section if you are including
 * stylesheets based on certain conditions.
 */
/* -- Delete this line if you want to use and modify this code
// Example: optionally add a fixed width CSS file.
if (theme_get_setting('canary_fixed')) {
  drupal_add_css(path_to_theme() . '/layout-fixed.css', 'theme', 'all');
}
// */

/**
 * Implementation of HOOK_theme().
 */
function canary_theme(&$existing, $type, $theme, $path) {
  $hooks = zen_theme($existing, $type, $theme, $path);
  // Add your theme hooks like this:
  $hooks['content'] = array( 
    'arguments' => array('vars' => NULL),
    'template' => 'content',
    'template_files' => array('content-'.$vars['type']),
    );
  /*
  $hooks['hook_name_here'] = array( // Details go here );
  */
  //$hooks['content'] = array( // Details go here );
  // @TODO: Needs detailed comments. Patches welcome!
  return $hooks;
}

/**
 * Override or insert variables into all templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered (name of the .tpl.php file.)
 */
/* -- Delete this line if you want to use this function
function canary_preprocess(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the page templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */

function canary_preprocess_page(&$vars, $hook) {
  // MANUALLY REMOVE TITLES FROM SOME PANELS -- PRE-ALPHA PANELS IS BROKEN FOR THIS
  $vars['title'] = ($vars['title'] != 'removeme')? $vars['title']: ''; 
  $vars['title'] = ($vars['title'] != 'Front Page')? $vars['title']: '';
  // MANUALLY FIX ESCAPED AMPERSANDS CREATED IN PANELS ALPHA
  if(strpos($vars['title'], '&amp;amp;', '&amp;') != 0){
    $vars['title'] = str_replace('&amp;amp;', '&amp;', $vars['title']);
  }
  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.)
  $body_classes = array($vars['body_classes']);
  switch (TRUE) {
    case $vars['primary_links'] :
      $body_classes[] = 'withprimary';
      break;
    case $vars['secondary_links'] :
      $body_classes[] = 'withsecondary';
      break;
  }
  $vars['body_classes'] = implode(' ', $body_classes); // Concatenate with spaces
  
 
  // Use Typogrify on titles
  $vars['title'] = module_invoke('typogrify', 'filter', 'process', null, 3, $vars['title']);
}


/**
 * Override or insert variables into the node templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */

function canary_preprocess_node(&$vars, $hook) {
  //$vars['sample_variable'] = t('Lorem ipsum.');
  // Use Typogrify on titles
  $vars['title'] = module_invoke('typogrify', 'filter', 'process', null, 3, $vars['title']);
  
  //use content-NODETYPE.tpl.php to theme content variable
  $vars['content'] = theme('content', $vars['node']);
}


function canary_preprocess_content($vars) {
  $vars['template_files'] = array('content-'.$vars['vars']->type);
  $vars = array_merge((array)$node, $vars);
}


/**
 * Override or insert variables into the comment templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function canary_preprocess_comment(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function canary_preprocess_block(&$vars, $hook) {
  $vars['sample_variable'] = t('Lorem ipsum.');
  $vars['block']->subject = module_invoke('typogrify', 'filter', 'process', null, 3, $vars['block']->subject);
  if($vars['block']->region == 'right'){
    switch ($vars['block']->bid){
      case 98:
        // WHAT'S HAPPENING NOW
        $vars['block']->subject .= '<span class="firstblock-bird">';
        break;
      case 144:
        // BIRDS EYE VIEW
        $vars['block']->subject .= '<span class="firstblock-bird">';
        break;
    }
  }
}


/**
 * Ensure messages are always lists (even when there is only one single message).
 */
function canary_status_messages($display = NULL) {
  $output = '';
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"messages $type\">\n";
    $output .= " <ul>\n";
    foreach ($messages as $message) {
      $output .= '  <li>'. $message ."</li>\n";
    }
    $output .= " </ul>\n";
    $output .= "</div>\n";
  }
  return $output;
}


/**
 * Generate the HTML output for a single menu link.
 *
 * @ingroup themeable
 * 
 * render LOCAL TASKS as tabs
 * add typogrify processing to menu items
 */
/*function canary_menu_item_link($link) {
  if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }
  if(module_exists('typogrify')){
  	$link['title'] = module_invoke('typogrify', 'filter', 'process', null, 3, $link['title']);
  	$link['localized_options']['html'] = true;
  }
  // If an item is a LOCAL TASK, render it as a tab
  if ($link['type'] & MENU_IS_LOCAL_TASK) {
    $link['title'] = '<span class="tab">' . $link['title'] . '</span>';
    $link['localized_options']['html'] = TRUE;
  }
  
  return l($link['title'], $link['href'], $link['localized_options']);
}*/

/**
* Add a custom ID to menu items based on the text in the link
*/
function canary_menu_item($link, $has_children, $menu = '', $in_active_trail = FALSE, $extra_class = NULL) {
  $class = ($menu ? 'expanded' : ($has_children ? 'collapsed' : 'leaf'));
  if (!empty($extra_class)) {
    $class .= ' '. $extra_class;
  }
  if ($in_active_trail) {
    $class .= ' active-trail';
  }
  $id = preg_replace("/[^a-zA-Z0-9]/", "", strip_tags($link));
  return '<li id="'.$id.'" class="'. $class .'">'. $link . $menu ."</li>\n";
}



/**
* Format fields in a view 
* used in views-view-fields--work--block-2.tpl
*/
function canary_format_views_field($field){
  $output = '';
  if (!empty($field->separator)){
    $output .= $field->separator; 
  }
  $output .= '<'. $field->inline_html .' class="views-field-'. $field->class .'">';
  if ($field->label){
    $output .= '<label class="views-label-'. $field->class .'">';
    $output .= $field->label .': ';
    $output .=  '</label>';
  }
  // $field->element_type is either SPAN or DIV depending upon whether or not
  // the field is a 'block' element type or 'inline' element type.
  $output .= '<'. $field->element_type .' class="field-content">'. $field->content .'</'. $field->element_type .'>';
  $output .= '</'. $field->inline_html .'>';
  return $output;
}


/**
* Display views block w/ title
* used in content-project.tpl.php
*/
function canary_render_views_block_title($view_name = "", $display_name = "", $nid, $blocktitle = TRUE){
  $view = views_get_view($view_name); //load a view 
  if (!empty($view)) {
    $view->execute($display_name); // execute the SQL. results are added to VIEW object
    if(!empty($view->result)){
      $display_title = $view->display[$display_name]->display_title;
      $output = '';
      $output .= sprintf('<div class="block %s">', zen_id_safe($display_title));
      if($blocktitle != FALSE){
        if(is_string($blocktitle)){
          $output .= '<h3 class="title blocktitle">' . $blocktitle . '</h3>';
        } else {
          $title = $view->get_title();
          $output .= '<h3 class="title blocktitle">' . $title . '</h3>';
        }
      }
      $output .= views_embed_view($view_name, $display_name, $nid);
      $output .= '</div>';
    }
  }
  return $output;
}
