#include <iostream>
#include <fstream>
using namespace std;

class User {
public:
    string username;
    string password;
    int rewardPoints;
    float billDiscount;

    User() {
        rewardPoints = 0;
        billDiscount = 0.0;
    }

    void registerUser() {
        cout << "\n--- New User Registration ---\n";

        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        ofstream file;
        file.open("../data/users.txt", ios::app);

        file << username << " "
             << password << " "
             << rewardPoints << " "
             << billDiscount << endl;

        file.close();

        cout << "Registration Successful!\n";
    }

    bool loginUser() {

        string u, p;
        cout << "\n--- Login ---\n";

        cout << "Username: ";
        cin >> u;

        cout << "Password: ";
        cin >> p;

        ifstream file("../data/users.txt");

        while(file >> username >> password >> rewardPoints >> billDiscount) {

            if(username == u && password == p) {
                cout << "Login Successful!\n";
                file.close();
                return true;
            }
        }

        file.close();
        cout << "Invalid Credentials!\n";
        return false;
    }
};
