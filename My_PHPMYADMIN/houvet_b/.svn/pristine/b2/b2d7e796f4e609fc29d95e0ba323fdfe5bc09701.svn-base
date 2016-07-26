//Ajout d'une base de données
function add_bdd()
{
	var value = document.getElementById("new-bd").value;
	$('<li id=""><a href="#">'+ value +'</a></li>').appendTo($('#navbar'));
	document.getElementById("new-bd").value = '';
}

//Renommer la base de données
function rename_bdd(button)
{
	if (button.innerHTML == "Renommer")
	{
		button.innerHTML = "Sauvegarder";
		var value = document.getElementById("name-bd").innerHTML;
		document.getElementById("name-bd").innerHTML = "<input type='text' style='width:200px;' class='form-control' value='" + value +"'>";
	}
	else
	{
		var value = document.getElementById("name-bd").firstChild.value;
		document.getElementById("navbar").getElementsByClassName("active")[0].firstChild.innerHTML = value;
		button.innerHTML = "Renommer";
		document.getElementById("name-bd").innerHTML = value;
	}
}

//Supprimer la base de données
function delete_bdd()
{

}

//Ajout d'une table
function add_table()
{
	var value = document.getElementById("new-table").value;
	$('<tr class="select-table"><td class="name-table">' + value + '</td><td>0</td><td><button class="btn btn-warning btn-sm" onClick="rename_table(this);">Renommer</button></td><td><button class="btn btn-danger btn-sm" onClick="delete_table(this);">Supprimer</button></td></tr>').appendTo($('#item-tables'));
	document.getElementById("new-table").value = '';
}

//Rennomer une table
function rename_table(button)
{
	if (button.innerHTML == "Renommer")
	{
		button.innerHTML = "Sauvegarder";
		var value = button.parentNode.parentNode.getElementsByClassName("name-table")[0].innerHTML;
		button.parentNode.parentNode.getElementsByClassName("name-table")[0].innerHTML = "<input type='text' class='form-control' value='" + value +"'>";
	}
	else
	{
		var value = button.parentNode.parentNode.getElementsByClassName("name-table")[0].firstChild.value;
		button.parentNode.parentNode.getElementsByClassName("name-table")[0].innerHTML = value;
		button.innerHTML = "Renommer";
	}
}

//Suppression d'une table
function delete_table(button)
{
	button.parentNode.parentNode.remove();
}