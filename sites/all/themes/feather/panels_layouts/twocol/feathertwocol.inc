<?php
// $Id: twocol.inc,v 1.1.2.1 2008/12/16 21:27:58 merlinofchaos Exp $

/**
 * Implementation of hook_panels_layouts().
 */
function feather_feathertwocol_panels_layouts() {
  $items['feathertwocol'] = array(
    'title' => t('Feather Two column'),
    'icon' => 'feathertwocol.png',
    'theme' => 'feathertwocol',
    //'css' => 'feathertwocol.css',
    'panels' => array(
      'left' => t('Left side'),
      'right' => t('Right side')
    ),
  );

  return $items;
}