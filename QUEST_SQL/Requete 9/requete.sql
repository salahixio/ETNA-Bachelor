SELECT genre.NOM AS `nom genre`, COUNT(GENRE_ID) AS `nombre films`, SUM(DUREE_MIN) AS `minutes totales`
FROM etna_tp.genre, etna_tp.film
WHERE genre.ID = film.GENRE_ID AND (genre.ID >= 3 AND genre.ID <= 5)
GROUP BY GENRE_ID; 