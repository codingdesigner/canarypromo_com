<?php
$view = new view;
$view->name = 'project_elements';
$view->description = 'Fields from projects';
$view->tag = 'related';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'upload_fid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => FALSE,
      'text' => '',
      'make_link' => FALSE,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'trim' => FALSE,
      'max_length' => '',
      'word_boundary' => TRUE,
      'ellipsis' => TRUE,
      'strip_tags' => FALSE,
      'html' => FALSE,
    ),
    'type' => 'ul',
    'separator' => ', ',
    'empty' => '',
    'link_to_file' => 1,
    'only_listed' => 1,
    'exclude' => 0,
    'id' => 'upload_fid',
    'table' => 'node',
    'field' => 'upload_fid',
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'sticky' => array(
    'order' => 'DESC',
    'id' => 'sticky',
    'table' => 'node',
    'field' => 'sticky',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
  'title' => array(
    'order' => 'ASC',
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'nid' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'default_argument_type' => 'node',
    'default_argument' => '',
    'validate_type' => 'node',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '',
    'validate_argument_node_type' => array(
      'project' => 'project',
      'blog' => 0,
      'case_study' => 0,
      'client' => 0,
      'event' => 0,
      'flex_feature' => 0,
      'happening' => 0,
      'page' => 0,
      'press_mention' => 0,
      'press_release' => 0,
      'profile' => 0,
      'service' => 0,
      'testimonial' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '2' => 0,
      '3' => 0,
      '4' => 0,
      '5' => 0,
      '1' => 0,
      '6' => 0,
      '7' => 0,
      '8' => 0,
    ),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
));
$handler->override_option('filters', array(
  'status_extra' => array(
    'operator' => '=',
    'value' => '',
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'status_extra',
    'table' => 'node',
    'field' => 'status_extra',
    'relationship' => 'none',
  ),
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'project' => 'project',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'none',
));
$handler->override_option('cache', array(
  'type' => 'none',
));
$handler->override_option('header_format', '1');
$handler->override_option('header_empty', 0);
$handler->override_option('items_per_page', 1);
$handler->override_option('style_plugin', 'semanticviews_default');
$handler->override_option('style_options', array(
  'grouping' => '',
  'group' => array(
    'element_type' => 'h3',
    'class' => 'title',
  ),
  'list' => array(
    'element_type' => '',
    'class' => '',
  ),
  'row' => array(
    'element_type' => 'div',
    'class' => 'item-#',
    'last_every_nth' => '0',
    'first_class' => 'first',
    'last_class' => 'last',
    'striping_classes' => 'odd even',
  ),
));
$handler->override_option('row_plugin', 'semanticviews_fields');
$handler->override_option('row_options', array(
  'semantic_html' => array(
    'tid_1' => array(
      'element_type' => 'div',
      'class' => 'medium',
    ),
    'tid' => array(
      'element_type' => 'div',
      'class' => 'responsibilities',
    ),
    'field_related_service_nid' => array(
      'element_type' => 'div',
      'class' => 'services',
    ),
  ),
  'skip_blank' => 1,
));
$handler = $view->new_display('block', 'Downloads Block', 'block_1');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'field_image_fid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'download_thumb_imagelink',
    'multiple' => array(
      'group' => 1,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_image_fid',
    'table' => 'node_data_field_image',
    'field' => 'field_image_fid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'field_image_fid_1' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'default',
    'multiple' => array(
      'group' => 1,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_image_fid_1',
    'table' => 'node_data_field_image',
    'field' => 'field_image_fid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'upload_fid' => array(
    'label' => 'Attached files',
    'alter' => array(
      'alter_text' => FALSE,
      'text' => '',
      'make_link' => FALSE,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'trim' => FALSE,
      'max_length' => '',
      'word_boundary' => TRUE,
      'ellipsis' => TRUE,
      'strip_tags' => FALSE,
      'html' => FALSE,
    ),
    'type' => 'ul',
    'separator' => ', ',
    'empty' => '',
    'link_to_file' => 1,
    'only_listed' => 1,
    'exclude' => 0,
    'id' => 'upload_fid',
    'table' => 'node',
    'field' => 'upload_fid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('title', 'Downloads');
$handler->override_option('style_plugin', 'default');
$handler->override_option('style_options', array());
$handler->override_option('row_plugin', 'fields');
$handler->override_option('row_options', array(
  'inline' => array(
    'field_image_fid' => 'field_image_fid',
    'field_image_fid_1' => 'field_image_fid_1',
  ),
  'separator' => '',
));
$handler->override_option('block_description', 'Downloads Project Block');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('block', 'Images Block', 'block_2');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'field_image_fid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'imagefield__lightbox2__rightcol_grid_br_rounded__original',
    'multiple' => array(
      'group' => 0,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_image_fid',
    'table' => 'node_data_field_image',
    'field' => 'field_image_fid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'random' => array(
    'order' => 'ASC',
    'id' => 'random',
    'table' => 'views',
    'field' => 'random',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('items_per_page', 0);
$handler->override_option('style_plugin', 'views_rotator');
$handler->override_option('style_options', array(
  'timeout' => '5',
  'speed' => '1',
  'pause' => 1,
  'back_next_buttons' => 0,
  'height' => '124',
));
$handler->override_option('row_plugin', 'fields');
$handler->override_option('row_options', array(
  'inline' => array(
    'field_image_fid' => 'field_image_fid',
    'field_image_fid_1' => 'field_image_fid_1',
  ),
  'separator' => '',
));
$handler->override_option('block_description', 'Images Project Block');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('block', 'Bird\'s Eye View Block', 'block_3');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'tid_1' => array(
    'label' => 'Medium',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'type' => 'separator',
    'separator' => ', ',
    'empty' => '',
    'link_to_taxonomy' => 1,
    'limit' => 1,
    'vids' => array(
      '3' => 3,
      '2' => 0,
      '4' => 0,
      '5' => 0,
      '1' => 0,
      '6' => 0,
      '7' => 0,
      '8' => 0,
    ),
    'exclude' => 0,
    'id' => 'tid_1',
    'table' => 'term_node',
    'field' => 'tid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'tid' => array(
    'label' => 'Responsibilities',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'type' => 'separator',
    'separator' => ', ',
    'empty' => '',
    'link_to_taxonomy' => 1,
    'limit' => 1,
    'vids' => array(
      '4' => 4,
      '2' => 0,
      '3' => 0,
      '5' => 0,
      '1' => 0,
      '6' => 0,
      '7' => 0,
      '8' => 0,
    ),
    'exclude' => 0,
    'id' => 'tid',
    'table' => 'term_node',
    'field' => 'tid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'field_related_service_nid' => array(
    'label' => 'Service{s}',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'custom',
    'format' => 'default',
    'multiple' => array(
      'group' => 1,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_related_service_nid',
    'table' => 'node_data_field_related_service',
    'field' => 'field_related_service_nid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('title', 'Bird\'s Eye View');
$handler->override_option('block_description', 'Bird\'s Eye View Project Block');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('attachment', 'Related by Client Attachment', 'attachment_1');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'field_related_client_nid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'plain',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 1,
    'id' => 'field_related_client_nid',
    'table' => 'node_data_field_related_client',
    'field' => 'field_related_client_nid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'title' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'field_related_client_nid' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'default_argument_type' => 'php',
    'default_argument' => '',
    'validate_type' => 'node',
    'validate_fail' => 'not found',
    'break_phrase' => 0,
    'not' => 0,
    'id' => 'field_related_client_nid',
    'table' => 'node_data_field_related_client',
    'field' => 'field_related_client_nid',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '$n = node_load(arg(1));
$rel_client = $n->field_related_client[0][\'nid\'];
return $rel_client;',
    'validate_argument_node_type' => array(
      'client' => 'client',
      'blog' => 0,
      'case_study' => 0,
      'event' => 0,
      'flex_feature' => 0,
      'happening' => 0,
      'page' => 0,
      'press_mention' => 0,
      'press_release' => 0,
      'profile' => 0,
      'project' => 0,
      'service' => 0,
      'testimonial' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '2' => 0,
      '3' => 0,
      '4' => 0,
      '5' => 0,
      '1' => 0,
      '6' => 0,
      '7' => 0,
      '8' => 0,
    ),
    'validate_argument_type' => 'tid',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
));
$handler->override_option('header', '<div class="related-projects">Related Projects</div>
<span class="related-projects-type">By Client: </span>');
$handler->override_option('header_format', '3');
$handler->override_option('items_per_page', 10);
$handler->override_option('row_options', array(
  'semantic_html' => array(
    'title' => array(
      'element_type' => 'div',
      'class' => 'title',
    ),
  ),
  'skip_blank' => 1,
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', 0);
$handler->override_option('inherit_exposed_filters', FALSE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'block_3' => 'block_3',
  'default' => 0,
  'block_1' => 0,
  'block_2' => 0,
));
$handler = $view->new_display('attachment', 'Related by Industry Attachment', 'attachment_2');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'name' => array(
    'label' => 'Term',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_taxonomy' => 0,
    'exclude' => 1,
    'id' => 'name',
    'table' => 'term_data',
    'field' => 'name',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'title' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('arguments', array(
  'name' => array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'title' => '',
    'default_argument_type' => 'php',
    'default_argument' => '',
    'validate_type' => 'taxonomy_term',
    'validate_fail' => 'not found',
    'glossary' => 0,
    'limit' => '0',
    'case' => 'none',
    'path_case' => 'none',
    'transform_dash' => 0,
    'add_table' => 0,
    'require_value' => 0,
    'id' => 'name',
    'table' => 'term_data',
    'field' => 'name',
    'validate_user_argument_type' => 'uid',
    'validate_user_roles' => array(
      '2' => 0,
    ),
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
    'default_options_div_prefix' => '',
    'default_argument_user' => 0,
    'default_argument_fixed' => '',
    'default_argument_php' => '$n = node_load(arg(1));
foreach($n->taxonomy as $tx){
	if($tx->vid == 5){
		$term = $tx->name;
		return $term;
	}
}',
    'validate_argument_node_type' => array(
      'blog' => 0,
      'case_study' => 0,
      'client' => 0,
      'event' => 0,
      'flex_feature' => 0,
      'happening' => 0,
      'page' => 0,
      'press_mention' => 0,
      'press_release' => 0,
      'profile' => 0,
      'project' => 0,
      'service' => 0,
      'testimonial' => 0,
    ),
    'validate_argument_node_access' => 0,
    'validate_argument_nid_type' => 'nid',
    'validate_argument_vocabulary' => array(
      '5' => 5,
      '2' => 0,
      '3' => 0,
      '4' => 0,
      '1' => 0,
      '6' => 0,
      '7' => 0,
      '8' => 0,
    ),
    'validate_argument_type' => 'name',
    'validate_argument_transform' => 0,
    'validate_user_restrict_roles' => 0,
    'validate_argument_php' => '',
  ),
));
$handler->override_option('header', '<span class="related-projects-type">By Industry: </span>');
$handler->override_option('header_format', '3');
$handler->override_option('items_per_page', 10);
$handler->override_option('row_options', array(
  'semantic_html' => array(
    'title' => array(
      'element_type' => 'div',
      'class' => 'title',
    ),
  ),
  'skip_blank' => 1,
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', 0);
$handler->override_option('inherit_exposed_filters', FALSE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'block_3' => 'block_3',
  'default' => 0,
  'block_1' => 0,
  'block_2' => 0,
));
$handler = $view->new_display('block', 'Links Block', 'block_4');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'field_link_out_url' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'default',
    'multiple' => array(
      'group' => 1,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_link_out_url',
    'table' => 'node_data_field_link_out',
    'field' => 'field_link_out_url',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('title', 'Links');
$handler->override_option('row_options', array(
  'semantic_html' => array(
    'field_link_out_url' => array(
      'element_type' => 'div',
      'class' => 'ext-link',
    ),
  ),
  'skip_blank' => 1,
));
$handler->override_option('block_description', 'Links Project Block');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('block', 'Project Feature Image Block', 'block_5');
$handler->override_option('fields', array(
  'field_image_feature_fid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'vignette_homepage_feature_default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_image_feature_fid',
    'table' => 'node_data_field_image_feature',
    'field' => 'field_image_feature_fid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('row_options', array(
  'semantic_html' => array(
    'field_image_feature_fid' => array(
      'element_type' => 'div',
      'class' => 'feature-image',
    ),
  ),
  'skip_blank' => 1,
));
$handler->override_option('block_description', 'Project Feature Image Block');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('block', 'Project Header Overview Block', 'block_6');
$handler->override_option('fields', array(
  'field_related_client_nid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 1,
      'text' => '<h2>[field_related_client_nid]</h2>',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'plain',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_related_client_nid',
    'table' => 'node_data_field_related_client',
    'field' => 'field_related_client_nid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
  'field_short_description_value' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'default',
    'multiple' => array(
      'group' => TRUE,
      'multiple_number' => '',
      'multiple_from' => '',
      'multiple_reversed' => FALSE,
    ),
    'exclude' => 0,
    'id' => 'field_short_description_value',
    'table' => 'node_data_field_short_description',
    'field' => 'field_short_description_value',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('row_options', array(
  'semantic_html' => array(
    'field_related_client_nid' => array(
      'element_type' => 'div',
      'class' => 'related-client',
    ),
    'field_short_description_value' => array(
      'element_type' => 'div',
      'class' => 'teaser',
    ),
  ),
  'skip_blank' => 1,
));
$handler->override_option('block_description', 'Project Header Overview Block');
$handler->override_option('block_caching', -1);
$handler = $view->new_display('attachment', 'Images Block Attach 1', 'attachment_3');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'field_image_fid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'imagefield__lightbox2__rightcol_grid_bl_rounded__original',
    'multiple' => array(
      'group' => 0,
      'multiple_number' => '1',
      'multiple_from' => '1',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_image_fid',
    'table' => 'node_data_field_image',
    'field' => 'field_image_fid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'random' => array(
    'id' => 'random',
    'table' => 'views',
    'field' => 'random',
  ),
));
$handler->override_option('items_per_page', 0);
$handler->override_option('style_plugin', 'views_rotator');
$handler->override_option('style_options', array(
  'timeout' => '6',
  'speed' => '1',
  'pause' => 1,
  'back_next_buttons' => 0,
  'height' => '124',
));
$handler->override_option('row_plugin', 'fields');
$handler->override_option('row_options', array(
  'inline' => array(
    'field_image_fid' => 'field_image_fid',
    'field_image_fid_1' => 'field_image_fid_1',
  ),
  'separator' => '',
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', FALSE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'block_2' => 'block_2',
  'default' => 0,
  'block_1' => 0,
  'block_3' => 0,
  'block_4' => 0,
  'block_5' => 0,
  'block_6' => 0,
));
$handler = $view->new_display('attachment', 'Images Block Attach 2', 'attachment_4');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'field_image_fid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'imagefield__lightbox2__rightcol_grid_tr_rounded__original',
    'multiple' => array(
      'group' => 0,
      'multiple_number' => '1',
      'multiple_from' => '2',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_image_fid',
    'table' => 'node_data_field_image',
    'field' => 'field_image_fid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'random' => array(
    'id' => 'random',
    'table' => 'views',
    'field' => 'random',
  ),
));
$handler->override_option('items_per_page', 0);
$handler->override_option('style_plugin', 'views_rotator');
$handler->override_option('style_options', array(
  'timeout' => '7',
  'speed' => '1',
  'pause' => 1,
  'back_next_buttons' => 0,
  'height' => '',
));
$handler->override_option('row_plugin', 'fields');
$handler->override_option('row_options', array(
  'inline' => array(
    'field_image_fid' => 'field_image_fid',
    'field_image_fid_1' => 'field_image_fid_1',
  ),
  'separator' => '',
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', FALSE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'block_2' => 'block_2',
  'default' => 0,
  'block_1' => 0,
  'block_3' => 0,
  'block_4' => 0,
  'block_5' => 0,
  'block_6' => 0,
));
$handler = $view->new_display('attachment', 'Images Block Attach 3', 'attachment_5');
$handler->override_option('fields', array(
  'nid' => array(
    'label' => 'Nid',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'exclude' => 1,
    'id' => 'nid',
    'table' => 'node',
    'field' => 'nid',
    'relationship' => 'none',
  ),
  'field_image_fid' => array(
    'label' => '',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'link_class' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 0,
    'label_type' => 'none',
    'format' => 'imagefield__lightbox2__rightcol_grid_tl_rounded__original',
    'multiple' => array(
      'group' => 0,
      'multiple_number' => '1',
      'multiple_from' => '3',
      'multiple_reversed' => 0,
    ),
    'exclude' => 0,
    'id' => 'field_image_fid',
    'table' => 'node_data_field_image',
    'field' => 'field_image_fid',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  ),
));
$handler->override_option('sorts', array(
  'random' => array(
    'id' => 'random',
    'table' => 'views',
    'field' => 'random',
  ),
));
$handler->override_option('items_per_page', 0);
$handler->override_option('style_plugin', 'views_rotator');
$handler->override_option('style_options', array(
  'timeout' => '8',
  'speed' => '1',
  'pause' => 1,
  'back_next_buttons' => 0,
  'height' => '124',
));
$handler->override_option('row_plugin', 'fields');
$handler->override_option('row_options', array(
  'inline' => array(
    'field_image_fid' => 'field_image_fid',
    'field_image_fid_1' => 'field_image_fid_1',
  ),
  'separator' => '',
));
$handler->override_option('attachment_position', 'after');
$handler->override_option('inherit_arguments', TRUE);
$handler->override_option('inherit_exposed_filters', FALSE);
$handler->override_option('inherit_pager', FALSE);
$handler->override_option('render_pager', TRUE);
$handler->override_option('displays', array(
  'block_2' => 'block_2',
  'default' => 0,
  'block_1' => 0,
  'block_3' => 0,
  'block_4' => 0,
  'block_5' => 0,
  'block_6' => 0,
));
