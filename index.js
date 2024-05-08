// include express
const express = require("express");
// create object to interface with express
const app = express();
// ? ? ? 
const fetch = require("cross-fetch");
const bodyParser = require('body-parser');
// use json
app.use(express.json());

// get a database handle
const db = require('./sqlWrap');

// print info about incoming HTTP request (for debugging)
app.use(function(req, res, next) {
  //console.log("debugging : ", req.method, req.url);
  next();
})

// make all the files in 'public' available 
app.use(express.static("public"));

// if no file specified, return the main page
app.get("/", (request, response) => {
  // response.sendFile(__dirname + "/public/homePage.html");
  response.sendFile(__dirname + "/public/myVideos.html");
  // response.send("http://" + request.headers.host + "/homePage.html");
});

app.get("/getList", (request, response) => {
  // get all the data in the VideoTable table in the database
  getListFromVideoTable(response);
});

async function getListFromVideoTable(response) {
  const tableContents = await dumpTable();
  //console.log("tableContents : ", tableContents);  
  const list = {"entities": tableContents, "count": tableContents.length};
  let listJSON = JSON.stringify(list);
  response.send(listJSON);
}

//GET recent video from database
app.get("/getMostRecent", async function(req, res) {
  let recentVideo = await getVideo();
  res.json(recentVideo);
});

// Post
app.post('/videoData', (request, response, next) => {
  let choice = request.body; // user's choice
  // console.log("test 1111", (typeof app.response)); // test
  insertAndCount(choice, response);
  //return response.send("Got POST");  
});

app.post('/deleteData',(request, response, next) => {
  let deleteId = request.body;
  deleteVideo(deleteId)
  .then(res => { 
    // 200 means the server has successfully processed the request
    response.send('{"status" : "200"}');
  });
});

////////////////////////////////////////////////////////////////

// Need to add response if page not found!
app.use(function(req, res) {
  res.status(404);
  res.type('txt');
  res.send('404 - File ' + req.url + ' not found');
}); // end of pipeline specification

// Now listen for HTTP requests
// it's an event listener on the server!
const listener = app.listen(3000, function() {
  console.log("The static server is listening on port " + listener.address().port);
});

////////////////////// Sql section //////////////////////
 async function insertAndCount(vidObj, response) {
   // get all date from VideoTable
   const tableContents = await dumpTable();
   // get length from VideoTable
   let i = tableContents.length;
   // console.log(i);
   if (i >= 0 && i < 8) {
     // console.log("add record to table");
     // update data if records great than 1
     if (i >= 1) {
       await updateflagsToFalse();
     }
     
     // insert a video to the table
     await insertVideo(vidObj);
     let status = '{"status" : "200", "info" : "success"}';
     response.send(status);
   } else {
     let status = '{"status" : "400", "info" : "fail"}';
     response.send(status);
   }
 }

// insert a record from the VideoTable
async function insertVideo(v) {
  const sql = "insert into VideoTable (url, nickname, userid, flag) values (?, ?, ?, TRUE)";
  await db.run(sql, [v.url, v.nickname, v.userid]);
};

// delete a record from the VideoTable
async function deleteVideo(v) {
  const tableContents = await dumpTable();
  let len = tableContents.length;
  if (len <= 0) {return;}
  // execute sql
  await deleteRecord(v);
  // get the recent record from the VideoTable
  let lastRecord = await getLastRecord();
  // set the value of the latest data flag to 1
  if (lastRecord.flag == 0) {
    // console.log("test ", lastRecord.flag);
    // updateLastRecord(lastRecord.flag);
    await updateLastRecord(lastRecord.rowIdNum);
  }
}

// Set the flag value of all data in the table to false
async function updateflagsToFalse() {
  let updateSql = "UPDATE VideoTable SET flag = FALSE WHERE flag = TRUE";
  await db.run(updateSql);
}

// Modify the last data flag value to true, if necessary
async function updateLastRecord(rowIdNum) {
  let updateSql = "UPDATE VideoTable SET flag = TRUE WHERE rowIdNum = ?";
  await db.run(updateSql, [rowIdNum]);
}

// find the latest record
async function getVideo() {
  // warning! You can only use ? to replace table data, not table name or column name.
  const sql = 'select * from VideoTable where flag = TRUE';
  let result = await db.get(sql);
  //console.log(result); //test
  let json = JSON.stringify(result);
  return json;
};

// query all data
async function dumpTable() {
  const sql = "select * from VideoTable";
  let result = await db.all(sql);
  return result;
};

// Query the last record in the VideoTable (the latest record)
async function getLastRecord() {
  const sql = "select * from VideoTable order by rowIdNum DESC limit 1";
  let result = await db.get(sql);
  return result;
};

// delete a record in the VideoTable
async function deleteRecord(v) {
  const sql = "delete from VideoTable where rowIdNum = ?";
  await db.run(sql, [v.rowIdNum]);
}