<?php
/**
 * form structure
 */
function mmd_form($form, &$form_state) {
  $form['mmd_form'] = array(
    '#title' => t("dmn_form"),
    '#prefix' => '<div>',
    '#suffix' => '</div>',
    '#type' => 'fieldset',
  );

  $form['mmd_form']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('title'),
    '#size' => 80,
    '#maxlength' => 255,
    '#required' => FALSE,
  );

  $form['mmd_form']['data'] = array(
    '#type' => 'textarea',
    '#cols' => 80,
    '#rows' => 10,
    '#title' => t('First Name'),
    '#required' => FALSE,
  );
  $form['mmd_form']['file'] = array(
    '#type' => 'file',
    '#title' => 'Image',
    '#description' => t('Choose image with next extension: jpg, jpeg, png or gif'),
  );
  $form['mmd_form']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'submit',
  );

  return $form;
}