<?php
require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/plain");

$name_db = (isset($_GET["db_name"])) ? $_GET["db_name"] : NULL;
$table_name = (isset($_GET["table_name"])) ? $_GET["table_name"] : NULL;
if ($name_db && $table_name) {
	select_db($pdo, $name_db);
	if(delete_table($pdo, $table_name))
    	echo "1";
    else
    	echo "0";
}
else
    echo "0";

?>