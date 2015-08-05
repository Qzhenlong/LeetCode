#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are 
those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

解析：给定一个二维字符数组，和一个字符串，判断该字符串是否在二维数组当中

思路：
(1)就是在二维数组里找一个给定字符串构成的连通图，如果存在则返回true,否则返回false，大部分重复的情况下，重复遍历数组多次，超时

*/

class Solution {
public:
    //Time Limit Exceeded
    bool exist(vector<vector<char > >& board, string word) {
        bool res = false;
		if(board.size() <= 0 || word.size() <= 0) return false;
		for(int i = 0; i < board.size(); i++){
			for(int j = 0; j < board[0].size(); j++){
				if(board[i][j] == word[0]) res = (res || dfs(board, word, 0, i, j));
				if(res) return res;
			}
		}
		return res;
    }
	bool dfs(vector<vector<char > > &board, string word, int i, int x, int y){
		if(i == word.size()) return true;
		if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[i]) return false;
		char tmp = board[x][y];
		board[x][y] = '#'; //访问过了
		bool isExist = dfs(board, word, i+1, x+1, y) || dfs(board, word, i+1, x, y+1) 
			|| dfs(board, word, i+1, x-1, y) || dfs(board, word, i+1, x, y-1) ;
		board[x][y] = tmp; //这样就不会Time Limit Exceeded, 不知道为什么，直接返回isExist就会超时
		return isExist;
	}
	/*
	bool dfs(vector<vector<char > > board, string word, int i, int x, int y){ //这样会超时
		if(i == word.size()) return true;
		if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[i]) return false;
		board[x][y] = '#'; //访问过了
		return dfs(board, word, i+1, x+1, y) || dfs(board, word, i+1, x, y+1) 
			|| dfs(board, word, i+1, x-1, y) || dfs(board, word, i+1, x, y-1) ;
	}
	*/

};

int main(){
	Solution c;
	const int n = 4;
	char A[][n] = {
		{'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'b'}
	};
	vector<vector<char > > grid;
	for(int i = 0; i < sizeof(A)/ n; i++){
		vector<char > cur;
		for(int j = 0; j < n; j++){
			cur.push_back(A[i][j]);
			//cout << A[i][j] << " ";
		}
		//cout << endl;
		grid.push_back(cur);
	}
	cout << c.exist(grid, "aaaaaaaaaaaaaaaaaaaa");
	return 0;
}
