// affichage des sections de Mes infos
$( "#droits" ).click(function() {
	document.getElementById("infos_bancaire").className = "hidden";
	document.getElementById("ayants_droits").className = "container";
	document.getElementById("infos_contact").className = "hidden";
	document.getElementById("infos_perso").className = "hidden";
	document.getElementById("contact").className = "";
	document.getElementById("infos").className = "";
	document.getElementById("bancaire").className = "";
	$( this )[0].className = "active";
});

$( "#infos" ).click(function() {
	document.getElementById("infos_bancaire").className = "hidden";
	document.getElementById("ayants_droits").className = "hidden";
	document.getElementById("infos_contact").className = "hidden";
	document.getElementById("infos_perso").className = "container";
	document.getElementById("contact").className = "";
	document.getElementById("bancaire").className = "";
	document.getElementById("droits").className = "";
	$( this )[0].className = "active";
});

$( "#bancaire" ).click(function() {
	document.getElementById("infos_bancaire").className = "container";
	document.getElementById("ayants_droits").className = "hidden";
	document.getElementById("infos_contact").className = "hidden";
	document.getElementById("infos_perso").className = "hidden";
	document.getElementById("contact").className = "";
	document.getElementById("infos").className = "";
	document.getElementById("droits").className = "";
	$( this )[0].className = "active";
});

$( "#contact" ).click(function() {
	document.getElementById("infos_bancaire").className = "hidden";
	document.getElementById("ayants_droits").className = "hidden";
	document.getElementById("infos_contact").className = "container";
	document.getElementById("infos_perso").className = "hidden";
	document.getElementById("bancaire").className = "";
	document.getElementById("infos").className = "";
	document.getElementById("droits").className = "";
	$( this )[0].className = "active";
	initialize();
});

//Bouton Editer/sauvegarder
$( "#edit_infos" ).click(function() {
	if($( this )[0].innerHTML == "Editer")
	{
		$( this )[0].innerHTML = "Sauvegarder";
		var form_control = document.getElementsByClassName("persos");
		for (var i = 0; i < form_control.length; i++) {
			form_control[i].removeAttribute('readonly');
		};
	}
	else
	{
		alert("Infos mis à jour");
		$( this )[0].innerHTML = "Editer";
		var form_control = document.getElementsByClassName("persos");
		for (var i = 0; i < form_control.length; i++) {
			form_control[i].setAttribute('readonly', 'true');
		};
	}
});

//Ajout d'un ajout-droit
$("#add_item").click(function() {
	$('<tr><td class="elem"><input class="modif_item" type="text" size="10" value=""></td><td class="elem"><input class="modif_item" type="text" size="10" value=""></td><td class="elem"><input class="modif_item" type="text" size="10" value=""></td><td class="elem"><input class="modif_item" type="text" size="10" value=""></td><td class="elem"><input class="modif_item" type="text" size="10" value=""></td><td><button class="btn btn-primary btn-sm" onClick="edit_ligne(this)">Sauvegarder</button></td><td><button class="btn btn-danger btn-sm" onClick=remove_ligne(this)>Supprimer</button></td></tr>').appendTo($('.table > tbody'));
});

//Suppresion d'un ayant-droit
function remove_ligne(button) {
	button.parentNode.parentNode.remove();
};

//Edition d'un ayant-droit
function edit_ligne(button) {
	if (button.innerHTML == "Editer")
	{
		var elems = button.parentNode.parentNode.getElementsByClassName("elem");
		button.innerHTML = "Sauvegarder";
		for (var i = 0; i < elems.length; i++) {
			elems[i].innerHTML = "<input class='modif_item' type='text' size='10' value='" + elems[i].innerHTML +"'>";
		};
	}
	else
	{
		var elems = button.parentNode.parentNode.getElementsByClassName("elem");
		button.innerHTML = "Editer";
		for (var i = 0; i < elems.length; i++) {
			elems[i].innerHTML = elems[i].firstChild.value;
		};	
	}
};

//Bouton Editer/sauvegarder
$( "#edit_compte" ).click(function() {
	if($( this )[0].innerHTML == "Editer")
	{
		$( this )[0].innerHTML = "Sauvegarder";
		var form_control = document.getElementsByClassName("compte");
		for (var i = 0; i < form_control.length; i++) {
			form_control[i].removeAttribute('readonly');
		};
	}
	else
	{
		alert("Infos mis à jour");
		$( this )[0].innerHTML = "Editer";
		var form_control = document.getElementsByClassName("compte");
		for (var i = 0; i < form_control.length; i++) {
			form_control[i].setAttribute('readonly', 'true');
		};
	}
});

//Barre de progression
function timer1(n) {
	$("#progress1").css("width", n + "%");
	if(n < 100) {
		setTimeout(function() {
			timer1(n + 10);
		}, 200);
	}
}
$(function (){
	$("#launch1").click(function() {
		timer1(0);
	});
});

function timer2(n) {
	$("#progress2").css("width", n + "%");
	if(n < 100) {
		setTimeout(function() {
			timer2(n + 10);
		}, 200);
	}
}
$(function (){
	$("#launch2").click(function() {
		timer2(0);
	});
});

function timer3(n) {
	$("#progress3").css("width", n + "%");
	if(n < 100) {
		setTimeout(function() {
			timer3(n + 10);
		}, 200);
	}
}
$(function (){
	$("#launch3").click(function() {
		timer3(0);
	});
});

//Google maps
function initialize() {
	var mapProp = {
    	center:new google.maps.LatLng(49.5664377, 3.6222503),
    	zoom:10,
    	mapTypeId:google.maps.MapTypeId.ROADMAP
  	};
var map=new google.maps.Map(document.getElementById("map"),mapProp);

marker = new google.maps.Marker({
    map: map,
    draggable: true,
    position: {lat: 49.5664377, lng: 3.6222503}
  });
}


//Bouton Contact
$( "#send" ).click(function() {
	var contacts = document.getElementsByClassName("contacts");
	for (var i = 0; i < contacts.length; i++) {
		contacts[i].value = "";
	};
	alert("Votre message a bien été envoyé");
});
