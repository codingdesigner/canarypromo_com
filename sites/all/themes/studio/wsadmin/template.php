<?php

if (db_is_active() && is_null(theme_get_setting('js_enhancement'))) {
  global $theme_key;
  $defaults = array(
    'js_enhancement' => 0,
  );
  $settings = theme_get_settings($theme_key);
  if (module_exists('node')) {
    foreach (node_get_types() as $type => $name) {
      unset($settings['toggle_node_info_' . $type]);
    }
  }
  variable_set(
    str_replace('/', '_', 'theme_' . $theme_key . '_settings'),
    array_merge($defaults, $settings)
  );
  theme_get_setting('', TRUE);
}

if (theme_get_setting('js_enhancement')) {
  drupal_add_js(path_to_theme() . '/js/tab-assembly.js', 'theme', 'footer');
}

if (theme_get_setting('js_enhancement') && arg(0) == 'admin' && arg(1) == NULL) {
  drupal_add_js(path_to_theme() . '/js/admin-tabs.js', 'theme', 'footer');
}

function wsadmin_preprocess(&$vars, $hook) {
  if(is_file(drupal_get_path('theme', 'wsadmin') . '/preprocess/preprocess-' . str_replace('_', '-', $hook) . '.inc')) {
    include(drupal_get_path('theme', 'wsadmin') . '/preprocess/preprocess-' . str_replace('_', '-', $hook) . '.inc');
  }
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function wsadmin_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    return '<div class="breadcrumb">'. implode(' » ', preg_replace('/>' . t('Home') . '</', '>' . t('Public site') . '<', $breadcrumb)) .'</div>';
  }
}