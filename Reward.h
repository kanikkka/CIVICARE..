#ifndef REWARD_H
#define REWARD_H
#include <iostream>
#include <fstream>
using namespace std;

class Reward {

public:

    int calculatePoints(string type) {

        if(type == "Water" || type == "Light")
            return 20;        // high impact

        if(type == "Road")
            return 15;

        return 10;            // garbage etc
    }

    float convertToDiscount(int points) {
        // 100 points = ₹50 discount
        return (points / 100.0) * 50;
    }

    void addReward(string username, string type) {

        int newPoints = calculatePoints(type);

        ifstream file("../data/users.txt");
        ofstream temp("../data/temp.txt");

        string u, p;
        int points;
        float discount;

        while(file >> u >> p >> points >> discount) {

            if(u == username) {
                points += newPoints;
                discount = convertToDiscount(points);
            }

            temp << u << " "
                 << p << " "
                 << points << " "
                 << discount << endl;
        }

        file.close();
        temp.close();

        remove("../data/users.txt");
        rename("../data/temp.txt", "../data/users.txt");

        cout << "\nReward Added: " << newPoints << " points";
        cout << "\nTotal Discount: Rs " << discount << endl;
    }

    void viewWallet(string username) {

        ifstream file("../data/users.txt");

        string u, p;
        int points;
        float discount;

        while(file >> u >> p >> points >> discount) {

            if(u == username) {

                cout << "\n===== WALLET =====\n";
                cout << "User: " << u << endl;
                cout << "Points: " << points << endl;
                cout << "Bill Discount: Rs " << discount << endl;

                break;
            }
        }

        file.close();
    }
};

#endif
