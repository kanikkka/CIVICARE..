function login(){
    let username = document.getElementById("username").value;
    let password = document.getElementById("password").value;

    if(username=="" || password==""){
        alert("Please fill all fields");
        return;
    }

    // Temporary demo login
    if(username=="admin" && password=="admin"){
        alert("Admin login successful!");
        window.location.href="admin.html";
    } else {
        alert("Login successful!");
        window.location.href="../index.html";
    }
}
