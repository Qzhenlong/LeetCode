#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
/*
��Ŀ��
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

����������һ��������X'�͡�O���Ķ�ά�����ҵ����б�'X'��Χ�����򣬲��������ڵ�Oȫ����ΪX

˼·�����������ɡ�O�����ɵ���ͨ��ͼ�������ͼ�е�Ԫ��û�б߽��Ԫ�أ�˵����Ȼ����X����Χ���ɽ�������ȫ������ΪX
    ��Number of Islandsһ���˼·����
(1)����һ�����͵ľ�������Ӧԭchar����'X'Ϊ1����O��Ϊ0
(2)����һ�Σ������;�������0���ɵ�ÿ����ͨ��ͼ����������Ψһ��ʶ�����һ����ͨ��ͼ��0ȫ����2���ڶ�����ͨ��ͼ��0ȫ����Ϊ3...
(3)Ϊһ����ϣ���¼��ÿ����ͨ��ͼ�Ƿ�1��Χ������'X'��Χ�����򽫼�Ϊtrue�������Ϊfalse
(4)���ɨ��ԭ���󣬽�����Χ�ġ�O��ȫ������Ϊ'X'
ʱ�临�Ӷ�O(n)
*/
class Solution {
public:
	//һֱ��ʾRuntime Error��ԭ��δ����
    void solve(vector<vector<char > >& board) {
        if(board.size() == 0) return;
		int m = board.size(), n = board[0].size(), index = 2;
		vector<vector<int > > intboard(m, vector<int >(n, 1));
	    vector<bool > isSurrounded;
		isSurrounded.push_back(false);
		isSurrounded.push_back(false);
		//ת��
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(board[i][j] == 'O') intboard[i][j] = 0;
				
		//����
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				if(intboard[i][j] == 0){
					isSurrounded.push_back(true);
					dfs(intboard, isSurrounded, index, i, j);
					index++;
				}
		}
		//����
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
		//ת��
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(board[i][j] == 'O') intboard[i][j] = 0;
				
		//����
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
	//���滹��Runtime Error��������Ի���˼·��ֱ���ҳ���Щû����Χ�ĵط������ˣ�ʣ�µľ��Ǳ���Χ��
    void __solve(vector<vector<char > >& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
		int m = board.size(), n = board[0].size();
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
                if (i == 0 || j == 0 || i == m-1 || j == n-1) //�ڱ��ϵ���ͨͼһ����û�б���Χ��
                   // __dfs(board, i, j); 
					bfs(board, i, j);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] = (board[i][j] == 'T') ? 'O' : 'X';
    }
    
	void __dfs(vector<vector<char > > &grid, int x, int y){
		if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 'O') return;
		grid[x][y] = 'T';
		__dfs(grid, x+1, y); //�ĸ�����
		__dfs(grid, x, y+1);
		__dfs(grid, x-1, y);
		__dfs(grid, x, y-1);
	}
	//!����RunTime Error���ѹ������ͨ������ô�ͣ�������dfs������bfs��
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


