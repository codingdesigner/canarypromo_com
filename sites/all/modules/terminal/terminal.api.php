<?php
// $Id: terminal.api.php,v 1.1.2.1 2009/11/29 08:48:08 snufkin Exp $

/**
 * Expose a method to be executed by the Drupal Terminal.
 *
 * @return
 *   An array of terminal commands. Each command has one of the following items:
 *   - "title": The name of the command.
 *   - "pattern": Helpful pattern text that's displayed to the user when using
 *     the 'help' command.
 *   - "description": A short help text for the command.
 *   - "callback": The function callback which is executed when the command is
 *     run by the user.
 */
function hook_terminal() {
  $commands['help'] = array(
    'title' => t('Help'),
    'pattern' => t('help [pattern]'),
    'description' => t('Displays helpful information about builtin commands. If PATTERN is specified, gives detailed help on the command matching PATTERN.'),
    'callback' => 'terminal_command_help',
  );
  return $commands;
}
