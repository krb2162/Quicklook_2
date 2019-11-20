
function play(){
       var audio = document.getElementById("audio");
       audio.play();
                 }
$(document).ready(function(){
	$(".save").click(function(){  
		play();
 //        //play a sound
 //        var audio = {};
 //        audio["pew"] = new Audio();
 //        audio["pew"].src = "http://www.ranqde.org/static/bell-ring-01.mp3"
 //        audio["pew"].addEventListener('load'), function() {
 //        	audio["pew"].play();
 //        }
 //        console.log("clicked!")
    })

	
    TESTER = document.getElementById('tester');
    Plotly.plot( TESTER, [{
    x: times,
    y:  event_count}], {
    margin: { t: 0 } } );
    console.log( Plotly.BUILD );
    console.log(sliding_average)
});
