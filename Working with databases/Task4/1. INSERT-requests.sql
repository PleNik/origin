INSERT INTO genre (name)VALUES
('Pop music'),
('Hip-hop'),
('Rock'),
('Classic music'),
('Chanson');

INSERT INTO artist (name) VALUES
('Юрий Антонов'),
('Modern Talking'),
('Basta'),
('The Scorpions'),
('Sting'),
('Vanessa-Mae'),
('Joe Dassin');

INSERT INTO genreartist (genre_id, artist_id) VALUES
(1, 1),
(1, 2),
(2, 3),
(2, 5),
(3, 3),
(3, 4),
(3, 5),
(4, 6),
(5, 7);

INSERT INTO album (name, year_of_issue) VALUES
('Зеркало', '1993-12-31'),
('Лунная дорожка', '1993-12-31'),
('Поверь в мечту', '1983-12-31'),
('Heath and soul', '2010-12-31'),
('Universe: 12tn album', '2003-12-30'),
('Basta 3', '2020-12-31'),
('Basta 1', '2019-12-31'),
('Lonely Crow', '1972-12-31'),
('Fly to the rainbow', '1974-12-31'),
('The last ship', '2019-12-31'),
('Symphincities', '2010-12-31'),
('Choreogarphy', '2004-12-31'),
('Subject to Change', '2001-12-31'),
('Les Femmes de ma vie', '1978-12-31'),
('Le Jardin du Luxembourg', '1976-12-31');

INSERT INTO artistalbum (artist_id, album_id) VALUES
(1, 1),
(1, 2),
(1, 3),
(2, 4),
(3, 4),
(2, 5),
(3, 7),
(4, 8),
(5, 8),
(4, 9),
(4, 10),
(5, 10),
(5, 11),
(5, 12),
(6, 12),
(6, 13),
(7, 14),
(7, 15);


INSERT INTO track (album_id, artist_id , name, duration) VALUES
(1, 1, 'Зеркало', '0 00:03:37'),
(1, 1, 'Не забывай', '0 00:03:51'),
(1, 1, 'Завтра', '0 00:03:37'),
(2, 1, 'Лунная дорожка', '0 00:05:54'),
(2, 1, 'Не говорите мне, прощай', '0 00:04:19'),
(3, 1, 'Поверь в мечту', '0 00:04:33'),
(3, 1, 'На улице Каштановой', '0 00:03:54'),
(4, 2, 'Brother Louis', '0 00:03:45'),
(5, 2, 'Secret', '0 00:03:33'),
(6, 3, 'мой Урбан', '0 00:04:12'),
(7, 3, 'Mother', '0 00:03:56'),
(8, 4, 'my Action', '0 00:03:53'),
(9, 4, 'Fly to the rainbow', '0 00:09:36'),
(11, 5, 'Next to You', '0 00:02:30'),
(11, 5, 'I Hung My Head', '0 00:04:23'),
(10, 5, 'So to Speak', '0 00:03:34'),
(10, 5, 'Language of Birds', '0 00:03:52'),
(12, 6, 'Sebre Dance', '0 00:05:59'),
(12, 6, 'Emerald Tiger', '0 00:03:50'),
(13, 6, 'Yantra', '0 00:05:52'),
(14, 7, 'La Premiere Femme De Ma Vie', '0 00:02:22'),
(14, 7, 'Noisette Et Cassidy', '0 00:02:52'),
(15, 7, 'A Toi', '0 00:02:52'),
(15, 7, 'Comme Disait Valentine', '0 00:03:07');

INSERT INTO collection (name, year_of_issue) VALUES
('Зеркало', '2008-12-31'),
('Secret', '2018-12-31'),
('Emelard Tiger', '2000-12-31'),
('Sabre Dance', '2019-12-31'),
('My Day', '2021-12-31');

INSERT INTO trackcollection (track_id, collection_id) VALUES
(1, 1),
(11, 1),
(16, 1),
(3, 2),
(9, 2),
(15, 2),
(8, 3),
(12, 3),
(23, 3),
(4, 3),
(18, 4),
(21, 4),
(17, 4),
(2, 5),
(9, 5),
(24, 5);