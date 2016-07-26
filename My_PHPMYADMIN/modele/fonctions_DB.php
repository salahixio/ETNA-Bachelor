<?php
/*
** fonctions_DB.php for my_phpmyadmin in /Users/benoit-xavierhouvet/Desktop/ETNA/my_phpmyadmin/houvet_b/modele
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 23 00:44:37 2015 HOUVET Benoît - Xavier
// Last update Wed Jan  6 16:31:47 2016 HOUVET Benoît - Xavier
*/

error_reporting(-1);
ini_set('display_errors', 'On');
date_default_timezone_set('UTC');

//include_once("./connexion.php");

function list_db($pdo)
{
  $list = $pdo->query('SHOW DATABASES');
  $i = 0;
  while( ( $db = $list->fetchColumn( 0 ) ) !== false )
    {
      $tab[$i] = $db;
      $i++;
    }
  if ($tab != NULL)
    return $tab;
  else
    return NULL;
}

function create_db($pdo, $name, $encodage)
{
  $requete = "CREATE DATABASE `".$name."` CHARACTER SET `".$encodage."` COLLATE utf8_bin";
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function delete_db($pdo, $name)
{
  $requete = "DROP DATABASE IF EXISTS `".$name."`";
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function liste_table($pdo, $name)
{
  $list = $pdo->query("SHOW TABLES FROM `".$name."`");
  $i = 0;
  while( ( $table = $list->fetchColumn( 0 ) ) !== false )
    {
      $tab[$i] = $table;
      $i++;
    }
  if ($tab != NULL)
    return $tab;
  else
    return NULL;
}
// $tab[$j][3] doit contenir une str du type "PRIMARY KEY NOT NULL DEFAULT(toto)" ou null
function create_table($pdo, $name, $tab)
{
  $i = 1;
  $j = 0;
  $requete = "CREATE TABLE `".$name."`(";
  while ($j < $i)
  {
	$requete = $requete.$tab[$j][0]." ".$tab[$j][1];
	if (isset($tab[$j][2]))
	  $requete = $requete." ".$tab[$j][2];
	if ($j < $i - 1)
	  $requete = $requete.",";
	$j++;
  }
  $requete = $requete.")";
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function rename_table($pdo, $old_name, $new_name)
{
  $requete = "RENAME TABLE `".$old_name."` TO `".$new_name."`";
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function add_element($pdo, $table, $colomn, $type, $taille)
{
  if (!(empty($taille)))
    $requete = "ALTER TABLE `".$table."` ADD `".$colomn."` ".$type."(".$taille.")";
  else
    $requete = "ALTER TABLE `".$table."` ADD `".$colomn."` ".$type;
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function delete_element($pdo, $table, $colomn)
{
  $requete = "ALTER TABLE `".$table."` DROP `".$colomn."`";
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function edit_element($pdo, $table, $old_name, $new_name, $type, $taille)
{
  if (!(empty($taille)))
    $requete = "ALTER TABLE `".$table."` CHANGE `".$old_name."` `".$new_name."` ".$type."(".$taille.")";
  else
    $requete = "ALTER TABLE `".$table."` CHANGE `".$old_name."` `".$new_name."` ".$type;
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function stat_table($pdo, $table)
{
  $requete = "SELECT COUNT(*) FROM `".$table."`";
  $tmp = $pdo->query($requete);
  if ($tmp === FALSE)
    return FALSE;
  else
    {
      $tmp2 = $tmp->fetchAll(PDO::FETCH_ASSOC);
      return ($tmp2[0]["COUNT(*)"]);
    }
}

function list_content($pdo, $table)
{
  $tmp = $pdo->query("SELECT * FROM `".$table."`");
  $tab = $tmp->fetchAll(PDO::FETCH_ASSOC);
  if ($tab != NULL)
    return $tab;
  else
    return NULL;
}


function select_db($pdo, $name_db)
{
  $requete = "USE `".$name_db."`";
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

// $value est une str comprenant toutes les valeurs séparé par des virgules

function add_line($pdo, $name_column, $value)
{
  $requete = "INSERT INTO `".$name_column."` VALUES (".$value.")";
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function delete_table($pdo, $name_table)
{
  $requete = "DROP TABLE `".$name_table."`";
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function edit_line($pdo, $value, $name_table)
{
  $requete = "UPDATE `".$name_table."` SET `".$value."`";
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function delete_line($pdo, $value, $name_table)
{
  $requete = "DELETE FROM `".$name_table."` WHERE ".$value;
  return $requete;
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function list_cols($pdo, $name_table, $name_db)
{
  $list = $pdo->query("SHOW COLUMNS FROM `".$name_db."`.`".$name_table."`");
  $tab = $list->fetchAll(PDO::FETCH_ASSOC);
  if ($tab != NULL)
    return $tab;
  else
    return NULL;
}

function	stats_db($pdo, $name_db)
{
  $list = $pdo->query("SHOW TABLES FROM `".$name_db."`");
  $i = 0;
  while( ( $table = $list->fetchColumn( 0 ) ) !== false )
    $i++;
  if ($i == 0)
    return NULL;
  else
    {
      $tab[0] = $i;
      $requete = "SELECT table_schema, round(sum(data_length+index_length)/1024/1024,4) AS \"Size (MB)\"
    FROM information_schema.Tables
    GROUP BY table_schema";
      $taille = $pdo->query($requete);
      $all = $taille->fetchAll();
      $j = 0;
      while (isset($all[$j]))
	{
	  if ($all[$j][0] == $name_db)
	    $tab[1] = $all[$j][1];
	  $j++;
	}
      $requete = "SHOW TABLE STATUS FROM `".$name_db."`";
      $tmp = $pdo->query($requete);
      $toto = $tmp->fetchAll();
      if (isset($toto[1]))
	{
	  $date = new DateTime($toto[0]["Create_time"]);
	  $j = 1;
	  while (isset($toto[$j]))
	    {
	      $datetmp = new DateTime($toto[$j]["Create_time"]);
	      if ($date >= $datetmp)
		$date = $datetmp;
	      $j++;
	    }
	}
      else
	{
	  if (isset($toto[0]))
	    $date = new DateTime($toto[0]["Create_time"]);
	}
      $tab[2] = $date->format('d/m/Y');
      return $tab;
    }
}

function        as_primary_key($pdo, $name_table)
{
  $requete = "DESC `".$name_table."`";
  $tmp = $pdo->query($requete);
  $tmp2 = $tmp->fetchAll();
  $i = 0;
  while ((isset($tmp2[$i])) && (!isset($result)))
    {
      if ($tmp2[$i]["Key"] == "PRI")
	$result = $tmp2[$i]["Field"];
      $i++;
    }
  if (!isset($result))
    return NULL;
  else
    return $result;
}

function	request_single($pdo, $requete)
{
  $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES,false);
  $tmp = $pdo->prepare($requete);
  if ($tmp === FALSE)
    {
      $tmp2=$pdo->errorInfo();
      return $tmp2[2];
    }
  else
    {
      $tmp3 = $pdo->query($requete);
      $tmp4 = $tmp3->fetchAll();
      if ($tmp4 == FALSE)
	return TRUE;
      else
	return $tmp4;
    }
}
