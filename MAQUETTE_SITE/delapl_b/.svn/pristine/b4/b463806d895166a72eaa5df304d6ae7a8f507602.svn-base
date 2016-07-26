$( "#connexion" ).click(function() {
	if($( this )[0].innerHTML == "Se connecter")
	{
		alert("Vous êtes maintenant connecté\nVous pouvez accéder à vos infos");
		var infos = document.getElementById("infos");
		infos.className = "";
		$( this )[0].innerHTML = "Se déconnecter";
	}
	else
	{
		alert("Vous êtes maintenant déconnecté");
		var infos = document.getElementById("infos");
		infos.className = "hidden";
		$( this )[0].innerHTML = "Se connecter";
	}
});