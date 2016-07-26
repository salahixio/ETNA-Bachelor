//Ajout d'une ligne
function add_line()
{
	var db_name = document.getElementsByClassName("active")[0].innerHTML;
	var table_name = document.getElementById('table-name').innerHTML;
	var json_values = '{';
	var value = '';
	var nodes = document.getElementById("item-tables").firstChild.childNodes;
	for (var i = 0; i < nodes.length - 1; i++) {
		value = '"'+nodes[i].className+'": "'+nodes[i].firstChild.value+ '"';
		if (i != nodes.length - 2)
			value += ", ";
		json_values += value;
	}
	json_values += '}';
	JSON.parse(json_values);
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
	    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
			if (xhr.responseText != "1")
	        	alert("La création de la ligne a échouée");
	        else
	        {
				get_lines(document.getElementById('table-name'));
	        }
	    }
	};
	xhr.open("POST", "add_line.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("db_name=" + db_name  + "&table_name=" + table_name + "&json_values=" + json_values);
}

//Affiche la création de nouvelle ligne
function display_add_line()
{
	var db_name = document.getElementsByClassName("active")[0].innerHTML;
	var table_name = document.getElementById('table-name').innerHTML;
	document.getElementById('list-tables').innerHTML = "";	
	$('<table class="table"><thead id="header-table" class="text-center"></thead><tbody id="item-tables" class="text-center">').appendTo($('#list-tables'));	
	$('</tbody></table>').appendTo($('#list-tables'));
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
	    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
	    	var response = xhr.responseXML;
	    	var items   = response.getElementsByTagName("item");
	    	var str = "<tr>";
	    	var new_line = "<tr>";
			for (var i=0, length=items.length; i<length; i++) {
	    		var champ = items[i].firstChild;
				str += '<td>' + champ.getAttribute("name") + '</td>';
				new_line += '<td class="'+champ.getAttribute("name")+'"><input type="text" class="form-control" value=""></td>';
	    	}
			$(str + '<td></td></tr>').appendTo($('#header-table'));
	    	$(new_line + '<td><button class="btn btn-success btn-sm" onClick="add_line(this);">Ajouter</button></td></tr>').appendTo($('#item-tables'));
	    }
	};
	xhr.open("POST", "get_columns.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("db_name=" + db_name  + "&table_name=" + table_name);
	
}

//Edition d'une ligne
function edit_line(button)
{
}

//Suppression d'une ligne
function delete_line(button)
{
	var db_name = document.getElementsByClassName("active")[0].innerHTML;
	var primary_value = button.parentNode.parentNode.getElementsByClassName("primary")[0].innerHTML;
	var table_name = document.getElementById('table-name').innerHTML;
	var confirm = window.confirm('Etes vous sur de vouloir supprimer la ligne ' + primary_value + '?');
	if (confirm)
	{
		var xhr = new XMLHttpRequest();
		xhr.onreadystatechange = function() {
		    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
		    	if (xhr.responseText == "1")
		    	{
					button.parentNode.parentNode.remove();
		    	}
		    	else
		        	alert("La suppression de la ligne a échouée");
		    }
		};
		xhr.open("GET", "delete_line.php?db_name="+db_name+"&table_name="+table_name+"&primary_value="+primary_value, true);
		xhr.send(null);
	}
}

//Récupération des lignes d'une table
function get_lines(table)
{
	var db_name = document.getElementsByClassName("active")[0].innerHTML;
	var table_name = table.innerHTML;
	var lignes = table.parentNode.childNodes[1].innerHTML;
	hide_db();
	$('<div id="infos"><h2 id ="table-name">' + table_name + '</h2><span id="stats-table">Table de ' + lignes +' ligne(s)</span></div><div id="return-list"><button class="btn btn-primary" onClick="display_db(\'\');">Retour à la liste</button><button id="add-line" class="btn btn-success" onClick="display_add_line();">Insérer des lignes</button></div><hr>').appendTo($('#infos-base'));
	$('<table class="table"><thead id="columns" class="text-center"></thead><tbody id="item-tables" class="text-center">').appendTo($('#list-tables'));
	$('</tbody></table>').appendTo($('#list-tables'));
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
	    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
	    	var response = xhr.responseXML;
	    	var columns = response.getElementsByTagName("header");
	    	var count = response.getElementsByTagName("count");
	    	var primary = response.getElementsByTagName("primary")[0];
	    	var str = '<tr>';
	    	var champs   = columns[0].childNodes;
	    	for (var j=0, length=champs.length; j<length; j++) {
				str += '<td>' + champs[j].getAttribute("name") + '</td>';
	    	}
	    	if (primary.getAttribute("name") != 0)
	    		str += '<td></td><td></td>';
			$(str + '</tr>').appendTo($('#columns'));
	    	var items   = response.getElementsByTagName("item");
	    	var str = "";
			for (var i=0, length=items.length; i<length; i++) {
				str = '<tr class="select-table">';
	    		var champs   = items[i].childNodes;
	    		for (var j=0, length_champs=champs.length; j<length_champs; j++) {
	    			str += '<td ';
	    			if (champs[j].getAttribute("column") == primary.getAttribute("name"))
						str += 'class="primary"';
					str += '>' + champs[j].getAttribute("name") + '</td>';
	    		}
	    		if (primary.getAttribute("name") != 0)
	    			str += '<td><button class="btn btn-warning btn-sm" onClick="">Editer</button></td><td><button class="btn btn-danger btn-sm" onClick="delete_line(this);">Supprimer</button></td>';
				$(str + '</tr>').appendTo($('#item-tables'));
    		}
	    }
	};
    xhr.open("POST", "get_lines.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("db_name=" + db_name + "&table_name=" + table_name);
}