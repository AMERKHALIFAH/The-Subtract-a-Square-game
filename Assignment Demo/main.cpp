#include <iostream>
#include "FourInARowGame.h"

using namespace std;

int main() {
    string player1Name, player2Name;
    int player1Type, player2Type;

    cout << "Welcome to the Four-in-a-Row Game! :)\n";

    // Set up Player 1
    cout << "Enter Player 1 name: ";
    cin >> player1Name;
    cout << "Choose Player 1 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> player1Type;

    switch (player1Type) {
        case 1:
            cout << player1Name << " is set as a Human Player.\n";
            break;
        case 2:
            cout << player1Name << " is set as a Random Computer Player.\n";
            break;
        default:
            cout << "Invalid choice for Player 1. Exiting the game.\n";
            return 1;
    }

    // Set up Player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    cin >> player2Type;

    switch (player2Type) {
        case 1:
            cout << player2Name << " is set as a Human Player.\n";
            break;
        case 2:
            cout << player2Name << " is set as a Random Computer Player.\n";
            break;
        default:
            cout << "Invalid choice for Player 2. Exiting the game.\n";
            return 1;
    }

    // Validate input
    if ((player1Type != 1 && player1Type != 2) || (player2Type != 1 && player2Type != 2)) {
        cout << "Invalid player type detected. Exiting the game.\n";
        return 1;
    }

    // Determine if players are human or computer
    bool player1IsComputer = (player1Type == 2);
    bool player2IsComputer = (player2Type == 2);

    // Create the game instance
    FourInARowGame* game = new FourInARowGame(player1Name, player2Name, player1IsComputer, player2IsComputer);


    game->play_game();

    // Cleanup
    delete game;

    return 0;
}