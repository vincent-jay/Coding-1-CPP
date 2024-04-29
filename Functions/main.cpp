// Vincent Ridpath
// Week 7, Wednesday
// Functions

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// return type (int, in this case)
// name
// (input parameters), what variables you feed into the function
// {code}, what happens when the function is called
int triple(int number) {
    return number * 3;
}

// overload the triple function by creating another function with the same name
// return a string, function name is triple, accepts a string as parameter
// input = "Coffee", output = "CoffeeCoffeeCoffee"

string triple(string input) {
    return input + input + input;
}

string triple(string givenString, bool vertical) {
    if(vertical) {
        string output = "\n";
        for(int i = 0; i < 3; i++) {
            output += givenString + "\n";
        }
        return output;
    }
    else {
        return givenString + givenString + givenString;
    }
}

// default values instead of overloading functions
// building a function that returns a die roll
// it will return an int. it will accept one parameter (sides)
// it'll use random, so lets include that

// 6 is the default value
int DiceRoll(int sides = 6, int min = 1) {
    return rand() % sides + min;
}

int AddRecursive(int startNum) {
    if (startNum == 0) {
        return 0;
    }
    return startNum + AddRecursive(startNum - 1);
}

int main() {
    srand(time(0));

    cout << "5 + 4 + 3 + 2 + 1 = " << AddRecursive(5) << ".\n";

    
    
    cout << "What number would you like to triple?\n";
    int input = 0;
    cin >> input;
    cout << input << " tripled = " << triple(input) << ".\n";

    cout << "Triple of Vincent is " << triple("Vincent") << ".\n";

    cout << "Triple of Vincent is " << triple("Vincent", true) << "\n";

    cout << "Your d6 roll is " << DiceRoll() << ".\n";

    cout << "Your d20 roll is " << DiceRoll(20) << ".\n";

    cout << "I was born in the year " << DiceRoll(50, 1970) << ".\n";
    
}
