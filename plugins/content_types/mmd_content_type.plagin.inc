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
function mmd_content_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->title = t('');
  $block->content = '';

  // create external path to images
  if ($wrapper = file_stream_wrapper_get_instance_by_uri('public://')) {
    $path = $wrapper->getExternalUrl();
    $src_path = $path . 'mmd-img/';
    $thumbnail_path = $path . 'mmd-img/thumbnail/';
  }

  //database query
  $query = db_select('mmd','m')
    ->fields('m')
    ->orderBy('created', 'DESC');
  if(!empty($panel_args)) {
    $query->condition('mid', $panel_args, '=');
  }
  $result = $query->execute();

  $i = 1;
  while($row = $result->fetchAssoc()) {

    //prepare variable for transfer to theme function
    $vars = _mmd_prepare_vars($row, $panel_args, $i);
    $row = $vars['row'];
    $i = $vars['i'];

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
      'read_more' => $row['read_more'],
    ));
  }

  if(empty($block->content)) {
    $block->content = t('No data to show');
  };

  return $block;
}

/**
 * Create and redefine some vars in $row array;
 *
 * @param $row
 *    single result from db_select
 * @param null $arg
 *    panel argument
 * @param $i
 *
 * @return array()
 */
function _mmd_prepare_vars($row, $arg = NULL, $i) {
  if (($i % 2) == 1) {
    $row['style'] = 'odd';
    $i++;
  } else {
    $row['style'] = 'even';
    $i++;
  }
  if(empty($arg)) {
    $row['read_more'] = NULL;
    if(strlen($row['data']) >= 550) {
      $row['data'] = substr($row['data'], 0, 550) . '...';
      $row['read_more'] = '<a href="' . url(current_path() . '/' . $row['mid']) . '">' . t('Read more') . '</a>';
    }
  }
  else {
    $back_path = explode('/' , url(current_path()));
    array_pop($back_path);
    $back_path = url(implode('/',$back_path));
    $row['read_more'] = '<a href="' . $back_path . '">' . t('Back to full list') . '</a>';
  }
  $row['setting'] = unserialize($row['setting']);
  if(empty($row['setting']['filename'])) {
    $row['setting']['filename'] = 'noimage.png';
  }
  $return['row'] = $row;
  $return['i'] = $i;
  return $return;
}