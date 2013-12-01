<?php
// $Id: preprocess-region.inc,v 1.3 2009/04/20 17:15:17 zarabadoo Exp $

/**
 * TODO: Add documentation
 */

// Declare alternate template files based on the region.
$vars['template_files'][] = 'region-' . theme('id_safe', $vars['region']->name);

// Create id and class information.
$vars['region_attributes'] = '';
$vars['region_attributes']['id'] = theme('id_safe', $vars['region']->name);
$vars['region_attributes']['class'][] = 'region';

$vars['attributes'] = theme('render_attributes', $vars['region_attributes']);
