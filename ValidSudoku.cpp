#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char > >& board) {
        int sign[10]; //±Í÷æ
        //Test Row
        for(int row = 0; row < 9; row++){ 
                for(int i = 1; i <= 9; i++) sign[i] = 0; 
                for(int col = 0; col < 9; col++) 
                        if(board[row][col] != '.') sign[board[row][col]-'0']++;
                for(int i = 1; i <= 9; i++)
                        if(sign[i] > 1) return false;
        }
        //Test Column
        for(int col = 0; col < 9; col++) { 
                for(int i = 1; i <= 9; i++) sign[i] = 0; 
                for(int row = 0; row < 9; row++)
                        if(board[row][col] != '.') sign[board[row][col]-'0']++;
                for(int i = 1; i <= 9; i++)
                        if(sign[i] > 1) return false;
        }
        //Test sub grid
        for(int row_base = 0; row_base <= 6; row_base += 3)
            for(int col_base = 0; col_base <= 6; col_base += 3)
            {
                    for(int i = 1; i <= 9; i++) sign[i] = 0; 
                    for(int row = 0; row < 3; row++)
                            for(int col = 0; col < 3; col++)
                                    if(board[row_base+row][col_base+col] != '.') sign[board[row_base+row][col_base+col]-'0']++;
                    for(int i = 1; i <= 9; i++)
                            if(sign[i] > 1) return false; 
            }
        return true;
    }
};
int main()
{
  Solution c;
  
  while(1);
  return 1;   
}

