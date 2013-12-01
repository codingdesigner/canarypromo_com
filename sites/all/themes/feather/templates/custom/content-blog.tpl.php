<?php
$fields = $vars['content'];
$v = $vars['vars'];
$output = '';
// dsm($fields);
// dsm($v);

//move desired fields to the top. unset the field after moving it.
// subtitle
/*
$output .= $v['field_subtitle_rendered'];
unset($fields['field_subtitle']);
*/

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

// set aside images and video to display after content
$video = $v['field_video_rendered'];
unset($fields['field_video']);
$images = $v['field_image_rendered'];
unset($fields['field_image']);
$link = $v['field_link_out_rendered'];
unset($fields['field_link_out']);
$rel_project = $v['field_related_project_rendered'];
unset($fields['field_related_project']);
$rel_service = $v['field_related_service_rendered'];
unset($fields['field_related_service']);

//move desired fields to the top. unset the field after moving it.
// feature image
if($v['field_image_feature'][0]['filepath']){
  $field = $fields['field_image_feature'];
  $imagecache_selector = $v['field_imagecache_selector'][0][value];
  $feature_image = $v['field_image_feature'][0];
  $image_filepath = $feature_image['filepath'];
  $alt = $feature_image['data']['alt'];
  $title = $feature_image['data']['title'];
  $attributes = array(
    'class' => $imagecache_selector,
  );
  $output .= '<div class="field field-type-image field-field-image-feature">';

  if($imagecache_selector != 'original_size'){
    $img = theme('imagecache', $imagecache_selector, $image_filepath, $alt, $title, $attributes);
    $lb_img_url = imagecache_create_url('pagewidth', $image_filepath);
    $rel = 'lightshow[field_image_feature]';
    $rel .= $title;
    $options = array(
    'attributes' => array(
      'rel' => $rel,
      ),
    'html' => TRUE,
    'absolute' => TRUE,
    );
    $output .= l($img, $lb_img_url, $options);
  } else {
    $output .= sprintf('<img title="%s" alt="%s" src="/%s"/>', $title, $alt, $image_filepath);
  }
  $output .= '</div>';
  //if (strlen($field['#value']) > 1) { $output .= $field['#value'];  }
  //else if (strlen($field['#children']) > 1) { $output .= $field['#children']; }
  unset($fields['field_image_feature']);
}

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

// display images and video after content
$output .= $video;
$output .= $images;
$output .= $link;
$output .= $rel_project;
$output .= $rel_service;

print $output;
?>

