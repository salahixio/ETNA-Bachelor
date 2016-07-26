SELECT genre.NOM AS `nom_genre`, MAX(DUREE_MIN) AS `duree_min`
FROM etna_tp.genre, etna_tp.film
WHERE genre.ID = film.GENRE_ID
GROUP BY genre.ID;