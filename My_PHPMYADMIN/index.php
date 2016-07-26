<?php
error_reporting(0);
ini_set('display_errors', 'Off');
session_start();
if ($_POST['destroy'] == "true")
{
	$_SESSION['login'] = NULL;
	$_SESSION['mdp'] = NULL;
	$_SESSION['port'] = NULL;
	$_SESSION['ip'] = NULL;
}
$flag = TRUE;
if (($_POST['ip']) != "")
{
  if (($_POST['login']) == "")
    $_POST['login'] = '';
  if (($_POST['mdp']) == "")
    $_POST['mdp'] = '';
  try
    {
      $flag = array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION);
      $pdo = new PDO('mysql:host='.$_POST['ip'].';port='.$_POST['port'].';', $_POST['login'], $_POST['mdp'], $flag);
    }
  catch (Exception $e)
    {
      $flag = FALSE;
    }
  if ($flag != FALSE)
    {
	  $_SESSION['login'] = $_POST['login'];
	  $_SESSION['mdp'] = $_POST['mdp'];
	  $_SESSION['port'] = $_POST['port'];
	  $_SESSION['ip'] = $_POST['ip'];
	  header('Location: controller/index.php');
    }
}
if ((is_null($_SESSION['login'])))
{
  if ($flag == FALSE)
    echo "Mauvaise connexion. Veuillez reessayer\n";
  ?>
<link href="/houvet_b/vue/bootstrap/dist/css/bootstrap.min.css" rel="stylesheet">
<link href="/houvet_b/vue/css/index.css" rel="stylesheet">
<center>
<h2>Bonjour et bienvenue sur le site my_PHPmyAdmin.</h2>
<form action="#" method="post">
	Adresse du serveur : <input type="text" class="form-control" value="localhost" name="ip" style="width:200px;"><br>
	Port : <input type="number" class="form-control" name="port" value="9998" style="width:200px;"><br>
	Login : <input type="text" value="root" class="form-control" name="login" style="width:200px;"><br>
	Mot de Passe : <input type="password" name="mdp" class="form-control" value="root" style="width:200px;"><br>
	<input type="submit" class="btn btn-success" value="Connexion"><br>
</form>
   </center>
<?php
}
?>