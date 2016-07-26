<?php

require_once("../modele/connexion.php");
require_once("../modele/fonctions_DB.php");

header("Content-Type: text/xml");
echo "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
echo "<list>";
$name_db = (isset($_POST["db_name"])) ? $_POST["db_name"] : NULL;
$stats = stats_db($pdo, $name_db);
if(!empty($stats))
{
	echo "<item id=\"date\" name=\"" . $stats[2] . "\" />";
	echo "<item id=\"nb_tables\" name=\"" . $stats[0] . "\" />";
	echo "<item id=\"size\" name=\"" . $stats[1] . "\" />";
}
else
{
	echo "<item id=\"date\" name=\"\" />";
	echo "<item id=\"nb_tables\" name=\"\" />";
	echo "<item id=\"size\" name=\"\" />";	
}
echo "</list>";

?>