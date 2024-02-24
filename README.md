# Tic-Tac-Toe-Game-in-c-
This C++ program implements a simple console-based Tic Tac Toe game for two players. Players can enter their moves by specifying the row and column where they want to place their mark ('X' or 'O'). The game supports multiple rounds and prompts users if they want to play again after each round.

How to Use
Clone the Repository:

bash:

git clone https://github.com/your-username/tic-tac-toe-game.git
Compile the Code:

bash:

g++ main.cpp -o tic_tac_toe
Run the Program:

bash:

./tic_tac_toe
Enter Player Names:

Players will be prompted to enter their names at the beginning of the game.
Gameplay:

Players take turns entering their moves by specifying the row and column.
The game will check for a win or a tie after each move.

Play Again:

After each round, the program will ask if the players want to play again.
Enter 'Y' or 'y' to play again, or 'N' or 'n' to exit the game.
Code Explanation
printBoard(char board[3][3]): Function to print the current state of the Tic Tac Toe board.

checkWin(char board[3][3], char player): Function to check if a player has won by checking rows, columns, and diagonals.

isBoardFull(char board[3][3]): Function to check if the board is full, indicating a tie.

Main game loop:

Players take turns entering moves until there is a winner or a tie.
After each round, players have the option to play again.

Example:
cpp

#include<iostream>
#include<iomanip>

// ... (your code)

int main() {
    // ... (rest of code)

    char exit;
    bool playAgain = true;

    while (playAgain) {
        // ... (game loop)

        cout<<"\n DO YOU WISH TO PLAY AGAIN? (Y/N) ";
        cin>>exit;

        if (exit == 'Y' || exit == 'y') {
            playAgain = true;

            // Reset the game board for a new round
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = ' ';
                }
            }
        } else {
            playAgain = false;
        }
    }

    // ... ( rest of code)

    return 0;
}
Author:

{ Abdul Ahad }

Feel free to contribute, report issues, or suggest improvements! 🎮
