<?php
// $Id: preprocess-comment-wrapper.inc,v 1.3 2009/04/20 17:15:17 zarabadoo Exp $
// TODO: Add documentation
$vars['wrapper_attributes'] = array();

$vars['wrapper_attributes']['id'] = 'comments';

$vars['title'] = t('Comments');

if ($vars['comment_count'] != 1) {
  $vars['comment_count'] = $vars['node']->comment_count . ' ' . t('comments posted');
}
else {
  $vars['comment_count'] = '1 ' . t('comment posted');
}

if (!$vars['content']) {
  $vars['content'] = '<p>' . t('There are currently no comments for this posting.') . '</p>';
  $vars['wrapper_attributes']['class'][] = 'no-comments';
}

switch ($vars['display_mode']) {
  case 1:
    $vars['wrapper_attributes']['class'][] = 'display-flat-collapsed';
    break;
  case 2:
    $vars['wrapper_attributes']['class'][] = 'display-flat-expanded';
    break;
  case 3:
    $vars['wrapper_attributes']['class'][] = 'display-threaded-collapsed';
    break;
  case 4:
    $vars['wrapper_attributes']['class'][] = 'display-threaded-expanded';
    break;
}

switch ($vars['display_order']) {
  case 1:
    $vars['wrapper_attributes']['class'][] = 'display-newest-first';
    break;
  case 2:
    $vars['wrapper_attributes']['class'][] = 'display-oldest-first';
    break;
}

switch ($vars['comment_controls_state']) {
  case 1:
    $vars['wrapper_attributes']['class'][] = 'comment-controls-above';
    break;
  case 1:
    $vars['wrapper_attributes']['class'][] = 'comment-controls-below';
    break;
  case 1:
    $vars['wrapper_attributes']['class'][] = 'comment-controls-both';
    break;
  case 1:
    $vars['wrapper_attributes']['class'][] = 'comment-controls-hidden';
    break;
  default:
    $vars['wrapper_attributes']['class'][] = 'comment-controls-off';
}

$vars['attributes'] = theme('render_attributes', $vars['wrapper_attributes']);
