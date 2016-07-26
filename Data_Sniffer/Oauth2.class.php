<?php

class Oauth2
{
	private $consumerKey;
	private $consumerKeySecret;
	private $bearerToken;

	public function __construct($consumerKey, $consumerKeySecret)
	{
		$this->consumerKey = $consumerKey;
		$this->consumerKeySecret = $consumerKeySecret;
		$this->bearerToken = $this->retrieve_bearerToken();
	}

	private function retrieve_bearerToken()
	{
		$authContext = stream_context_create(array(
      		'http' => array(
        	'method'  => 'POST',
        	'header'  => "Authorization: Basic " . base64_encode(($this->consumerKey).':'.($this->consumerKeySecret)) . "\r\n".
          	"Content-type: application/x-www-form-urlencoded;charset=UTF-8\r\n",
	        'content' => "grant_type=client_credentials"
        	),
    	));
		$authResponse = file_get_contents("https://api.twitter.com/oauth2/token", false, $authContext);
		$decodedAuth = json_decode($authResponse, true);    
		return ($decodedAuth["access_token"]);
	}

	public function getBearerToken()
	{
		return ($this->bearerToken);
	}
}

?>