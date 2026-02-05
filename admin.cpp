#include <iostream>
#include <fstream>
#include<queue>
#include<vector>
using namespace std;
struct Node{
    string user;
    string type;
    string location;
    int priority;
    bool operator<(const Node&n) const{
        return priority < n.priority;

    }
};

class Admin {

public:

void viewAll() {

    ifstream file("../data/complaints.txt");

    string user, type, location, status, desc;
    int priority;

    cout << "\n---- ALL COMPLAINTS ----\n";

    while(file >> user >> type >> location >> priority >> status) {

        getline(file, desc);

        cout << "\nUser: " << user;
        cout << "\nType: " << type;
        cout << "\nLocation: " << location;
        cout << "\nPriority: " << priority;
        cout << "\nStatus: " << status;
        cout << "\nDesc: " << desc;
        cout << "\n----------------------\n";
    }

    file.close();
}

void updateStatus() {

    string targetUser, targetLocation;

    cout << "Username: ";
    cin >> targetUser;

    cout << "Location: ";
    cin >> targetLocation;

    ifstream file("../data/complaints.txt");
    ofstream temp("../data/temp.txt");

    string user, type, location, status, desc;
    int priority;

    while(file >> user >> type >> location >> priority >> status) {

        getline(file, desc);

        if(user == targetUser && location == targetLocation)
            status = "Resolved";

        temp << user << " "
             << type << " "
             << location << " "
             << priority << " "
             << status << " "
             << desc << endl;
    }

    file.close();
    temp.close();

    remove("../data/complaints.txt");
    rename("../data/temp.txt", "../data/complaints.txt");

    cout << "Updated!\n";
}
void slowDepartment() {

    ifstream file("../data/complaints.txt");

    string user, type, location, status, desc;
    int priority;

    int water = 0, light = 0, road = 0, garbage = 0;

    while(file >> user >> type >> location >> priority >> status) {

        getline(file, desc);

        if(status == "Pending") {

            if(type == "Water") water++;
            else if(type == "Light") light++;
            else if(type == "Road") road++;
            else garbage++;
        }
    }

    file.close();

    cout << "\n---- PENDING COUNT ----\n";
    cout << "Water: " << water << endl;
    cout << "Light: " << light << endl;
    cout << "Road: " << road << endl;
    cout << "Garbage: " << garbage << endl;

    string slow = "Water";
    int max = water;

    if(light > max) { max = light; slow = "Light"; }
    if(road > max) { max = road; slow = "Road"; }
    if(garbage > max) { max = garbage; slow = "Garbage"; }

    cout << "\n⚠ Slowest Department: " << slow << endl;
}
void fakeDetector() {

    ifstream file("../data/complaints.txt");

    string user, type, location, status, desc;
    int priority;

    string checkUser, checkLocation, checkType;

    cout << "Enter user to check: ";
    cin >> checkUser;

    int count = 0;

    while(file >> user >> type >> location >> priority >> status) {

        getline(file, desc);

        if(user == checkUser)
            count++;
    }

    file.close();

    if(count >= 3)
        cout << "⚠ ALERT: Possible Fake Complaints!\n";
    else
        cout << "User looks genuine 👍\n";
}

void priorityDashboard() {

    ifstream file("../data/complaints.txt");

    priority_queue<Node> pq;

    string user, type, location, status, desc;
    int priority;

    while(file >> user >> type >> location >> priority >> status) {

        getline(file, desc);

        if(status == "Pending") {

            Node n;
            n.user = user;
            n.type = type;
            n.location = location;
            n.priority = priority;

            pq.push(n);
        }
    }

    file.close();

    cout << "\n NEXT TO RESOLVE (SMART ORDER)\n";

    while(!pq.empty()) {

        Node n = pq.top();
        pq.pop();

        cout << "\nUser: " << n.user;
        cout << "\nType: " << n.type;
        cout << "\nLocation: " << n.location;
        cout << "\nPriority: " << n.priority;
        cout << "\n----------------------\n";
    }
}


};
