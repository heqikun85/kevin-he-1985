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
  let appendData = {userid: userName, URL: URL, nickname: nickName,}
  
  // this is the URL of a post request/videoData
  // https://superTeam.ecs162-s22.repl.co
  // post request，this is an asynchronous request and will not block the main thread.
	// sendPostRequest('/videoData', appendData)
    // after the asynchronous request ends, call the following methods(then or catch)
  getRecent("/getMostRecent")
    .then(function(data) {
      // get the URL
      const url = data.URL;
      // get the nickname
      const nickName = data.nickName;
      // cache data the user input, note that when the page is closed, the data in sessionStorage will be cleared.
      // the object is used to get the address (URL) of the current page and redirect the browser to a new page(result.html 
      window.location = "/result.html";
    })
    .catch(function(error) {
      // async request failed, catch exception
      console.error("Error occurred:", error)
    }); 
}

	  let divElmt = document.getElementById("tiktokDiv");
	  // set up button
	  // add the blockquote element that TikTok wants to load the video into
	  addVideo("https://www.tiktok.com/@luciana90luna/video/7092846504284671238?is_from_webapp=1&sender_device=pc&web_id=7092861975067297326",divElmt);
	  
	  // on start-up, load the videos
	  loadTheVideos();

// Add the blockquote element that tiktok will load the video into
async function addVideo(tiktokurl,divElmt) {

  let videoNumber = tiktokurl.split("video/")[1];

  let block = document.createElement('blockquote');
  block.className = "tiktok-embed";
  block.cite = tiktokurl;
  // have to be formal for attribute with dashes
  block.setAttribute("data-video-id",videoNumber);
  block.style = "width: 325px; height: 563px;"

  let section = document.createElement('section');
  block.appendChild(section);
  
  divElmt.appendChild(block);
}

// Ye olde JSONP trick; to run the script, attach it to the body
function loadTheVideos() {
  body = document.body;
  script = newTikTokScript();
  body.appendChild(script);
}

// makes a script node which loads the TikTok embed script
function newTikTokScript() {
  let script = document.createElement("script");
  script.src = "https://www.tiktok.com/embed.js"
  script.id = "tiktokScript"
  return script;
}

// the reload button; takes out the blockquote and the scripts, and puts it all back in again.
// the browser thinks it's a new video and reloads it
function reloadVideo () {
  
  // get the two blockquotes
  let blockquotes 
 = document.getElementsByClassName("tiktok-embed");

  // and remove the indicated one
    block = blockquotes[0];
    console.log("block",block);
    let parent = block.parentNode;
    parent.removeChild(block);

  // remove both the script we put in and the
  // one tiktok adds in
  let script1 = document.getElementById("tiktokScript");
  let script2 = script.nextElementSibling;

  let body = document.body; 
  body.removeChild(script1);
  body.removeChild(script2);

  addVideo(example,divElmt);
  loadTheVideos();
}

// this is a async function
async function sendPostRequest(url, data) {
    // set request URL, header and body
    let response = await fetch(url, {
      method: 'POST', 
      headers: {'Content-Type': 'text/plain'},
      body: data }); // JSON type "{'I am JSON': 1}"
    // the request to the server is successful and the data is returned
    if (response.ok) {
      let data = await response.text();
      return data;
    } else {
      throw Error(response.status);
    }
}


// get the tag according to the id
const userSubmit = document.getElementById("userSubmit");
// get the value of "nickName" from the cache
let videoNickName = sessionStorage.getItem("nickName");
// get the value from the specific tag
let text = userSubmit.textContent;
// replace nick-name with the value entered by the user
userSubmit.textContent = text.replace('nick-name', videoNickName);;
  
// step 1: get the tag according to the id
let back = document.getElementById("backButton");
// step 2: register a click event for the specified label
back.addEventListener("click", backHomePage);
// step 3: back to the home page when the click event happend
function backHomePage() {
  window.location.replace("https://superTeam.ecs162-s22.repl.co");
}