<?php
require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/plain");

$name_db = (isset($_GET["db_name"])) ? $_GET["db_name"] : NULL;
if ($name_db) {
	if(create_db($pdo, $_GET["db_name"], "utf8"))
    	echo "1";
    else
    	echo "0";
}
else
    echo "0";

?>