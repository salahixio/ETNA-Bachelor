<?php

namespace DS\ReportBundle\DatabaseHandler;
Use MongoClient;
Use MongoCollection;
Use MongoRegex;

//require_once '../../../../autoload.php';

class DSDatabaseHandler
{
    public function add_tweets_on_db($results, $langue, $analysis)
    {    
	 $con = new MongoClient();
       	 $data = $con->selectDB('t_tweet');
	 $collection = new MongoCollection($data, 't_tweet');
	 $collection->drop();
	 $results = json_decode($results);
	 foreach($results->statuses as $result)
         {
    	     if ($langue == "en")
    	     {
	         require_once __DIR__.'/../../../../autoload.php';
	         $sentiment = new \PHPInsight\Sentiment();
	 	 $npn = $sentiment->categorise($result->text);
	 	 $tweet = array('picture' => $result->user->profile_image_url, 'id' => $result->id, 'screen_name' => $result->user->screen_name, 'name' => $result->user->name, 'tweet' => $result->text, 'date' => $result->created_at, 'langue' => $result->lang, 'GPS' => $result->coordinates, 'nbr_follower' => $result->user->followers_count, 'nbr_retweet' => $result->retweet_count, 'sentiment' => $npn);
             }
    	     else 
    	     {
	         $tweet = array('picture' => $result->user->profile_image_url, 'id' => $result->id, 'screen_name' => $result->user->screen_name, 'name' => $result->user->name, 'tweet' => $result->text, 'date' => $result->created_at, 'langue' => $result->lang, 'GPS' => $result->coordinates, 'nbr_follower' => $result->user->followers_count, 'nbr_retweet' => $result->retweet_count, 'sentiment' => 'negatifpositifneutral');
	     }
    	     $collection->insert($tweet);
	}
	$con->close();
    }

    public function prepare_new_request($keyword)
    {
        $con = new MongoClient();
	$db = $con->selectDB('t_tweet');
	$collection = new MongoCollection($db, 't_request');
	$collection->drop();
	$request = array('keyword' => $keyword);
	$collection->insert($request);
	$con->close();
    }

    public function retrieve_tweets_from_db()
    {
	$i = 0;
	$con = new MongoClient();
	$data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 't_tweet');
	$cursor = $collection->find();
	foreach ($cursor as $doc){
		$tab[$i] = $doc;
		$i = $i + 1;
	}
	if ($i > 0)
	{
	    return ($tab);
	}
	else
	{
	    return (null);
	}
	$con->close();
    }
    public function retrieve_tweets_from_db_index($index)
    {
	$i = 0;
	$test_index = 0;
	$con = new MongoClient();
	$data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 't_tweet');
	$cursor = $collection->find();
	foreach ($cursor as $doc){
	    if ($test_index >= $index)
	    {
		$tab[$i] = $doc;
		$i = $i + 1;
	    }
		$test_index = $test_index + 1;
	}
		return ($tab);
		$con->close();
    }

    public function retrieve_tweets_from_db_with_name($screenName)
    {
	$i = 0;
	$tab = array();
	$con = new MongoClient();
	$data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 't_tweet');
	$tmp = array("screen_name" => new MongoRegex("/$screenName/i"));
	$cursor = $collection->find($tmp);
	foreach ($cursor as $doc){		
		$tab[$i] = $doc;
		$i = $i + 1;
	}
	$con->close();
	if ($i > 0)
	{
	    return ($tab);
	}
	else
	{
	    return (array());
	}
    }

    public function retrieve_tweets_from_db_pos()
    {
	$i = 0;
	$str = array( 'nbr_retweet' => -1 );
	$con = new MongoClient();
	$data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 't_tweet');
	$tmp = array("sentiment" => new MongoRegex("/pos/i"));
	$cursor = $collection->find($tmp)->sort($str);
	foreach ($cursor as $doc){
		$tab[$i] = $doc;
		$i = $i + 1;
	}
	$con->close();
	if ($i > 0)
	{
	    return ($tab);
	}
	else
	{
	    return (null);
	}
    }
	
    public function retrieve_tweets_from_db_neut()
    {
	$i = 0;
	$str = array( 'nbr_retweet' => -1 );
	$con = new MongoClient();
	$data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 't_tweet');
	$tmp = array("sentiment" => new MongoRegex("/neu/i"));
	$cursor = $collection->find($tmp)->sort($str);
	foreach ($cursor as $doc){
		$tab[$i] = $doc;
		$i = $i + 1;
	}
	$con->close();
	if ($i > 0)
	{
	    return ($tab);
	}
	else
	{
	    return (null);
	}
    }
	
    public function retrieve_tweets_from_db_neg()
    {
	$i = 0;
	$str = array( 'nbr_retweet' => -1 );
	$con = new MongoClient();
	$data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 't_tweet');
	$tmp = array("sentiment" => new MongoRegex("/neg/i"));
	$cursor = $collection->find($tmp)->sort($str);
	foreach ($cursor as $doc){
		$tab[$i] = $doc;
		$i = $i + 1;
	}
	$con->close();
	if ($i > 0)
	{
	    return ($tab);
	}
	else
	{
	    return (null);
	}
    }

    public function get_pos_score()
    {
        $i = 0;
        $con = new MongoClient();
	$data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 't_tweet');
	$tmp = array("sentiment" => new MongoRegex("/pos/i"));
	$cursor = $collection->find($tmp)->count();
	$total = $collection->count();
	$con->close();
	if ($total == 0)
	{
	    return(0);
	}
	else
	{
	    return (($cursor / $total) * 100);
	}
    }
    public function get_neg_score()
    {
        $i = 0;
        $con = new MongoClient();
	$data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 't_tweet');
	$tmp = array("sentiment" => new MongoRegex("/neg/i"));
	$cursor = $collection->find($tmp)->count();
	$total = $collection->count();
	$con->close();
        if ($total == 0)
        {
            return(0);
        }
        else
        {
            return (($cursor / $total) * 100);
	}
										
    }

    public function get_neut_score()
    {
        $i = 0;
        $con = new MongoClient();
	$data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 't_tweet');
	$tmp = array("sentiment" => new MongoRegex("/neu/i"));
	$cursor = $collection->find($tmp)->count();
	$total = $collection->count();
	$con->close();
        if ($total == 0)
        {
            return(0);
        }
        else
        {
            return (($cursor / $total) * 100);
	}
    }
    public function count_tweet()
    {
        $con = new MongoClient();
	$data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 't_tweet');
	$total = $collection->count();
	$con->close();
	return ($total);
    }

    public function add_histo_on_db($request, $nbr_pos, $nbr_neu, $nbr_neg, $date)
    {
    	$con = new MongoClient();
        $data = $con->selectDB('t_tweet');
	$collection = new MongoCollection($data, 'history');
	$histo = array('tag' => $request, 'nbr_pos' => $nbr_pos, 'nbr_neu' => $nbr_neu, 'nbr_neg' => $nbr_neg, 'date' => $date);
	$collection->insert($histo);
	$con->close();
    }
    public function get_histo($tag)
    {
        $con = new MongoClient();
	$i = 0;
	$data = $con->selectDB('t_tweet');
        $collection = new MongoCollection($data, 'history');
	$tmp = array('tag' => $tag);
	$cursor = $collection->find($tmp);
	$fichierjs = fopen(__DIR__.'/vis.js', 'w+');
	fseek($fichierjs, 0);
	$items = "var items = [\n";
	foreach ($cursor as $doc)
	{
	$tmp = split(" ", $doc['date']);
	$tmp1 = $tmp[0];
	$tmp2 = split("-", $tmp1);
	$toto = $tmp2[2]."-".$tmp2[1]."-".$tmp2[0]." ".$tmp[1];
	$doc['date'] = $toto;
	    $tab[$i] = $doc;
	    $items .= "{x : '".$doc["date"]."', y: '".$doc["nbr_neg"]."', group : 1},\n";
	    $items .= "{x : '".$doc["date"]."', y: '".$doc["nbr_pos"]."', group : 2},\n";
	    $items .= "{x : '".$doc["date"]."', y: '".$doc["nbr_neu"]."', group : 3},\n";
	    $i = $i + 1;
	}
	$items .= "];\n";
	fputs($fichierjs, $items);
	fclose($fichierjs);
	$con->close();
	if ($i > 0)
	{
	return ($tab);
	}
	else
	{
	return null;
	}
    }
}