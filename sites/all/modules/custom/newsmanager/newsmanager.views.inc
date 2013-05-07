<?php

/**
 * Implements hook_views_api().
 */
function newsmanager_views_api() {
	return array(
		'api' => 3,
		'path' => drupal_get_path('module', 'newsmanager'),
	);
}

/**
 * Implements hook_views_default_views().
 */
function newsmanager_views_default_views() {
	$t = get_t();

	$views = array();

	// Create Teaser View
	$view = new view();
	$view->name = 'newsarticle_teaser_view';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'node';
	$view->human_name = 'Newsarticle Teaser View';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Newsarticle Teaser View';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '5';
	$handler->display->display_options['pager']['options']['tags']['first'] = '« first page';
	$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ previous page';
	$handler->display->display_options['pager']['options']['tags']['next'] = 'next page ›';
	$handler->display->display_options['pager']['options']['tags']['last'] = 'last page »';
	$handler->display->display_options['style_plugin'] = 'grid';
	$handler->display->display_options['style_options']['columns'] = '2';
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['row_options']['inline'] = array(
		'title' => 'title',
	);
	/* Feld: Inhalt: Bild */
	$handler->display->display_options['fields']['field_newsarticle_image']['id'] = 'field_newsarticle_image';
	$handler->display->display_options['fields']['field_newsarticle_image']['table'] = 'field_data_field_newsarticle_image';
	$handler->display->display_options['fields']['field_newsarticle_image']['field'] = 'field_newsarticle_image';
	$handler->display->display_options['fields']['field_newsarticle_image']['label'] = '';
	$handler->display->display_options['fields']['field_newsarticle_image']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_newsarticle_image']['click_sort_column'] = 'fid';
	$handler->display->display_options['fields']['field_newsarticle_image']['settings'] = array(
		'image_style' => 'thumbnail',
		'image_link' => 'content',
	);
	/* Feld: Inhalt: Titel */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	/* Feld: Inhalt: Body */
	$handler->display->display_options['fields']['body']['id'] = 'body';
	$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
	$handler->display->display_options['fields']['body']['field'] = 'body';
	$handler->display->display_options['fields']['body']['label'] = '';
	$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
	$handler->display->display_options['fields']['body']['settings'] = array(
		'trim_length' => '50',
	);
	/* Sort criterion: Inhalt: Post date */
	$handler->display->display_options['sorts']['created']['id'] = 'created';
	$handler->display->display_options['sorts']['created']['table'] = 'node';
	$handler->display->display_options['sorts']['created']['field'] = 'created';
	$handler->display->display_options['sorts']['created']['order'] = 'DESC';
	/* Filter criterion: Inhalt: Veröffentlicht */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'node';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value'] = 1;
	$handler->display->display_options['filters']['status']['group'] = 1;
	$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
	/* Filter criterion: Inhalt: Typ */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'node';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
		'newsarticle' => 'newsarticle',
	);
	/* Filter criterion: Inhalt: End Date (field_newsarticle_end_date) */
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['id'] = 'field_newsarticle_end_date_value';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['table'] = 'field_data_field_newsarticle_end_date';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['field'] = 'field_newsarticle_end_date_value';
	/* Filter criterion: Inhalt: Start Date (field_newsarticle_start_date) */
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['id'] = 'field_newsarticle_start_date_value';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['table'] = 'field_data_field_newsarticle_start_date';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['field'] = 'field_newsarticle_start_date_value';

	/* Display: Block */
	$handler = $view->new_display('block', 'Block', 'block');
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: Inhalt: Veröffentlicht */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'node';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value'] = 1;
	$handler->display->display_options['filters']['status']['group'] = 1;
	$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
	/* Filter criterion: Inhalt: Typ */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'node';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
		'newsarticle' => 'newsarticle',
	);
	/* Filter criterion: Inhalt: Start Date (field_newsarticle_start_date) */
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['id'] = 'field_newsarticle_start_date_value';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['table'] = 'field_data_field_newsarticle_start_date';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['field'] = 'field_newsarticle_start_date_value';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['operator'] = '<=';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['granularity'] = 'minute';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['form_type'] = 'date_text';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['default_date'] = 'now';
	/* Filter criterion: Inhalt: End Date (field_newsarticle_end_date) */
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['id'] = 'field_newsarticle_end_date_value';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['table'] = 'field_data_field_newsarticle_end_date';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['field'] = 'field_newsarticle_end_date_value';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['operator'] = '>=';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['granularity'] = 'minute';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['form_type'] = 'date_text';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['default_date'] = 'now';
	/* Filter criterion: Inhalt: Sprache */
	$handler->display->display_options['filters']['language']['id'] = 'language';
	$handler->display->display_options['filters']['language']['table'] = 'node';
	$handler->display->display_options['filters']['language']['field'] = 'language';
	$handler->display->display_options['filters']['language']['value'] = array(
		'***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
	);

	$translatables['newsarticle_teaser_view'] = array(
		t('Master'),
		t('Newsarticle Teaser View'),
		t('more'),
		t('Apply'),
		t('Reset'),
		t('Sort by'),
		t('Asc'),
		t('Desc'),
		t('Items per page'),
		t('- All -'),
		t('Offset'),
		t('« first page'),
		t('‹ previous page'),
		t('next page ›'),
		t('last page »'),
		t('Block'),
	);

	$views[$view->name] = $view;

	// Create Overview View
	$view = new view();
	$view->name = 'newsarticle_overview_view';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'node';
	$view->human_name = 'Newsarticle Overview View';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Newsarticle Overview';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['pager']['options']['tags']['first'] = '« first page';
	$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ previous page';
	$handler->display->display_options['pager']['options']['tags']['next'] = 'next page ›';
	$handler->display->display_options['pager']['options']['tags']['last'] = 'last page »';
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['row_plugin'] = 'node';
	/* No results behavior: Global: Unfiltered text */
	$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
	$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
	$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
	$handler->display->display_options['empty']['area_text_custom']['label'] = 'No articles found!';
	$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
	$handler->display->display_options['empty']['area_text_custom']['content'] = 'No articles were found.<br>Try adjusting your filter criteria.';
	/* Feld: Inhalt: Titel */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	/* Sort criterion: Inhalt: Post date */
	$handler->display->display_options['sorts']['created']['id'] = 'created';
	$handler->display->display_options['sorts']['created']['table'] = 'node';
	$handler->display->display_options['sorts']['created']['field'] = 'created';
	$handler->display->display_options['sorts']['created']['order'] = 'DESC';
	/* Filter criterion: Inhalt: Veröffentlicht */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'node';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value'] = 1;
	$handler->display->display_options['filters']['status']['group'] = 1;
	$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
	/* Filter criterion: Inhalt: Typ */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'node';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
		'newsarticle' => 'newsarticle',
	);
	/* Filter criterion: Inhalt: Start Date (field_newsarticle_start_date) */
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['id'] = 'field_newsarticle_start_date_value';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['table'] = 'field_data_field_newsarticle_start_date';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['field'] = 'field_newsarticle_start_date_value';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['operator'] = '<=';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['expose']['operator_id'] = 'field_newsarticle_start_date_value_op';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['expose']['label'] = 'Start Date (field_newsarticle_start_date)';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['expose']['operator'] = 'field_newsarticle_start_date_value_op';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['expose']['identifier'] = 'field_newsarticle_start_date_value';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['expose']['remember_roles'] = array(
		2 => '2',
		1 => 0,
		3 => 0,
	);
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['granularity'] = 'minute';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['form_type'] = 'date_text';
	$handler->display->display_options['filters']['field_newsarticle_start_date_value']['default_date'] = 'now';
	/* Filter criterion: Inhalt: End Date (field_newsarticle_end_date) */
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['id'] = 'field_newsarticle_end_date_value';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['table'] = 'field_data_field_newsarticle_end_date';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['field'] = 'field_newsarticle_end_date_value';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['operator'] = '>=';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['expose']['operator_id'] = 'field_newsarticle_end_date_value_op';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['expose']['label'] = 'End Date (field_newsarticle_end_date)';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['expose']['operator'] = 'field_newsarticle_end_date_value_op';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['expose']['identifier'] = 'field_newsarticle_end_date_value';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['granularity'] = 'minute';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['form_type'] = 'date_text';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['default_date'] = 'now';
	/* Filter criterion: Inhalt: Sprache */
	$handler->display->display_options['filters']['language']['id'] = 'language';
	$handler->display->display_options['filters']['language']['table'] = 'node';
	$handler->display->display_options['filters']['language']['field'] = 'language';
	$handler->display->display_options['filters']['language']['value'] = array(
		'***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
	);
	/* Filter criterion: Inhalt: Datum (field_newsarticle_date) */
	$handler->display->display_options['filters']['field_newsarticle_date_value']['id'] = 'field_newsarticle_date_value';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['table'] = 'field_data_field_newsarticle_date';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['field'] = 'field_newsarticle_date_value';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['operator'] = 'between';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['exposed'] = TRUE;
	$handler->display->display_options['filters']['field_newsarticle_date_value']['expose']['operator_id'] = 'field_newsarticle_date_value_op';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['expose']['label'] = 'Datum';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['expose']['operator'] = 'field_newsarticle_date_value_op';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['expose']['identifier'] = 'field_newsarticle_date_value';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['expose']['remember_roles'] = array(
		2 => '2',
		1 => 0,
		3 => 0,
	);
	$handler->display->display_options['filters']['field_newsarticle_date_value']['form_type'] = 'date_popup';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['year_range'] = '-10:+0';

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['path'] = 'newsarticle-overview';
	$translatables['newsarticle_overview_view'] = array(
		t('Master'),
		t('Newsarticle Overview'),
		t('more'),
		t('Apply'),
		t('Reset'),
		t('Sort by'),
		t('Asc'),
		t('Desc'),
		t('Items per page'),
		t('- All -'),
		t('Offset'),
		t('« first page'),
		t('‹ previous page'),
		t('next page ›'),
		t('last page »'),
		t('Start Date'),
		t('End Date'),
		t('Page'),
	);

	$views[$view->name] = $view;

	// Create Archive View
	$view = new view();
	$view->name = 'newsarticle_archive_view';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'node';
	$view->human_name = 'Newsarticle Archive View';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Newsarticle Archive View';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Reset';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['pager']['options']['tags']['first'] = '« first page';
	$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ previous page';
	$handler->display->display_options['pager']['options']['tags']['next'] = 'next page ›';
	$handler->display->display_options['pager']['options']['tags']['last'] = 'last page »';
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['row_plugin'] = 'node';
	/* No results behavior: Global: Unfiltered text */
	$handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
	$handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
	$handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
	$handler->display->display_options['empty']['area_text_custom']['label'] = 'No articles found!';
	$handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
	$handler->display->display_options['empty']['area_text_custom']['content'] = 'No articles were found.<br>Try adjusting your filter criteria.';
	/* Feld: Inhalt: Titel */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	/* Sort criterion: Inhalt: Post date */
	$handler->display->display_options['sorts']['created']['id'] = 'created';
	$handler->display->display_options['sorts']['created']['table'] = 'node';
	$handler->display->display_options['sorts']['created']['field'] = 'created';
	$handler->display->display_options['sorts']['created']['order'] = 'DESC';
	/* Filter criterion: Inhalt: Veröffentlicht */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'node';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value'] = 1;
	$handler->display->display_options['filters']['status']['group'] = 1;
	$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
	/* Filter criterion: Inhalt: Typ */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'node';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
		'newsarticle' => 'newsarticle',
	);
	/* Filter criterion: Inhalt: End Date (field_newsarticle_end_date) */
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['id'] = 'field_newsarticle_end_date_value';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['table'] = 'field_data_field_newsarticle_end_date';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['field'] = 'field_newsarticle_end_date_value';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['operator'] = '<=';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['granularity'] = 'minute';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['form_type'] = 'date_text';
	$handler->display->display_options['filters']['field_newsarticle_end_date_value']['default_date'] = 'now';
	/* Filter criterion: Inhalt: Sprache */
	$handler->display->display_options['filters']['language']['id'] = 'language';
	$handler->display->display_options['filters']['language']['table'] = 'node';
	$handler->display->display_options['filters']['language']['field'] = 'language';
	$handler->display->display_options['filters']['language']['value'] = array(
		'***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
	);
	/* Filter criterion: Inhalt: Datum (field_newsarticle_date) */
	$handler->display->display_options['filters']['field_newsarticle_date_value']['id'] = 'field_newsarticle_date_value';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['table'] = 'field_data_field_newsarticle_date';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['field'] = 'field_newsarticle_date_value';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['operator'] = 'between';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['exposed'] = TRUE;
	$handler->display->display_options['filters']['field_newsarticle_date_value']['expose']['operator_id'] = 'field_newsarticle_date_value_op';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['expose']['label'] = 'Datum';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['expose']['operator'] = 'field_newsarticle_date_value_op';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['expose']['identifier'] = 'field_newsarticle_date_value';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['expose']['remember_roles'] = array(
		2 => '2',
		1 => 0,
		3 => 0,
	);
	$handler->display->display_options['filters']['field_newsarticle_date_value']['form_type'] = 'date_popup';
	$handler->display->display_options['filters']['field_newsarticle_date_value']['year_range'] = '-10:+0';

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['path'] = 'newsarticle-archive';
	$translatables['newsarticle_archive_view'] = array(
		t('Master'),
		t('Newsarticle Archive View'),
		t('more'),
		t('Apply'),
		t('Reset'),
		t('Sort by'),
		t('Asc'),
		t('Desc'),
		t('Items per page'),
		t('- All -'),
		t('Offset'),
		t('« first page'),
		t('‹ previous page'),
		t('next page ›'),
		t('last page »'),
		t('Page'),
	);

	$views[$view->name] = $view;

	return $views;
}