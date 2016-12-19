<?php

namespace PlanningBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use PlanningBundle\Entity\Planning;
use PlanningBundle\Entity\PlanningAgent;
use PlanningBundle\Entity\Agent;
use PlanningBundle\Entity\Domaine;
use PlanningBundle\Entity\FicheIntervention;
use UserBundle\Entity\User;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use FOS\UserBundle\Model;

class AgentController extends Controller
{
	public function getPlanningJourDescribe(Request $request){
	    $post = $request->request;
	    $date = $post->get('dateTime');
	    $date = new \Datetime($date);
	    $actualMonth = $this->tradMonth($date->format('F')) . " " . $date->format('Y');
	    $startActualWeek = $this->startDateWeek($date);
	    for ($i = 0; $i < 5; $i++){
		$day = $startActualWeek->format('l');
		$day = $this->tradDay($day);
		$trad = $day . ' ' . $startActualWeek->format('d');
		$days[$i] = $trad;
		$startActualWeek->modify('+1 day');
	    }
	    $date->modify('-5 day');
	    return[$actualMonth => $days];
	}

	public function init_planning()
	{
	    $planning = array();
	    $planning["8h"] = [[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]]];
	    $planning["9h"] = [[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]]];
	    $planning["10h"] = [[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]]];
	    $planning["11h"] = [[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]]];
	    $planning["14h"] = [[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]]];
	    $planning["15h"] = [[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]]];
	    $planning["16h"] = [[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]]];
	    $planning["17h"] = [[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]],[[0,0,0],[0,0,0],[0,0,0],[0,0,0],[0,0,0]]];
	    return $planning;
	}

	public function transform($planning, $args, $datebegin)
	{
		foreach($planning as $jour){
		    foreach($jour as $plann){
			$date = $plann["heureDebut"];
			$dateatraiter = $date->format('Y-m-d H:i');
			$date = explode(" ", $dateatraiter);
			$datejour = $date[0];
			$heureminutes = $date[1];
			$datejour = explode("-", $datejour);
			$annee = $datejour[0];
			$mois = (int)$datejour[1];
			$jour = (int)$datejour[2];
			$heureminutes = explode(':', $heureminutes);
			$heure = (int)$heureminutes[0];
			$minutes  = (int)$heureminutes[1];
			$jourbegin = (int)$datebegin->format('d');
			$jourchoisi = $jour - $jourbegin;
			if($minutes == 0)
		   	    $index = 0;
			elseif($minutes == 20)
			    $index = 1;
			else
			    $index = 2;
			$minutefin = $minutes + 15;
			if($minutes == 0)
			    $minutes = "00";
			$args[$heure.'h'][$index][$jourchoisi]['id'] = $plann['id'];
			$args[$heure.'h'][$index][$jourchoisi]['idDomaine'] = $plann['idDomaine']; 
			$args[$heure.'h'][$index][$jourchoisi]['heure'] = $heure.":".$minutes ."-".$heure.":".$minutefin;
		    }
	        }
            return $args;
	}

	public function tradMonth($en_month){
	    $month["January"] = "Janvier";
	    $month["February"] = "Fevrier";
	    $month["March"] = "Mars";
	    $month["April"] = "Avril";
	    $month["May"] = "Mai";
	    $month["June"] = "Juin";
	    $month["July"] = "Juiller";
	    $month["Auguste"] = "Aout";
	    $month["September"] = "Septembre";
	    $month["October"] = "Octobre";
	    $month["November"] = "Novembre";
	    $month["December"] = "Decembre";
	    return $month[$en_month];
	}

	public function tradDay($en_day){
	    $month["Monday"] = "Lundi";
	    $month["Tuesday"] = "Mardi";
	    $month["Wednesday"] = "Mercredi";
	    $month["Thursday"] = "Jeudi";
	    $month["Friday"] = "Vendredi";
	    return $month[$en_day];
	}

	public function startDateWeek($date){
	    $actualDay = $date->format('N');
	    $diffDay = $actualDay - 1;
	    $modif = '-'.$diffDay.' day';
	    $date->modify($modif);
	    $actualHeure = $date->format('G');
	    $modif = '-'.$actualHeure.' hour';
	    $date->modify($modif);
	    $actualMin = $date->format('i');
	    $modif = '-'.$actualMin.' minute';
	    $date->modify($modif);
	    $actualSec = $date->format('s');
	    $modif = '-'.$actualSec.' second';
	    $date->modify($modif);
	    return $date;
	}

	/**
	 * open view to display user's reservations
	 * @return \Symfony\Component\HttpFoundation\Response
	 */
	public function openPlanningAction($Date)
	{
		$isuser = false;
		$actualDate = ($Date != "") ? new \Datetime($Date) : new \Datetime();
		$actualMonth = $this->tradMonth($actualDate->format('F')) . " " . $actualDate->format('Y');
		$startActualWeek = $this->startDateWeek($actualDate);
		$date = $startActualWeek;
		for ($i = 0; $i < 5; $i++) {
			$day = $startActualWeek->format('l');
			$day = $this->tradDay($day);
			$trad = $day . ' ' . $startActualWeek->format('d');
			$anneemonth = $date->format('Y-m');
			$index = $anneemonth . '-' . $startActualWeek->format('d');
			$days[$index] = $trad;
			$startActualWeek->modify('+1 day');
		}
		foreach ($this->getUser()->getRoles() as $role) {
			if ($role == 'ROLE_USER') {
				$isuser = true;
				continue;
			}
		}
		$date->modify('-5 day');
		$date_before = clone $date;
		$date_after = clone $date;
		$date_before->modify('-7 day');
		$date_after->modify('+7 day');
		$args = $this->init_planning();
		$repository = $this->getDoctrine()->getManager()->getRepository("PlanningBundle:Planning");
		$planning = $repository->getPlanningAgentWeek($this->getUser()->getId(), $date);
		$date->modify('-5 day');
		if ($planning != NULL)
			$args = $this->transform($planning, $args, $date);
		return $this->render('PlanningBundle:Reservation:reservation.html.twig', array(
				'days' => $days,
				'reservations' => $args,
				'actualmonth' => $actualMonth,
				'afterDate' => $date_after->format('Y-m-d H:i:s'),
				'beforeDate' => $date_before->format('Y-m-d H:i:s'),
				'isuser' => $isuser
			)
		);
	}


	/**
	 * open view to manage agents
	 * @return \Symfony\Component\HttpFoundation\Response
	 */
	public function gestionAgentAction()
	{
		//TODO
		//Récupérer liste des agents
		$repository = $this->getDoctrine()->getManager()->getRepository('UserBundle:User');		
		$users = $repository->findAll();
		    foreach ($users as $agent){
			foreach ($agent->getRoles() as $role){
			    if ($role == 'ROLE_AGENT'){
			    	$agents[$agent->getId()] = $agent->getNom() . " " . $agent->getPrenom();
			    }
			}
		    }
		if (empty($agents))
			$agents[0] = "Aucun agent enregistre";
		$repo_domaine = $this->getDoctrine()->getManager()->getRepository('PlanningBundle:Domaine');
		$domaines = array();
		$domaineAll = $repo_domaine->findAll();
		foreach ($domaineAll as $domaine){
			$domaines[$domaine->getId()] = $domaine->getNomDomaine();
		}

		return $this->render('PlanningBundle:Agent:gestion_agent.html.twig',array(
				'agents' => $agents,
				'domaines' => $domaines
			)
		);
	}

	/**
	 * @param Request $request
	 * @return \Symfony\Component\HttpFoundation\RedirectResponse
	 */
	public function saveInfosAgentAction(Request $request)
	{
		try {
			$post = $request->request;
			$agent = $post->get('agent');
			$em = $this->getDoctrine()->getManager();
			$repository = $em->getRepository('PlanningBundle:PlanningAgent');

			if (!empty($post->get('domaines'))) {
				foreach ($post->get('domaines') as $domaine) {
					$isDomaineAdd = $repository->findOneBy(array('idDomaine' => $domaine, 'idAgent' => $agent));
					var_dump($isDomaineAdd);
					if (empty($isDomaineAdd)) {
						$planningAgent = new PlanningAgent();
						$planningAgent->setIdAgent($agent);
						$planningAgent->setIdDomaine($domaine);
						$em->persist($planningAgent);
						$em->flush();
					}
				}
			}
			return $this->redirectToRoute('im_front_gestion_agent');
		}
		catch (\Exception $e){
			return $this->redirectToRoute('im_front_gestion_agent');
		}
	}
}
