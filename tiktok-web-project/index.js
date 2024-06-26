'use strict'
// index.js
// This is our main server file

// A static server using Node and Express
const express = require("express");

// local modules
const db = require("./sqlWrap");
const win = require("./pickWinner");

// gets data out of HTTP request body 
// and attaches it to the request object
const bodyParser = require('body-parser');

/* might be a useful function when picking random videos */
function getRandomInt(max) {
  let n = Math.floor(Math.random() * max);
  console.log(n);
  return n;
}
/* start of code run on start-up */
// create object to interface with express
const app = express();

// Code in this section sets up an express pipeline

app.get("/getTwoVideos",(req,res)=>{
  dumpTable();
  var vid1 =  {};
  var vid2 =  {};  
  do{
    var n = getRandomInt(10);
    var v = getRandomInt(10);
    getDataObj(n)
      .then(function (data){
        vid1 = data;
        console.log("this is in loop1:", vid2.url);
      });
     
    getDataObj(v)
      .then(function (data){
        vid2 = data;
        console.log("this is in loop2:", vid2.url);
      });
  }while(n == v);

    let twoVid ={list1: vid1, list2: vid2};
  
  //do{
   // let list = getTwoVid;
  //}while(list[0].url == undefined || list[1].url == undefined);
  res.json(twoVid);
})

// print info about incoming HTTP request 
// for debugging
app.use(function(req, res, next) {
  console.log(req.method,req.url);
  next();
})
// make all the files in 'public' available 
app.use(express.static("public"));

// if no file specified, return the main page
app.get("/", (request, response) => {
  response.sendFile(__dirname + "/public/compare.html");
});

// Get JSON out of HTTP request body, JSON.parse, and put object into req.body
app.use(bodyParser.json());


app.get("/getWinner", async function(req, res) {
  console.log("getting winner");
  try {
  // change parameter to "true" to get it to computer real winner based on PrefTable 
  // with parameter="false", it uses fake preferences data and gets a random result.
  // winner should contain the rowId of the winning video.
  let winner = await win.computeWinner(8,false);

  // you'll need to send back a more meaningful response here.
  res.json({});
  } catch(err) {
    res.status(500).send(err);
  }
});


// Page not found
app.use(function(req, res){
  res.status(404); 
  res.type('txt'); 
  res.send('404 - File '+req.url+' not found'); 
});

// end of pipeline specification

// Now listen for HTTP requests
// it's an event listener on the server!
const listener = app.listen(3000, function () {
  console.log("The static server is listening on port " + listener.address().port);
});

async function getDataObj(n){
  let sql = "SELECT * FROM VideoTable where rowIdNum = ?";
  let vid = await db.get(sql,[n]);
  console.log(vid.url);
  return vid;
}

async function dumpTable() {
  const sql = "select * from VideoTable";
  let result = await db.all(sql);
  //console.log(result);
  return result;
};

function getTwoVid(data){
  
}