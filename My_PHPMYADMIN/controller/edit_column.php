<?php
require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/plain");

$name_db = (isset($_GET["db_name"])) ? $_GET["db_name"] : NULL;
$table_name = (isset($_GET["table_name"])) ? $_GET["table_name"] : NULL;
$new_name = (isset($_GET["new_name"])) ? $_GET["new_name"] : NULL;
$old_name = (isset($_GET["old_name"])) ? $_GET["old_name"] : NULL;
$type_column = (isset($_GET["type_column"])) ? $_GET["type_column"] : NULL;
$size = (isset($_GET["size"])) ? $_GET["size"] : NULL;
if ($name_db && $table_name && $new_name && $old_name && $type_column) {
	select_db($pdo, $name_db);
	if(edit_element($pdo, $table_name, $old_name, $new_name, $type_column, $size))
    	echo "1";
    else
    	echo "0";
}
else
    echo "Erreur d'arguments";

?>