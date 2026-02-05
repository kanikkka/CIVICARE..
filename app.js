// Ye demo data hai – baad me tumhari file se connect karenge

let complaints = [
{type:"Water", location:"Block A", status:"Pending", priority:3},
{type:"Road", location:"Gate 2", status:"Resolved", priority:2},
{type:"Light", location:"Market", status:"Pending", priority:3}
];

function load(){

let table = document.getElementById("tableData");

let total = complaints.length;
let resolved = complaints.filter(c=>c.status=="Resolved").length;
let pending = total - resolved;

document.getElementById("total").innerText = total;
document.getElementById("resolved").innerText = resolved;
document.getElementById("pending").innerText = pending;


complaints.forEach(c=>{

table.innerHTML += `
<tr>
<td>${c.type}</td>
<td>${c.location}</td>
<td>${c.status}</td>
<td>${c.priority}</td>
</tr>
`;


});

}



load();
function toggle(){
 document.body.classList.toggle("dark");
}
function submitComplaint(){

let type = document.getElementById("type").value;
let location = document.getElementById("location").value;
let desc = document.getElementById("desc").value;

if(location=="" || desc==""){
 alert("Please fill all fields");
 return;
}

alert("Complaint Submitted Successfully!");

}
