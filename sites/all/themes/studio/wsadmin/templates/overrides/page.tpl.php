<?php
// $Id: page.tpl.php,v 1.2 2009/04/16 17:30:00 zarabadoo Exp $

/**
 * @file page.tpl.php
 *
 * Theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $attributes: This provide the attributes for the body tag.
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $css: An array of CSS files for the current page.
 * - $directory: The directory the theme is located in, e.g. themes/garland or
 *   themes/garland/minelli.
 * - $is_front: TRUE if the current page is the front page. Used to toggle the mission statement.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Page metadata:
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or 'rtl'.
 * - $head_title: A modified version of the page title, for use in the TITLE tag.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $body_classes: A set of CSS classes for the BODY tag. This contains flags
 *   indicating the current layout (multiple columns, single column), the current
 *   path, whether the user is logged in, and so on.
 * - $body_attributes: This is similar to $body_classes, except it goes further. There is the addition of the 'id' to the tag and more classes by default.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $mission: The text of the site mission, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $search_box: HTML to display the search box, empty if search has been disabled.
 * - $primary_links (array): An array containing primary navigation links for the
 *   site, if they have been configured.
 * - $secondary_links (array): An array containing secondary navigation links for
 *   the site, if they have been configured.
 *
 * Page content (in order of occurrance in the default page.tpl.php):
 * - $left: The HTML for the left sidebar.
 *
 * - $breadcrumb: The breadcrumb trail for the current page.
 * - $title: The page title, for use in the actual HTML content.
 * - $help: Dynamic help text, mostly for admin pages.
 * - $messages: HTML for status and error messages. Should be displayed prominently.
 * - $tabs: Tabs linking to any sub-pages beneath the current page (e.g., the view
 *   and edit tabs when displaying a node).
 *
 * - $pre_content: The HTML for above the main content.
 * - $content: The main content of the current Drupal page.
 * - $post_content: The HTML for below the main content.
 *
 * - $right: The HTML for the right sidebar.
 *
 * Footer/closing data:
 * - $feed_icons: A string of all feed icons for the current page.
 * - $footer_message: The footer message as defined in the admin settings.
 * - $footer : The footer region.
 * - $closure: Final closing markup from any modules that have altered the page.
 *   This variable should always be output last, after all other dynamic content.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <?php print $scripts; ?>
    <script type="text/javascript"><?php /* Needed to avoid Flash of Unstyled Content in IE */ ?> </script>
  </head>
  <body<?php print $attributes; ?>>
    <div id="page">
      <div id="site-information" class="clear-block">
        <?php if($site_name): ?>
        <h1 id="site-name"><a href="<?php print $front_page ?>admin" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?> Administration</a></h1>
        <?php endif; ?>
        <?php if($site_slogan): ?>
        <div id="site-slogan">
          <?php print $site_slogan; ?>
        </div><!-- /#site-slogan -->
        <?php endif; ?>
        <?php print $header; ?>
      </div><!-- /#header -->
      <div id="wrapper" class="clear-block">
        <?php if ($breadcrumb): ?>
        <div id="breadcrumb" class="clear-block">
          <?php print $breadcrumb; ?>
        </div><!-- /#breadcrumb -->
        <?php endif; ?>
        <?php if($messages || $mission): ?>
        <div id="information">
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
        </div><!-- /#information -->
        <?php endif; ?>
        <div id="container" class="clear-block">
          <div id="content" class="column">
            <div id="content-wrapper">
              <?php if (!empty($title)): ?>
              <h1 class="title" id="page-title"><?php print $title; ?></h1>
              <?php endif; ?>
              <?php print $help; ?>
              <?php if($tabs): ?>
              <div id="tabs" class="clear-block">
                <?php print $tabs; ?>
              </div>
              <?php endif; ?>
              <?php print $pre_content; ?>
              <?php if($content): ?>
              <div id="content-content">
                <?php print $content; ?>
              </div><!-- /#content-content -->
              <?php endif; ?>
              <?php print $post_content; ?>
            </div><!-- /#content-wrapper -->
          </div><!-- /#content -->
          <?php print $left; ?>
        </div><!-- /#container -->
      </div><!-- /#wrapper -->
      <?php if($primary_links || $secondary_links): ?>
      <div id="site-navigation">
        <?php if ($primary_links): ?>
        <div id="primary" class="clear-block">
          <?php print theme('links', $primary_links, array('class' => 'links primary-links')); ?>
        </div><!-- /#primary -->
        <?php endif; ?>
        <?php if (!empty($secondary_links)): ?>
        <div id="secondary" class="clear-block">
          <?php print theme('links', $secondary_links, array('class' => 'links secondary-links')); ?>
        </div><!-- /#secondary -->
        <?php endif; ?>
      </div><!-- /#navigation -->
      <?php endif; ?>
      <div id="extra-information" class="clear-block">
        <?php print $footer_message; ?>
        <?php print $feed_icons; ?>
        <?php print $footer; ?>
      </div><!-- /#footer -->
    </div><!-- /#page -->
    <div id="fixed-navigation" class="clear-block">
      <?php if($search_box): ?>
      <div id="search-box">
        <?php print $search_box; ?>
      </div><!-- /#search-box -->
      <?php endif; ?>
    </div>
    <?php print $closure; ?>
  </body>
</html>
