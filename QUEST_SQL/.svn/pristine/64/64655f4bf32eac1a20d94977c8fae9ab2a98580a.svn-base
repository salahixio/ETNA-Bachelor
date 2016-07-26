SELECT film.TITRE, film.DATE_DEBUT_AFFICHE AS date_debut, film.DISTRIB_ID, distrib.NOM AS nom_distrib
FROM film, distrib
WHERE film.DISTRIB_ID = distrib.ID AND TITRE LIKE "%day%"
ORDER BY DATE_DEBUT_AFFICHE DESC;