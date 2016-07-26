SELECT 
(SELECT COUNT(ID) FROM abonnement WHERE ID != 0) AS `nombre_abonnement`,
(SELECT CEIL(AVG(PRIX)) FROM abonnement WHERE ID != 0) AS `moyenne_abonnement`,
(SELECT COUNT(ABO_ID) FROM membre WHERE ID != 0) AS `nombre_abonnees`;