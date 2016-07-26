<?php
/*
** fonctions_DB.php for my_phpmyadmin in /Users/benoit-xavierhouvet/Desktop/ETNA/my_phpmyadmin/houvet_b/modele
**
** Made by HOUVET Benoît - Xavier
** Login   <houvet_b@etna-alternance.net>
**
** Started on  Wed Dec 23 00:44:37 2015 HOUVET Benoît - Xavier
// Last update Sat Dec 26 23:31:26 2015 HOUVET Benoît - Xavier
*/
error_reporting(-1);
ini_set('display_errors', 'On');
include_once("./connexion.php");

function	list_db($pdo)
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

function	create_db($pdo, $name, $encodage)
{
  $requete = "CREATE DATABASE `".$name."` CHARACTER SET ".$encodage." COLLATE utf8_bin";
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}

function        delete_db($pdo, $name, $encodage)
{
  $requete = "DROP DATABASE ".$name;
  $tmp = $pdo->prepare($requete)->execute();
  if ($tmp === FALSE)
    return FALSE;
  else
    return TRUE;
}



//delete_db($pdo, 'tutu', 'utf8');
//echo '<br>';
//print_r(list_db($pdo));
