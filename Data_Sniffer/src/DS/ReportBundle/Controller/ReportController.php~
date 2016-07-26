<?php
namespace DS\ReportBundle\Controller;

use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Symfony\Component\HttpFoundation\Request;

class ReportController extends Controller
{
    public function FormAction()
    {
        if ((isset($_GET['key'])) && ($_GET['key'] != ""))
       	{
		$keyW = urlencode($_GET['key']);
		$tweets = $this->GetTweetsAction($keyW, $_GET['lang'], $_GET['lat'],$_GET['lng'], $_GET['radius']);
		$this->PrepareNewRequestAction($keyW);
		$this->AddTweetsAction($tweets, $_GET['lang']);
		$database_handler = $this->container->get('ds_report.DatabaseHandler');
		$tweetAnalyse = $this->container->get('ds_report.TweetAnalyse');
		//$tweetAnalyse->start_streaming_api();
		$histo = $database_handler->get_histo($this->getApiUrl($_GET['key'], $_GET['lang'], $_GET['lat'],$_GET['lng'], $_GET['radius']));
		$database_handler->add_histo_on_db($this->getApiUrl($_GET['key'], $_GET['lang'], $_GET['lat'],$_GET['lng'], $_GET['radius']), $this->getScore()['pos'], $this->getScore()['neut'], $this->getScore()['neg'], date("d-m-Y H:i"));
		if ((isset($_GET['screen_name'])) && ($_GET['screen_name'] != ""))
		{
                    $content = $this->get('templating')->render('DSReportBundle:Report:form.html.twig', array('tweets' => $this->RetrieveTweetsByNameAction($_GET['screen_name']), 'nom' => urldecode($keyW), 'screen' => $_GET['screen_name'], 'score' => $this->getScore(), 'count' => $this->container->get('ds_report.DatabaseHandler')->count_tweet(), 'arr' => $this->tweetArray(), 'histo' => $histo, 'addr' => $_GET['addr']));
		}
		 else
		 {
		     $content = $this->get('templating')->render('DSReportBundle:Report:form.html.twig', array('tweets' => $this->RetrieveTweetsAction(), 'nom' => urldecode($keyW), 'screen' => $_GET['screen_name'], 'score' => $this->getScore(), 'count' => $this->container->get('ds_report.DatabaseHandler')->count_tweet(), 'arr' => $this->tweetArray(), 'histo' => $histo, 'addr' => $_GET['addr']));
		 }
	}
	else
	{
		$content = $this->get('templating')->render('DSReportBundle:Report:form.html.twig', array('score'=> $this->getScore()));
	}
	return new Response($content);
    }
    
    public function GetTweetsAction($key, $lang, $lat, $lng, $rad)
    {
        $tweetAnalyse = $this->container->get('ds_report.TweetAnalyse');
	return ($tweetAnalyse->get_tweets($key, $lang, $lat, $lng, $rad));
    }

    public function AddTweetsAction($tweets, $lang)
    {
	$database_handler = $this->container->get('ds_report.DatabaseHandler');
	$analysis = $this->container->get('ds_report.Analysis');
	$database_handler->add_tweets_on_db($tweets, $lang, $analysis);
    }

    public function RetrieveTweetsAction()
    {
	$database_handler = $this->container->get('ds_report.DatabaseHandler');
	return ($database_handler->retrieve_tweets_from_db());
    }

    public function RetrieveTweetsByNameAction($name)
    {
	$database_handler = $this->container->get('ds_report.DatabaseHandler');
	return ($database_handler->retrieve_tweets_from_db_with_name($name));
    }

    public function PrepareNewRequestAction($keyword)
    {
	$database_handler = $this->container->get('ds_report.DatabaseHandler');
	$database_handler->prepare_new_request($keyword);
    }

    public function tweetArray()
        {
	    $database_handler = $this->container->get('ds_report.DatabaseHandler');
	    $tab = array('pos' => $database_handler->retrieve_tweets_from_db_pos(),
	    	     'neut' => $database_handler->retrieve_tweets_from_db_neut(),
                     'neg' => $database_handler->retrieve_tweets_from_db_neg());
	    return ($tab);
	}

    public function getScore()
        {
	    $database_handler = $this->container->get('ds_report.DatabaseHandler');
	    $tab = array('pos' =>  $database_handler->get_pos_score(),
	    	    'neut' =>  $database_handler->get_neut_score(),
		    'neg' =>  $database_handler->get_neg_score());

	    return ($tab);
        }

    public function getApiUrl($keyW, $lang, $lat, $lng, $rad)
    {
         $str = "https://api.twitter.com/1.1/search/tweets.json?q=".$keyW."&count=100&result_type=mixed";
         if ( $lang != "")
	 {
	      $str = $str."&lang=".$lang;
	 }
	 if ($lat != "" && $lng != "" && $rad != "")
	 {
	     $str = $str."&geocode=".$lat.",".$lng.",".$rad."km";
	 }
	 return ($str);
    }
	   
    public function tweet_addAction($count)
	{
	    $database = $this->container->get('ds_report.DatabaseHandler');
	    $count_actu = $database->count_tweet();
	    if ($count_actu > $count)
	    {
		$tab = $database->retrieve_tweets_from_db_index($count);
		$str = ('Tweet entre le tweet' . $count . " et le tweet " . $count_actu);
		$response = new JsonResponse();
		return $response->setData(array('text' => $str, 'tweet' => $tab, 'index' => $count_actu));	
	    }
	    else
	    {
	        $response = new JsonResponse();
		return $response->setData(array('text' => 'fail', 'index' => $count));
	    }
   	}
}
