(function ($) {
  Drupal.behaviors.automodal = function () {
    var selector = Drupal.settings.automodal.selector || '.automodal';
    
    var settings = {
      autoResize: true,
      autoFit: true,
      width: 600,
      height: 400,
      //onSubmit: function (a, b) {} 
    }
    
    $(selector).click(function () {
      settings.url = $(this).attr('href') || '#';
      
      if (settings.url.indexOf('?') >= 0) {
        settings.url += '&'
      }
      else {
        settings.url += '?'
      }
      settings.url += 'automodal=true';
      
      Drupal.modalFrame.open(settings);
      
      return false;
    });
  }
  
})(jQuery);