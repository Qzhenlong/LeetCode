#include<iostream>
#include<vector>
using namespace std;
/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
解析：N皇后问题，保证棋盘上的N个皇后无法互相攻击
思路：从1到N的全排列中去掉不符合条件的可能即可， 用一个数组记录每一行皇后的位置，(i, pos[i])表示第i行皇后位于第pos[i]列中
排除的方法：
设当前行为r, 则之前行中的皇后与当前后的冲突的位置有三个pos[i], pos[i]-(r-i), pos[i]+(r-i),后两个可能不在棋盘内，所以要判断一下。
*/

class Solution {
public:
    vector<vector<string > > solveNQueens(int n) {
        vector<vector<string > > ans;
		vector<int > pos;
		if(n <= 0) return ans;
		fun(ans, pos, n);
		return ans;
    }
	void fun(vector<vector<string > > &ans, vector<int > &pos, int n){ //r为当前行号
		int r = pos.size();
		if(r >= n){ //找到一个解
		    vector<string > OneAns;
			string cur = "";
			for(int i = 0; i < n; i++) cur += '.'; //初始化为全.
			for(int i = 0; i < n; i++){
				if(i == 0) cur[pos[i]] = 'Q';
				else{
					cur[pos[i-1]] = '.';
					cur[pos[i]] = 'Q';
				}
				OneAns.push_back(cur);
			}
			ans.push_back(OneAns);
			return;
		}
		vector<bool > isValid(n, true); //是否为有效位置
		for(int i = 0; i < r; i++){
			isValid[pos[i]] = false;
			if((pos[i]-(r-i)) >= 0) isValid[pos[i]-(r-i)] = false;
			if((pos[i]+(r-i)) < n) isValid[pos[i]+(r-i)] = false;
		}
		for(int i = 0; i < n; i++){
			if(isValid[i]){
				pos.push_back(i);
				fun(ans, pos, n);
				pos.pop_back();
			}
		}
		
	}
};

int main(){
	Solution c;
	vector<vector<string > > ans = c.solveNQueens(4);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << endl;
		}
		cout << "***********************************" << endl;
	}
	cout << "Total Number: " << ans.size() << endl;
	return 0;
}
