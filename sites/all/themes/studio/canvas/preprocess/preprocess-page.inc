<?php
// $Id: preprocess-page.inc,v 1.3 2009/04/20 17:15:17 zarabadoo Exp $

/**
 * Implementation of theme_preprocess_HOOK().
 * Passes variables to the page templates.
 *
 * @return $vars
 */
// Prepare the variables that store our classes and ids for the body tag.
if(!isset($vars['page']->attributes)) {
  $vars['body_attributes'] = array();
}

// Get our path for use in the class and id assembly.
$path = drupal_get_path_alias(arg(0) . '/' . arg(1));
$path_chunked = explode('/', $path);

// Check to see if the front page is being viewed and assign the appropriate
// class. Otherwise, use the node path to determine the section and
// 'not-front' as the class.
if ($vars['is_front']) {
  $vars['body_attributes']['id'] = 'front-page';
  $vars['body_attributes']['class'][] = 'front';
}
elseif (arg(0) == 'comment' and arg(1) == 'reply') {
  $node_path = drupal_get_path_alias('node/' . arg(2));
  $parts = explode('/', $node_path);
  $vars['body_attributes']['class'][] = $parts[0] . '-section';
  $vars['body_attributes']['class'][] = 'not-front';
  $vars['body_attributes']['class'][] = 'comment-submit';
}
else {
  $vars['body_attributes']['class'][] = 'not-front';
  $vars['body_attributes']['class'][] = $path_chunked[0] . '-section';
}

// If we are viewing a node, parse out the url to make an id and form classes
// designating the type of node and that we are looking at a full node.
// If not, the title of the page will be used to form an id.
if (isset($vars['node'])) {
  $vars['body_attributes']['id'] = arg(0) . '-' . strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $vars['node']->title)) . '-page';
  $vars['body_attributes']['class'][] = 'full-' . $vars['node']->type;
  $vars['body_attributes']['class'][] = 'full-node-view';
}
elseif (!$vars['is_front'] && $vars['title']) {
  $vars['body_attributes']['id'] = arg(0) . '-' . strtolower(preg_replace('/[^a-zA-Z0-9-]+/', '-', $vars['title'])) . '-page';
}
elseif (!$vars['is_front']) {
  $vars['body_attributes']['id'] = arg(0) . '-page';
}

// If on the admin page, provide and 'administration page' id and a
// 'administration-section' class.
if (arg(0) == 'admin') {
  $vars['body_attributes']['id'] = 'administration-page';
  $vars['body_attributes']['class'][] = 'administration-section';
}

// Add a new class if the user is adding a new node.
if (arg(0) == 'node' && arg(1) == 'add' && arg(2)) {
  $vars['body_attributes']['id'] = 'node-add-' . arg(2);
	$vars['body_attributes']['class'][] = 'node-add';
}

// Add a class if a user is editing a node.
if (arg(0) == 'node' && arg(2) == 'edit') {
  $vars['body_attributes']['class'][] = 'node-edit';
}

// Add a class for when a user is editing a profile
if (arg(0) == 'user' && arg(1) == 'edit') {
  $vars['body_attributes']['class'][] = 'user-edit';
}

// Add a class if the viewing user is registered, otherwise, add a class
// designating an anonymous user is viewing.
if ($vars['logged_in']) {
  $vars['body_attributes']['class'][] = 'registered-user';
}
else {
  $vars['body_attributes']['class'][] = 'anonymous-user';
}

// If a user is an administrator, provide a special class.
if ($vars['is_admin']) {
  $vars['body_attributes']['class'][] = 'administrator';
}

// Check for a breadcrumb and add a class if it exists
if ($vars['breadcrumb']) {
  $vars['body_attributes']['class'][] = 'breadcrumb-active';
}

// Check for primary and secondary links and classes for each if they exist
if ($vars['primary_links']) {
  $vars['body_attributes']['class'][] = 'primary-links-active';
}

if ($vars['secondary_links']) {
  $vars['body_attributes']['class'][] = 'secondary-links-active';
}
//$vars['body_attributes']['class'][] = 'not-front';

// Crunch down our attributes into a single string to be appended to the body
// tag in the page template.
$vars['attributes'] = theme('render_attributes', $vars['body_attributes']);
