// Vincent Ridpath
// Adventure in C++

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int RollDie(int sides = 6) { return rand() % sides + 1; }

string askYesNo(string question) {
  cout << question;
  string yesNo = "";
  cin >> yesNo;
  return yesNo;
}

int main() {
  srand(time(0));

  int health = 10;
  int gold = 0;
  int turns = 0;
  string yesNo = "";

  yesNo = askYesNo("Would you like to go adventuring? (y/n)\n");

  while (yesNo == "y") { // Adventure loop
    turns += 1;
    cout << "An orc attacks you!\n";
    int playerRoll = RollDie(); // Block
    int orcRoll = RollDie();    // Attack
    cout << "The orc attacks with a roll of " << orcRoll << "!\n";
    cout << "You try to block with a roll of " << playerRoll << "!\n";
    if (playerRoll >= orcRoll) {
      cout << "You successfully block the attack!\n";
      cout << "You run away from the battle, losing 1 health and finding some "
              "gold.\n";
      gold += RollDie();
    } else {
      cout << "You did not block the attack!\n";
      health = health - orcRoll;
    }

    if (health <= 0) {
        cout << "The orc defeated you!.\n";
        break;
    } else {
        cout << "Your health is now " << health << ".\n";
    }

    yesNo = askYesNo("Would you like to keep adventuring? (y/n)\n");
  }

  // After adventure
  if (health <= 0) { // If player is dead
    cout << "You are dead!\n";
    cout << gold << " gold was left by your body.\n";
  } else {
    if (health < 5) {
      cout << "You are alive... barely. You should see a doctor.\n";
    } else {
      cout << "You are alive!\n";
    }
    cout << "You lasted " << turns << " turns.\n";
    cout << "You stopped with " << gold << " gold.\n";
  }
}