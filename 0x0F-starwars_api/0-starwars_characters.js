#!/usr/bin/node
const request = require('request');
const urlADR = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/';
function affiche (array, i) {
  if (i >= array.length) return;
  request(array[i], function (erreur, rep, bd) {
    console.log(JSON.parse(bd).name);
    affiche(array, i + 1);
  });
}
request(urlADR, function (error, response, body) {
  if (error) {
    console.log(error);
  } else {
    affiche(JSON.parse(body).characters, 0);
  }
});
