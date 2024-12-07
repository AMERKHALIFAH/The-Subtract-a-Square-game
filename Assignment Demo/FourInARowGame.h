#include "BoardGame_Classes.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class FourInARowGame : public Board<char> {
private:
    vector<vector<char>> grid; // 7x6 game board
    string playerNames[2];          // Names of the players
    char symbols[2];                     // Symbols for the players ('X', 'O')
    bool isComputer[2];                  // Tracks if a player is a computer
    int currentPlayer;                   // Tracks the current player (0 or 1)

public:
    FourInARowGame(string player1, string player2, bool player1IsComputer, bool player2IsComputer) {
        grid = std::vector<vector<char>>(6, vector<char>(7, ' '));
        playerNames[0] = player1;
        playerNames[1] = player2;
        symbols[0] = 'X';
        symbols[1] = 'O';
        isComputer[0] = player1IsComputer;
        isComputer[1] = player2IsComputer;
        currentPlayer = 0; // Player 1 starts
        srand(time(nullptr)); // Seed for random moves
    }

    // Display the board
    void display_board() override {
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                cout << (cell == ' ' ? '.' : cell) << " ";
            }
            cout << "\n";
        }
        cout << "0 1 2 3 4 5 6\n"; // Column labels for input
    }

    // Update the board with a move
    bool update_board(int col, int unused, char symbol) override {
        if (col < 0 || col >= 7 || grid[0][col] != ' ') return false;

        for (int row = 5; row >= 0; --row) {
            if (grid[row][col] == ' ') {
                grid[row][col] = symbol;
                return true;
            }
        }
        return false;
    }

    // Check for a win
    bool is_win() override {
        for (int row = 0; row < 6; ++row) {
            for (int col = 0; col < 7; ++col) {
                char curr = grid[row][col];
                if (curr == ' ') continue;

                // Check horizontal
                if (col + 3 < 7 &&
                    curr == grid[row][col + 1] &&
                    curr == grid[row][col + 2] &&
                    curr == grid[row][col + 3])
                    return true;

                // Check vertical
                if (row + 3 < 6 &&
                    curr == grid[row + 1][col] &&
                    curr == grid[row + 2][col] &&
                    curr == grid[row + 3][col])
                    return true;

                // Check diagonal (\)
                if (row + 3 < 6 && col + 3 < 7 &&
                    curr == grid[row + 1][col + 1] &&
                    curr == grid[row + 2][col + 2] &&
                    curr == grid[row + 3][col + 3])
                    return true;

                // Check diagonal (/)
                if (row + 3 < 6 && col - 3 >= 0 &&
                    curr == grid[row + 1][col - 1] &&
                    curr == grid[row + 2][col - 2] &&
                    curr == grid[row + 3][col - 3])
                    return true;
            }
        }
        return false;
    }

    // Check for a draw
    bool is_draw() override {
        for (int col = 0; col < 7; ++col) {
            if (grid[0][col] == ' ') return false;
        }
        return true;
    }

    // Check if the game is over
    bool game_is_over() override {
        return is_win() || is_draw();
    }

    // Play the game
    void play_game() {
        while (true) {
            display_board();
            cout << playerNames[currentPlayer] << " (" << symbols[currentPlayer] << "), it's your turn.\n";

            int col;
            if (isComputer[currentPlayer]) { // Random computer player
                do {
                    col = rand() % 7; // Random column
                } while (!update_board(col, 0, symbols[currentPlayer]));
                cout << "Computer chose column " << col << ".\n";
            } else { // Human player
                do {
                    cout << "choose a column (0-6): ";
                    cin >> col;
                } while (!update_board(col, 0, symbols[currentPlayer]));
            }

            // Check for a win
            if (is_win()) {
                display_board();
                cout << playerNames[currentPlayer] << " wins!\n";
                break;
            }

            // Check for a draw
            if (is_draw()) {
                display_board();
                cout << "It's a draw!\n";
                break;
            }

            // Switch player
            currentPlayer = 1 - currentPlayer;
        }
    }
};