<html>
<?php

if (($_POST['login']) != "")
{
	$pdo = new PDO('mysql:host='.$_POST['ip'].';port='.$_POST['port'].';', $_POST['login'], $_POST['mdp']);
	if ($mysqli->connect_error)
		echo "PB de connexion a la base de données";
	else
	{
		$_SESSION['login'] = $_POST['login'];	
	}
}

if (/*(!isset($_SESSION['login'])) && */(is_null($_SESSION['login'])))
{
?>
Bonjour et bienvenue sur le site my_PHPmyAdmin.
Veuillez taper ici vos identifiants de connexion : 
<form action="index.php" method="post">
	Adresse du serveur : <input type="text" value="localhost" name="ip"><br>
	Port : <input type="number" name="port" value="9998"><br>
	Login : <input type="text" value="root" name ="login"><br>
	Mot de Passe : <input type="password" name="mdp" value="root"><br>
	<input type="submit" value="Connexion"><br>
</form>
<?php
}
else
{
	include_once('./user.php');
}
?>
</html>