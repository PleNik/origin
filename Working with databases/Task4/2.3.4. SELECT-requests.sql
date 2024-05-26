--Задание 2
--1. Название и продолжительность самого длительного трека
SELECT name, duration FROM track
WHERE duration = (SELECT MAX(duration) FROM track);

--2. Название треков, продолжительность которых не менее 3,5 минут
SELECT name, duration FROM track
WHERE duration >= '0 00:03:30';

--3. Названия сборников, вышедших в период с 2018 по 2020 годы включительно
SELECT name, year_of_issue FROM collection
WHERE EXTRACT ('year' FROM year_of_issue) >= '2018' AND EXTRACT ('year' FROM year_of_issue) <= '2020';

--4. Исполнители, чьё имя состоит из одного слова
SELECT name FROM artist
WHERE name NOT LIKE '% %';

--5. Название треков, которые содержат слова «мой» или «my»
SELECT name FROM track
WHERE name LIKE '%my%' OR name LIKE '%мой%';

--Задание 3
-- 1. Количество исполнителей в каждом жанре
SELECT g.name, count(gar.artist_id) FROM genre g
JOIN genreartist gar ON g.id = gar.genre_id
GROUP BY g.name;

--2. Количество треков, вошедших в альбомы 2019–2020 годов
SELECT count(t.id)  FROM track t
JOIN album a ON t.album_id = a.id
WHERE year_of_issue = '2019-12-31' OR year_of_issue = '2020-12-31';

--3. Средняя продолжительность треков по каждому альбому
SELECT a.name, AVG(t.duration) FROM track t
JOIN album a ON t.album_id = a.id
GROUP BY a.name;

--4. Все исполнители, которые не выпустили альбомы в 2020 году
SELECT ar.name FROM album alb
JOIN artistalbum al ON alb.id=al.album_id
JOIN artist ar ON al.artist_id = ar.id
WHERE EXTRACT ('year' FROM year_of_issue) != 2020
GROUP BY ar.name;

--5. Названия сборников, в которых присутствует конкретный исполнитель
SELECT a.name, c.name FROM collection c
JOIN trackcollection tc ON c.id = tc.collection_id
JOIN track t ON tc.track_id = t.id
JOIN artist a ON t.artist_id  = a.id
GROUP BY a.name, c.name
HAVING a.name = 'Joe Dassin';


--Задание 4
-- 1. Названия альбомов, в которых присутствуют исполнители более чем одного жанра
SELECT alb.name, count(*) FROM album alb
JOIN artistalbum al ON alb.id = al.album_id
JOIN artist ar ON al.artist_id = ar.id
JOIN genreartist g ON ar.id = g.artist_id
JOIN genre g2 ON g.genre_id = g2.id
GROUP BY alb.name
HAVING count(*)>1;

--2. Наименования треков, которые не входят в сборники
SELECT t.name FROM collection c
JOIN trackcollection tc ON c.id = tc.collection_id
JOIN track t ON tc.track_id = t.id;
--выводит те, треки,которые входят. Как сделать, чтобы выводил те, которые не входят?

--3. Исполнитель или исполнители, написавшие самый короткий по продолжительности трек, — теоретически таких треков может быть несколько
SELECT a.name, t.duration FROM artist a
RIGHT JOIN track t ON a.id = t.artist_id
GROUP BY a.name, t.duration
HAVING t.duration = (SELECT MIN(t.duration) FROM track t);

--4. Названия альбомов, содержащих наименьшее количество треков
SELECT a.name, COUNT(t.album_id) number_of_tracks FROM album a
JOIN track t ON a.id = t.album_id
GROUP BY a.name
ORDER BY number_of_tracks;
--выводит альбомы с количеством треков. Как сделать, чтобы считать количество и затем выводить его минимальное значение?
