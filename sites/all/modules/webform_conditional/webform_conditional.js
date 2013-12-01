$(document).ready(function() {

	$.each(webform_conditional, function(dependentField, dependentInfo) {
		var formItemWrapper = webform_condtional_wrapper(dependentField,dependentInfo);
		
		formItemWrapper.css("display", "none");
		// Add onclick handler to Parent field
			webform_conditional_add_onchange(dependentField, dependentInfo);

		});
	return;

});
function webform_condtional_wrapper(dependentField,dependentInfo){
	if(dependentInfo['type']=='fieldset' || dependentInfo['type']=='markup'){
		return $('#webform-component-' + dependentField);
	}
	var cssName = dependentField.replace(/_/g,"-");
	if(dependentInfo['fieldsetId']!=''){
		cssName = dependentInfo['fieldsetId'].replace(/_/g,"-") + "-" + cssName;
	}
	cssId = "#edit-submitted-" + cssName + "-wrapper";
	if($(cssId).length==0){
		cssId = "#edit-submitted-" + cssName + "-1-wrapper";
		return $(cssId).parent().parent();
	}else{
		return $(cssId);
	}
	
}
function webform_conditional_add_onchange(dependentField, dependentInfo) {
	var field_name = webform_conditional_escape("["+dependentInfo['monitor_field_key'] + "]");
	var changeFunction = function() {
		// If checked
		
		var currentValue = webform_conditional_field_value(field_name); 
			
		/*
		 * if((dependentInfo['monitor_field_trigger'] = 'empty' &&
		 * currrentValue == '' ) ||
		 * (dependentInfo['monitor_field_trigger'] = 'not empty' &&
		 * currrentValue != '' ) ||
		 * currentValue==dependentInfo['monitor_field_value'] ){
		 */
		if(webform_coditional_matches(currentValue,dependentInfo['monitor_field_value'])){
				// show the hidden div
			 webform_condtional_wrapper(dependentField,dependentInfo).show(
						"slow");
		}else {
				// otherwise, hide it
			webform_condtional_wrapper(dependentField,dependentInfo).hide(
						"slow");
				// and clear data (using different selector: want the
				// textarea to be selected, not the parent div)
			webform_conditional_clear_dependents(dependentField,dependentInfo);
			
			
			// $("#edit-submitted-" +
			// dependentField.replace(/_/g,"-")).val('');
			}
		};
	var components = $("#webform-client-form-" + webform_conditional_nid + " *[name*='"+field_name+"']");
	if(components.attr('type')=='radio' || components.attr('type')=='checkbox'){
		components.click(changeFunction);
	}else{
		components.change(changeFunction);
	}
	
}
function webform_conditional_clear_dependents(dependentField,dependentInfo){
	 
		
	 if(dependentInfo['type']=='fieldset'){
	  // when hidding a fieldset clear all components inside it
		$('#webform-component-' +dependentField+ ' input[type=text]'
				+ ',#webform-component-' +dependentField+ ' select'
				+ ',#webform-component-' +dependentField+ ' textarea').val('').trigger('change');
		
		$('#webform-component-' +dependentField+ ' input[type=checkbox]'
			+',#webform-component-' +dependentField+ ' input[type=radio]').attr('checked', false).trigger('change');

		return;
	 }
	 field_name_dependent = "["+ dependentField + "]";
	 var component = $('[name*="'+field_name_dependent+'"]');
	 //make sure there are actually components - could be just markup
	if(component.length > 0){
		 if((component[0].nodeName == 'INPUT' && component.attr('type') == 'text' )
		 	|| component[0].nodeName == 'SELECT'
		 	|| component[0].nodeName == 'TEXTAREA'){
			 component.val('').trigger('change');
		 }else if(component[0].nodeName == 'INPUT' &&
				(component.attr('type') == 'radio' || component.attr('type') == 'checkbox'  ) ){
			 component.attr('checked', false).trigger('change');
		 }
	 }
	
}
function webform_conditional_field_value(field_name){
	if($('input[name*="'+field_name+'"]:checked').length == 1){
		return $('input[name*="'+field_name+'"]:checked').val();
	}else if($('select[name*="'+field_name+'"] option:selected').length == 1){
		return $('select[name*="'+field_name+'"] option:selected').val();
	}
}
function webform_coditional_matches(currentValue,triggerValues){
	found = false;
	$.each(triggerValues, function(index, value) { 
		  if(currentValue==value){
			  found = true;
			  return false;
		  }
		});
	return found;
}
function webform_conditional_escape(myid) { 
	   return  myid.replace(/(:|\.)/g,'\\$1');
}
