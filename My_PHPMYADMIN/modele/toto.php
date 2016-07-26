<?php
include("./connexion.php");
include("./fonctions_DB.php");

function	rename_bdd($pdo, $name_old_table, $name_new_table)
{
  system("./mysqldump --host=localhost --user=root --password=root --no-create-db --default-character-set=utf8 --lock-tables=FALSE --tables ".$name_old_table." >dump.sql");
  $requete = "CREATE DATABASE `".$name_new_table."` CHARACTER SET utf8 COLLATE utf8_bin";
  $pdo->query($requete);
  system("cat dump.sql | ./mysql --host=localhost --user=root --password=root --database=".$name_new_table);
  $requete2 = $requete = "DROP DATABASE `".$name_old_table."`";
  $pdo->query($requete2);
}

rename_bdd($pdo, "attention", "Cool");


?>
