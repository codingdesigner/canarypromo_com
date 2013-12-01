<?php
// $Id: semanticviews-view-fields.tpl.php,v 1.1.2.3 2009/09/20 08:12:41 bangpound Exp $
/**
 * @file semanticviews-view-fields.tpl.php
 * Default simple view template to display all the fields as a row. The template
 * outputs a full row by looping through the $fields array, printing the field's
 * HTML element (as configured in the UI) and the class attributes. If a label
 * is specified for the field, it is printed wrapped in a <label> element with
 * the same class attributes as the field's HTML element.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output
 *     safe.
 *   - $field->element_type: The HTML element wrapping the field content and
 *     label.
 *   - $field->attributes: An array of attributes for the field wrapper.
 *   - $field->handler: The Views field handler object controlling this field.
 *     Do not use var_export to dump this object, as it can't handle the
 *     recursion.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @see template_preprocess_semanticviews_view_fields()
 * @ingroup views_templates
 * @todo Justify this template. Excluding the PHP, this template outputs angle
 * brackets, the label element, slashes and whitespace.
 */
 // dsm($fields);
?>
<?php 
  $image_icon = $fields['field_image_icon_fid'];
  unset($fields['field_image_icon_fid']);
?>
  
<div class="project-container clearfix">
<div class="details">
  <?php
  print feather_format_semanticviews_field($fields['title']);
  print feather_format_semanticviews_field($fields['field_short_description_value']);
  print feather_format_semanticviews_field($fields['tid']);
  print views_embed_view('project_related', 'block_10', $fields['nid']->raw);
  unset($fields['title']);
  unset($fields['tid']);
  unset($fields['field_short_description_value']);
  unset($fields['nid']);
  ?>
<?php foreach ($fields as $id => $field): ?>
  <?php print feather_format_semanticviews_field($field); // in template.php ?>
  <?php /*
  <?php if ($field->element_type): ?>
    <<?php print $field->element_type;?><?php print drupal_attributes($field->attributes); ?>>
  <?php endif; ?>

    <?php if ($field->label): ?>
      <label<?php print drupal_attributes($field->attributes); ?>>
        <?php print $field->label; ?>:
      </label>
    <?php endif; ?>

      <?php print $field->content; ?>

  <?php if ($field->element_type): ?>
    </<?php print $field->element_type;?>>
  <?php endif; ?>
  */ ?>
<?php endforeach; ?>
</div>

<div class="image">
<?php
  print feather_format_semanticviews_field($image_icon);
?>
</div>
</div>


