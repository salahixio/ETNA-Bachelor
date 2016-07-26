<?php
require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/plain");

$name_db = (isset($_GET["db_name"])) ? $_GET["db_name"] : NULL;
$table_name = (isset($_GET["table_name"])) ? $_GET["table_name"] : NULL;
$primary_value = (isset($_GET["primary_value"])) ? $_GET["primary_value"] : NULL;
if ($name_db && $table_name && $primary_value) {
	select_db($pdo, $name_db);
	$where_condition = as_primary_key($pdo, $table_name)." = ".$primary_value;
	//echo delete_line($pdo, $where_condition, $table_name);
	if(delete_line($pdo, $where_condition, $table_name))
    	echo "1";
    else
    	echo "0";
}
else
    echo "-1";

?>