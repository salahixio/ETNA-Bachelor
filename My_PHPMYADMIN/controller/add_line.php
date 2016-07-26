<?php
require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/plain");

$name_db = (isset($_POST["db_name"])) ? $_POST["db_name"] : NULL;
$table_name = (isset($_POST["table_name"])) ? $_POST["table_name"] : NULL;
$json_values = (isset($_POST["json_values"])) ? $_POST["json_values"] : NULL;
if ($name_db && $table_name && $json_values) {
	select_db($pdo, $name_db);
	$json_values = json_decode($json_values);
	$values = "";
	foreach ($json_values as $value) {
		$values .= "'".$value . "', ";
	}
	$values = substr($values, 0, strlen($values) - 2);
	if(add_line($pdo, $table_name, $values))
    	echo "1";
    else
    	echo "0";
}
else
    echo "-1";

?>