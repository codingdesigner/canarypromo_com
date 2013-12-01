<?php
// $Id: page.tpl.php,v 1.2 2009/04/16 17:29:55 zarabadoo Exp $

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
<!DOCTYPE html>
<html lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <?php print $scripts; ?>
    <!--[if IE]>
		<script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
		<link rel="stylesheet" href="/css/ie.css">
		<![endif]-->
  </head>
  <body<?php print $attributes; ?>>
    <div id="page">
	    <div id="trees">
	    	<div id="container">
	    		<header>
	    			<div id="logo-title">
	    				<h1 id="site-name"><a href="<?php print $front_page ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a></h1>
	    			</div>  <!--//logo-title-->
	          <nav>
	          	<div id="menu-birds">
	          		<div id="bird-01" class="menubird"></div>
	              <div id="bird-02" class="menubird"></div>
								<div id="bird-03" class="menubird"></div>
								<div id="bird-04" class="menubird"></div>
	          	</div> <!--//menu-birds-->
							<?php print $navbar; ?> <!--TODO_REMOVE-->
							<?php print $menu; ?>
	          </nav> <!--//navigation-->
	    		</header>  <!--//header-->
	        <section id="content">
	        	<section id="top-feature">
		          <?php if(!$is_front): ?>
			          <?php if ($title): ?>
								  <div id="feature-text">
					          <?php if ($title): ?>
						          <hgroup>
							          <?php if ($pre_title): ?>
							            <h3 class="pre-title"><?php print $pre_title; ?></h3>
							          <?php endif; //--if ($pre_title)?>
						            <h1 class="title"><?php print $title; ?>
						              <?php /* if ($feed_icons): ?>
						                <span class="feed-icons"><?php print $feed_icons; ?></span>
						              <?php endif; */ ?>
						            </h1>
						            <?php if ($subtitle): ?>
							            <h2 id="subtitle"><?php print $subtitle; ?></h2>
							          <?php endif; //--if ($subtitle)?>
											</hgroup>
					          <?php endif; //--if ($title)?>
					          <?php print $featuretext; ?>
									</div> <!--//feature-text-->
								<?php endif; //--if ($title)?>
								<?php if ($featureimage): ?>
									<div id="feature-image"><?php print $featureimage; ?></div> <!--//feature-image-->
								<?php endif; //--if ($featureimage)?>
							<?php else: //if($is_front) ?>
								<div id="feature-image"><?php print $featureimage; ?></div> <!--//feature-image-->
								<div id="feature-text"><?php print $featuretext; ?></div> <!--//feature-text-->
								
			        <?php endif; //if($is_front) ?>   		

	        	</section> <!--//top-feature-->
	          <section id="main-content">
		      
		          <?php if ($messages): ?>
					    <section id="messages">
					      <?php print $messages; ?>
					    </section><!-- /#messages -->
					    <?php endif; //if ($messages) ?>
					
							<?php if ($tabs): ?>
		          <nav id="tabs">
		            <?php print $tabs; ?>
		          </nav>
		          <?php endif; //if ($tabs)?>
		
							<?php if ($help): print $help; endif; ?>
	
		          <?php if($full_width_top || $header): ;?>
          		<section id="full-width-top">
          			<?php print $header; ?> <!--TODO_REMOVE-->
								<?php print $full_width_top; ?>
          		</section> <!--//full-width-top-->
							<?php endif; //if($full_width_top || $header)?>
							
	          	<section id="main">
		            <?php if($pre_content || $content_top): ;?>
	          		<section id="pre-content">
	          			<?php print $content_top; ?> <!--TODO_REMOVE-->
									<?php print $pre_content; ?>
	          		</section> <!--//pre-content-->
								<?php endif; //if($pre_content || $content_top) ?>
								
								<?php if($is_front):?>
				          <?php if ($pre_title): ?>
				            <div class="pre-title"><?php print $pre_title; ?></div>
				          <?php endif; //--if ($pre_title)?>

				          <?php if ($title): ?>
				            <h1 class="title"><?php print $title; ?>
				              <?php if ($feed_icons): ?>
				                <span class="feed-icons"><?php print $feed_icons; ?></span>
				              <?php endif; ?>
				            </h1>
				          <?php endif; //--if ($title)?>
								<?php endif; //if(!$is_front)?>
								
								<?php if($content): ;?>
	          		<section id="content-content">
	          			<?php print $content; ?>
	          		</section> <!--//content-content-->
								<?php endif; //if($content) ?>
								
								<?php if($post_content || $content_bottom): ;?>
	          	
	          			<?php print $content_bottom; ?> <!--TODO_REMOVE-->
									<?php print $post_content; ?>
	         
								<?php endif; //if($pre_content || $content_top) ?>

	          	</section> <!--//main-->

	   					<?php if($right): ?>
			          <section id="content-right">
									<?php print $right; ?>
			          </section><!-- /#content-right -->
			        <?php endif; //--if($right) ?>
			
							<footer>
			          <?php if ($footerleft): ?>
			            <div id="footer-left"><?php print $footerleft; ?></div><!--//footer-left-->
			          <?php endif; //if ($footerleft)?>
			          <?php if ($footerright): ?>
			            <div id="footer-right"><?php print $footerright; ?></div><!--//footer-right-->
			          <?php endif; //if ($footerright)?>
			        </footer> <!-- //#footer -->

	          </section> <!--//main-content-->
	        </section> <!--//content-->
	    	</div> <!--//container-->
	    </div> <!-- //trees -->
		</div><!-- //page -->

		<?php print $closure_region; ?>
    <?php print $closure; ?>
  </body>
</html>
