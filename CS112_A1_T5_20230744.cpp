//Program:The Subtract-a-Square game involves two players and a pile of coins.
//        In turns, players subtract a square number of coins from the pile until no coins remain.
//        The player making the last Resort move emerges as the winner."
//Author: Amir Fathi Hagamir Khalifah
//ID: 20230744
//Version: 1.3
//Date: 2024/3/2




#include <iostream>
#include <cmath>

using namespace std;

bool isSquare(int n) {
    if(n >= 0 && sqrt(n) == floor(sqrt(n))){
        return true;
    }
    return false;
}

int get_Valid_Move(int remaining_Coins, string player_Name){
    int invalid_Moves_Count = 0;
    int invalidMoveThreshold = 3;
    int move;

    cout << player_Name << ", pick a square number of coins: ";
    cin >> move;
    while (!isSquare(move) || move <= 0|| move > remaining_Coins){
        cout << "Invalid move: Must be a positive square number less than or equal to remaining coins." << endl;
        cout << player_Name << ", pick a square number of coins: ";
        cin >> move;
    }

    return move;
}

int main() {

    int remaining_Coins;

    while (true) {
        cout << "Welcome to Subtract-a-Square game\n";

        cout << "Choose your starting option:\n"
                     "1. Randomize starting coins\n"
                     "2. Enter starting coins manually\n"
                     "Enter your choice (1 or 2): ";

        string starting_Choice;
        cin >> starting_Choice;

        if (starting_Choice == "1" || starting_Choice == "2") {
            if (starting_Choice == "1") {
                int random_Starting_Coins = rand() % 51 + 50;
                while (isSquare(random_Starting_Coins)) {
                    random_Starting_Coins = rand() % 51 + 50;
                }
                remaining_Coins = random_Starting_Coins;
                cout << "Starting with randomly chosen " << random_Starting_Coins << " coins.\n";
            }else if (starting_Choice == "2"){
                while (true) {
                    int user_Starting_Coins;
                    cout << "Enter the starting number of coins: ";
                    cin >> user_Starting_Coins;

                    if (isSquare(user_Starting_Coins)){
                        cerr << "Error: Please enter a non-square number for the starting coins." << endl;
                    } else {
                        remaining_Coins = user_Starting_Coins;
                        cout << "Starting with manually entered " << user_Starting_Coins << " coins.\n";
                        break;
                    }
                }
            }
            break;
        } else {
            cerr << "Invalid choice. Please try again." << endl;
        }
    }

    string currentPlayer = "Player 1";

    while (remaining_Coins > 0) {
        cout << "\nThere are " << remaining_Coins << " coins remaining.\n";
        int move = get_Valid_Move(remaining_Coins, currentPlayer);
        remaining_Coins -= move;
        cout << currentPlayer << " takes " << move << " coins.\n";

        if (remaining_Coins == 0) {
            cout << "\n" << currentPlayer << " wins!\n";
            break;
        }

        // Switch players for the next round
        currentPlayer = (currentPlayer == "Player 1") ? "Player 2" : "Player 1";
    }

}


