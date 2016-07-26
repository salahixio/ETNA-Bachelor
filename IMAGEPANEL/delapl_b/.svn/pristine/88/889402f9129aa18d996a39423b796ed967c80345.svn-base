<?php
// create_images.php for ok in /home/antoine/Documents/PHP/ImagePanel/delapl_b
//
// Made by DELAPLACE Antoine
// Login   <delapl_b@etna-alternance.net>
//
// Started on  Fri Nov 13 20:47:46 2015 DELAPLACE Antoine
// Last update Mon Nov 23 14:39:59 2015 DELAPLACE Antoine
//

$create_images_number = 0;
$copied_images_number = 0;
$image_size = 200;
$meta_image_size = 1000;
$image_x = 0;
$image_y = 0;

/*
Gére la création de toute les images en fonction du format de celle-ci
 */
function create_images($images, $options)
{
  global $copied_images_number;
  global $image_y;
  global $image_x;
  global $image_size;
  global $meta_image_size;
  $i = 0;
  $image = 0;
  while (isset($images[$i]))
  {
    if ($image_y >= $meta_image_size)
      {
	save_new_image($image, $options);
	$image_x = 0;
	$image_y = 0;
      }
    if ($image_x == 0 && $image_y == 0)
      $image = imagecreatetruecolor(1000, 1000);
    $image_copy= copy_image($images[$i]);
    if ($image_copy !== FALSE)
      paste_image($image, $image_copy);
    ++$i;
  }
  save_new_image($image, $options);
  imagedestroy($image);
  echo "$copied_images_number image(s) trouvee(s).\n";
}

/*
Ajoute l'image dans la meta-image
 */
function paste_image($image, $image2)
{
  global $image_size;
  global $image_x;
  global $image_y;
  global $meta_image_size;
  $x = imagesx($image2);
  $y = imagesy($image2);
  if ($x > $y)
    $max = $x;
  else
    $max = $y;
  $rapport = $image_size / $max;
  $new_x = $x * $rapport;
  $new_y = $y * $rapport;
  imagecopyresampled($image, $image2, $image_x, $image_y, 0, 0, $new_x, $new_y, $x, $y);
  $image_x += $image_size;
  if ($image_x >= $meta_image_size)
    {
      $image_x = 0;
      $image_y += $image_size;
    }
}

/*
  Récupére l'image en utilisant la fonction correspondante
  Retourne l'image
 */
function copy_image($name_image)
{
  global $copied_images_number;
  $explode = explode(".", $name_image);
  $format = strtolower($explode[count($explode)-1]);
  if ($format == "jpg" || $format == "jpeg")
    $image2 = imagecreatefromjpeg($name_image);
  else if ($format == "gif")
    $image2 = imagecreatefromgif($name_image);
  else if ($format == "png")
    $image2 = imagecreatefrompng($name_image);
  else
    {
      echo "Le format de l'image $name_image n'est pas valide\n";
      return (false);
    }
  ++$copied_images_number;
  return ($image2);
}

/*
Save de la meta-image en fonction du format souhaité
 */
function save_new_image($image, $options)
{
  global $create_images_number;
  ++$create_images_number;
  if ($create_images_number > 1)
    $filename = $options["base"].$create_images_number.".jpg";
  else
    $filename = $options["base"].".jpg";
  imagejpeg($image, $filename);
}
