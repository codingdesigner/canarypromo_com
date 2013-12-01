<?php
//dsm($vars);
$fields = $vars->content;
//print_r($fields);
$output = '';

//move desired fields to the top. unset the field after moving it.

// feature image
/*
if($fields['field_image_feature']){
  $field = $fields['field_image_feature'];
  if (strlen($field['#value']) > 1) { $output .= $field['#value'];  } 
  else if (strlen($field['#children']) > 1) { $output .= $field['#children']; }
  unset($fields['field_image_feature']);
}
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