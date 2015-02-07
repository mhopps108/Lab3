#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
   
   char board[3][3] = {'0','0','0','0','0','0','0','0','0'};
   
   cout << board[2][0] << board[2][1] << board[2][2] << endl;
   cout << board[1][0] << board[1][1] << board[1][2] << endl;
   cout << board[0][0] << board[0][1] << board[0][2] << endl;

   return 0;
}

