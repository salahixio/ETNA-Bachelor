//Ajout d'une colonne
function add_column()
{
	var table_name = document.getElementById("table-name").innerHTML;
	var select = document.getElementById("type-column");
	var type_column = select.options[select.selectedIndex].value;
	var column_name = document.getElementById("column-name").value;
	var size = document.getElementById("size").value;
	var db_name = document.getElementsByClassName("active")[0].innerHTML;
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
	    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
	    	if (xhr.responseText == "1")
	    	{
				$('<tr><td>'+column_name+'</td><td>'+type_column.toLowerCase()+'</td><td>'+size+'</td><td><button class="btn btn-warning btn-sm" onClick="">Editer</button></td><td><button class="btn btn-danger btn-sm" onClick="delete_column(this);">Supprimer</button></td></tr>').appendTo($('#item-tables'));
	    		document.getElementById("size").value = "";
	    		document.getElementById("column-name").value = "";
	    	}
	    	else
	        	alert("La création de la colonne a échouée");
	    }
	};
	xhr.open("GET", "add_column.php?db_name="+db_name+"&table_name="+table_name+"&column_name="+column_name+"&type_column="+type_column+"&size="+size, true);
	xhr.send(null);
}

var tmp_column = "";

//Editer une colonne
function edit_column(button)
{
	if (button.innerHTML == "Editer")
	{
		button.innerHTML = "Sauvegarder";
		var value = button.parentNode.parentNode.firstChild.innerHTML;
		var type_column = button.parentNode.parentNode.childNodes[1].innerHTML;
		var size = button.parentNode.parentNode.childNodes[2].innerHTML;
		tmp_column = value;
		button.parentNode.parentNode.firstChild.innerHTML = "<input type='text' class='form-control' value='" + value +"'>";
		button.parentNode.parentNode.childNodes[1].innerHTML = "<select class='form-control'><option selected='selected'>"+type_column.toUpperCase()+"</option>" + get_options_for_select("") + "</select>";
		button.parentNode.parentNode.childNodes[2].innerHTML = "<input type='text' class='form-control' value='" + size +"'>";
	}
	else
	{
		var value = button.parentNode.parentNode.firstChild.firstChild.value;
		var select = button.parentNode.parentNode.childNodes[1].firstChild;
		var type_column = select.options[select.selectedIndex].value;
		var size = button.parentNode.parentNode.childNodes[2].firstChild.value;
		var db_name = document.getElementsByClassName("active")[0].innerHTML;
		var table_name = document.getElementById('table-name').innerHTML;
		var xhr = new XMLHttpRequest();
		xhr.onreadystatechange = function() {
		    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
		    	if (xhr.responseText == "1")
		    	{
					button.parentNode.parentNode.firstChild.innerHTML = value;
					button.parentNode.parentNode.childNodes[1].innerHTML = type_column.toLowerCase();
					button.parentNode.parentNode.childNodes[2].innerHTML = size;
		    	}
		    	else
		    	{
		        	alert("La modification de la table a échouée");
		        }
		    }
		};
		xhr.open("GET", "edit_column.php?db_name="+db_name+"&table_name="+table_name+"&new_name="+value+"&old_name="+tmp_column+"&type_column="+type_column+"&size="+size, true);
		xhr.send(null);
		button.innerHTML = "Editer";		
	}
}

//Suppression d'une colonne
function delete_column(button)
{
	var db_name = document.getElementsByClassName("active")[0].innerHTML;
	var column_name = button.parentNode.parentNode.firstChild.innerHTML;
	var table_name = document.getElementById('table-name').innerHTML;
	var confirm = window.confirm('Etes vous sur de vouloir supprimer ' + column_name + '?');
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
		        	alert("La suppression de la colonne a échouée");
		    }
		};
		xhr.open("GET", "delete_column.php?db_name="+db_name+"&table_name="+table_name+"&column_name="+column_name, true);
		xhr.send(null);
	}
}

//Récupére l'ensemble des colonnes
function get_columns(table)
{
	var db_name = document.getElementsByClassName("active")[0].innerHTML;
	var table_name = table.innerHTML;
	var lignes = table.parentNode.childNodes[1].innerHTML;
	hide_db();
	$('<div id= "infos"><h2 id ="table-name">' + table_name + '</h2><span id="stats-table">Table de ' + lignes +' ligne(s)</span></div><div id="return-list"><button class="btn btn-primary" onClick="display_db(\'\');">Retour à la liste</button></div><hr>').appendTo($('#infos-base'));
	$('<table class="table"><thead class="text-center"><tr><td>Nom de la colonne</td><td>Type</td><td>Taille</td><td></td><td></td></tr></thead><tbody id="item-tables" class="text-center"></tbody><tfoot class="text-center"><tr><td><input id="column-name" type="text" class="form-control" value=""></td><td><select id="type-column" class="form-control">' + get_options_for_select('selected="selected"') + '</select></td><td><input id="size" type="text" class="form-control" value=""></td><td><button id="add-column" class="btn btn-success btn-sm" onClick="add_column(this);">Ajouter</button></td><td></td></tr></tfoot></table>').appendTo($('#list-tables'));
	var xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function() {
	    if (xhr.readyState == 4 && (xhr.status == 200 || xhr.status == 0)) {
	    	var response = xhr.responseXML;
	    	var items   = response.getElementsByTagName("item");
	    	var str = "";
			for (var i=0, length=items.length; i<length; i++) {
				str = '<tr class="select-table">';
	    		var champs   = items[i].childNodes;
	    		for (var j=0, length_champs=champs.length; j<length_champs; j++) {
					str += '<td>' + champs[j].getAttribute("name") + '</td>';
	    		}
				$(str + '<td><button class="btn btn-warning btn-sm" onClick="edit_column(this);">Editer</button></td><td><button class="btn btn-danger btn-sm" onClick="delete_column(this);">Supprimer</button></td></tr>').appendTo($('#item-tables'));
    		}
    	}
	};
    xhr.open("POST", "get_columns.php", true);
    xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xhr.send("db_name=" + db_name  + "&table_name=" + table_name);
}

function get_options_for_select(selected)
{
	return '<option '+selected+' title="Un nombre entier de 4 octets. La fourchette des entiers relatifs est de -2 147 483 648 à 2 147 483 647. Pour les entiers positifs, c\'est de 0 à 4 294 967 295">INT</option><option title="Une chaîne de longueur variable (0-65,535), la longueur effective réelle dépend de la taille maximum d\'une ligne">VARCHAR</option><option title="Une colonne TEXT d\'une longueur maximum de 65 535 (2^16 - 1) caractères, stockée avec un préfixe de deux octets indiquant la longueur de la valeur en octets 	">TEXT</option><option title="Une date, la fourchette est de «1000-01-01» à «9999-12-31»">DATE</option><optgroup label="Numérique"><option title="Un nombre entier de 1 octet. La fourchette des nombres avec signe est de -128 à 127. Pour les nombres sans signe, c\'est de 0 à 255">TINYINT</option><option title="Un nombre entier de 2 octets. La fourchette des nombres avec signe est de -32 768 à 32 767. Pour les nombres sans signe, c\'est de 0 à 65 535">SMALLINT</option><option title="Un nombre entier de 3 octets. La fourchette des nombres avec signe est de -8 388 608 à 8 388 607. Pour les nombres sans signe, c\'est de 0 à 16 777 215">MEDIUMINT</option><option '+selected+' title="Un nombre entier de 4 octets. La fourchette des entiers relatifs est de -2 147 483 648 à 2 147 483 647. Pour les entiers positifs, c\'est de 0 à 4 294 967 295">INT</option><option title="Un nombre entier de 8 octets. La fourchette des nombres avec signe est de -9 223 372 036 854 775 808 à 9 223 372 036 854 775 807. Pour les nombres sans signe, c\'est de 0 à 18 446 744 073 709 551 615">BIGINT</option><option disabled="disabled">-</option><option title="Un nombre en virgule fixe (M, D) - le nombre maximum de chiffres (M) est de 65 (10 par défaut), le nombre maximum de décimales (D) est de 30 (0 par défaut)">DECIMAL</option><option title="Un petit nombre en virgule flottante, la fourchette des valeurs est -3.402823466E+38 à -1.175494351E-38, 0, et 1.175494351E-38 à 3.402823466E+38">FLOAT</option><option title="Un nombre en virgule flottante double-précision, la fourchette des valeurs est -1.7976931348623157E+308 à -2.2250738585072014E-308, 0, et 2.2250738585072014E-308 à 1.7976931348623157E+308">DOUBLE</option><option title="Synonyme de DOUBLE (exception : dans le mode SQL REAL_AS_FLOAT, c\'est un synonyme de FLOAT)">REAL</option><option disabled="disabled">-</option><option title="Une colonne contenant des bits (M), stockant M bits par valeur (1 par défaut, maximum 64)">BIT</option><option title="Un synonyme de TINYINT(1), une valeur de zéro signifie faux, une valeur non-zéro signifie vrai">BOOLEAN</option><option title="Un alias pour BIGINT UNSIGNED NOT NULL AUTO_INCREMENT UNIQUE">SERIAL</option></optgroup><optgroup label="Contient la date et l\' heure"><option title="Une date, la fourchette est de «1000-01-01» à «9999-12-31»">DATE</option><option title="Une combinaison date et heure, la fourchette est de «1000-01-01 00:00:00» à «9999-12-31 23:59:59»">DATETIME</option><option title="Un type d\'horodatage, la fourchette est de «1970-01-01 00:00:01» UTC à «2038-01-09 03:14:07» UTC, en nombre de secondes depuis le moment de référence («1970-01-01 00:00:00» UTC)">TIMESTAMP</option><option title="Une heure, la fourchette est de «-838:59:59» à «838:59:59»">TIME</option><option title="Une année à quatre chiffres (4 par défaut) ou à deux chiffres (2), la fourchette est de 70 (1970) à 69 (2069) ou 1901 à 2155 ainsi que 0000">YEAR</option></optgroup><optgroup label="Chaîne de caractères"><option title="Une chaîne de longueur fixe (0-255, 1 par défaut) qui est toujours complétée à droite par des espaces lorsqu\'enregistrée">CHAR</option><option title="Une chaîne de longueur variable (0-65,535), la longueur effective réelle dépend de la taille maximum d\'une ligne">VARCHAR</option><option disabled="disabled">-</option><option title="Une colonne de type TEXT d\'une longueur maximum de 255 (2^8 - 1) caractères, stockée avec un préfixe d\'un octet indiquant la longueur de la valeur en octets">TINYTEXT</option><option title="Une colonne TEXT d\'une longueur maximum de 65 535 (2^16 - 1) caractères, stockée avec un préfixe de deux octets indiquant la longueur de la valeur en octets 	">TEXT</option><option title="Une colonne TEXT d\'une longueur maximum de 16 777 215 (2^24 - 1) caractères, stockée avec un préfixe de trois octets indiquant la longueur de la valeur en octets">MEDIUMTEXT</option><option title="Une colonne TEXT d\'une longueur maximum de 4 294 967 295 ou 4 GiB (2^32 - 1) caractères, stockée avec un préfixe de quatre octets indiquant la longueur de la valeur en octets">LONGTEXT</option><option disabled="disabled">-</option><option title="Similaire au type CHAR, mais stocke des chaînes binaires au lieu de chaînes non binaires">BINARY</option><option title="Similaire au type VARCHAR, mais stocke des chaînes binaires au lieu de chaînes non binaires">VARBINARY</option><option disabled="disabled">-</option><option title="Une colonne BLOB d\'une longueur maximum de 255 (2^8 - 1) octets, stockée avec un préfixe d\'un octet indiquant la longueur de la valeur">TINYBLOB</option><option title="Une colonne BLOB d\'une longueur maximum de 16 777 215 (2^24 - 1) octets, stockée avec un préfixe de trois octets indiquant la longueur de la valeur">MEDIUMBLOB</option><option title="Une colonne BLOB d\'une longueur maximum de 65 535 (2^16 - 1) octets, stockée avec un préfixe de quatre octets indiquant la longueur de la valeur">BLOB</option><option title="Une colonne BLOB d\'une longueur maximum de 4 294 967 295 ou 4GiB (2^32 - 1), stockée avec un préfixe de quatre octets indiquant la longueur de la valeur">LONGBLOB</option><option disabled="disabled">-</option><option title="Une énumération, choisie parmi une liste comportant jusqu\'à 65 535 valeurs ou la valeur spéciale \'\' indiquant une erreur">ENUM</option><option title="Une valeur unique choisie parmi un ensemble comportant jusqu\'à 64 membres">SET</option></optgroup><optgroup label="Spatial"><option title="Un type pouvant stocker une valeur géométrique de tout type">GEOMETRY</option><option title="Un point dans un espace à deux dimensions">POINT</option><option title="Une courbe avec une interpolation linéaire entre les points">LINESTRING</option><option title="Un polygone">POLYGON</option><option title="Une collection de points">MULTIPOINT</option><option title="Une collection de courbes avec l\'interpolation linéaire entre les points">MULTILINESTRING</option><option title="Une collection de polygones">MULTIPOLYGON</option><option title="Une collection d\'objets de géométrie de tout type">GEOMETRYCOLLECTION</option></optgroup>';
}

