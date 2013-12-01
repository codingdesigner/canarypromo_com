<?php

/**
 * Create alternate template file name for the specific node types.
 */
$vars['template_files'][] = 'content-' . str_replace('_', '-', $vars['vars']['vars']['node']->type);

/**
 * By default, set the display to be the regular content.
 */
 $vars['display'] = $vars['content'];
 
