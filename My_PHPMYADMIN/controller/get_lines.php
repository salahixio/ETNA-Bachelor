<?php

require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/xml");
echo "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
echo "<list>";

$name_db = (isset($_POST["db_name"])) ? $_POST["db_name"] : NULL;
$table_name = (isset($_POST["table_name"])) ? $_POST["table_name"] : NULL;

if ($name_db && $table_name) {
	select_db($pdo, $name_db);
	$lignes = list_content($pdo, $table_name);
	$columns = list_cols($pdo, $table_name, $name_db);
	$has_primary_key = as_primary_key($pdo, $table_name) === NULL ? 0 : as_primary_key($pdo, $table_name);
	echo "<header>";
	foreach ($columns as $column) {
		echo "<champ name=\"" . $column['Field'] . "\" />";
	}
	echo "</header>";
	echo "<count name=\"".count($columns)."\"/>";
	echo "<primary name=\"".$has_primary_key."\"/>";
	foreach ($lignes as $ligne) {
		echo "<item>";
		foreach ($ligne as $column => $value) {
			echo "<champ column=\"" . $column . "\" name=\"" . $value . "\" />";
		}
		echo "</item>";
	}
}
echo "</list>";

?>