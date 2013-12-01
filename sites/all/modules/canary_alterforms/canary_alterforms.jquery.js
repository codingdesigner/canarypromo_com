if(Drupal.jsEnabled){
  $(document).ready(function(){
    $("input#edit-search-block-form-1").attr("value", "Looking for something specific?").addClass("teaser").click( function() {
      $(this).attr("value", "").unbind('click');
    });
  });
}