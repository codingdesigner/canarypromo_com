<?php
// $Id: preprocess-node-content.inc,v 1.1 2009/04/06 21:09:29 zarabadoo Exp $

/**
 * Create alternate template file name for the specific node types.
 */
$vars['template_files'][] = 'node-content-' . str_replace('_', '-', $vars['node']->type);

/**
 * By default, set the display to be the regular content.
 */
 $vars['display'] = $vars['content'];