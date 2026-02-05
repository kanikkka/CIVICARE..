let complaints = [
{user:"kanika", type:"Water", location:"Block A", status:"Pending", priority:3},
{user:"raj", type:"Road", location:"Gate 2", status:"Resolved", priority:2},
{user:"kashish", type:"Light", location:"Market", status:"Pending", priority:3}
];

function loadAdmin(){

let table = document.getElementById("adminTable");

let total = complaints.length;
let resolved = complaints.filter(c=>c.status=="Resolved").length;
let pending = total - resolved;
let high = complaints.filter(c=>c.priority==3).length;

document.getElementById("total").innerText = total;
document.getElementById("resolved").innerText = resolved;
document.getElementById("pending").innerText = pending;
document.getElementById("highPriority").innerText = high;

table.innerHTML="";

complaints.forEach((c,i)=>{
table.innerHTML += `
<tr>
<td>${c.user}</td>
<td>${c.type}</td>
<td>${c.location}</td>
<td><span class="badge ${c.status}">${c.status}</span></td>
<td>${c.priority}</td>
<td>
<button class="action-btn update-btn" onclick="updateStatus(${i})">Update</button>
</td>
</tr>
`;
});

}

function updateStatus(index){
let newStatus = prompt("Enter new status (Pending/Resolved):", complaints[index].status);
if(newStatus=="Pending" || newStatus=="Resolved"){
 complaints[index].status = newStatus;
 loadAdmin();
 alert("Status Updated!");
}else{
 alert("Invalid Status!");
}
}

loadAdmin();
