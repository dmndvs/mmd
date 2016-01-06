<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('mmd-content'),
  'description' => t('Show added content by mmd_form'),
  'category' => t('Content'),
  'render callback' => 'mmd_content_render',
);

/**
 * Callback for ctools content_type plugin
 */
function mmd_content_render() {
  $block = new stdClass();
  $block->title = t('MMD Content');
  $block->content = '';

  // create external path for images
  if ($wrapper = file_stream_wrapper_get_instance_by_uri('public://')) {
    $path = $wrapper->getExternalUrl();
    $src_path = $path . 'mmd-img/';
    $thumbnail_path = $path . 'mmd-img/thumbnail/';
  }

  $result = db_select('mmd','m')
    ->fields('m')
    ->orderBy('created', 'DESC')
    ->execute();

  $i = 1;
  while($row = $result->fetchAssoc()) {

    // creating general class style for row
    if (($i % 2) == 1) {
      $row['style'] = 'odd';
      $i++;
    } else {
      $row['style'] = 'even';
      $i++;
    }

    $row['setting'] = unserialize($row['setting']);
    if(empty($row['setting']['filename'])) {
      $row['setting']['filename'] = 'noimage.png';
    }
    $block->content .= theme('mmd_display_item', array(
      'title' => $row['title'],
      'data' => $row['data'],
      'created' => date('r',$row['created']),
      'img' => $row['setting']['filename'],
      'importance' => $row['setting']['importance'],
      'src_path' => $src_path,
      'thumbnail_path' => $thumbnail_path,
      'imp_img' => 'imp.png',
      'row' => $row['style'],
    ));
  }
  return $block;
}