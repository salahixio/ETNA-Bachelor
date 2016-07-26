$("#button1").click(function() {
  $( this ).removeClass('btn red').addClass('btn green');
});

$("#button2").click(function() {
  $( this ).attr('disabled','disabled');
});

$("#button3").click(function() {
	if ($( this )[0].innerHTML == "Cliquez encore !")
	{
		$(this)[0].innerHTML = "Cliquez";
		alert($(this)[0].innerHTML);
	}
	else
  		$( this )[0].innerHTML = "Cliquez encore !";
});

$(".group").click(function() {
	var red_button;
	red_button = document.getElementsByClassName("btn red group");
	if (red_button[0] != null)
	{
		while (red_button[0] != null)
			red_button[0].className = "btn green group";
	}
	else
	{
		green_button = document.getElementsByClassName("btn green group");
		while (green_button[0] != null)
			green_button[0].className = "btn red group";
	}
});