#!/usr/bin/node

const request = require('request');

const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(filmUrl, (error, response, body) => {
  if (error) {
    console.error('Error:', error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Error: Status code ${response.statusCode}`);
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;

  if (!characters || characters.length === 0) {
    return;
  }

  let completed = 0;
  const characterNames = new Array(characters.length);

  characters.forEach((characterUrl, index) => {
    request(characterUrl, (err, res, charBody) => {
      if (err) {
        console.error('Error:', err);
        return;
      }

      const character = JSON.parse(charBody);
      characterNames[index] = character.name;
      completed++;

      if (completed === characters.length) {
        characterNames.forEach((name) => {
          console.log(name);
        });
      }
    });
  });
});
