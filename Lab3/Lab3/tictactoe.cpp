#include <iostream>
#include "tictactoe.h"
using namespace std;


int main(int argc, const char * argv[]) {
   
   char board[3][3] = {0};
   board[0][0] = 'X';
   board[2][2] = 'O';
   PrintBoard(board);

   
   cout << "\n\n";
   return 0;
}


// PrintBoard takes a 2-dimensional array parameter representing the game state
// and prints it to cout. See the spec for details on formatting the output.
void PrintBoard(char board[3][3]) {
   cout << " - 0  1  2 " << endl;
   for (int i = 0; i < 3; i++) {
      cout << " " << i;
      for (int j = 0; j < 3; j++) {
         if (board[i][j] == 0) {
            cout << " . ";
         }
         else {
            cout << " " << board[i][j] << " ";
         }
      }
      cout << endl;
   }
}

// GetMove uses cin to read the user's choice for where to move next on the
// board. It does NOT update the game board with the move choice; it simply
// scans in values to the row and col variables, which will update whatever
// variables were used as arguments in the main. Do not check move validity
// in this function.
void GetMove(int *row, int *col) {
   
}

// MoveIsValid returns true if the board is empty at the requested row/col,
// and false otherwise. Used in main to see if the move is valid and alert
// the user if it is not.
bool MoveIsValid(char board[3][3], int row, int col) {
   
   return true;
}