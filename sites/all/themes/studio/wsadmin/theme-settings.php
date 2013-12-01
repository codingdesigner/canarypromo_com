<?php

/**
 * Implementation of hook_settings()
 * 
 * Custom theme settings are created here.
 * 
 * @param $saved_settings
 * @return unknown_type
 */
function phptemplate_settings($saved_settings) {
  $defaults = array(
    'js_enhancement' => 0,
  );

  $settings = array_merge($defaults, $saved_settings);

  $form = array(
    'js_enhancement' => array(
      '#type' => 'checkbox',
      '#title' => t('Activate javascript interface enhancements'),
      '#default_value' => $settings['js_enhancement'],
      '#description' => t('When enabled, the administrative pages will be given a javascript-based reformatting. This is merely intended for navigational purposes and does not provide AJAX loading of any sort.'),
    )
  );

  return $form;
}