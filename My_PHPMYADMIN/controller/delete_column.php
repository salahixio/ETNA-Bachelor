<?php
require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/plain");

$name_db = (isset($_GET["db_name"])) ? $_GET["db_name"] : NULL;
$table_name = (isset($_GET["table_name"])) ? $_GET["table_name"] : NULL;
$column_name = (isset($_GET["column_name"])) ? $_GET["column_name"] : NULL;
if ($name_db && $table_name && $column_name) {
	select_db($pdo, $name_db);
	if(delete_element($pdo, $table_name, $column_name))
    	echo "1";
    else
    	echo "0";
}
else
    echo "-1";

?>