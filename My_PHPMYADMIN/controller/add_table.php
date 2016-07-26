<?php
require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/plain");

$name_db = (isset($_POST["db_name"])) ? $_POST["db_name"] : NULL;
$table_name = (isset($_POST["table_name"])) ? $_POST["table_name"] : NULL;
$column_name = (isset($_POST["column_name"])) ? $_POST["column_name"] : NULL;
$type_column = (isset($_POST["type_column"])) ? $_POST["type_column"] : NULL;
$nulle = (isset($_POST["nulle"])) ? $_POST["nulle"] : NULL;
$primary = (isset($_POST["primary"])) ? $_POST["primary"] : NULL;
$state_column = $primary." ".$nulle;
$arr = array();
if (isset($name_db) && isset($table_name) && isset($column_name) && isset($type_column) && isset($state_column)) {
	select_db($pdo, $name_db);
	$arr[0] = array($column_name, $type_column, $state_column);
	if(create_table($pdo, $table_name, $arr))
    	echo "1";
    else
    	echo "0";
}
else
    echo "0";

?>