var twoVid = new Array();

let videoElmts = document.getElementsByClassName("tiktokDiv");

let reloadButtons = document.getElementsByClassName("reload");
let heartButtons = document.querySelectorAll("div.heart");
for (let i=0; i<2; i++) {
  let reload = reloadButtons[i]; 
  reload.addEventListener("click",function() { reloadVideo(videoElmts[i]) });
  heartButtons[i].classList.add("unloved");
} // for loop

getRandVid("/getTwoVideos")
  .then(function (data){
    for(let i = 0; i < data.length; i++){
      twoVid[i] = data[i].url;
    }
  })
// hard-code videos for now
// You will need to get pairs of videos from the server to play the game.
const urls = [twoVid[0], twoVid[1]];

for (let i=0; i<2; i++) {
      addVideo(urls[i],videoElmts[i]);
    }
    // load the videos after the names are pasted in! 
    loadTheVideos();

async function getRandVid(url){
  let res = await fetch(url); //get response object from database
  if(res.ok){
    let json = await res.json();
    twoVid = JSON.parse(json);
  }else{
    throw Error(res.status);
  }
}

    