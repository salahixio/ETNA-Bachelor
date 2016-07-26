<!DOCTYPE html>
<html>
    <head>
		<meta charset="utf-8">
    	<meta http-equiv="X-UA-Compatible" content="IE=edge">
    	<meta name="viewport" content="width=device-width, initial-scale=1">
        <title>My_PhpMyAdmin</title>
        <link href="/houvet_b/vue/bootstrap/dist/css/bootstrap.min.css" rel="stylesheet">	
        <link href="/houvet_b/vue/css/index.css" rel="stylesheet">
    </head>
    <body>
		<!-- Modal -->
		<div class="modal fade" id="db-modal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
		  <div class="modal-dialog" role="document">
		    <div class="modal-content">
		      <div class="modal-header">
		        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
		        <h4 class="modal-title" id="myModalLabel"></h4>
		      </div>
		      <div class="modal-body">
		        <p>Voulez-vous vraiment supprimer la base de données ?</p>
		      </div>
		      <div class="modal-footer">
		        <button type="button" class="btn btn-danger" data-dismiss="modal" onClick="delete_db();">Supprimer</button>
		        <button type="button" class="btn btn-default" data-dismiss="modal">Annuler</button>
		      </div>
		    </div>
		  </div>
		</div>
		<div id="nav">
		<div>
		<form method="post" action="../index.php">
		<input type="text" name="destroy" value="true" hidden/>
		<input type="submit" class="btn btn-danger" value="Déconnexion" />
		</form>
		</div>
			<h5>Bases de données</h5>
	    	<div class="scrollable">
	    		<div id="ajout-db">
			       	<input type="text" class="form-control" id="new-db" value="">
			       	<button id="add-db" class="btn btn-success btn-xs" onClick="add_db();">Ajouter</button>
			    </div>
		      	<ul id="navbar">
				<?php
				foreach($dbs as $db)
				{
				?>
					<li id=""><a href="#" onclick="set_active(this);"><?php echo $db; ?></a></li>
				<?php
				}
				?>
		       	</ul>
			</div>
		</div>
    	<div id="tables">
    		<div id="infos-base">
    		</div>
			<div id ="list-tables" class="scrollable">
		   	</div>
		</div>
		<div id="free request">
		</div>
    	<footer>
			<!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    		<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
    		<!-- Include all compiled plugins (below), or include individual files as needed -->
    		<script src="/houvet_b/vue/bootstrap/dist/js/bootstrap.min.js"></script>
    		<script src="https://code.jquery.com/jquery-1.10.2.js"></script>
    		<script src="/houvet_b/vue/js/db_actions.js"></script>
    		<script src="/houvet_b/vue/js/table_actions.js"></script>
    		<script src="/houvet_b/vue/js/line_actions.js"></script>
    		<script src="/houvet_b/vue/js/column_actions.js"></script>
    		<script src="/houvet_b/vue/bootstrap/js/modal.js"></script>
		</footer>
	</body>
</html>