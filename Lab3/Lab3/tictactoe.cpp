#include <iostream>
#include "tictactoe.h"
using namespace std;

int main(int argc, const char * argv[]) {
   
   const int MAX_MOVES = 9;   // maximum number of moves on the board
   char board[3][3] = {0};    // matrix of game board
   
   cout << "  - TicTacToe - " << endl;
   int playerTurn = -1;       // for tracking whos turn it is
   
   // take moves until board is full
   for (int i = 0; i < MAX_MOVES; i++) {
      int row = -1, col = -1;
      
      PrintBoard(board);
      
      playerTurn *= -1;       // keep track of whos turn it is
      while (!MoveIsValid(board, row, col)
             || row < 0 || row >= 3 || col < 0 || col >= 3) {
         
         if (playerTurn > 0) {
            cout << "\n  X's turn: ";
         }
         else {
            cout << "   O's turn: ";
         }

         GetMove(&row, &col);
         
         if (!MoveIsValid(board, row, col)) {
            cout << "That space is already taken." << endl;
         }
      }
      board[row][col] = playerTurn;    // assign value to board matrix
      
      if (CheckWinner(board) == 1) {
         cout << "X Wins!" << endl;
      }
      else if (CheckWinner(board) == -1) {
         cout << "O Wins!" << endl;
      }
      else if (CheckWinner(board) == 'T') {
         cout << "Tie." << endl;
      }
   }
   
   cout << "\n No move moves." << endl;
   
   cout << "\n\n";
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
   char yumyum = 0;     // eats up the , on user input
   cin >> *row >> yumyum >> *col;
}

// returns true if the board is empty at the requested row/col
bool MoveIsValid(char board[3][3], int row, int col) {
   return board[row][col] == 0 ? true : false;
}

char CheckWinner(char board[3][3]) {
   char winner = 'T';
   
   //     X X X
   for (int i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
         winner = board[i][0];
      }
   }

   // X
   // X
   // X
   for (int i = 0; i < 3; i++) {
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
         winner = board[0][1];
      }
   }
   
   // X                 X
   //   X      or     X
   //     X         X
   if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
       (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
      winner = board[1][1];
   }
   
   /*
   // checking the result:
   switch (winner) {
      case 'T': // tie
         break;
      case 1: // X won
         break;
      case -1: // O won
         break;
   }
*/
   return winner;
}


