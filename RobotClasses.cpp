// Vincent Ridpath, Week 11
// Coding 1
// Classes

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Classes are our own variable types

class robot {
private:
    // define variables and functions
    // data members
    string name;
    int charge;
public:
    // member functions
    void status() {
        cout << "robot: " << name << ", charge: " << charge << "\n";
    }
    // constructors (like beginPlay or Create event)
    // runs when a new instance is created 
    robot(string givenName = "Robot", int givenCharge = 5) {
        cout << "The constructor has been called.\n";
        name = givenName;
        charge = givenCharge;
        status();
    }
    // getters and setters
    void SetName(string givenName) {
        name = givenName;
    }
    void SetCharge(int givenCharge) {
        if (givenCharge > 0) {
            charge = givenCharge;
        }
        else {
            charge = 0;
        }
    }
    // getters
    string GetName() { return name; }
    int GetCharge() { return charge; }
};

int main() {
    srand(time(0));
    cout << "Let's make classes!\n";
    // create a new variable of the type "robot" named "hal"
    robot hal; // this is where the constructor function is called
    hal.SetName("Hal");
    hal.SetCharge(10);
    cout << "My robot's name is " << hal.GetName() << ".\n";
    cout << "My robot's charge is " << hal.GetCharge() << ".\n";
    hal.status();

    // create a new instance of robot and use the constructor to give it
    // a custom name an charge
    robot metalgear("Metal Gear", 8);

    vector<robot> bots;
    vector<string> names {"Rock", "Roll", "Blues", "Bass"};

    for (int i = 0; i < 10; i++) {
        string tempName = names[rand() % 4];
        int tempCharge = rand() % 10 + 1;
        bots.push_back(robot(tempName, tempCharge));
    }
    cout << "Our first bot in the list is: \n";
    bots[0].status();
}