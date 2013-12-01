<?php

// $Id: flickr_nodes.admin.inc,v 1.1 2008/12/17 09:51:21 tobiassjosten Exp $


/**
 * @file
 * Associate nodes with Flickr tags and show their respective photos.
 */


/*****************************************************************************
 * ADMIN SETTINGS
 *****************************************************************************/

/**
 * Flickr nodes administration settings form.
 */
function flickr_nodes_admin_settings() {
  $form['flickr_nodes_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API Key'),
    '#required' => TRUE,
    '#default_value' => _flickr_nodes_variable('api_key'),
    '#description' => t('API Key from Flickr'),
  );

  $times = array(900, 1800, 2700, 3600, 7200, 10800, 14400, 18000, 21600, 43200, 86400);
  $ageoptions = drupal_map_assoc($times, 'format_interval');
  $form['flickr_nodes_cache_duration'] = array(
    '#type' => 'select',
    '#title' => t('Update interval'),
    '#options' => $ageoptions,
    '#default_value' => _flickr_nodes_variable('cache_duration'),
    '#description' => t('How often, as most, to renew cached Flickr data'),
  );

  $form['flickr_nodes_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Tag prefix'),
    '#required' => TRUE,
    '#default_value' => _flickr_nodes_variable('prefix'),
    '#description' => t('Prefix to use for Flickr tags, in syntax &lt;prefix&gt;:&lt;content-type&gt;-&lt;nid&gt;'),
  );

  $form['flickr_nodes_tag_override'] = array(
    '#type' => 'textfield',
    '#title' => t('Tag override'),
    '#default_value' => _flickr_nodes_variable('tag_override'),
    '#description' => t('Override the standard tag syntax with a "hard coded" one, or leave empty to disable this feature'),
  );

  $content_types = node_get_types('names');
  $form['flickr_nodes_content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types'),
    '#options' => $content_types,
    '#default_value' => _flickr_nodes_variable('content_types'),
    '#description' => t('Tags will be generated, and photos fetched, for selected content types'),
  );

  $sizes = array(
    's' => t('Square - 75x75 pixel square'),
    't' => t('Thumbnail - 100 pixels on longest side'),
    'm' => t('Small - 240 pixels on longest side'),
    '-' => t('Medium - 500 pixels on longest side'),
    'b' => t('Large - 1024 pixels on longest side'),
    'o' => t('Original image'),
  );

  $form['flickr_nodes_size'] = array(
    '#type' => 'select',
    '#title' => t('Single photo size'),
    '#options' => $sizes,
    '#default_value' => _flickr_nodes_variable('size'),
    '#description' => t('Which photo size to use for single images'),
  );

  $form['flickr_nodes_block_size'] = array(
    '#type' => 'select',
    '#title' => t('Block photo size'),
    '#options' => $sizes,
    '#default_value' => _flickr_nodes_variable('block_size'),
    '#description' => t('Which photo size to use for blocks'),
  );

  $form['flickr_nodes_page_size'] = array(
    '#type' => 'select',
    '#title' => t('Page photo size'),
    '#options' => $sizes,
    '#default_value' => _flickr_nodes_variable('page_size'),
    '#description' => t('Which photo size to use for pages'),
  );

  $form['flickr_nodes_block_photos'] = array(
    '#type' => 'textfield',
    '#title' => t('Photos per block'),
    '#required' => TRUE,
    '#default_value' => _flickr_nodes_variable('block_photos'),
    '#description' => t('The maximum number of photos to show per block'),
  );

  $form['flickr_nodes_page_photos'] = array(
    '#type' => 'textfield',
    '#title' => t('Photos per page'),
    '#required' => TRUE,
    '#default_value' => _flickr_nodes_variable('page_photos'),
    '#description' => t('The maximum number of photos to show per page'),
  );

  return system_settings_form($form);
}

/**
 * Validate user input.
 */
function flickr_nodes_admin_settings_validate($form, &$form_state) {
  $key = trim($form_state['values']['flickr_nodes_api_key']);
  if ($key && (preg_match('/^[A-Fa-f\d]{32}$/', $key) != 1)) {
    form_set_error('flickr_nodes_api_key', t('You have specified an invalid API key.'));
  }

  $block_photos = trim($form_state['values']['flickr_nodes_block_photos']);
  if ($block_photos && !is_numeric($block_photos)) {
    form_set_error('flickr_nodes_block_photos', t('You must only enter a numeric value for "Photos per block".'));
  }

  $page_photos = trim($form_state['values']['flickr_nodes_page_photos']);
  if ($page_photos && !is_numeric($page_photos)) {
    form_set_error('flickr_nodes_page_photos', t('You must only enter a numeric value for "Photos per page".'));
  }
}

/**
 * Clean up user input.
 */
function flickr_nodes_admin_settings_submit($form, &$form_state) {
  $form_state['values']['flickr_nodes_api_key'] = trim($form_state['values']['flickr_nodes_api_key']);
  $form_state['values']['flickr_nodes_block_photos'] = trim($form_state['values']['flickr_nodes_block_photos']);
  $form_state['values']['flickr_nodes_page_photos'] = trim($form_state['values']['flickr_nodes_page_photos']);
}
