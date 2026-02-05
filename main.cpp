#include <iostream>
#include "User.cpp"
#include "Complaint.cpp"
#include "Department.cpp"
#include "Reward.h"
#include "Admin.cpp"


using namespace std;

void showMenu() {
    cout << "\n====================================\n";
    cout << "   CIVICARE - SMART CITY PORTAL\n";
    cout << "====================================\n";

    cout << "1. Citizen Login\n";
    cout << "2. Register\n";
    cout << "3. Add Complaint\n";
    cout << "4. Track Status\n";
    cout << "5. Rewards\n";
    cout << "6. Department Performance\n";
    cout << "7. Admin Panel\n";
    cout << "0. Exit\n";
}

int main() {
    int choice;

    do {
        showMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
               User u;
             u.loginUser();
               break;
}

        case 2: {
             User u;
             u.registerUser();
             break;
}

            case 3: {
    string currentUser;
    cout << "Enter your username first: ";
    cin >> currentUser;

    Complaint c;
    c.addComplaint(currentUser);
    break;
}

            case 4: {
    string user;
    cout << "Enter Username: ";
    cin >> user;

    Complaint c;
    c.viewComplaints(user);
    break;
}

case 5: {
    string user;
    cout << "Enter Username: ";
    cin >> user;

    Reward r;
    r.viewWallet(user);
    break;
}

           

            case 6: {
    Department d;
    d.performanceReport();
    break;
}
case 7: {

    Admin a;

    cout << "1. View All";
    cout << "\n2. Update Status";
    cout << "\n3. Slow Department";
    cout << "\n4. Fake Detector\n";
    cout<<"\n5. Priority Dashboard\n";
    int op;
    cin >> op;

    if(op == 1)
        a.viewAll();
    else if(op == 2)
        a.updateStatus();
    else if(op == 3)
        a.slowDepartment();
        else if(op==5)
        a.priorityDashboard();
    else
        a.fakeDetector();

    break;
}

            case 0:
                cout << "Thank You for using CiviCare\n";
                break;

            default:
                cout << "Invalid Choice! Try Again\n";
        }

    } while(choice != 0);

    return 0;
}
