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
  $page->name = 'mmd_content_page';
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
      'type' => 'normal',
      'title' => '',
      'name' => 'main-menu',
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
  $handler->name = 'page_mmd_content_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'mmd_content_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel-mmd-content',
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
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e91bf3ca-97e3-468f-8320-fd3cc1035b2a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5547468a-5a9a-4102-be19-1a0c358f6ef7';
    $pane->panel = 'center';
    $pane->type = 'mmd_content_type.plagin';
    $pane->subtype = 'mmd_content_type.plagin';
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
    $pane->uuid = '5547468a-5a9a-4102-be19-1a0c358f6ef7';
    $display->content['new-5547468a-5a9a-4102-be19-1a0c358f6ef7'] = $pane;
    $display->panels['center'][0] = 'new-5547468a-5a9a-4102-be19-1a0c358f6ef7';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-5547468a-5a9a-4102-be19-1a0c358f6ef7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['mmd_content_page'] = $page;

  return $pages;

}
