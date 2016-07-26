<?php
// capture_images.php for ok in /home/antoine/Documents/PHP/ImagePanel/delapl_b
//
// Made by DELAPLACE Antoine
// Login   <delapl_b@etna-alternance.net>
//
// Started on  Fri Nov 13 15:20:03 2015 DELAPLACE Antoine
// Last update Sun Nov 15 15:30:12 2015 DELAPLACE Antoine
//

/*
Si le lien est correct, lance la capture des images
 */
function capture_images($lien, &$images)
{
  $is_accessible_link = false;
  if (file_exists($lien))
    {
      if (!is_dir($lien)
	  && is_readable($lien) && ($file = fopen($lien, 'r')) !== FALSE)
	$is_accessible_link = true;
    }
  else if (preg_match_all("/^http[s]{0,1}:\/\//", $lien)
	   && ($file = fopen($lien, 'r')) !== FALSE)
    $is_accessible_link = true;
  else
      echo "Lien $lien non traité : Impossible d'accéder au site\n";
  if ($is_accessible_link)
    open_link($file, $lien, $images);
}

/*
Recupere les liens vers les images de la page et lance la creation des images
 */
function open_link($file, $lien, &$images)
{
  $html = "";
  while ($read = fread($file, 100))
    $html .= $read;
  $pattern = '/<img[\s\w"\'=-]*src[\s]*=[\s]*[\'|"]([\w.:?&=\/_-]*)[\'|"]/';
  preg_match_all($pattern, $html, $src_img);
  $i = 0;
  while (isset($src_img[1][$i]))
    {
      $name_image = $src_img[1][$i];
      if (preg_match('/^http/', $lien))
	{
	  if (!preg_match_all('/^http/', $name_image))
	    $name_image = $lien . "/" . $src_img[1][$i];
	}
      else if (!preg_match('/^\//', $name_image))
	{
	  preg_match_all('/[\w.\/-]*\//', $lien, $chemin);
	  $name_image = $chemin[0][0] . $src_img[1][$i];
	}
      $images[] = $name_image;
      ++$i;
    }
  fclose($file);
}