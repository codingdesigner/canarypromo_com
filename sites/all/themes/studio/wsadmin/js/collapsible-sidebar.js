$(document).ready(function() {
  $('body').addClass('collapsible-sidebar');
  //var sidebarHeight = $('#container').innerHeight(); 
  $('#sidebar-left').animate({opacity: ".5"}, 0).addClass('collapsed-sidebar').hover(function () {
      $(this).removeClass('collapsed-sidebar').addClass('expanded-sidebar').stop().animate({width: "100px", opacity: ".9"}, 'fast');
      $(this).children('.block').stop().animate({opacity: "1"}, 'fast');
    }, function () {
      $(this).removeClass('expanded-sidebar').addClass('collapsed-sidebar').stop().animate({width: "20px", opacity: ".5"}, 'fast');
      $(this).children('.block').stop().animate({opacity: "0"}, 'fast');
    }
  ).children('.block').animate({opacity: "0"}, 0);
  //$('#container').change(function () {
    //$('#sidebar-left').height($('#container').innerHeight());
  //}).change();
  /*$('#sidebar-left').children('.block').hover(function () {
    $(this).addClass('block-hover');
    //$(this).children('.block-content').stop().show('slow');
  }, function () {
    $(this).removeClass('block-hover');
    //$(this).children('.block-content').stop().hide('slow');
  });*/
});