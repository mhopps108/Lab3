/* Matt Hopps
 * CECS 282 Lab3
 * 2/12/15
 */
#include <iostream>
#include "tictactoe.h"
using namespace std;

int main(int argc, const char * argv[]) {
   const int MAX_MOVES = 9;   // maximum number of moves on the board
   char board[3][3] = {0};    // matrix of game board
   int playerTurn = -1;       // for tracking whos turn it is
   int movesPlayed = 0;       // number of moves played so far
   char winner = 0;           // winning player
   int row = -1, col = -1;    // set row and col to invalid position
   
   cout << "  - TicTacToe - " << endl;
   // loop until there is a winner or no moves left
   while (winner == 0 && movesPlayed < MAX_MOVES) {
      
      PrintBoard(board);
      playerTurn *= -1;       // switch players each completed loop
      
      // ask for move from a player until valid move played
      do {
         if (playerTurn > 0) {
            cout << "\n X's turn: ";
         }
         else {
            cout << "\n O's turn: ";
         }
         
         GetMove(&row, &col);
         
         if (!MoveIsValid(board, row, col)) {
            cout << " That space is already taken." << endl;
         }
         
      } while (!MoveIsValid(board, row, col));
      
      board[row][col] = playerTurn;    // assign player value to board matrix
      winner = CheckWinner(board);     // checks for a winner
      movesPlayed++;                   // increment moves played in game
   }
   
   // game over print final board and results of game
   PrintBoard(board);
   PrintResults(winner);

   cout << endl << endl;
   return 0;
}

// takes a 2-dimensional array and prints it
void PrintBoard(char board[3][3]) {
   cout << "\n    0  1  2 " << endl;
   cout << "   ----------" << endl;
   for (int i = 0; i < 3; i++) {
      cout << " " << i << "|";
      for (int j = 0; j < 3; j++) {
         if (board[i][j] == 1) {
            cout << " X ";
         }
         else if (board[i][j] == -1) {
            cout << " O ";
         }
         else {
            cout << " . ";
         }
      }
      cout << " | " << endl;
   }
   cout << "   ----------" << endl;
}

// use cin to read the user's choice for where to move next on the board
void GetMove(int *row, int *col) {
   char yumyum = 0;     // eats up the ',' in user input
   cin >> *row >> yumyum >> *col;
}

// returns true if the board is empty at the requested row/col
bool MoveIsValid(char board[3][3], int row, int col) {
   return board[row][col] == 0 ? true : false;
}

// returns char value of a winner after searching the board
char CheckWinner(char board[3][3]) {
   char winner = 0;
   
   // check for vertical wins
   for (int i = 0; i < 3; i++) {
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
         winner = board[0][i];
      }
   }
   
   // check for horizontal wins
   for (int i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
         winner = board[i][1];
      }
   }
   
   // check for cross wins
   if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
       (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
      winner = board[1][1];
   }
   
   return winner;
}

// outputs the results of the game, the winner or tie
void PrintResults(char winner) {
   if (winner == 1) {
      cout << "\n ** X Wins! **" << endl;
   }
   else if (winner == -1) {
      cout << "\n ** O Wins! **" << endl;
   }
   else { // if tie game
      cout << "\n BOO! Tie, no move moves." << endl;
   }
}