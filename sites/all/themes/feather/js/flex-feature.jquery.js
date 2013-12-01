// ADD ZEBRA STRIPING TO MENUS
if(Drupal.jsEnabled){
  $(document).ready(function(){
    $("#feature-image").hover(
      function(){
        //$(this).addClass('hover');
        $(this).find(".feature-container .message-holder .more-info:visible").stop().animate({
          height: 86,
        }, 1000, function(){});
      },
      function(){
        //$(this).removeClass('hover');
        $(this).find(".feature-container .message-holder .more-info:visible").stop().animate({
          height: 0,
        }, 500, function(){});
      }
   );
  });
}
