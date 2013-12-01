// ADD ZEBRA STRIPING TO MENUS
if(Drupal.jsEnabled){
  $(document).ready(function(){
    $("ul.menu li:nth-child(odd)").addClass("odd");
    $("ul.menu li:nth-child(even)").addClass("even")
  });
}