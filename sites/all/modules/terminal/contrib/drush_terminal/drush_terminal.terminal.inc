<?php
// $Id: drush_terminal.terminal.inc,v 1.1.2.3 2010/03/29 02:40:11 snufkin Exp $

/**
 * Implementation of hook_terminal.
 */
function drush_terminal_terminal() {
  $commands['drush'] = array(
    'title' => t('Drush'),
    'pattern' => 'drush help [command]',
    'description' => t('Execute "drush help" for more information.'),
    'callback' => 'drush_terminal_terminal_command',
  );
  return $commands;
}

/**
 * Terminal callback; Executes a Drush command.
 */
function drush_terminal_terminal_command($args = array()) {
  // Retrieve the required values.
  $php = variable_get('drush_terminal_php', NULL);
  $drush = variable_get('drush_terminal_drush', NULL);
  $root = variable_get('drush_terminal_root', NULL);
  $phpargs = variable_get('drush_terminal_phpargs', '-d safe_mode=off');
  if (!isset($php, $drush, $root)) {
    echo t('You must visit admin/settings/drush_terminal and configure the module.');
    exit;
  }

  // Invoke Drush.
  $args = implode(' ', $args);
  $output = array();
  exec("$php $phpargs $drush -r '$root' " . $args, $output);
  $output = implode("\n", $output);
  echo $output;
}

