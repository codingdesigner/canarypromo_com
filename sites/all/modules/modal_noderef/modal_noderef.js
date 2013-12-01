(function ($) {
  /**
   * Add modal node references to all editors with the given class.
   */
  Drupal.behaviors.modalNodeRef = function () {
    var selector = '.edit-in-modal';
    
    var settings = {
      autoResize: true,
      autoFit: true,
      width: 600,
      height: 400
    }
    
    // Add a click handler to each modal link.
    $(selector).click(function () {
      $this = $(this);
      
      settings.url = $this.attr('href') || '#';
      if (settings.url.indexOf('?') >= 0) {
        settings.url += '&'
      }
      else {
        settings.url += '?'
      }
      
      // Find the last form field:
      // Iterate through previous div's until we find it.
      var $nr = $this.parents('.modal-noderef-creation-link-wrapper').prevAll('div');
      $targetField = null;
      for (var i = 0; i < $nr.length; i++) {
        $targetField = firstEmpty($($nr[i]));
        if ($targetField != null && $targetField.length > 0)
          break; // Found it!
      }
      
      // If there is no empty field, send a warning
      if ($targetField == null || $targetField.length == 0) {
        // This is so lame.
        alert(Drupal.t('All available items are full. Either delete one or try adding another item first.'));
        return false;
      }
      
      
      // This receives the child window's node title and ID and puts that into the autocomplete box.
      settings.onSubmit = function (data) {
        $targetField.val(data.message);
      } 
      
      // Add the flag to the end to make sure that the modal is opened correctly.
      settings.url += 'automodal=true';
      
      Drupal.modalFrame.open(settings);
      
      return false;
    });
  }
  
  /**
   * Return the first empty field.
   */
  function firstEmpty($fields) {
    var $fempty = $fields.find('.form-autocomplete[value=""]:first');
    if ($fempty.length > 0) {
      return $fempty;
    }
    
    // Try to click the "Add another item" button.
    // This can work, we just need to fire the correct event.
    //$fields.find('.content-add-more>input[type=submit]').click();
  }
  
})(jQuery);
