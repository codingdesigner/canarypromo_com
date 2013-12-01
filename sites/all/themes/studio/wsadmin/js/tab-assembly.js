function adminTabbify(adminTabs, container){
  $('<div id="admin-tabs"><ul class="category-tabs"></ul><div class="category-options"></div></div>').prependTo(container);
  $(adminTabs).each(function(item, tab){
    var controlTab = '<li id="option-' + item + '" class="tab-option"><h3>' + tab[0] + '</h3>';
    //$('<li id="option-' + item + '" class="tab-option"><h3>' + tab[0] + '</h3>').appendTo('#admin-tabs .category-tabs');
    if (tab[1]) {
      //$('<p class="description">' + tab[1] + '</p>').appendTo('#admin-tabs .category-tabs');
      controlTab = controlTab + '<p class="description">' + tab[1] + '</p>';
    };
    //$('</li>').appendTo('#admin-tabs .category-tabs');
    controlTab = controlTab + '</li>';
    $(controlTab).appendTo('#admin-tabs .category-tabs');
    $('<div id="category-option-' + item + '" class="category-option">' + tab[2] + '</div>').appendTo('#admin-tabs .category-options');
  });
  $('div.category-option').hide(0);
  $('li.tab-option:first').addClass('selected');
  $('div.category-option:first').show(0).addClass('option-expanded');
  $('li.tab-option').click(function(){
    if (!$(this).hasClass('selected')) {
      $('li.selected').removeClass('selected');
      $(this).addClass('selected');
      $('div.option-expanded').slideUp('fast').removeClass('option-expanded');
      var itemID = '#category-' + $(this).attr('id');
      $(itemID).slideDown('fast').addClass('option-expanded');
    };
  });
}