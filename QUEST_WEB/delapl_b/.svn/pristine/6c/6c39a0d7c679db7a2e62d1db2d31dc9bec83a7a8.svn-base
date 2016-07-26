function put_nbr(value)
{
	var results;
	results = document.getElementsByClassName("result");
	for (var i = 0; i < results.length; i++) {
	 results[i].innerHTML += value;
	}
	document.getElementById("results").innerHTML += value;
}

function put_operator(value)
{
	var results;
	results = document.getElementsByClassName("result");
	for (var i = 0; i < results.length; i++) {
	 results[i].innerHTML = "";
	}
	document.getElementById("results").innerHTML += value;
}

function reset()
{
	var results;
	results = document.getElementsByClassName("result");
	for (var i = 0; i < results.length; i++) {
	 results[i].innerHTML = "";
	}
	document.getElementById("results").innerHTML = "";	
}

function calculate()
{
	var results, calcul;
	results = document.getElementsByClassName("result");
	calcul = eval(document.getElementById("results").innerHTML);
	for (var i = 0; i < results.length; i++) {
		results[i].innerHTML = parseInt(calcul);
	}
	document.getElementById("results").innerHTML = parseInt(calcul); 
}