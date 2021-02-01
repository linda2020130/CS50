window.onscroll = function() {mySticky();};

var topnav = document.getElementById("topnav");
var sticky = topnav.offsetTop;

function mySticky() {
    if (window.pageYOffset > sticky) {
        topnav.classList.add("sticky");
    } else {
        topnav.classList.remove("sticky");
    }
}