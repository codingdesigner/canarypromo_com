<?php
$fields = $vars['content'];
$v = $vars['vars'];
// dsm($fields);
// dsm($v);
$output = '';


// move 'read more' link to the end of teaser text
if(module_exists('ed_readmore')){
  define('ED_READMORE_PLACEMENT_DEFAULT', 'inline');
  $display = variable_get('ed_readmore_placement', ED_READMORE_PLACEMENT_DEFAULT);
  // Don't do anything if placing the link is disabled
  if ($display != 'disable') {
    // Check to make sure that this is a teaser and there's actually more to read
    if ($v['teaser'] && $v['readmore']) {
      $fields['body']['#value'] = ed_readmore_link_place($fields['body']['#value'], $v['node'], $display);
    }
  }
}

// remove image tags from teaser
if($v['teaser']){
  if(strstr($fields['body']['#value'], '<img')){
    $fields['body']['#value'] = strip_tags($fields['body']['#value'], '<p><a><strong><em><h3><h4><ul><ol><li>');
    // $teaser_image = 
    if(module_exists('imagecache')){
      $node = node_load($v['nid']);
      // dsm($node);
      $image_filepath = $node->field_image[0]['filepath'];
      $alt = $node->field_image[0]['data']['alt'];
      $title = $node->field_image[0]['data']['title'];
      $attributes = array(
        'class' => 'first-image',
      );
      $teaser_image = theme('imagecache', 'left_col_small_snap24_1pxborder', $image_filepath, $alt, $title, $attributes);
      $output .= $teaser_image;
  	}
  }
}
//move desired fields to the top. unset the field after moving it.
// subtitle
/*
$output .= $v['field_subtitle_rendered'];
unset($fields['field_subtitle']);
*/


//loop through all remaining fields and print their values
if (is_array($fields)) {
  foreach($fields as $field) {
    //print field values
    if (strlen($field['#value']) > 1) { $output .= $field['#value'];  } 
    else if (strlen($field['#children']) > 1) { $output .= $field['#children']; }
    //loop through groups
    elseif (is_array($field)) {
      //unset($field['#children']);            
      foreach($field as $groupfield) {
        if (strlen($groupfield['#value']) > 1) { print $groupfield['#value'];}
        elseif(strlen($groupfield['#children']) > 1){ print $groupfield['#children'];}
      }
    }
  }
} 
print $output;
?>