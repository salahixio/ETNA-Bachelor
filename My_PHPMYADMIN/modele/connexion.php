<?php
session_start();
//echo $_SESSION['ip'];
$pdo = new PDO('mysql:host='.$_SESSION['ip'].';port='.$_SESSION['port'].';', $_SESSION['login'], $_SESSION['mdp']);
?>
