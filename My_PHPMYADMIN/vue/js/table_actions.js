//Ajout d'une table
function add_table()
{
	var new_table = document.getElementById("new-table").value;
	var select = document.getElementById("type-column");
	var type_column = select.options[select.selectedIndex].value;
	var column_name = document.getElementById("column-name").value;
	var db_name = document.getElementsByClassName("active")[0].innerHTML;
	var nulle = (document.getElementById("nulle").checked == true) ? "NOT NULL" : "";
	var primary = (document.getElementById("primary").checked == true) ? "PRIMARY KEY" : "";
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
	    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
	    	if (xhr.responseText != "1")
	        	alert("La création de la table a échouée");
	        else
	        {
				display_db(document.getElementById("navbar").getElementsByClassName("active")[0]);
	        }
	    }
	};
	xhr.open("POST", "add_table.php", true);
	xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	xhr.send("db_name="+db_name+"&table_name="+new_table+"&column_name="+column_name+"&type_column="+type_column+"&nulle="+nulle+"&primary="+primary);
}

//Affiche une liste de colonne et un nom pour la nouvelle table
function display_add_table()
{
	hide_db();
	$('<div><h2 id ="add-new-table">Nom de la table</h2><input type="text" id="new-table" style="width:200px; display:inline-block; margin-left:5px;" class="form-control" value=""><button class="btn btn-success" onClick="add_table();">Créer</button></div><hr>').appendTo($('#infos-base'));
	$('<table class="table"><thead class="text-center"><tr><td>Nom de la colonne</td><td>Type</td></tr></thead><tbody id="item-tables" class="text-center">').appendTo($('#list-tables'));
	var select = "<select id='type-column' class='form-control'><option value='INT'>INT</option><option value='VARCHAR(50)'>VARCHAR</option value='TEXT'><option>TEXT</option><option value='DATE'>DATE</option></select>";
	$('<tr class=""><td class=""><input id="column-name" type="text" class="form-control" value=""></td><td>'+ select + '</td><td>clé primaire <INPUT type="checkbox" id="primary" value="PRIMARY KEY"></td><td>Ne peut etre null <INPUT type="checkbox" id="nulle" value="NOT NULL"></td></tr>').appendTo($('#item-tables'));	
	$('</tbody></table>').appendTo($('#list-tables'));
	
}

var tmp_table = "";

//Rennomer une table
function rename_table(button)
{
	if (button.innerHTML == "Renommer")
	{
		button.innerHTML = "Sauvegarder";
		var value = button.parentNode.parentNode.getElementsByClassName("name-table")[0].innerHTML;
		tmp_table = value;
		button.parentNode.parentNode.getElementsByClassName("name-table")[0].innerHTML = "<input type='text' class='form-control' value='" + value +"'>";
		button.parentNode.parentNode.firstChild.removeAttribute("onClick");
	}
	else
	{
		var value = button.parentNode.parentNode.getElementsByClassName("name-table")[0].firstChild.value;
		var db_name = document.getElementById('db-name').innerHTML;
		var xhr = new XMLHttpRequest();
		xhr.onreadystatechange = function() {
		    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
		    	if (xhr.responseText == "1")
		    	{
					button.parentNode.parentNode.getElementsByClassName("name-table")[0].innerHTML = value;
		    	}
		    	else
		    	{
		    		button.parentNode.parentNode.getElementsByClassName("name-table")[0].innerHTML = tmp_table;
		        	alert("La modification de la table a échouée");
		        }
		    }
		};
		xhr.open("GET", "rename_table.php?db_name="+db_name+"&new_name="+value+"&old_name="+tmp_table, true);
		xhr.send(null);
		button.innerHTML = "Renommer";
		button.parentNode.parentNode.firstChild.setAttribute("onClick", "get_lines(this);");		
	}
}

//Suppression d'une table
function delete_table(button)
{
	var value = button.parentNode.parentNode.firstChild.innerHTML;
	var db_name = document.getElementById('db-name').innerHTML;
	var confirm = window.confirm('Etes vous sur de vouloir supprimer ' + value + '?');
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
		        	alert("La suppression de la table a échouée");
		    }
		};
		xhr.open("GET", "delete_table.php?db_name="+db_name+"&table_name="+value, true);
		xhr.send(null);
	}
}

//Récupére l'ensemble des tables
function get_tables()
{
	var db_name = document.getElementsByClassName("active")[0].innerHTML;
	document.getElementById('list-tables').innerHTML = '';

	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
	    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
	    	var response = xhr.responseXML;
			var items   = response.getElementsByTagName("item");
			document.getElementById("list-tables").className = "color-gray scrollable";
			$('<table class="table"><thead class="text-center"><tr><td>Nom de la table</td><td>Lignes</td><td></td><td></td><td><button id="add-table" class="btn btn-success btn-sm" onClick="display_add_table();">Ajouter</button></td></tr></thead><tbody id="item-tables" class="text-center">').appendTo($('#list-tables'));				
			for (var i=0, length=items.length; i<length; i++) {
				$('<tr class="select-table"><td class="name-table" onclick="get_lines(this);">' + items[i].getAttribute("name") + '</td><td>' + items[i].getAttribute("lignes") + '</td><td><button type="button" class="btn btn-primary btn-sm" onClick="get_columns(this.parentNode.parentNode.firstChild);">Structure</button></td><td><button class="btn btn-warning btn-sm" onClick="rename_table(this);">Renommer</button></td><td><button class="btn btn-danger btn-sm" onClick="delete_table(this);">Supprimer</button></td></tr>').appendTo($('#item-tables'));
    		}
    		$('</tbody></table>').appendTo($('#list-tables'));
	    }
	};
    xhr.open("POST", "get_tables.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("db_name=" + db_name);
}

