// $Id: content_type_selector.js,v 1.1.2.2 2009/04/29 19:06:12 markuspetrux Exp $

/**
 * @file
 * Content type selector to quickly switch from one type to another
 * in content type administration pages.
 */

Drupal.behaviors.contentTypeSelector = function(context) {
  // Find the primary tabs wrapper. We will not render the selector if we
  // don't find the primary tabs wrapper. Example: delete confirmation form.
  $('#tabs-wrapper:not(.content-type-selector-processed)', context).addClass('content-type-selector').each(function() {
    var tabs = this, settings = Drupal.settings.contentTypeSelector;

    // Prepend the selector to the primary tabs wrapper, floating to the right.
    // In case of wrapping, the selector will remain on top of the tabs.
    $(Drupal.theme('contentTypeSelector', settings)).prependTo(tabs);

    // Helper function to redirect to the proper destination.
    // Returns false so that it can be used to prevent default event action.
    function goto() {
      var nodetype = $('#content-type-selector').val();
      if (nodetype && nodetype != settings.current) {
        window.location = settings.urlmask.replace(/NODETYPE/, nodetype);
      }
      return false;
    }

    // Bind onchange event to the selector.
    $('#content-type-selector').bind('change', function() {
      goto();
    });

    // Bind onclick event as well to catch up browsers not firing onchange.
    $('#content-type-selector-go').bind('click', function() {
      return goto();
    });
  });
};

/**
 * Theme the selector form.
 *
 * This form is never sent to the server, we don't even use name attributes for
 * the elements. Only id, so that we can find them using jQuery selectors.
 */
Drupal.theme.prototype.contentTypeSelector = function(settings) {
  var options = [];
  $.each(settings.types, function(value, label) {
    var selected = (value == settings.current ? ' selected="selected"' : '');
    options.push('<option value="'+ value +'"'+ selected +'>'+ label +'</option>');
  });
  return '<div id="content-type-selector-wrapper"><form method="post" action="javascript:void(0)">'
    +'<div class="form-item">'
      +'<label for="content-type-selector">'+ Drupal.t('Switch type:') +'</label>&nbsp;'
      +'<select id="content-type-selector">'+ options.join('') +'</select>&nbsp;'
    +'</div>'
    +'<input type="submit" id="content-type-selector-go" value="'+ Drupal.t('Go') +'" class="form-submit" />'
    +'</form></div>';
};
