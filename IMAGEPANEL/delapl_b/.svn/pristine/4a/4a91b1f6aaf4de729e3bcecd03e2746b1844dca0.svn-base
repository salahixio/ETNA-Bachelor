<?php
// imagepanel.php for ok in /home/antoine/Documents/PHP/ImagePanel/delapl_b
//
// Made by DELAPLACE Antoine
// Login   <delapl_b@etna-alternance.net>
//
// Started on  Fri Nov 13 09:46:27 2015 DELAPLACE Antoine
// Last update Mon Nov 23 14:38:34 2015 DELAPLACE Antoine
//

require_once("check_arguments.php");
require_once("capture_images.php");
require_once("create_images.php");

$options = check_arguments($argc, $argv);
$images = array();
if ($options != false)
  {
    $i = 0;
    while (isset($options["liens"][$i]))
      {
	capture_images($options["liens"][$i], $images);
	++$i;
      }
    if (!empty($images))
      create_images($images, $options);
  }
