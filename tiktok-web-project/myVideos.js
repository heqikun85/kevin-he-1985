// globe value, which include all data from server (VideoTable)
let lists = NaN;

// add events to "addNewVideos" button
let addBtn = document.getElementById("addNewVideos");
addBtn.addEventListener("click", addNewVideo);

// Add events to each button(8 buttons)
for (i = 0; i < 8; i++) {
	buttonId = "deleltebut" + i;
	// get the tag according to the id
	let deleteBtn = document.getElementById(buttonId);
	// register a click event for the specified label
	deleteBtn.addEventListener("click", deleteVideo);
}

function deleteVideo() {
  // get current button id
  let buttonId = this.id;
  // get button id last digit
  let lastDigit = buttonId.substr(buttonId.length - 1, 1);
  //console.log("last", lastDigit);
  // append "input id"
  let inputId = "entity" + lastDigit;
  // get input object
  let input = document.getElementById(inputId);
  // get id
  let id = lastDigit;
  // JSON Serialization
  let deleteRow = {"rowIdNum" : lists[id].rowIdNum};
  let deleteEntity = JSON.stringify(deleteRow);
  deleteVideoById(deleteEntity);
}

function deleteVideoById(entityId) {
  console.log(entityId);
  sendPostRequest('/deleteData', entityId)
    // after the asynchronous request ends, call the following methods(then or catch)
    .then(function(data) {
      // decode JSON 
      let rel = JSON.parse(data);
      //console.log("delete data : ", rel.status);
      if (rel.status == "200") {
        // reload "myVideos Page"
        window.onload = windowReload();
      }
    })
    .catch(function(error) {
      // async request failed, catch exception
      console.error("Error occurred:", error)
    }); 
}

// this is a async function
async function sendPostRequest(url, data) {
    // set request URL, header and body
    let response = await fetch(url, {
      method: 'POST', 
      headers: {'Content-Type': 'application/json'},
      body: data}); 
    // the request to the server is successful and the data is returned
    if (response.ok) {
      let data = await response.text();
      return data;
    } else {
      throw Error(response.status);
    }
}

function addNewVideo() {
  window.location = "/tiktokpet.html";
}

///////////////////////////////////////////////////////////////////////
function windowReload() { 　　 
  getList("/getList");
} 　　
window.onload = windowReload;

async function getList(url){ 
  fetch(url).then(response => 
    response.json().then(data => ({
        data: data,
        status: response.status
    })).then(res => {
      console.log(res.status, res.data.entities);
      refreshUI(res.data.entities);
  }));
}

function refreshUI(entities) {
  let len = entities.length;
  lists = entities;
  if (len >= 8) {
    playButton.disabled = false;
    playButton.style.opacity = 1;
    addBtn.disabled = true;
    addBtn.style.opacity = 0.2;
  } else{
    playButton.disabled = true;
    playButton.style.opacity = 0.2;  
    addBtn.disabled = false;
    addBtn.style.opacity = 1;
  }
  for (i = 0; i < 8; i++) {
	  inputId = "entity" + i;
    deleteBtnId = "deleltebut" + i;
	  // get input tag
	  let inputTag = document.getElementById(inputId);
    let deleteBtn = document.getElementById(deleteBtnId);
    // update data
    if (i < len) {
      inputTag.textContent = entities[i].userid;
      deleteBtn.style.opacity = 0.8;
      deleteBtn.disabled = false;
    } else {
      inputTag.textContent = "";
	    inputTag.style.border = "dashed 2px #a9a9a9";
      deleteBtn.style.opacity = 0.3;
      deleteBtn.disabled = true;   
    }
  }
}

// add events to "playButton" button
let playButton = document.getElementById("playButton");
playButton.addEventListener("click", playVideo);
function playVideo() {
  console.log("test !");
}
