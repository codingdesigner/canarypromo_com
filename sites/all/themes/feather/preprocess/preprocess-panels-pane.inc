<?php
// dsm($vars);

// add markup for little bird to certain panes
if($vars['output']->css_class == 'birds-eye'){
  $vars['title'] .= '<span class="firstblock-bird"></span>';
}