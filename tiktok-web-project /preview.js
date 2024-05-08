// This viewer takes a TikTok video URL and displays it in a nice magenta box, and gives it a reload button in case you want to watch it again. 

  let reloadButton = document.getElementById("reload");
  let divElmt = document.getElementById("tiktokDiv");

getRecent("/getMostRecent")
  .then(function display(vidObj){
    //console.log("this data", vidObj.url); //test
   
    addVideo(vidObj.url,divElmt);
    loadTheVideos();

    const userSubmit = document.getElementById("userSubmit");
    let nick = vidObj.nickname;
    userSubmit.textContent = nick;
  });

//listener reload button and exce it
reloadButton.addEventListener("click",reloadVideo);

// Add the blockquote element that tiktok will load the video into
async function addVideo(tiktokurl,divElmt) {
  //console.log(tiktokurl);
  let videoNumber = tiktokurl.split("video/")[1];

  let block = document.createElement('blockquote');
  block.className = "tiktok-embed";
  block.cite = tiktokurl;
  // have to be formal for attribute with dashes
  block.setAttribute("data-video-id",videoNumber);
  block.style = "width: 325px; height: 563px;";

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
  script.src = "https://www.tiktok.com/embed.js";
  script.id = "tiktokScript";
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

  //get the video again
  getRecent("/getMostRecent")
    .then(function refresh(vidObj){
      addVideo(vidObj.url,divElmt);
      loadTheVideos();
    });
}
  
// step 1: get the tag according to the id
let back = document.getElementById("continueButton");
// step 2: register a click event for the specified label
back.addEventListener("click", backHomePage);
// step 3: back to the home page when the click event happend
function backHomePage() {
  window.location.replace("/myVideos.html");
}

//get most recent video data as json from server
async function getRecent(url){
  let response = await fetch(url); //get response data from database
  if(response.ok){
    let json = await response.json(); // use json
    let v = JSON.parse(json);
    return v;
  }else{
    throw Error(response.status);
  }
}



