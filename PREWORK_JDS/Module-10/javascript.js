document.getElementById("button1").addEventListener("click", myFunction);

function myFunction(){
    document.getElementById("box").style.height = "250px"
}

document.getElementById("button2").addEventListener("click", colorFunction);

function colorFunction(){
    document.getElementById("box").style.backgroundColor = "blue"
}

document.getElementById("button3").addEventListener("click", fadeFunction);

function fadeFunction(){
    document.getElementById("box").style.opacity = "0.6"
}

document.getElementById("button4").addEventListener("click", resetFunction);

function resetFunction(){
    document.getElementById("box").style ="height:150px; width:150px; background-color:orange; margin:25px"
}