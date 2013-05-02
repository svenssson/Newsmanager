<?php

/**
 * @file
 * Administration settings for Newsmanager Module
 */

/**
 * Administration settings form.
 *
 * @return
 *   The completed form definition.
 */
function newsmanager_admin_settings() {
	// Define the form array
	$form = array();
	
	// Define general settings fieldset
	$form['newsmanager_general_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('General settings'),
	);

	// Load installed languages
	$languages = language_list('enabled');
	$i = 0;
	foreach(array_keys($languages[1]) as $key) {
		$form_lang[$i] = $languages[1][$key]->name;
		$i++;
	}

	// Define content of general settings fieldset
	$form['newsmanager_general_settings']['newsmanager_show_author'] = array(
		'#type' => 'checkbox',
		'#title' => t('Show author and date information for articles.'),
		'#default_value' => variable_get('node_submitted_newsarticle'),
	);

	$form['#submit'][] = 'newsmanager_admin_settings_submit';

	return system_settings_form($form);
}

function newsmanager_admin_settings_submit($form, &$form_state) {
	variable_set('node_submitted_newsarticle', $form['newsmanager_general_settings']['newsmanager_show_author']['#value']);
}