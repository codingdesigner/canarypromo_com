if(Drupal.jsEnabled){
  $(document).ready(function(){
    $('#block-views-Birdfeed-block_2 .view-display-id-block_2 .view-content h3.month').css({
      'margin-bottom': 0,
      'padding-bottom': '9px'
      });
    $('#block-views-Birdfeed-block_2 .view-display-id-block_2 .view-content ul').css({
      'margin-bottom': 0,
      'padding-bottom': '18px'
    });
    $('#block-views-Birdfeed-block_2 .view-display-id-block_2 .view-content').accordion({ 
      header: 'h3.month', 
      autoHeight: false,
      event: 'mouseover',
      animated: function(options) {
      	return options.down ? "easeOutCubic" : "easeInOutCubic";
        },
      duration: function(options) {
				return options.down ? 700 : 400;
  			}
      });
  });
}