/**
 * Created by benoit-xavierhouvet on 08/06/2016.
 */
var express     =   require("express");
var app         =   express();
var bodyParser  =   require("body-parser");
var mongoose    =   require("mongoose");
var passport 	= 	require('passport');
var LocalStrategy = require('passport-local').Strategy;
var cookieParser = require('cookie-parser');
var session = require('express-session');

//app.use(cookieParser());
//app.use(bodyParser());
//app.use(passport.initialize());
//app.use(passport.session());

//TODO : Utilisation le connect-mongo pour save le cookie 
app.use(bodyParser.json())
app.use(bodyParser.urlencoded({extended: true}))
app.use(cookieParser('keyboard cat'));
app.use(session({
	secret: 'keyboard cat',
	resave: false,
	saveUninitialized: true
}))

app.use(passport.initialize());
app.use(passport.session());

app.use(function(req, res, next) {
	res.header("Access-Control-Allow-Origin", "*");
	res.header("Access-Control-Allow-Headers", "Content-Type, X-Requested-With");
	res.header('Access-Control-Allow-Methods', 'GET,PUT,POST,DELETE');
	next();
});

mongoose.connect('mongodb://localhost:27017/mean');
var mongoSchema =   mongoose.Schema;

var commentaireSchema = new mongoSchema({
	"commentaireDate" :  { type: Date, default: Date.now },
	"commentaireContenu" : String,
	"commentaireAuteur" : String
});

var articleSchema  = new mongoSchema({
	"articleTitre" : String,
	"articleDate" :  { type: Date, default: Date.now },
	"articleContenu" : String,
	"articleAuteur" : String,
	"articleComment" : [ commentaireSchema ]
});

var userSchema = new mongoSchema({
    "username" : String,
    "password" : String,
    "email" : String,
    "role" : String
});

userSchema.methods.validPassword = function( pwd ) {
	return ( this.password === pwd );
};

var User = mongoose.model('User',userSchema);
var article = mongoose.model('article',articleSchema);
var commentaire = mongoose.model('commentaire',commentaireSchema);

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({"extended" : false}));



app.get("/article",function(req,res,next){
	var response = {};
	article.find().sort("-articleDate").exec(function(err,data){
		if(err) {
			response = {"error" : true,"message" : "Error fetching data"};
		} else {
			response = {"error" : false,"data" : data};
		}
		res.json(response);
	});
});

app.get("/article/:id", function(req, res,next){
	var response = {};
	article.findById(req.params.id,function(err,data){
		if(err) {
			response = {"error" : true,"message" : "Error fetching data"};
		} else {
			response = {"error" : false,"data" : data};
		}
		res.json(response);
	});
});

app.post("/article",function(req,res,next){
	var db = new article();
	var response = {};
	db.articleTitre = req.body.titre;
	db.articleContenu = req.body.contenu;
	db.articleAuteur = req.body.auteur;
	db.save(function(err){
		if(err) {
			response = {"error" : true,"message" : "Error adding data"};
		} else {
			response = {"error" : false,"message" : "Data added"};
		}
		res.json(response);
	});
});

app.post("/article/:id",function(req,res, next){
	var response = {};
	var articleEnCour = new article();
	article.findById(req.params.id,function(err,data){
		if(err) {
			response = {"error" : true,"message" : "Error fetching data"};
			res.json(response);
		} else {
			data.articleComment.push({commentaireAuteur: req.body.auteur,commentaireContenu: req.body.contenu});
			data.save(function(err){
				if(err) {
					response = {"error" : true,"message" : "Error update data"};
				} else {
					response = {"error" : false,"data" : data};
				}
				res.json(response);
			});
		}
	});
});

app.put("/article/:id", function(req, res,next){
	article.findById(req.params.id, function(err, data) {
		if (err)
			res.send(err);
		if(req.body.auteur)
			data.articleAuteur = req.body.auteur;
		if(req.body.titre)
			data.articleTitre = req.body.titre;
		if(req.body.date)
			data.articleDate = req.body.date;
		if(req.body.contenu)
			data.articleContenu = req.body.contenu;
		data.save(function(err) {
			if (err)
				res.send(err);
			res.json({ message: 'Data updated!' });
		});
	});
});

app.delete("/article/:id", function(req,res,next){
	article.remove({_id: req.params.id}, function(err, data) {
		if (err)
			res.send(err);
		res.json({ message: 'Data deleted' });
	});
});

app.put("/article/:id_article/commentaire/:id", function(req, res,next){
	article.findById(req.params.id_article, function(err, data){
		if (err)
			res.json(err);
		arr = data.articleComment;
		for (var i = 0, len = arr.length; i < len; i++) {
			if(arr[i]._id == req.params.id){
				if(req.body.auteur)
					arr[i].commentaireAuteur = req.body.auteur;
				if(req.body.date)
					arr[i].commentaireDate = req.body.date;
				if(req.body.contenu)
					arr[i].commentaireContenu = req.body.contenu;
				data.save(function(err) {
					if (err)
						res.json(err);
				});
			}
		}
		res.json(data);
	});
});

app.delete("/article/:id_article/commentaire/:id", function(req, res,next){
	article.findById(req.params.id_article, function(err, data){
		if (err)
			res.json(err);
		arr = data.articleComment;
		var tabtmp = [];
		for (var i = 0, len = arr.length; i < len; i++){
			if(arr[i]._id != req.params.id){
				tabtmp.push(arr[i]);
			}
		}
		data.articleComment = tabtmp;
		data.save(function(err) {
			if (err)
				res.json(err);
		});
		res.json(tabtmp);
	});
});

app.get("/user", function(req, res, next){
    var response = {};
    User.find().sort("username").exec(function(err,data){
        if(err) {
            response = {"error" : true,"message" : "Error fetching data"};
        } else {
            response = {"error" : false,"data" : data};
        }
        res.json(response);
    });
});

app.post("/user", function(req, res, next){
    var db = new User();
    var response = {};
    User.count().where('email').equals(req.body.email).exec(function(err, data){
	if(data == 0){
	    db.username = req.body.username;
	    db.email = req.body.email;
	    db.password = req.body.password;
	    db.role = req.body.role;
	    db.save(function(err){
		if(err) {
		    response = {"error" : true,"message" : "Error adding data"};
		} else {
		    response = {"error" : false,"message" : "Data added"};
		}
		res.json(response);
	    });
	}else{
	    res.json({"error" : true, "message" : "Email account already exist"});
	}
    });
});

app.put("/user/:id", function(req, res, next){
    User.findById(req.params.id, function(err, data) {
	if (err)
	    res.send(err);
	if(req.body.username)
	    data.username = req.body.username;
	if(req.body.email)
	    data.email = req.body.email;
	if(req.body.role)
	    data.role = req.body.role;
	if(req.body.password)
	    data.articleContenu = req.body.password;
	data.save(function(err) {
	    if (err)
		res.send(err);
	    res.json({ message: 'Data updated!' });
	});
    });
});

app.delete("/user/:id", function(req, res, next){
    User.remove({_id: req.params.id}, function(err, data) {
	if (err)
	    res.send(err);
	res.json({ message: 'Data deleted' });
    });
});

// Partie de BX

passport.serializeUser(function(user, done) {
	done(null, user);
});

passport.deserializeUser(function(user, done) {
	done(null, user);
});

passport.use('log', new LocalStrategy({
		usernameField: 'email'
	},
	function(username, password, done) {
		User.findOne({ email: username }, function (err, user) {
			if (err) { return done(err); }
			if (!user) {
				return done(null, { message: 'Incorrect username.' });
			}
			if (!user.validPassword(password)) {
				return done(null, { message: 'Incorrect password.' });
			}
			return done(null, user);
		});
	}
));

app.post('/login',
	passport.authenticate('log'),
	function(req, res) {
		res.json(req.user);
	});

app.get('/logout', function(req, res, next){
	req.logout();
	res.json({message : 'deconnecté'});
});

app.get('/isconnected', function(req, res, next){
	var sess = req.session
	if (sess.views) {
		res.json({views : sess.views});
	}
	else {
		res.json({message : 'Non'});
	}
});

app.listen(3000);
