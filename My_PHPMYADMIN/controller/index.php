<?php
//session_start();
require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

$dbs = list_db($pdo);

include("../vue/index.php");
?>