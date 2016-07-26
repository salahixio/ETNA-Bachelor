<?php
// check_arguments.php for ok in /home/antoine/Documents/PHP/ImagePanel/delapl_b
//
// Made by DELAPLACE Antoine
// Login   <delapl_b@etna-alternance.net>
//
// Started on  Fri Nov 13 10:05:43 2015 DELAPLACE Antoine
// Last update Sun Nov 15 12:26:47 2015 DELAPLACE Antoine
//

/*
Vérifie les arguments du script
 */
function check_arguments($argc, $argv)
{
  $options = array();
  $i = 1;
  while (isset($argv[$i]) && $argv[$i][0] == "-")
    {
      if (!check_options($argv[$i], $options))
	  return (false);
      else if (has_limit_option($argv[$i]) && !check_option_limit($argv[++$i], $options))
	  return (false);
      ++$i;
    }
  if (!isset($argv[$i]) || !isset($argv[$i + 1]))
    {
      echo "Il vous manque des arguments\n";
      return (false);
    }
  else if (preg_match_all("/^http[s]{0,1}:\/\//", $argv[$argc - 1]))
    {
      echo "La base n'est pas valide\n";
      return (false);
    }
  while (isset($argv[$i]) && $i < ($argc - 1))
      $options["liens"][] = $argv[$i++];
  $options["base"] = $argv[$i];
  return ($options);
}

/*
Vérifie l'ensemble des options d'un argument
 */
function check_options($argv, &$options)
{
  if (!preg_match_all("/^[-][gjlnNps]+$/", $argv))
    {
      echo "Les options sont invalides(g,j,l,n,N,p,s)\n";
      return (false);
    }
  else
    {
      $i = 1;
      $is_ok = true;
      while (isset($argv[$i]) && $is_ok)
	{
	  $is_ok = add_options($argv[$i], $options);
	  ++$i;
	}
      return ($is_ok);
    }
}

/*
Ajoute les options au tableau
 */
function add_options($argv, &$options)
{
  if ($argv == "s")
    $options["sort"] = 1;
  if ($argv == "n" || $argv == "N")
    {
      if (isset($options["name"]) && $options["name"] != $argv)
	{
	  echo "Vous avez entrez l'option n et N\n";
	  return (false);
	}
      else
	$options["name"] = $argv;
    }
  if ($argv == "j" || $argv == "g" || $argv == "p")
    {
      if (isset($options["format"]) && $options["format"] != $argv)
	{
	  echo "Vous avez entrez plusieurs options de format\n";
	  return (false);
	}
      else
	$options["format"] = $argv;
    }
  return (true);
}

/*
Vérifie si l'option limit est présente
 */
function has_limit_option($argv)
{
  return (preg_match_all("/^[-][a-zA-Z]*l[a-zA-Z]*$/", $argv));
}

/*
Vérifie si la limite a bien été entrée
 */
function check_option_limit($limit, &$options)
{
  if (!preg_match_all("/[0-9]+/", $limit))
    {
      echo "Vous n'avez pas précisé de limite avec l'option l\n";
      return (false);
    }
  else
    {
      $options["limit"] = $limit;
      return (true);
    }
}