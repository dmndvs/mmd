<?php
/**
 * @file mmd.form.inc
 * Contain all form functions
 */

/**
 * form structure
 */
function mmd_form($form, &$form_state) {
  $form['mmd_form'] = array(
    '#title' => t("dmn_form"),
    '#type' => 'fieldset',
  );

  $form['mmd_form']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#size' => 80,
    '#maxlength' => 255,
    '#required' => TRUE,
  );

  $form['mmd_form']['checkbox'] = array(
    '#type' => 'checkbox',
    '#title' => t("It's important"),
  );

  $form['mmd_form']['file'] = array(
    '#type' => 'file',
    '#description' => t('Choose image with next extension: jpg, jpeg, png or gif') . '<br>' . t('max size: 1mb'),
  );

  $form['mmd_form']['data'] = array(
    '#type' => 'textarea',
    '#cols' => 80,
    '#rows' => 10,
    '#title' => t('First Name'),
    '#required' => FALSE,
  );


  $form['mmd_form']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('submit'),
  );

  return $form;
}

/**
 * form validation
 *
 * @see mmd_form()
 */
function mmd_form_validate($form, &$form_state) {

  $form_state['values']['title'] = _mmd_clear_data($form_state['values']['title']);
  $form_state['values']['data'] = _mmd_clear_data($form_state['values']['data'], 'data');

  if(strlen($form_state['values']['title']) >= 250) {
    form_set_error('title', t('title length is too long'));
  }

  /**
   * Check file, upload, rename and create thumbnail
   */
  if(isset($form_state['values']['file'])) {
    $validators = array(
      'file_validate_is_image' => array(),
      'file_validate_extensions' => array('png gif jpg jpeg'),
      'file_validate_size' => array(1 * 1024 * 1024),
    );

    if ($file = file_save_upload('file', $validators, 'public://mmd-img/')) {
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);

      $extension = pathinfo($file->filename, PATHINFO_EXTENSION);

      $filename = time() . '_' . rand(1,99999) . '.' . $extension;
      file_move($file, 'public://mmd-img/'. $filename);
      $file->filename = $filename;

      if(_mmd_create_img_thumbnail($file->filename)) {
        $form_state['values']['file'] = $file;
      }
      else {
        unset($form_state['values']['file']);
        drupal_unlink('public://mmd-img/' . $file->filename);
      }
    }
  }
}

/**
 * submit handler
 *
 * @see mmd_form()
 * @see mmd_form_validate()
 */
function mmd_form_submit($form, &$form_state) {
  if(_mmd_insert_into_db($form_state)) {
    drupal_set_message(t('Added new item: @title', array('@title' => $form_state['values']['title'])));
  }
  else {
    drupal_set_message(t('Something went wrong'), 'error');
  }

}

/**
 * Handler, that insert validated data into database
 *
 * @see mmd_form()
 * @see mmd_form_validate()
 * @see mmd_form_submit()
 */
function _mmd_insert_into_db(&$form_state) {

  /**
   * creating settings array:
   */
  $setting = array();
  $setting['importance'] = $form_state['values']['checkbox'];

  if(isset($form_state['values']['file']->filename)) {
    $setting['filename'] = $form_state['values']['file']->filename;
  }
  $data = array(
    'title' => $form_state['values']['title'],
    'data' => $form_state['values']['data'],
    'created' => time(),
    'setting' => $setting,
  );
  if (drupal_write_record('mmd', $data)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Handler, that clear not allowed tags
 *
 * @param $data - input string value from form
 * @param $type - type of data
 * @return string
 */
function _mmd_clear_data($data, $type = NULL) {
  if($type == 'data') {
    $data = check_plain($data);
  }
  else {
    $data = drupal_html_to_text($data);
  }
  return $data;
}

/**
 * Handler, that created thumbnail of src image.
 * @param $src - filename of uploaded img
 * @return TRUE or FALSE.
 */
function _mmd_create_img_thumbnail($src) {
      $img = image_load('public://mmd-img/' . $src);
      if ($img->info['width'] >= 150) {
        image_resize($img, 150, ($img->info['height'] * 150 / $img->info['width']));
      }
      if(image_save($img, 'public://mmd-img/thumbnail/' . $src)) {
        return TRUE;
      }
      else {
        return FALSE;
      }
}



