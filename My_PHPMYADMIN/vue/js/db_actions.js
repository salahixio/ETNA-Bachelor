//Ajout d'une base de données
function add_db()
{
	var value = document.getElementById("new-db").value;
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
	    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
	    	if (xhr.responseText == "1")
	    	{
	    		$('<li id=""><a href="#" onclick="set_active(this);">'+ value +'</a></li>').appendTo($('#navbar'));
				document.getElementById("new-db").value = '';
	    	}
	    	else
	        	alert("La création de la base a échouée");
	    }
	};
	xhr.open("GET", "add_db.php?db_name="+value, true);
	xhr.send(null);
}

//Renommer la base de données
function rename_db(button)
{
	if (button.innerHTML == "Renommer")
	{
		button.innerHTML = "Sauvegarder";
		var value = document.getElementById("db-name").innerHTML;
		document.getElementById("db-name").innerHTML = "<input type='text' style='width:200px;' class='form-control' value='" + value +"'>";
	}
	else
	{
		var new_value = document.getElementById("db-name").firstChild.value;
		var old_value = document.getElementsByClassName("active")[0].innerHTML;
		var xhr = new XMLHttpRequest();
		xhr.onreadystatechange = function() {
		    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
		    	if (xhr.responseText == "1")
		    	{
					document.getElementById("navbar").getElementsByClassName("active")[0].innerHTML = new_value;
					document.getElementById("db-name").innerHTML = new_value;
		    	}
		    	else
		        	alert("La modification de la base a échouée");
		    }
		};
		xhr.open("GET", "rename_db.php?new_name="+new_value+"&old_name="+old_value, true);
		xhr.send(null);
		button.innerHTML = "Renommer";
	}
}

//Supprimer la base de données
function delete_db()
{
	var value = document.getElementById('db-name').innerHTML;
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
		if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
		   	if (xhr.responseText == "1")
		    {
		   		document.getElementById("infos-base").innerHTML = "";
		   		document.getElementById("navbar").getElementsByClassName("active")[0].parentNode.remove();
				document.getElementById('list-tables').innerHTML = '';
				document.getElementById("list-tables").className = "scrollable";
		   	}
		   	else
		       	alert("La suppression de la base a échouée");
	    }
	};
	xhr.open("GET", "delete_db.php?db_name="+value, true);
	xhr.send(null);
}

//Ouvre la modal pour confirmer la suppression de la base de données
function confirm_delete_db()
{
	var value = document.getElementById('db-name').innerHTML;
	document.getElementById('myModalLabel').innerHTML = 'Suppression de la base : '+value;
	$('#db-modal').modal();
}

//Récupére les stats de la base de données
function get_stats_db()
{
	var value = document.getElementsByClassName("active")[0].innerHTML;
	var stats = ["00/00/00", 0, 0];
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
	    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
	    	var response = xhr.responseXML;
	    	stats[0] = response.getElementById('date').getAttribute("name");
	    	stats[1] = response.getElementById('nb_tables').getAttribute("name");
	    	stats[2] = response.getElementById('size').getAttribute("name");
	    	if (stats[0] != 0)
    			document.getElementById("stats-base").innerHTML = '(créée le ' + stats[0] + ', ' + stats[1] + ' tables, ' + stats[2] + ' Mo)';
	    }
	};
    xhr.open("POST", "get_stats_db.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("db_name=" + value);
}

//Affiche les infos de la base et la liste de ses tables
function display_db(link)
{
	var db_name = document.getElementsByClassName("active")[0].innerHTML;

	document.getElementById("infos-base").innerHTML = "";
	$('<div id ="base"><h2 id="db-name">' + db_name + '</h2><span id="stats-base"></span></div><div id="modif-base"><button id="free-request" class="btn btn-primary" onClick="display_area()">Requêtes</button><button id="rename-base" class="btn btn-warning" onClick="rename_db(this);">Renommer</button><button class="btn btn-danger" onClick="confirm_delete_db();">Supprimer</button></div><hr>').appendTo($('#infos-base'));
	get_stats_db();
	get_tables();
}

function hide_db()
{
	document.getElementById("infos-base").innerHTML = "";
	document.getElementById("list-tables").innerHTML = "";	
}
function display_area()
{	
	hide_db();
	$('<textarea id="request-area" class="form-control" rows="15" cols="150"></textarea><button id="request-valide" class="btn btn-primary" onClick="display_request(document.getElementById("request-area").value)">executer</button>').appendTo($('#list-tables'));
}
//Change la base de données séléctionnée
function set_active(link)
{
	if (document.getElementById("navbar").getElementsByClassName("active")[0] != undefined)
		document.getElementById("navbar").getElementsByClassName("active")[0].className = "";
	link.className = "active";
	display_db(link);
}

function display_request(request)
{
	document.getElementById("request-area").value = "";
	xhr.open("POST", "request_single.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("request=" + request);
}