// step 1: get the tag according to the id
let submit = document.getElementById("continueButton");
// step 2: register a click event for the specified label
submit.addEventListener("click", buttonAction);

// step 3: respose to this event 
function buttonAction() {
  // get <input> value from user input
	let userName = document.getElementById("userName").value;
	let videoURL = document.getElementById("URL").value;
	let nickName = document.getElementById("nickName").value;
  // the values user input can not empty
  if (userName.length <= 0 || videoURL.length <= 0 || nickName.length <= 0) {return;}
	// combine the values into a single string（& to separate them）
  // let appendData = {userid: userName, url: videoURL, nickname: nickName,};
  const list = {"userid": userName, "nickname": nickName, "url": videoURL};
  // JSON.stringify(list, null, "\t");
  //console.log("list  ~~~", list);
  
  // post request，this is an asynchronous request and will not block the main thread.
	sendPostRequest('/videoData', list)
  .then(response => {
    let data = JSON.parse(response);
    let status = data.status;
    if (status == "200") {
      window.location = "/preview.html";
    } else if (status == "400") {
      alert("database full");
    } else {
      // for other condition
    }
  });
}

// relocation
let videosButton = document.getElementById("videosButton");
videosButton.addEventListener("click", myVideos);

function myVideos() {
  console.log("myVideos xxx : ", this.id); 
  window.location = "/myVideos.html";
}

// this is a async function for post request
async function sendPostRequest(url,data) {
  params = {
    method: 'POST', 
    headers: {'Content-Type': 'application/json'},
    body: JSON.stringify(data) };
    //console.log("about to send post request");
  
  let response = await fetch(url, params);
  if (response.ok) {
    let data = await response.text();
    return data;
  } else {
    throw Error(response.status);
  }
}