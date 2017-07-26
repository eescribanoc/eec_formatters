<?php

/**
 *
 * Render general settings form. Which entities can use this formatter
 * and which can use the fallback setting.
 * Unfortunatly this doesn't seem to do anything yet :-( / :-) ?
 *
 */
function eec_formatters_settings_form() {
    $form = array();
    $entities = array();

    foreach (entity_get_info() as $entity_type => $entity) {
        $entities[$entity_type] = $entity['label'];
    }

    $form['eec_formatters_link_formatter_entities_with_fallback'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Entities that are allowed to use the fallback setting of linking back to current entity.'),
        'description' => 'For example it would not make sense to link to a bean, or other entities without a normal full page view.',
        '#options' => $entities,
        '#default_value' => variable_get('eec_formatters_link_formatter_entities_with_fallback', array('node', 'user')),
    );

    // eec_formatters_default_colorbox_settings       eec_formatters_button_formatter_use_default_colorbox_settings
    $form['eec_formatters_button_formatter_use_custom_colorbox_js'] = array(
        '#type' => 'checkbox',
        '#title' => t('Use default colorbox settings'),
        'description' => 'It seems that there are problems if the colorbox js are not injected within the pane, if this gets solved then this setting should be unchecked. To use custom colorbox js, check the checkbox.',
        '#options' => $entities,
        '#default_value' => variable_get('eec_formatters_button_formatter_use_custom_colorbox_js', TRUE),
    );
    // eec_formatters_set_colorbox_query              eec_formatters_button_formatter_unset_colorbox_query
    $form['eec_formatters_button_formatter_unset_colorbox_query'] = array(
        '#type' => 'checkbox',
        '#title' => t('Unset colorbox query'),
        'description' => 'To unset the colorbox query check this checkbox.',
        '#options' => $entities,
        '#default_value' => variable_get('eec_formatters_button_formatter_unset_colorbox_query', TRUE),
    );
    return system_settings_form($form);
}