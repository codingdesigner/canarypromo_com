<?php
if($vars['region']->name == 'left'){
  $vars['region_attributes']['class'][] = ' column sidebar';
}

$vars['attributes'] = theme('render_attributes', $vars['region_attributes']);
