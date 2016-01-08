<?php
/**
 * @file
 * mmd_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function mmd_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'dmn_content_page';
  $page->task = 'page';
  $page->admin_title = 'mmd-content-page';
  $page->admin_description = '';
  $page->path = 'mmd-content';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'MMD-Content',
    'name' => 'main-menu',
    'weight' => '22',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_dmn_content_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'dmn_content_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'mmd-content',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'MMD-content';
  $display->uuid = 'ca31d9de-7cb3-4d82-820b-79b1b520f2be';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-147023b4-dd67-43b2-bccb-de1701d4d38c';
    $pane->panel = 'middle';
    $pane->type = 'mmd_content_type.plugin';
    $pane->subtype = 'mmd_content_type.plugin';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '147023b4-dd67-43b2-bccb-de1701d4d38c';
    $display->content['new-147023b4-dd67-43b2-bccb-de1701d4d38c'] = $pane;
    $display->panels['middle'][0] = 'new-147023b4-dd67-43b2-bccb-de1701d4d38c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['dmn_content_page'] = $page;

  return $pages;

}
