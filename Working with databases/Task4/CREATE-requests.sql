CREATE TABLE IF NOT EXISTS Genre (
id SERIAL PRIMARY KEY,
name VARCHAR(60) NOT NULL
);

CREATE TABLE IF NOT EXISTS Artist (
id SERIAL PRIMARY KEY,
name VARCHAR(60) NOT NULL
);

CREATE TABLE IF NOT EXISTS GenreArtist (
genre_id INTEGER REFERENCES Genre(id),
artist_id INTEGER REFERENCES Artist(id),
CONSTRAINT pk PRIMARY KEY (genre_id, artist_id)
);

CREATE TABLE IF NOT EXISTS Album (
id SERIAL PRIMARY KEY,
name VARCHAR(60) NOT NULL,
year_of_issue DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS ArtistAlbum (
artist_id INTEGER REFERENCES Artist(id),
album_id INTEGER REFERENCES Album(id),
CONSTRAINT prk PRIMARY KEY (artist_id, album_id)
);

CREATE TABLE IF NOT EXISTS Track (
id SERIAL PRIMARY KEY,
album_id INTEGER NOT NULL REFERENCES Album(id),
artist_id INTEGER NOT NULL REFERENCES Artist(id),
name VARCHAR(60) NOT NULL,
duration INTERVAL NOT NULL
);

CREATE TABLE IF NOT EXISTS Collection (
id SERIAL PRIMARY KEY,
name VARCHAR(60) NOT NULL,
year_of_issue DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS TrackCollection (
track_id INTEGER NOT NULL REFERENCES Track(id),
collection_id INTEGER NOT NULL REFERENCES Collection (id),
CONSTRAINT psk PRIMARY KEY (track_id, collection_id)

SELECT t.name FROM track t
LEFT JOIN trackcollection tc ON t.id = tc.track_id
WHERE tc.track_id IS NULL;

WITH AlbumTrackCount AS (
SELECT a.name, COUNT(t.album_id) AS number_of_tracks FROM album a
JOIN track t ON a.id = t.album_id
GROUP BY a.name
)
SELECT name FROM AlbumTrackCount
WHERE number_of_tracks = (SELECT MIN(number_of_tracks) FROM AlbumTrackCount);
