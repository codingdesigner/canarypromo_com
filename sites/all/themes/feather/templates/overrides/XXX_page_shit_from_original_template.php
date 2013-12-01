<div id="page">
  <div id="site-information" class="clear-block">
    <?php if($site_name): ?>
    <h1 id="site-name"><a href="<?php print $front_page ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a></h1>
    <?php endif; ?>
    <?php if($site_slogan): ?>
    <div id="site-slogan">
      <?php print $site_slogan; ?>
    </div><!-- /#site-slogan -->
    <?php endif; ?>
    <?php print $header; ?>
  </div><!-- /#site-information -->
  <div id="wrapper" class="clear-block">
    <?php if ($messages): ?>
    <div id="messages" class="clear-block">
      <?php print $messages; ?>
    </div><!-- /#messages -->
    <?php endif; ?>
    <?php if ($mission): ?>
    <div id="mission" class="clear-block">
      <?php print $mission; ?>
    </div><!-- /#mission -->
    <?php endif; ?>
    <div id="container" class="clear-block">
      <div id="content" class="column clear-block">
        <?php if ($breadcrumb): ?>
        <div id="breadcrumb">
          <?php print $breadcrumb; ?>
        </div><!-- /#breadcrumb -->
        <?php endif; ?>
        <div id="content-wrapper" class="clear-block">
          <?php if ($title): ?>
          <h2 class="title" id="page-title"><?php print $title; ?></h2>
          <?php endif; ?>
          <?php if ($tabs): ?>
          <div id="tabs" class="clear-block">
            <?php print $tabs; ?>
          </div>
          <?php endif; ?>
          <?php if ($help): print $help; endif; ?>
          <?php print $pre_content; ?>
          <?php if($content): ?>
          <div id="content-content">
            <?php print $content; ?>
          </div><!-- /#content-content -->
          <?php endif; ?>
          <?php print $post_content; ?>
          <?php print $horizontal_blocks; ?>
        </div><!-- /#content-wrapper -->
      </div><!-- /#content -->
      <?php print $left; ?>
      <?php print $right; ?>
    </div><!-- /#container -->
  </div><!-- /#wrapper -->
  <?php if ($primary_links || $secondary_links): ?>
  <div id="site-navigation" class="clear-block">
    <?php if ($primary_links): ?>
    <div id="primary" class="clear-block">
      <?php print theme('links', $primary_links, array('class' => 'links primary-links')); ?>
    </div><!-- /#primary -->
    <?php endif; ?>
    <?php if ($secondary_links): ?>
    <div id="secondary" class="clear-block">
      <?php print theme('links', $secondary_links, array('class' => 'links secondary-links')); ?>
    </div><!-- /#secondary -->
    <?php endif; ?>
    <?php print $menus; ?>
  </div><!-- /#menus -->
  <?php endif; ?>
  <?php if($search_box): ?>
  <div id="search-box" class="clear-block">
    <?php print $search_box; ?>
  </div><!-- /#search-box -->
  <?php endif; ?>
  <div id="extra-information" class="clear-block">
    <?php print $footer_message; ?>
    <?php print $feed_icons; ?>
    <?php print $footer; ?>
  </div><!-- /#extra-information -->
</div><!-- /#page -->