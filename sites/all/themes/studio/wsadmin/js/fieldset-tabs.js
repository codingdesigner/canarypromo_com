$(document).ready(function () {
  var adminTabs = [];
  var standardFieldsets = $('#content-content #node-form .standard').children('fieldset');
  var adminFieldsets = $('#content-content #node-form .admin div').children('fieldset');
  var fieldsets = [];
  fieldsets = standardFieldsets.concat(adminFieldsets);
  //alert(fieldsets);
  var counter = -1;
  $.each(fieldsets, function (item, set) {
    if (($(set).find('legend').text() != 'Input format') && ($(set).find('legend').text() != '')) {
      counter++;
      var setTab = [];
      setTab[0] = $(set).children('legend').text();
      $(set).children('legend').remove();
      setTab[1] = $(set).children('div.fieldset-wrapper').children('.description').html();
      $(set).children('div.fieldset-wrapper').children('.description').remove();
      setTab[2] = $(set).html();
      adminTabs[counter] = setTab;
      $(set).remove();
    };
  });
  adminTabs.sort();
  adminTabbify(adminTabs, '#content-content #node-form');
});
