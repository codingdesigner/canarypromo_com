<?php
// $Id: semanticviews-view-unformatted.tpl.php,v 1.1.2.3 2009/09/19 22:33:48 bangpound Exp $
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
 //split rows array in half to create columns
$num_rows = count($rows);
$split = ceil($num_rows / 2);
$rows1 = array_slice($rows, 0, $split);
$rows2 = array_slice($rows, $split);
?>
<?php if (!empty($title)): ?>
  <<?php print $group_element; ?><?php print drupal_attributes($group_attributes); ?>>
    <?php print $title; ?>
  </<?php print $group_element; ?>>
<?php endif; ?>
<?php if (!empty($list_element)): ?>
  <<?php print $list_element; ?><?php print drupal_attributes($list_attributes); ?>>
<?php endif; ?>

<div class="cases cases-left">
  <?php foreach ($rows1 as $id => $row): ?>
    <?php if (!empty($row_element)): ?>
    <<?php print $row_element; ?><?php print drupal_attributes($row_attributes[$id]); ?>>
    <?php endif; ?>
      <?php print $row; ?>
    <?php if (!empty($row_element)): ?>
    </<?php print $row_element; ?>>
    <?php endif; ?>
  <?php endforeach; ?>
</div>
<div class="cases cases-right">
  <?php foreach ($rows2 as $id => $row): ?>
    <?php if (!empty($row_element)): ?>
    <<?php print $row_element; ?><?php print drupal_attributes($row_attributes[$id]); ?>>
    <?php endif; ?>
      <?php print $row; ?>
    <?php if (!empty($row_element)): ?>
    </<?php print $row_element; ?>>
    <?php endif; ?>
  <?php endforeach; ?>
</div>

<?php if (!empty($list_element)): ?>
  </<?php print $list_element; ?>>
<?php endif; ?>