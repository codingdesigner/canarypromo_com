<?php
// $Id: block-horizontal_blocks.tpl.php,v 1.1 2009/04/06 21:11:21 zarabadoo Exp $

/**
 * @file block.tpl.php
 *
 * Theme implementation to display a block.
 *
 * Available variables:
 * - $title: Block title.
 * - $content: Block content.
 * - $module: Module that generated the block.
 * - $delta: This is a numeric id connected to each module.
 * - $region: The block region embedding the current block.
 *
 * Helper variables:
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 */
?>
<div<?php print $attributes; ?>>
  <div class="padding">
  <?php if ($title): ?>
    <h2><?php print $title ?></h2>
  <?php endif;?>

    <div class="block-content">
      <?php print $content ?>
    </div>
  </div>
</div>
