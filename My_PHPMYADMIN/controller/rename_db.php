<?php
require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/plain");

$new_name = (isset($_GET["new_name"])) ? $_GET["new_name"] : NULL;
$old_name = (isset($_GET["old_name"])) ? $_GET["old_name"] : NULL;
if ($new_name && $old_name) {
	//TODO
	if(true)
    	echo "1";
    else
    	echo "0";
}
else
    echo "0";

?>