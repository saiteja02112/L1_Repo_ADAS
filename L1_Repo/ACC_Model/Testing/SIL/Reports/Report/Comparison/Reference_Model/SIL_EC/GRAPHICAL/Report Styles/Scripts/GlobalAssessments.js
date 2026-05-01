

/*/////////////////////////////////////////*/
/*//////////// Global Assessments /////////*/
/*/////////////////////////////////////////*/

function showRepresentation(isGraphRep)
{
	if(isGraphRep)
	{
		$("#Table_Representation").hide();
		$("#Graph_Representation").show();
	}
	else
	{
		$("#Graph_Representation").hide();
		$("#Table_Representation").show();
	}
}

function showGraphRepresentation()
{
	$("#Table_Representation").hide();
	$("#Graph_Representation").show();
}

function showTableRepresnetation()
{
	$("#Graph_Representation").hide();
	$("#Table_Representation").show();
}

function ShowAllGlobalAssessments() {
	$('.' + "PASS").show();
	$('.' + "FAIL").show();
	$('.' + "NOT_TRIGGERED").show();
}

function ShowGlobalAssessments(_class) {
	$('.' + "GAssessment").hide();
	$('.' + _class).show();
}

function decompressAllTheLoadingSignalGraphsData()
{
	loadAllSignalsDataForInputs();
	loadAllSignalsDataForPassed();
	loadAllSignalsDataForFailed();
	loadAllSignalsDataForNotTrigered();
	loadAllGlobalAssessmentsForStatus("PASS");
	loadAllGlobalAssessmentsForStatus("FAIL");
	loadAllGlobalAssessmentsForStatus("NOT_TRIGGERED");
}

function decompressAllGlobalAssessmentsGraphsData()
{
	loadAllGlobalAssessmentsForStatus("PASS");
	loadAllGlobalAssessmentsForStatus("FAIL");
	loadAllGlobalAssessmentsForStatus("NOT_TRIGGERED");
}

function loadAllGlobalAssessmentsForStatus(_class)
{
	$("." + _class).find(".tc-ic").click();
}

function loadAssessJSFile(divId, scriptName)
{
	//Remove any special char from id
	divId=divId.replace(/[^\s_0-9a-zA-Z]/gi, '');
	$("div."+divId)[0].remove();
	var script = document.createElement('script');
	script.type = 'text/javascript';
	script.src = scriptName + '.js';    
	document.head.appendChild(script);
}



//Create New Assessment Plot
function tip_cnasp(id, title, assessXAxis, assessYAxis, timeTol)
{
	if($('#ia' + id).attr('tag') === 'off'){
		Plotly.purge(id);
		$('#ia' + id).attr("tag","on")
		$('#ia' + id).show();
	}else {
		$('#ia' + id).attr("tag","off")
		$('#ia' + id).hide();
		var GAssessment = {
			type: 'scatterg1',
			mode: 'lines',
			name: 'Global Assessment',
			x: assessXAxis,
			y: assessYAxis,
			line: {color: '#0c63e8' , shape: 'hv'}
		}
   
		var data = [GAssessment];
		
		var layout = {
		  title: title, 		  
		  xaxis: {
		  title: 'Time in seconds' + '<br><br> TimeTol = ' + timeTol ,
		  line: {color: '#e6e3e3'},
		  linecolor: '#e6e3e3',
		  },
	  
		  yaxis: {
		  title: 'Value',
		  line: {color: '#e6e3e3'},
		  linecolor: '#e6e3e3',
		  },
		  plot_bgcolor: '#fff',
		  paper_bgcolor: '#fff',
		  line: {color: '#000'},
		  font: {color: '#000'},
		};

		Plotly.react(id, data, layout, {responsive: true});
	}
}


//Create New Assessment Plot
function cnasp(id, title, assessXAxis, assessYAxis, timeTol)
{
	Plotly.toImage({
    data: [{
			type: 'scatter',
			mode: 'lines',
			name: 'Global Assessment',
			x: assessXAxis,
			y: assessYAxis,
			line: {color: '#0c63e8' , shape: 'hv'}
	}],
	layout: {
	  title: title, 		  
	  xaxis: {
	  title: 'Time in seconds' + '<br><br> TimeTol = ' + timeTol ,
	  line: {color: '#e6e3e3'},
	  linecolor: '#e6e3e3',
	  },
  
	  yaxis: {
	  title: 'Value',
	  line: {color: '#e6e3e3'},
	  linecolor: '#e6e3e3',
	  },
	  plot_bgcolor: '#fff',
	  paper_bgcolor: '#fff',
	  line: {color: '#000'},
	  font: {color: '#000'},
	}
  }).then(src => {
    return new Promise((resolve, reject) => 
	{$('#' + id).prepend($('<img>',{id:'ia' + id, tag: 'on', src: src, width: '100%', height: '50%'})); })
	});
}

function coloring_ga_RadioButns(radio_btn_ID , Color)
{
	$("#radio_ga_all").css('color', '#8a8a8a');
	$("#radio_ga_passed").css('color', '#8a8a8a');
	$("#radio_ga_failed").css('color', '#8a8a8a');
	$("#radio_ga_not_triggered").css('color', '#8a8a8a');
	$("#radio_ga_passed_with_not_tri").css('color', '#8a8a8a');
		
	$("#" + radio_btn_ID).css('color', Color);
}




















