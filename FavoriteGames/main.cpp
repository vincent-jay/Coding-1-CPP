#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
    vector<string> favoriteGames;
    string input = "";
    cout << "Welcome to your favorite games list.\n";
    
    while(true) {
        cout << "What would you like to do?\n";
        cout << "(add, show, remove, quit)\n";

        cin >> input;

        if (input == "add") {
            cout << "What game would you like to add?\n";
            cin >> input;
            favoriteGames.push_back(input);
        }
        else if (input == "show") {
            if (favoriteGames.size() > 0) {
                cout << "Favorite Games: \n";
                for (int i = 0; i < favoriteGames.size(); i += 1) {
                    cout << i + 1 << ". " << favoriteGames[i] << "\n";
                }
            }
            else {
                cout << "You don't have any games in your list.\n";
            }
        }
        else if (input == "remove") {
            if (favoriteGames.size() > 0) {
                favoriteGames.pop_back();
                cout << "Removed last game from list.\n";
            }
            else {
                cout << "You don't have any games in your list.\n";
            }
        }
        else if (input == "quit") {
            cout << "Goodbye!\n";
            break;
        }

        
    }

    
}