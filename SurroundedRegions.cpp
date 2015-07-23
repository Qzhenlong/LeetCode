#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
/*
题目：
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

解析：给定一个包含‘X'和’O‘的二维矩阵，找到所有被'X'包围的区域，并将区域内的O全部变为X

思路：查找所有由’O‘建成的连通子图，如果子图中的元素没有边界的元素，说明必然被’X‘包围，可将该区域全部设置为X
    与Number of Islands一题的思路相似
(1)将用一个整型的矩阵来对应原char矩阵，'X'为1，‘O’为0
(2)遍历一次，将整型矩阵中由0构成的每个连通子图用其它整数唯一标识，如第一个连通子图将0全部变2，第二个连通子图将0全部变为3...
(3)为一个哈希表记录第每个连通子图是否被1包围（即被'X'包围）是则将记为true，否则记为false
(4)最后扫描原矩阵，将被包围的‘O’全部更新为'X'
时间复杂度O(n)
*/
class Solution {
public:
	//一直提示Runtime Error，原因未发现
    void solve(vector<vector<char > >& board) {
        if(board.size() == 0) return;
		int m = board.size(), n = board[0].size(), index = 2;
		vector<vector<int > > intboard(m, vector<int >(n, 1));
	    vector<bool > isSurrounded;
		isSurrounded.push_back(false);
		isSurrounded.push_back(false);
		//转存
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(board[i][j] == 'O') intboard[i][j] = 0;
				
		//查找
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				if(intboard[i][j] == 0){
					isSurrounded.push_back(true);
					dfs(intboard, isSurrounded, index, i, j);
					index++;
				}
		}
		//更新
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(isSurrounded[intboard[i][j]]) board[i][j] = 'X';
		
    }
	void dfs(vector<vector<int > > &board, vector<bool > &isSurrounded, int index, int x, int y){
		if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 0) return;
		if((x-1) < 0 || (x+1) >= board.size() || (y-1) < 0 || (y+1) >= board[0].size()) isSurrounded[index] = false;	
        board[x][y] = index;			
		dfs(board, isSurrounded, index, x-1, y);
		dfs(board, isSurrounded, index, x, y-1);
		dfs(board, isSurrounded, index, x+1, y);
		dfs(board, isSurrounded, index, x, y+1);
	}
	
	//
    void _solve(vector<vector<char > >& board) {
        if(board.size() == 0) return;
		int m = board.size(), n = board[0].size();
		vector<vector<int > > intboard(m, vector<int >(n, 1));
		vector<pair<int, int > > index;
	    bool isSurrounded;
		//转存
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(board[i][j] == 'O') intboard[i][j] = 0;
				
		//更新
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				if(intboard[i][j] == 0){
					isSurrounded = true;
					_dfs(intboard, isSurrounded, index, i, j);
					if(isSurrounded)
						for(int k = 0; k < index.size(); k++) board[index[k].first][index[k].second] = 'X';
					index.clear();
				}
		}
		
    }
	void _dfs(vector<vector<int > > &board, bool &isSurrounded, vector<pair<int, int> > &index, int x, int y){
		if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != 0) return;
		if((x-1) < 0 || (x+1) >= board.size() || (y-1) < 0 || (y+1) >= board[0].size()) isSurrounded = false;	
        index.push_back(make_pair(x, y));
		board[x][y] = 1;
		_dfs(board, isSurrounded, index, x-1, y);
		_dfs(board, isSurrounded, index, x, y-1);
		_dfs(board, isSurrounded, index, x+1, y);
		_dfs(board, isSurrounded, index, x, y+1);	
	}
	//上面还是Runtime Error，想想可以换个思路，直接找出那些没被包围的地方就行了，剩下的就是被包围的
    void __solve(vector<vector<char > >& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
		int m = board.size(), n = board[0].size();
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
                if (i == 0 || j == 0 || i == m-1 || j == n-1) //在边上的连通图一定是没有被包围的
                   // __dfs(board, i, j); 
					bfs(board, i, j);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = (board[i][j] == 'T') ? 'O' : 'X';
    }
    
	void __dfs(vector<vector<char > > &grid, int x, int y){
		if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 'O') return;
		grid[x][y] = 'T';
		__dfs(grid, x+1, y); //四个方向
		__dfs(grid, x, y+1);
		__dfs(grid, x-1, y);
		__dfs(grid, x, y-1);
	}
	//!还是RunTime Error，难怪这道题通过率这么低，不能用dfs，就用bfs吧
    void bfs(vector<vector<char > > &board, int row, int col) {
        if (board[row][col] != 'O') return;
        int N = board.size(), M = board[0].size();
        queue<pair<int, int> > q;
        q.push(make_pair(row, col));
        while (!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i < 0 || i >= N || j < 0 || j >= M) continue;
            if (board[i][j] != 'O') continue;// important to recheck!
            board[i][j] = 'T';
            q.push(make_pair(i-1, j));
            q.push(make_pair(i+1, j));
            q.push(make_pair(i, j-1));
            q.push(make_pair(i, j+1));
        }
    }
};

int main(){
	Solution c;
	const int n = 4;
	char A[][n] = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'},
	};
	vector<vector<char > > grid;
	for(int i = 0; i < sizeof(A)/ n; i++){
		vector<char > cur;
		for(int j = 0; j < n; j++){
			cur.push_back(A[i][j]);
			cout << A[i][j] << " ";
		}
		cout << endl;
		grid.push_back(cur);
	}
	cout << endl;
	c.__solve(grid);
	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < grid[i].size(); j++)
			cout << grid[i][j] << " ";
		cout << endl;
	}
	return 0;
}


