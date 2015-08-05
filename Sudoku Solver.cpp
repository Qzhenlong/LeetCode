#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

�������Ź���ÿһ���ж�������1-9�ķ�Χ�ڣ���ֻ����һ�Ρ�����1-9��ÿ���ӹ�����ֻ����һ�Σ�

��1�������

��2�������

��3�����9���ӹ���

˼·����Valid Sodoku��ͬ�����������Ź�����N�ʺ��������ƣ��ɲ��õݹ����
˼·�����������ϵ����ۣ���Ϊ��Ŀ���뱣֤����ֻ��һ���⣬������̽ÿһ�����ӵ�ʱ��ֻ��Ҫ���ǵ�ǰ�С��С����ο���������������ͽ�����һ��������̽����������ݡ�
ע���ж�һ�����������ĸ����ο����ƣ�ǰ��һ������˱Ƚ�trivial�ķ�����
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
		for(int i = 0; i < 9; ++i) //��Ԫ�ض���board[row][col]����
			if(board[i][col] == board[row][col] && i != row) return false;
		for(int i = 0; i < 9; ++i) //��Ԫ�ض���board[row][col]����
			if(board[row][i] == board[row][col] && i != col) return false;
		int gridRow = row/3*3, gridCol = col/3*3; //�ӹ����ڶ���board[row][col]����
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
