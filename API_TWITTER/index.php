<!DOCTYPE HTML>
<html>
	<head>
		<title>Test Twitter</title>
        <meta charset="utf-8" />		
		<meta name="language" content="Fr" />
	</head>
	<body>
		<div id="formulaire">
			<form action="tweets.php" method="post">
				<label>Recherche : </label><input type="text" name="recherche"><br />
				<label>Geolocalisation : </label><input type="text" name="geoloc" placeholder="longitutude,latitude,radius"><br />
				<input type="submit" name="submit"><br />
			</form>
		</div>
	</body>
</html>