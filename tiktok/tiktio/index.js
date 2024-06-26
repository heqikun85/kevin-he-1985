//There is no starter code for TikTokPets-2, but you can copy either your code, or the solution we distribute, for TikTokPets-1 here to get started.
let id1 = "Ray";
if(true){
  var id2 = "Mia";
  console.log(id1);
}
console.log(id2);
f()// this work
function f (){}// define a function in this way will be awailable for using before. 
let g = function(){console.log("This dies not")}//will not work, Function 
g = () =>{console.log("nor this")}


// index.js
// This is our main server file

// A static server using Node and Express
const express = require("express");
// gets data out of HTTP request body 
// and attaches it to the request object
const bodyParser = require('body-parser');
// create object to interface with express
const app = express();
// Code in this section sets up an express pipeline

// print info about incoming HTTP request 
// for debugging
app.use(function(req, res, next) {
  console.log(req.method,req.url);
  next();
});

app.use(express.text());
// make all the files in 'public' available 

app.use(function(req, res, next) {
  console.log("body contains",req.body);
  next();
});

app.use(express.static("public"));

// if no file specified, return the main page
app.get("/", (request, response) => {
  response.sendFile(__dirname + "/public/tiktokpets.html");
});

app.post("/videoData", (req, res) =>{
  console.log("sending Response")
  return res.send('recieved POST'); 
});

// Need to add response if page not found!
app.use(function(req, res){
  res.status(404); res.type('txt'); 
  res.send('404 - File '+req.url+' not found'); 
});

// end of pipeline specification

// Now listen for HTTP requests
// it's an event listener on the server!
const listener = app.listen(3000, function () {
  console.log("The static server is listening on port " + listener.address().port);
});
