function cut_sentences()
{
	var texte, citation;
	citation = document.getElementById("fccitation");
	texte = citation.innerHTML;
	texte = texte.replace(/\. /g, ".\n");
	alert(texte);
}

function replace_ponctuation()
{
	var citation;
	citation = document.getElementById("fccitation");
	citation.innerHTML = citation.innerHTML.replace(/[\.,;?:!\-_\'\"’]/g, "");
}

function add_author()
{
	var citation;
	citation = document.getElementById("fccitation");
	citation.innerHTML = citation.innerHTML + " Tyler Durden";
}

function sort_words()
{
	var citation, words, results;
	citation = document.getElementById("fccitation");
	results = "";
	words = citation.innerHTML.split(" ");
	words.sort();
	for (var i = 0; i < words.length; i++) {
		if(words[i].search(/[\.,]$/) != -1)
			words[i] = words[i].substring(0, words[i].length - 1);
		results += words[i] + "<br />";
	}
	document.getElementById("results").innerHTML = results;
}

function search_word()
{
	var search, find, citation;
	search = document.getElementsByName("key")[0];
	citation = document.getElementById("fccitation");
	if (search.value != "")
	{
		find = citation.innerHTML.search(search.value);
		if (find == -1)
			alert("Le mot ne fait pas parti de la citation");
		else
			alert("Le mot fait parti de la citation");
	}
}