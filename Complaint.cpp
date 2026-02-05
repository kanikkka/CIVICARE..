#include <iostream>
#include <fstream>
#include <string>
#include "Reward.h"

using namespace std;

class Complaint {

public:
    int priority;
    string username;
    string type;
    string location;
    string description;
    string status;

    // ---------------- ADD COMPLAINT ----------------
    void addComplaint(string currentUser) {

        username = currentUser;

        cout << "\n--- Add New Complaint ---\n";

        cout << "Complaint Type (Road/Water/Light/Garbage): ";
        cin >> type;
        cin.ignore();

        cout << "Location: ";
        getline(cin, location);

        cout << "Description: ";
        getline(cin, description);

        status = "Pending";

        // Priority Logic
        if (type == "Water" || type == "Light")
            priority = 3;
        else if (type == "Road")
            priority = 2;
        else
            priority = 1;

        ofstream file("../data/complaints.json", ios::app);

        if (!file.is_open()) {
            cout << "Error opening complaints file!\n";
            return;
        }

        file << "{\n";
        file << "  \"username\": \"" << username << "\",\n";
        file << "  \"type\": \"" << type << "\",\n";
        file << "  \"location\": \"" << location << "\",\n";
        file << "  \"priority\": " << priority << ",\n";
        file << "  \"status\": \"" << status << "\",\n";
        file << "  \"description\": \"" << description << "\"\n";
        file << "},\n";

        file.close();

        // Reward system
        Reward r;
        r.addReward(currentUser, type);

        cout << "\n✅ Complaint Added Successfully!\n";
    }

    // ---------------- VIEW COMPLAINTS (BASIC) ----------------
    void viewComplaints(string currentUser) {

        ifstream file("../data/complaints.json");

        if (!file.is_open()) {
            cout << "No complaints data found!\n";
            return;
        }

        string line;
        bool found = false;

        cout << "\n----- YOUR COMPLAINTS -----\n";

        while (getline(file, line)) {
            if (line.find("\"username\": \"" + currentUser + "\"") != string::npos) {
                found = true;
                cout << line << endl;
            }
        }

        if (!found)
            cout << "No complaints found for you!\n";

        file.close();
    }

    // ---------------- DEPARTMENT LOGIC ----------------
    string getDepartment(string type) {

        if (type == "Water")
            return "Water Department";
        if (type == "Light")
            return "Electricity Department";
        if (type == "Road")
            return "Road Department";

        return "Sanitation Department";
    }
};
