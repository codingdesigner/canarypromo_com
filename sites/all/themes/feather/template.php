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
function feather_preprocess(&$vars, $hook) {
	//dsm($hook);
  if(is_file(drupal_get_path('theme', 'feather') . '/preprocess/preprocess-' . str_replace('_', '-', $hook) . '.inc')) {
    include(drupal_get_path('theme', 'feather') . '/preprocess/preprocess-' . str_replace('_', '-', $hook) . '.inc');
  }
}

/* incremental classes when grouping multiple cck values in views */
function feather_content_view_multiple_field($items, $field, $values) {
  $output = '';
  foreach ($items as $index => $item) {
    if (!empty($item) || $item == '0') {
      $classes = 'field-item';
      $classes .= ' field-item-'. ($index+1);
      $output .= '<div class="'. $classes .'">'. $item .'</div>';
    }
  }
  return $output;
}


// set custom html text inside main menu links
function feather_menu_item_link($link) {
  if($link['menu_name'] == 'primary-links'){
    switch(TRUE){
      case ($link['link_title'] == 'Work'):
        $link['title'] = 'Get to know our <em>Work</em>';
        break;
      case ($link['link_title'] == 'Services'):
        $link['title'] = 'Get heard <em>Services</em>';
        break;
      case ($link['link_title'] == 'Case Studies'):
        $link['title'] = 'Get some understanding <em>Case Studies</em>';
        break;
      case ($link['link_title'] == 'About'):
        $link['title'] = 'Get to know our <em>Team</em>';
        break;
      case ($link['link_title'] == 'Contact'):
        $link['title'] = 'Getting to know <em>You</em>';
        break;
    }
    $link['localized_options']['html'] = TRUE;
    $link['localized_options']['attributes']['title'] = $link['link_title'];
  }
  if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }

  return l($link['title'], $link['href'], $link['localized_options']);
}
/**
* Add a custom ID to menu items based on the text in the link
*/
function feather_menu_item($link, $has_children, $menu = '', $in_active_trail = FALSE, $extra_class = NULL) {
  $class = ($menu ? 'expanded' : ($has_children ? 'collapsed' : 'leaf'));
  if (!empty($extra_class)) {
    $class .= ' '. $extra_class;
  }
  if ($in_active_trail) {
    $class .= ' active-trail';
  }
  
  $id = 'menu-item-'. preg_replace("/[^a-zA-Z0-9]/", "", strip_tags($link));
  return '<li id="'.$id.'" class="'. $class .'">'. $link . $menu ."</li>\n";
}



/**
* Format fields in a view 
* used in views-view-fields--work--block-2.tpl
*/
function feather_format_views_field($field){
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
function feather_format_semanticviews_field($field){
	$output = '';
	if ($field->element_type){
		$output .= '<'.$field->element_type.drupal_attributes($field->attributes).'>';
	}
	if ($field->label){
		$output .= '<label'.drupal_attributes($field->attributes).'>'.$field->label.':</label>';
	}
  $output .= $field->content;
  if ($field->element_type){
		$output .= '</'.$field->element_type.'>';
	}
	return $output;
}


/**
* Display views block w/ title
* used in content-project.tpl.php
*/
function feather_render_views_block_title($view_name = "", $display_name = "", $nid, $blocktitle = TRUE){
  $view = views_get_view($view_name); //load a view 
  if (!empty($view)) {
    $view->execute($display_name); // execute the SQL. results are added to VIEW object
    if(!empty($view->result)){
      $display_title = $view->display[$display_name]->display_title;
      $output = '';
      $output .= sprintf('<div class="block %s">', feather_id_safe($display_title));
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


/**
 * Converts a string to a suitable html ID attribute.
 *
 * http://www.w3.org/TR/html4/struct/global.html#h-7.5.2 specifies what makes a
 * valid ID attribute in HTML. This function:
 *
 * - Ensure an ID starts with an alpha character by optionally adding an 'id'.
 * - Replaces any character except alphanumeric characters with dashes.
 * - Converts entire string to lowercase.
 *
 * @param $string
 *   The string
 * @return
 *   The converted string
 */
function feather_id_safe($string) {
  // Replace with dashes anything that isn't A-Z, numbers, dashes, or underscores.
  $string = strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $string));
  // If the first character is not a-z, add 'id' in front.
  if (!ctype_lower($string{0})) { // Don't use ctype_alpha since its locale aware.
    $string = 'id' . $string;
  }
  return $string;
}


/**
 * Render callback.
 *
 * @ingroup themeable
 */
// REMOVE the pane separator 
function feather_panels_default_style_render_panel($display, $panel_id, $panes, $settings) {
  $output = '';
  foreach ($panes as $pane_id => $content) {
	  // test that content exists before rendering the pane, duh
	  if($content->content){
		  $output .= $text = panels_render_pane($content, $display->content[$pane_id], $display);
  	}
  }
  return $output;
}

/**
 * Format a group of form items.
 *
 * @param $element
 *   An associative array containing the properties of the element.
 *   Properties used: attributes, title, value, description, children, collapsible, collapsed
 * @return
 *   A themed HTML string representing the form item group.
 *
 * @ingroup themeable
 */
function feather_fieldset($element) {
  if (!empty($element['#collapsible'])) {
    drupal_add_js('misc/collapse.js');

    if (!isset($element['#attributes']['class'])) {
      $element['#attributes']['class'] = '';
    }

    $element['#attributes']['class'] .= ' collapsible';
    if (!empty($element['#collapsed'])) {
      $element['#attributes']['class'] .= ' collapsed';
    }
  }
  
  return '<fieldset'. drupal_attributes($element['#attributes']) .'>'. ($element['#title'] ? '<legend><span>'. $element['#title'] .'</span></legend>' : '') . (isset($element['#description']) && $element['#description'] ? '<div class="description">'. $element['#description'] .'</div>' : '') . (!empty($element['#children']) ? $element['#children'] : '') . (isset($element['#value']) ? $element['#value'] : '') ."</fieldset>\n";
}

/**
 * Return a themed form element.
 *
 * @param element
 *   An associative array containing the properties of the element.
 *   Properties used: title, description, id, required
 * @param $value
 *   The form element's data.
 * @return
 *   A string representing the form element.
 *
 * @ingroup themeable
 */
function feather_form_element($element, $value) {
  // dsm($element);
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  $output = '<div class="form-item"';
  if (!empty($element['#id'])) {
    $output .= ' id="'. $element['#id'] .'-wrapper"';
  }
  $output .= ">\n";
  $required = !empty($element['#required']) ? '<span class="form-required" title="'. $t('This field is required.') .'">*</span>' : '';

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    if (!empty($element['#id'])) {
      $output .= ' <label for="'. $element['#id'] .'">'. $t('!title: !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
    else {
      $output .= ' <label>'. $t('!title: !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
  }
  
  if (!empty($element['#description'])) {
    $output .= ' <div class="description">'. $element['#description'] ."</div>\n";
  }

  $output .= " $value\n";

  // if (!empty($element['#description'])) {
  //     $output .= ' <div class="description">'. $element['#description'] ."</div>\n";
  //   }

  $output .= "</div>\n";

  return $output;
}


/**
 * Takes a needle and haystack (just like in_array()) and does a wildcard search on it's values.
 *
 * @param    string        $string        Needle to find
 * @param    array        $array        Haystack to look through
 * @result    array                    Returns the elements that the $string was found in
 */
function feather_in_array ($string, $array = array ())
{       
    foreach ($array as $key => $value) {
        unset ($array[$key]);
        if (strpos($value, $string) !== false) {
            $array[$key] = $value;
        }
    }       
    return $array;
}