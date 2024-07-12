


// This viewer takes a TikTok video URL and displays it in a nice magenta box, and gives it a reload button in case you want to watch it again. 

// for example, these are hardcoded
const example = 'https://www.tiktok.com/@cheyennebaker1/video/7088856562982423854';


// grab elements we'll use 
// these are global! 

let divElmt = document.getElementById("tiktokDiv");

// set up button


// add the blockquote element that TikTok wants to load the video into
addVideo(example,divElmt);

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