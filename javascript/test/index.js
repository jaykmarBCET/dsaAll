
let root = document.getElementById("root");

 let navBarValue = ["About", "Projects","Skills","Contact"];

 let nav = document.createElement("nav");

 
 let Node = [];
 navBarValue.map((item)=>{
    let li = document.createElement("a")
    li.innerHTML = item;
    li.href = `$/{item}`
    Node.push(li);
})

Node.map((item)=>{
    
    nav.appendChild(item)
})
root.appendChild(nav)

