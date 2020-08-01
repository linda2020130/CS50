/* 
Type sqlite3 movies.db to run sql command at the command line,
and type ".schema" to output the CREATE TABLE statements that were used to generate each of the tables in the database
*/

sqlite> .schema
CREATE TABLE movies (
                    id INTEGER,
                    title TEXT NOT NULL,
                    year NUMERIC,
                    PRIMARY KEY(id)
                );
CREATE TABLE stars (
                movie_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id),
                FOREIGN KEY(person_id) REFERENCES people(id)
            );
CREATE TABLE directors (
                movie_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id),
                FOREIGN KEY(person_id) REFERENCES people(id)
            );
CREATE TABLE ratings (
                movie_id INTEGER NOT NULL,
                rating REAL NOT NULL,
                votes INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id)
            );
CREATE TABLE people (
                id INTEGER,
                name TEXT NOT NULL,
                birth NUMERIC,
                PRIMARY KEY(id)
            );



/*
Q1 - List the titles of all movies released in 2008.
*/

SELECT title FROM movies
WHERE year = 2008;


/*
Q2 - Query the birth year of Emma Stone
*/

SELECT birth FROM people
WHERE name = 'Emma Stone';


/*
Q3 - List the titles of all movies with a release date on or after 2018, in alphabetical order.
*/

SELECT title FROM movies
WHERE year >= 2018
ORDER BY title;


/*
Q4 - Query the number of movies with an IMDb rating of 10.0.
*/

SELECT COUNT(movie_id) FROM ratings
WHERE rating = 10.0;


/*
Q5 - List the titles and release years of all Harry Potter movies, in chronological order.
You may assume that the title of all Harry Potter movies will begin with the words “Harry Potter”, and that if a movie title begins with the words “Harry Potter”, it is a Harry Potter movie.
*/

SELECT title, year FROM movies
WHERE title LIKE 'Harry Potter%'
ORDER BY year;


/*
Q6 - Query the average rating of all movies released in 2012.
*/

SELECT AVG(rating) FROM ratings
WHERE movie_id IN (
SELECT id FROM movies
WHERE year = 2012);


/*
Q7 - List all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
*/

SELECT title, rating FROM
movies JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2010
ORDER BY rating DESC, title;


/*
Q8 - List the names of all people who starred in Toy Story.
You may assume that there is only one movie in the database with the title Toy Story.
*/

SELECT name FROM people
WHERE id IN (
SELECT person_id FROM 
movies JOIN stars ON movies.id = stars.movie_id
WHERE title = 'Toy Story');


/*
Q9 - List the names of all people who starred in a movie released in 2004, ordered by birth year.
If a person appeared in more than one movie in 2004, they should only appear in your results once.
People with the same birth year may be listed in any order.
No need to worry about people who have no birth year listed, so long as those who do have a birth year are listed in order.
*/

SELECT name FROM people
WHERE id IN (
SELECT DISTINCT(person_id) FROM
movies JOIN stars ON movies.id = stars.movie_id
WHERE year = 2004)
ORDER BY birth;


/*
Q10 - List the names of all people who have directed a movie that received a rating of at least 9.0.
*/

SELECT name FROM people
WHERE id IN (
SELECT person_id FROM
movies JOIN directors ON movies.id = directors.movie_id JOIN
ratings ON directors.movie_id = ratings.movie_id
WHERE rating >= 9.0);


/*
Q11 - List the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
You may assume that there is only one person in the database with the name Chadwick Boseman.
*/

SELECT title FROM
movies JOIN ratings ON movies.id = ratings.movie_id
WHERE id IN (
SELECT movie_id FROM
stars JOIN people ON stars.person_id = people.id
WHERE name = 'Chadwick Boseman')
ORDER BY rating DESC LIMIT 5;


/*
Q12 - List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
You may assume that there is only one person in the database with the name Johnny Depp.
You may assume that there is only one person in the database with the name Helena Bonham Carter.
*/

SELECT title FROM movies
WHERE id IN (
SELECT movie_id FROM
stars JOIN people ON stars.person_id = people.id
WHERE name IN ('Johnny Depp', 'Helena Bonham Carter')
GROUP BY movie_id
HAVING COUNT(person_id) = 2);


/*
Q13 - List the names of all people who starred in a movie in which Kevin Bacon also starred.
There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
Kevin Bacon himself should not be included in the resulting list.
*/

SELECT name FROM people
WHERE id IN (
SELECT person_id FROM stars
WHERE movie_id IN (
SELECT movie_id FROM
stars JOIN people ON stars.person_id = people.id
WHERE name = 'Kevin Bacon' AND birth = 1958))
AND NOT name = 'Kevin Bacon';

