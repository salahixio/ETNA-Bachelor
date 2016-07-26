<?php

require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/xml");
echo "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
echo "<list>";

$name_db = (isset($_POST["db_name"])) ? $_POST["db_name"] : NULL;

$tables = liste_table($pdo, $name_db);
select_db($pdo, $name_db);
foreach ($tables as $table) {
	echo "<item name=\"" . $table . "\" lignes=\"" . stat_table($pdo, $table) . "\" />";
}

echo "</list>";

?>