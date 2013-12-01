<?php
$fields = $vars['content'];
$v = $vars['vars'];
$output = '';
// dsm($fields);
// dsm($v);

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

//move desired fields to the top. unset the field after moving it.
print $fields['body']['#value'];
unset($fields['body']);
unset($fields['files']);

// print some views blocks in the content variable
print feather_render_views_block_title("project_related", "block_1", $vars->nid, FALSE); // about client // in template.php
print feather_render_views_block_title("project_related", "block_3", $vars->nid, FALSE); // latest press release
print feather_render_views_block_title("project_related", "block_5", $vars->nid); // related blog entries
$block = module_invoke('canary_attached_files', 'block', 'view', 0); // downloads
print '<div class="block canary_attached_files"><h3 class="title blocktitle">'.$block['subject'].'</h3>'; // downloads
print $block['content'] .'</div>'; // downloads
//print feather_render_views_block_title("project_elements", "block_1", $vars->nid); // downloads
print feather_render_views_block_title("project_related", "block_6", $vars->nid); // related press mentions
print feather_render_views_block_title("project_related", "block_9", $vars->nid); // related case studies
print feather_render_views_block_title("project_related", "block_7", $vars->nid); // related testimonials
print feather_render_views_block_title("project_related", "block_2", $vars->nid, FALSE); // client contact info

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