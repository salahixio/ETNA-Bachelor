<?php

require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/xml");
echo "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
echo "<list>";

$name_db = (isset($_POST["db_name"])) ? $_POST["db_name"] : NULL;
$table_name = (isset($_POST["table_name"])) ? $_POST["table_name"] : NULL;

if ($name_db && $table_name) {
	$columns = list_cols($pdo, $table_name, $name_db);
	foreach ($columns as $column) {
		if (strstr($column['Type'], '('))
		{
			$explode = explode('(', $column['Type']);
			$type = $explode[0];
			$explode_taille = explode(')',$explode[1]);
			$taille = $explode_taille[0];
		}
		else
		{
			$type = $column['Type'];
			$taille = "";
		}
		echo "<item>";
		echo "<champ name=\"" . $column['Field'] . "\" />";
		echo "<champ name=\"" . $type . "\" />";
		echo "<champ name=\"" . $taille . "\" />";
		echo "</item>";
	}
}
echo "</list>";

?>