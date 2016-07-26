<!DOCTYPE HTML>
<html>
  <head>
    <title>Test Twitter</title>
        <meta charset="utf-8" />    
    <meta name="language" content="Fr" />
  </head>
  <body>
<?php
require_once("Oauth2.class.php");
require_once("TweetResults.class.php");

$consumerKey = "9BzpcmkFx8qTMUk4sQIRgNrs2";
$consumerSecret = "hAcvuMr84j9e9DXNFfK2Fm2dIcwClFsLUzJGt0GiJk7kPYxKgc";

$Oauth2 = new Oauth2($consumerKey, $consumerSecret);
$TweetResults = new TweetResults($_POST["recherche"], $_POST["geoloc"]);
$results = $TweetResults->get_tweets_results($Oauth2->getBearerToken());
foreach($results->statuses as $result)
{
  echo "<p>";
  echo "<img src='".$result->user->profile_image_url."' />";
	echo "<span>".$result->text." </span><br />";
  echo "<span>Coordonnées : ".$result->geo->coordinates[0].";".$result->geo->coordinates[1]."</span>";
  echo "</p>";
}
?>
  </body>
</html>

