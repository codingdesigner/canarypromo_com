$(document).ready(function() {
  $('#content-content .admin .compact-link').remove();
  var adminPanels = $('#content-content .admin').find('div.admin-panel');
  var adminTabs = [];
  $.each(adminPanels, function (item, panel) {
    var adminPanel = [];
    adminPanel[0] = $(panel).find('h3').html();
    adminPanel[1] = $(panel).find('div.body p.description').html();
    $(panel).find('p.description').remove();
    adminPanel[2] = $(panel).find('div.body').html();
    adminTabs[item] = adminPanel;
  });
  adminTabs.sort();
  adminTabbify(adminTabs, '#content-content .admin');
  $('#content-content .admin .left').remove();
  $('#content-content .admin .right').remove();
});