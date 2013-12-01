/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

if(Drupal.jsEnabled){
  $(document).ready(function(){
    var container_bg = $("#container").css("background"),
        main_bg = $("#main").css("background"),
        workright_bg = $("body#node-our-work-page #content-right").css("background"),
        theme_grid_path = "/sites/all/themes/feather/css/images/",
        panel_first_bg = $("#main .panel-display .panel-col-first").css("background"),
        panel_last_bg = $("#main .panel-display .panel-col-last").css("background")
    $("#toggle p").toggle(
      function () {
        $("#container").css("background", "transparent url("+theme_grid_path+"grid-24-18-18.png) repeat scroll 0 0");
        $("#main").css("background", "transparent url("+theme_grid_path+"grid-24-18-24.png) repeat scroll 0 0");
        $("body#node-our-work-page #content-right").css("background", "transparent url("+theme_grid_path+"grid-24-18-24.png) repeat scroll 0 0");
        $("#main .panel-display .panel-col-first").css("background", "transparent url("+theme_grid_path+"grid-24-18-24.png) repeat scroll 0 0");
        $("#main .panel-display .panel-col-last").css("background", "transparent url("+theme_grid_path+"grid-24-18-18.png) repeat scroll 0 0");
      },
      function () {
        $("#container").css({"background" : container_bg});
        $("#main").css({"background" : main_bg});
        $("body#node-our-work-page #content-right").css({"background" : main_bg});
        $("#main .panel-display .panel-col-first").css({"background" : panel_first_bg});
        $("#main .panel-display .panel-col-last").css({"background" : panel_last_bg});
      }
    );
  });
}