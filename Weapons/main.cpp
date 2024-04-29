// Vincent Ridpath, Week 11 Wednesday Coding 1
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

// an enumerator is a custom variable type that evaluates to an integer
enum itemType {
    // equal to 0, 1, and 2 respectively
    weapon, tool, consumable
};

enum elementalType {
    // 0, 1, 2, 3, 4
    normal = 0, fire = 1, water = 2, earth = 3, air = 4
};

// create a class named enemy based on the Adventure assignment over spring break.

class item {
public: 
    itemType type;
    int damage;
    string name;
    elementalType element;
    int remainingUses;
    int healingAmount;

    item (string n = "Default", itemType t = weapon) {
        name = n; 
        type = t;

        if(type == weapon) { // calling weapon is the same as saying 0
            // calculate damage and element
            damage = rand() % 5 + 3;
            element = (elementalType)(rand() % 4 + 1); // typecast an int into elementalType
            remainingUses = 9999;
            healingAmount = 0;
        }
        else if(type == tool) {
            damage = 1;
            element = normal;
            remainingUses = rand() % 5 + 1;
            healingAmount = 0;
        }
        else if(type == consumable) {
            healingAmount = rand() % 5 + 1;
            damage = -healingAmount;
            element = normal;
            remainingUses = 1;
        }
    } // end of item constructor

    string typeToString(itemType type) {
        switch(type) {
            case weapon:
                return "weapon";
                break;
            case tool:
                return "tool";
                break;
            case consumable:
                return "consumable";
                break;
            default:
                return "unknown";
                break;
        }
        
    };
    
    string elementToString(elementalType element) {
        switch(element) {
            case fire:
                return "fire";
                break;
            case water:
                return "water";
                break;
            case earth:
                return "earth";
                break;
            case air:
                return "air";
                break;
            default:
                return "unknown";
                break;
        }
    
    };

    void Inspect() {
        cout << name << " has damage of " << damage << ", it's element is " << elementToString(element) << "\n";
        cout << "It can be used " << remainingUses << " more times, heals for " << healingAmount << "\n";
        cout << "And it is of the item type " << typeToString(type) << ".\n\n";
    }
};

class enemy {
public:
    int enemyHealth;
    item heldItem;

    enemy (item i) { // Constructor (when created event)
        enemyHealth = rand() % 11 + 10;
        heldItem = i;

    }
};


int main() {
    srand(time(0));
    int health = 20;
    
    cout << "More Classes!\n";

    vector<string> weaponNames = {"Excalibur", "Sting", "Mjolnir", "Eldritch Blade", "Spear of Destiny", "Soul Reaver", "Masamune", "Frostmourne", "Shadowmourne", "Doomhammer"};
    random_shuffle(weaponNames.begin(), weaponNames.end());

    item sword("Sword", weapon);
    sword.Inspect();

    vector<item> weapons;

    for(int i = 0; i < weaponNames.size(); i++) {
        weapons.push_back(item(weaponNames[i], weapon)); // create a weapon
        weapons[i].Inspect(); // inspect newly created weapon
    }

    // Start player vs enemy battle

    item playerWeapon("Lightsaber", weapon);
    playerWeapon.Inspect();
    item playerItem("Blue Milk", consumable);
    item enemyWeapon("Blaster", weapon);
    enemy stormtrooper(enemyWeapon);
    bool fighting = true;

    cout << "You enter a fight with a stormtrooper!\n";
    while (fighting == true) {
        cout << "Your health: " << health << ".\n";
        cout << "Enemy health: " << stormtrooper.enemyHealth << ".\n";
        cout << "Attack or use healing item?\n";
        cout << "(a/h) (Case sensitive)\n";
        string input = "";
        cin >> input;
        if(input == "a") {
            if (playerWeapon.remainingUses > 0) {
                stormtrooper.enemyHealth -= playerWeapon.damage;
                playerWeapon.remainingUses -= 1;
                cout << "Stormtrooper lost " << playerWeapon.damage << " health!\n";
            }
            else {
                cout << "You are out of uses for that item.\n";
            }
        }
        else if(input == "h") {
            if (playerItem.remainingUses > 0) {
                health += playerItem.healingAmount;
                playerItem.remainingUses -= 1;
                cout << "You drank " << playerItem.name << " and gained " << playerItem.healingAmount << " health!\n";
            }
            else {
                cout << "You are out of uses for that item.\n";
            }
        }
        else {
            cout << "Incorrect/misunderstood input. Turn skipped.\n";
        }

        // Enemy attack starts here

        if (stormtrooper.enemyHealth > 0) {
            health -= stormtrooper.heldItem.damage;
            cout << "You were attacked for " << stormtrooper.heldItem.damage << " damage!\n";
        }
        else {
            cout << "Stormtrooper was defeated!\n";
            cout << "You had " << health << " health left.\n";
            break;
        }  

        // Check if player is dead

        if (health < 1) {
            cout << "The stormtrooper defeated you.\n";
            cout << "They had " << stormtrooper.enemyHealth << " health left.\n";
            break;
        }

    }

    
    


    /* RECAP
        enumerators are a custom variable type with a limited number of possible values
        switch statements map all possible outcomes to a single test.
        classes can have other classes inside of them (enemy can hold an item)
        typecasting is when we want the compiler to try to change a variable into another variable.
        AI is great for generating a vector of names.
    /

    / HOMEWORK
        create BASIC adventure functionality using the enemy class for each encounter.
        each enemy must use a weapon.
        each enemy has health.
        player has option of using weapon or consumable
        at least one encounter, to the death.

        i am grading based on the enemy class, does it have the functionality that it needs
        to interact with the player
    */
    

}