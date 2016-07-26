<?php
namespace DS\ReportBundle\Controller;

use Symfony\Component\HttpFoundation\Response;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use MongoClient;
use MongoCollection;
use Unirest;
//use DatumboxAPI;
//use Symfony\Component\HttpFoundation\Request;
//use Symfony\Component\BrowserKit\Request;
class TestController extends Controller
{
	public function indexAction()
	{
		$i = 0;
//		$tweetAnalyse = $this->container->get('ds_report.TweetAnalyse');
//		$tweets = $tweetAnalyse->get_tweets("mot");
		$con = new MongoClient();
		$data = $con->selectDB('t_tweet');
		$collection = new MongoCollection($data, 't_tweet');
		$cursor = $collection->find();
		foreach ($cursor as $doc){
		$tab[$i] = $doc;
		$i = $i + 1;
		}
		$toto = $tab[0]['tweet'];
//		$text = str_replace(" ", "+", $toto);
//                echo $text;
//		$toto2 = "https://loudelement-free-natural-language-processing-service.p.mashape.com/nlp-text/?text=".$text;
//		$response = Unirest\Request::get("https://loudelement-free-natural-language-processing-service.p.mashape.com/nlp-text/?text=".$text,
//		    array(
//                        "X-Mashape-Key" => "SQqRhqjY8qmsho6kSHkbBYbsuEjpp1PhQfLjsn3Ly1P5rdfYMZ",
//                        "Accept" => "application/json"
//                    )
//                );
                //print_r($response);
//		$data2 = json_decode($response);

//		$authContext = stream_context_create(array(
//                    'http' => array(
//                                             'method'  => "GET",
//					     'header' => "X-Mashape-Key : SQqRhqjY8qmsho6kSHkbBYbsuEjpp1PhQfLjsn3Ly1P5rdfYMZ",
//					     'Content-Type' => "application/json"
//                                )
//
//                ));
//		Unirest\Request::setMashapeKey('<mashape_key>');
//		                $authResponse = file_get_contents($toto2, false, $authContext);
//		                $decodedAuth = json_decode($authResponse, true);
		$toto2 = $this->findSentiment($toto);		
		return new Response(var_dump($toto2));
	}

	public function findSentiment($tweets) {
	          $tmp = $this->container->get('ds_report.Analysis');
	       	 // $DatumboxAPI = $tmp->DatumboxAPI("9beb9c6a95ef4a3c61cfc891bd0a477a"); //initialize the DatumboxAPI client
		  $sentiment=$tmp->TwitterSentimentAnalysis($tweets); //call Datumbox service to get the sentiment
                  if($sentiment!=false) //if the sentiment is not false, the API call was successful
		  			return ($sentiment);
	}
}