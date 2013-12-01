<?php
$fields = $vars->content;
//print_r($fields);
//dsm($vars);
//dsm($fields);
$output = '';

//move desired fields to the top. unset the field after moving it.
// feature image
if($vars->field_image_feature[0]['filepath']){
  $field = $fields['field_image_feature'];
  $imagecache_selector = $vars->field_imagecache_selector[0][value];
  $feature_image = $vars->field_image_feature[0];
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
print $output;
?>

