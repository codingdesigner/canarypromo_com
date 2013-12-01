// ADD ZEBRA STRIPING TO MENUS
if(Drupal.jsEnabled){
  $(document).ready(function(){
    $("#feature-image").hover(
      function(){
        $(this).addClass('hover');
      },
      function(){
        $(this).removeClass('hover');
      }
   );
  });
}
//#feature-container .message-holder