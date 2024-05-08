"use strict"

//A static server using Node and Express

const express = require("express");
const fetch = require("cross-fetch");
// get Promise-based interface to sqlite3
const db = require('./sqlWrap');
// this also sets up the database

const app = express();

/* set up server pipeline to handle requests */

// print incoming url on console
app.use(function(req, res, next) {
  console.log("\n",req.method,req.url);
  next();
})


app.get("/testDB", 
  function (req,res,next) {
      databaseCodeExample();
      next();
    } )

// final pipeline state - file not found
app.use(function(req, res, next){
  console.log("send 404 response");
  res.status(404);
  // otherwise respond with plain-text. 
  res.type('txt').send('File not found');
});  

/* pipeline is now all set up */

// listen for requests :)
const listener = app.listen(3000, function() {
  console.log("The static server is listening on port " + listener.address().port);
});


/****************************/
/* some database operations */
/****************************/


// test the function that inserts into the database
function databaseCodeExample() {

  console.log("testing database");

  // put the video data into an object
  let vidObj = {
"url": "https://www.tiktok.com/@cheyennebaker1/video/7088856562982423854",
 "nickname": "Cat vs Fish",
 "userid": "ProfAmenta"
   }

 async function insertAndCount(vidObj) {

   await insertVideo(vidObj);
   const tableContents = await dumpTable();
   console.log(tableContents.length);
 }

insertAndCount(vidObj)
  .catch(function(err) {console.log("DB error!",err)});
  
  
  /*
  insertVideo(vidObj)
    .then(function() {
      console.log("success!");
    })
    .catch(function(err) {
      console.log("SQL error",err)} );

  dumpTable()
  .then(function(result) {
    let n = result.length;
    console.log(n+" items in the database"); })
  .catch(function(err) {
      console.log("SQL error",err)} );
  */
  
  getVideo("Cat vs Fish")
    .then(function(result) {
      // console.log("row contained",result); 
          })
    .catch(function(err) {
      console.log("SQL error",err)} );

}


// ******************************************** //
// Define async functions to perform the database 
// operations we need

// An async function to insert a video into the database
async function insertVideo(v) {
  const sql = "insert into VideoTable (url,nickname,userid,flag) values (?,?,?,TRUE)";

await db.run(sql,[v.url, v.nickname, v.userid]);
}

// an async function to get a video's database row by its nickname
async function getVideo(nickname) {

  // warning! You can only use ? to replace table data, not table name or column name.
  const sql = 'select * from VideoTable where nickname = ?';

let result = await db.get(sql, [nickname]);
return result;
}

// an async function to get the whole contents of the database 
async function dumpTable() {
  const sql = "select * from VideoTable"
  
  let result = await db.all(sql)
  return result;
}