#include <iostream>
#include <fstream>
using namespace std;

class Department {

public:

    void performanceReport() {

        ifstream file("../data/complaints.txt");

        string user, type, location, status, desc;
        int priority;

        int water=0, light=0, road=0, garbage=0;

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

        cout << "\n===== DEPARTMENT PERFORMANCE =====\n";

        cout << "Water Department Pending: " << water << endl;
        cout << "Electricity Pending: " << light << endl;
        cout << "Road Department Pending: " << road << endl;
        cout << "Sanitation Pending: " << garbage << endl;

        cout << "\n---- SLOWEST DEPARTMENT ----\n";

        int max = water;
        string slow = "Water Department";

        if(light > max) {
            max = light;
            slow = "Electricity Department";
        }

        if(road > max) {
            max = road;
            slow = "Road Department";
        }

        if(garbage > max) {
            max = garbage;
            slow = "Sanitation Department";
        }

        cout << "Most Slow: " << slow << endl;
    }
};
