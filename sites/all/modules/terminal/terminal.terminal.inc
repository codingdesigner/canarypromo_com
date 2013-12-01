<?php
// $Id: terminal.terminal.inc,v 1.1.2.2 2010/02/16 12:26:42 snufkin Exp $

/**
 * Implementation of hook_terminal().
 */
function terminal_terminal() {
  $commands['help'] = array(
    'title' => t('Help'),
    'pattern' => t('help [PATTERN]'),
    'description' => t('Displays helpful information about builtin commands. If PATTERN is specified, gives detailed help on the command matching PATTERN.'),
    'callback' => 'terminal_command_help',
  );
  $commands['history'] = array(
    'title' => t('History'),
    'pattern' => 'help [n]',
    'description' => t('Display the history list. If N is provided, will display the given amount of results. Defaults to 5.'),
    'callback' => 'terminal_command_history',
  );
  $commands['cache-clear'] = array(
    'title' => t('Cache Clear'),
    'pattern' => 'cache-clear',
    'description' => t('Clears all the Drupal cache.'),
    'callback' => 'terminal_command_cacheclear',
  );
  $commands['cron'] = array(
    'title' => t('Cron run'),
    'pattern' => 'cron',
    'description' => t('Run all cron hooks.'),
    'callback' => 'terminal_command_cron',
  );
  return $commands;
}

/**
 * Terminal callback for "help".
 */
function terminal_command_help($args = array()) {
  $commands = terminal_commands();
  // Check if the user wants help on a certain command.
  $name = isset($args[0]) ? $args[0] : -1;
  if (isset($commands[$name])) {
    $command = $commands[$name];
    $title = isset($command['title']) ? $command['title'] : $name;
    $description = isset($command['description']) ? $command['description'] : '';
    $pattern = isset($command['pattern']) ? $command['pattern'] : $name;
    echo "$title: $pattern\n $description";
  }
  else {
    // Present information about all the available commands.
    echo t("Drupal Terminal, version !version\nExecute 'help [command]' to retrieve more information about the given command:\n", array('!version' => '$Id: terminal.terminal.inc,v 1.1.2.2 2010/02/16 12:26:42 snufkin Exp $'));
    echo implode(', ', array_keys($commands));
  }
}

/**
 * Terminal command for "history".
 */
function terminal_command_history($args = array()) {
  global $user;
  $n = (isset($args[0]) && is_numeric($args[0])) ? $args[0] : 5;
  // Retrieve the user's history.
  $result = db_query("SELECT * FROM {terminal_history} WHERE uid = %d ORDER BY hid DESC LIMIT 0,%d", $user->uid, $n);
  // Construct the history array.
  $hist = array();
  while ($history = db_fetch_object($result)) {
    $hist[$history->hid] = $history->input;
  }
  // Make sure to present it in the correct order.
  ksort($hist);
  foreach ($hist as $input) {
    echo $input . "\n";
  }
}

/**
 * Terminal command for "cache-clear".
 */
function terminal_command_cacheclear() {
  drupal_flush_all_caches();
  echo t('The cache has been cleared.');
}

/**
 * Terminal command for "cron".
 */
function terminal_command_cron() {
  echo drupal_cron_run() ? t('Cron ran successfully.') : t('Cron run failed.');
}
