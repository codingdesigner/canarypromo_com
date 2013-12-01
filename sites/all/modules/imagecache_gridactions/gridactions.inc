<?php
// $ID: $

/**
 * Implementation of imagecache_hook_form()
 *
 * Settings for snapping to a pixel grid.
 * Accept a snap value and return it in pixels.
 * use: allows you to enter a baseline (snap) value 
 *  ex: '18' will round down to the nearest multiple on 18px
 *  ex: '15' will round down to the nearest multiple on 15px
 *
 * @param $action array of settings for this action
 * @return a form definition
 */
function gridactions_snap_form($action) {
  $form['info'] = array(
    '#value' => t('Your image will be cropped to the nearest multiple of any values entered here.')
  );
  $form['snapwidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Snap Width'),
    '#default_value' => ($action['snapwidth'])?$action['snapwidth']:1,
    '#description' => t('Enter a value in pixels to snap the width to.'),
  );
  $form['snapheight'] = array(
    '#type' => 'textfield',
    '#title' => t('Snap Height'),
    '#default_value' => ($action['snapheight'])?$action['snapheight']:1,
    '#description' => t('Enter a value in pixels to snap the height to.'),
  );
  
  return $form;
}

/**
 * Implementation of theme_hook() for imagecache_ui.module
 */
function theme_gridactions_snap($element) {
  //$data = $element['#value'];
  $output = 'This is the theme.';
  /*return 'snap width: '. $data['snapwidth'] 
      .', snap height: '. $data['snapheight'] 
      .', xoffset: '. $data['xoffset'] 
      .', yoffset: '. $data['yoffset'];*/
  return $output;
}

/**
 * Implementation of hook_image()
 *
 * Settings for snapping to a pixel grid.
 * Accept a snap value and return it in pixels.
 * use: allows you to enter a baseline (snap) value 
 *  ex: '18' will round down to the nearest multiple on 18px
 *  ex: '15' will round down to the nearest multiple on 15px
 *
 * Process the imagecache action on the passed image
 *
 * @param $image
 * array defining an image file, including  :
 *
 *   $image- >source as the filename,
 *
 *   $image->info array
 *
 *   $image->res handle on the image object
 */
function gridactions_snap_image(&$image, $action = array()) {
  $snapwidth = $action['snapwidth'];
  if($image->info['width'] > $snapheight){
    $nearest_snapwidth = floor($image->info['width'] / $snapwidth);
    $value_snapwidth = $snapwidth * $nearest_snapwidth;
  } else {
    $value_snapwidth = $image->info['width'];
  }
  
  $snapheight = $action['snapheight'];
  if($image->info['height'] > $snapheight){
    $nearest_snapheight = floor($image->info['height'] / $snapheight);
    $value_snapheight = $snapheight * $nearest_snapheight;
  } else {
    $value_snapheight = $image->info['height'];
  }
  
  if (!imageapi_image_scale_and_crop($image, $value_snapwidth, $value_snapheight)) {
    watchdog('imagecache_gridactions', 'imagecache_scale_and_crop failed. image: %image, data: %data.', array('%path' => $image, '%data' => print_r($data, true)), WATCHDOG_ERROR);
    return false;
  }
  return true;
}

////////////////////////////////////////////////


/**
 * Implementation of imagecache_hook_form()
 *
 * Accept a remove value and return it in pixels.
 * use: allows you to remove a few pixels in order to fit a bordered image precicely onto a grid
 *  ex: '10' will remove 10px
 *
 * @param $action array of settings for this action
 * @return a form definition
 */
function gridactions_remove_form($action) {
  $form['info'] = array(
    '#value' => t('Your image will be cropped by any values entered here.')
  );
  $form['removewidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Remove Width'),
    '#default_value' => ($action['removewidth'])?$action['removewidth']:1,
    '#description' => t('Enter a value in pixels to remove from the width.'),
  );
  $form['removeheight'] = array(
    '#type' => 'textfield',
    '#title' => t('Remove Height'),
    '#default_value' => ($action['removeheight'])?$action['removeheight']:1,
    '#description' => t('Enter a value in pixels to remove from the height.'),
  );
  
  return $form;
}

/**
 * Implementation of theme_hook() for imagecache_ui.module
 */
function theme_gridactions_remove($element) {
  //$data = $element['#value'];
  $output = 'This is the theme.';
  /*return 'snap width: '. $data['snapwidth'] 
      .', snap height: '. $data['snapheight'] 
      .', xoffset: '. $data['xoffset'] 
      .', yoffset: '. $data['yoffset'];*/
  return $output;
}

/**
 * Implementation of hook_image()
 *
 * Accept a remove value and return it in pixels.
 * use: allows you to remove a few pixels in order to fit a bordered image precicely onto a grid
 *  ex: '10' will remove 10px
 *
 * Process the imagecache action on the passed image
 *
 * @param $image
 * array defining an image file, including  :
 *
 *   $image- >source as the filename,
 *
 *   $image->info array
 *
 *   $image->res handle on the image object
 */
function gridactions_remove_image(&$image, $action = array()) {
  /*$remove = str_replace('remove-', '', $value);
  $value = $current_pixels - $remove;*/
  //watchdog('imagecache_gridactions', 'snap action. image: %image, action: %action.', array('%image' => print_r($image, true), '%action' => print_r($action, true)), WATCHDOG_DEBUG);
  
  $value_removewidth = floor($image->info['width'] - $action['removewidth']);
  $value_removeheight = floor($image->info['height'] - $action['removeheight']);
  
  if (!imageapi_image_scale_and_crop($image, $value_removewidth, $value_removeheight)) {
    watchdog('imagecache_gridactions', 'imagecache_scale_and_crop failed. image: %image, data: %data.', array('%path' => $image, '%data' => print_r($data, true)), WATCHDOG_ERROR);
    return false;
  }
  return true;
}

////////////////////////////////////////////////


