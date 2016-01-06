<?php
/**
 * @file
 * mmd_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function mmd_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_mmd-content:mmd-content.
  $menu_links['main-menu_mmd-content:mmd-content'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'mmd-content',
    'router_path' => 'mmd-content',
    'link_title' => 'MMD-Content',
    'options' => array(
      'identifier' => 'main-menu_mmd-content:mmd-content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 22,
    'customized' => 0,
  );
  // Exported menu link: main-menu_mmd-form:mmd.
  $menu_links['main-menu_mmd-form:mmd'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'mmd',
    'router_path' => 'mmd',
    'link_title' => 'MMD Form',
    'options' => array(
      'attributes' => array(
        'title' => 'My.Module.D',
      ),
      'identifier' => 'main-menu_mmd-form:mmd',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 21,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('MMD Form');
  t('MMD-Content');

  return $menu_links;
}
