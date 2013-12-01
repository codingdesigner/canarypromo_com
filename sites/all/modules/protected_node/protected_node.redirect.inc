<?php
// $Id: protected_node.redirect.inc,v 1.1 2008/10/14 09:35:29 tolmi Exp $
/**
 * @file
 * Redirected page callback file for the protected_node module.
 */

/**
 *
 */
function protected_node_enterpassword( ) {

  if (!isset( $_GET['destination'] )) {
    // Illegal call
    watchdog( 'protected_node', 'Illegal call to /protected-node', array(), WATCHDOG_WARNING );
    drupal_access_denied();
  }

  $info = variable_get( 'protected_node_info', '' );
  if (module_exists( 'token' )) {
    $info = token_replace( $info, 'node', node_load( $_SESSION['_protected_node']['current'] ) );
  }

  $form['protected_node'] = array(
    '#value' => $info
  );
  $form['protected_node_enterpassword'] = array(
    '#type' => 'fieldset',
    '#description' => t( 'The node you are trying to view is password protected. Please enter password below to proceed.' ),
    '#collapsible' => FALSE
  );
  $form['protected_node_enterpassword']['password'] = array(
    '#type' => 'password',
    '#title' => t( 'Node password' ),
    '#size' => 20
  );
  $form['protected_node_enterpassword']['submit'] = array(
    '#type' => 'submit',
    '#value' => t( 'OK' )
  );

  return $form;
}

/**
 *
 */
function protected_node_enterpassword_validate($form, &$form_state) {
  global $_protected_node_salt;

  $cnt = db_result( db_query( 'SELECT nid FROM {protected_nodes} WHERE passwd = \'%s\' AND nid = %d', sha1( $_protected_node_salt . $form['#post']['password'] ), $_SESSION['_protected_node']['current'] ) );
  if ($cnt < 1) {
    form_set_error( 'password', t( 'Incorrect password!' ) );
  }
}

/**
 *
 */
function protected_node_enterpassword_submit($form, &$form_state) {
  $_SESSION['_protected_node']['passwords'][$_SESSION['_protected_node']['current']] = TRUE;
  unset( $_SESSION['_protected_node']['current'] );
}