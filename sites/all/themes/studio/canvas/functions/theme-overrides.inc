<?php
// $Id: theme-overrides.inc,v 1.3 2009/04/20 17:15:16 zarabadoo Exp $

/**
 * Implementations of theme_blocks()
 * 
 * This is being overridden in order to flag the first and last blocks in a 
 * region. The preprocess function for block can then use that to give it the 
 * appropriate class.
 *
 * In addition, if a region has content, it is run through theme_region() that
 * will provide an easy way to provide wrappers without logic in the
 * page.tpl.php.
 * 
 * @param $region
 * @return region content
 */
function canvas_blocks($region) {
  $content->name = $region;
  $content->content = '';

  if ($list = block_list($region)) {
    $content->count = count($list);
    $counter = 0;
    foreach ($list as $key => $block) {
      $counter++;
      if ($counter == 1) {
        $block->attributes['class'][] = 'first';
      }

      if ($counter == $content->count) {
        $block->attributes['class'][] = 'last';
      }

      $content->content .= theme('block', $block);
    }
  }

  // Add any content assigned to this region through drupal_set_content() calls.
  $content->content .= drupal_get_content($content->name);

  if($content->content){
    return theme(array('region_' . $content->name, 'region'), $content);
  }
}

/**
 * Return a themed form element.
 * 
 * This override is to remove the colon on labels. They can be added in on a per 
 * label basis in a subtheme.
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
function canvas_form_element($element, $value) {
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
      $output .= ' <label for="'. $element['#id'] .'">'. $t('!title !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
    else {
      $output .= ' <label>'. $t('!title !required', array('!title' => filter_xss_admin($title), '!required' => $required)) ."</label>\n";
    }
  }

  $output .= " $value\n";

  if (!empty($element['#description'])) {
    $output .= ' <div class="description">'. $element['#description'] ."</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Return a themed list of items.
 *
 * @param $items
 *   An array of items to be displayed in the list. If an item is a string,
 *   then it is used as is. If an item is an array, then the "data" element of
 *   the array is used as the contents of the list item. If an item is an array
 *   with a "children" element, those children are displayed in a nested list.
 *   All other elements are treated as attributes of the list item element.
 * @param $title
 *   The title of the list.
 * @param $type
 *   The type of list to return (e.g. "ul", "ol")
 * @param $attributes
 *   The attributes applied to the list element.
 * @return
 *   A string containing the list output.
 */
function canvas_item_list($items = array(), $title = NULL, $type = 'ul', $attributes = NULL) {
  $output = '';
  if (isset($title)) {
    $output .= '<h3 class="item-list-title">'. $title .'</h3>';
  }
  
  // Add the 'item-list' class to the list container element
  if ($attributes['class']) {
    $attributes['class'] .= ' item-list';
  }
  else {
    $attributes['class'] = 'item-list';
  }
  
  if (!empty($items)) {
    $output .= "<$type". drupal_attributes($attributes) .'>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        $data .= theme('item_list', $children, NULL, $type, $attributes); // Render nested list
      }
      if ($i == 0) {
        $attributes['class'] = empty($attributes['class']) ? 'first' : ($attributes['class'] .' first');
      }
      if ($i == $num_items - 1) {
        $attributes['class'] = empty($attributes['class']) ? 'last' : ($attributes['class'] .' last');
      }
      $output .= '<li'. drupal_attributes($attributes) .'>'. $data ."</li>\n";
    }
    $output .= "</$type>";
  }
  return $output;
}
