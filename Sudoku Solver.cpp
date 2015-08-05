#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

解析：九宫格，每一列行都必须在1-9的范围内，且只出现一次。数字1-9在每个子宫格中只出现一次，

（1）检查行

（2）检查列

（3）检查9个子宫格

思路：与Valid Sodoku不同，这题是填充九宫格，与N皇后问题相似，可采用递归求解
思路：（借助网上的讨论）因为题目输入保证有且只有一个解，所以试探每一个格子的时候，只需要考虑当前行、列、矩形框满足条件，满足就进入下一个格子试探，不满足回溯。
注意判断一个格子落入哪个矩形框的设计，前面一题采用了比较trivial的方法！
*/
class Solution {
public:

    void solveSudoku(vector<vector<char> > &board) {
        dfs(board);
    }
	bool dfs(vector<vector<char > > &board){
		for(int i = 0; i < 9; ++i)
			for(int j = 0; j < 9; ++j)
				if(board[i][j] == '.'){
					for(int k = 1; k <= 9; ++k){
						board[i][j] = k + '0';
						if(isValid(board, i, j) && dfs(board)) return true;
						board[i][j] = '.';
					}
					return false;
				}
		return true;
	}
	bool isValid(vector<vector<char > > &board, int row, int col){
		for(int i = 0; i < 9; ++i) //列元素都与board[row][col]不等
			if(board[i][col] == board[row][col] && i != row) return false;
		for(int i = 0; i < 9; ++i) //行元素都与board[row][col]不等
			if(board[row][i] == board[row][col] && i != col) return false;
		int gridRow = row/3*3, gridCol = col/3*3; //子宫格内都与board[row][col]不等
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 3; ++j)
				if(gridRow + i != row && gridCol + j != col && board[gridRow+i][gridCol+j] == board[row][col]) return false;
		return true;
	}
};

int main(){
	Solution c;
	
	return 0;
}
