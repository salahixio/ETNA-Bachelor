<?php
require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/plain");

$name_db = (isset($_GET["db_name"])) ? $_GET["db_name"] : NULL;
$new_name = (isset($_GET["new_name"])) ? $_GET["new_name"] : NULL;
$old_name = (isset($_GET["old_name"])) ? $_GET["old_name"] : NULL;
if ($name_db && $new_name && $old_name) {
	select_db($pdo, $name_db);
	if(rename_table($pdo, $old_name, $new_name))
    	echo "1";
    else
    	echo "0";
}
else
    echo "0";

?>