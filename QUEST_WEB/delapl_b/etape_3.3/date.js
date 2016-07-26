function return_date()
{
	var date = document.getElementsByName("date")[0].value;
	var tmp = date.split("-");
	var tmp2= tmp[2].split(" ");
	var tmp3 = tmp2[1].split(":");
	var tab_date = [tmp[0], tmp[1], tmp2[0], tmp3[0], tmp3[1], tmp3[2]];
	return (tab_date);
}

function calculate_age()
{
	var date, date_jour, age, date_age;
	date = return_date();
	date = new Date(date[0], date[1]-1, date[2], date[3], date[4], date[5]);
	date_jour = new Date();
	var ans = date_jour.getFullYear() - date.getFullYear();
	var mois = date_jour.getMonth() - date.getMonth();
	var jour = date_jour.getDay() - date.getDay();
	var heure = date_jour.getHours() - date.getHours();
	var minutes = date_jour.getMinutes() - date.getMinutes();
	var secondes = date_jour.getSeconds() - date.getSeconds();
	alert(ans+ "ans "+mois+"mois "+jour+"jours "+heure+"heures "+minutes+"minutes "+secondes+"secondes.");
}

function calculate_timestamp()
{
	var date, age;
	date = return_date();
	date = new Date(date[0], date[1]-1, date[2], date[3], date[4], date[5]);
	age = date.getTime();
	alert(age);
}

function calculate_minutes()
{
	var date, date_jour, time;
	date = return_date();
	date = new Date(date[0], date[1]-1, date[2], date[3], date[4], date[5]);
	date_jour = new Date();
	time = date_jour.getTime() - date.getTime();
	time = time / 1000 / 60
	alert(parseInt(time));
}

function calculate_jours()
{
	var date, date_jour, time;
	date = return_date();
	date_jour = new Date();
	if(date_jour.getMonth() == date[1]-1 && date_jour.getDay() < date[2])
		annee = date_jour.getFullYear() + 1;
	else
		annee = date_jour.getFullYear();
	date = new Date(annee, date[1]-1, date[2], date[3], date[4], date[5]);
	time = date.getTime() - date_jour.getTime();
	time = time / 1000 / 60 / 60 / 24;
	alert(parseInt(time));
}

function noel()
{
	var date_jour, annee, date, time;
	date_jour = new Date();
	if(date_jour.getMonth() == "12" && date_jour.getDay() > 25)
		annee = date_jour.getFullYear() + 1;
	else
		annee = date_jour.getFullYear();
	date = new Date(annee, "11", "25");
	console.log(date_jour);
	console.log(date);
	time = date.getTime() - date_jour.getTime();
	time = time / 1000 / 60 / 60 / 24;
	alert(parseInt(time));
}