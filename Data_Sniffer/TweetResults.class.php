<?php

class TweetResults
{

	private $url;
	private $search;
	private $geocode;

	public function __construct($search, $geocode = "")
	{
		$this->url = 'https://api.twitter.com/1.1/search/tweets.json?';
		$this->search = 'q='.$search;
		$this->geocode = '&geocode='.$geocode;
	}

	public function get_tweets_results($bearerToken)
	{
		$context = stream_context_create(array(
	      'http' => array(
	      'method'  => 'GET',
	      'header'  => "Authorization: Bearer " . $bearerToken . "\r\n",
	      ),
		));
		$encodedData = file_get_contents($this->url.$this->search.$this->geocode."&count=100", false, $context);
		return (json_decode($encodedData)); 
	}
}

?>