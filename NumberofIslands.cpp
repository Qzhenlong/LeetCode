#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and 
is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

����������һ����ά����grid�������1����½�أ�0����ˮ�����㵺�������������Ķ��壺��Χ����ˮ���ɶ��½��ˮƽ��ֱ�������������ܶ���ˮ

˼·��
��1������½�����������������б�����б����ڣ�����Ϊ��̬�滮����⣬
	dp[i][j]��ʾ�ӣ�0��0������i,j��֮��ĵ�����������״̬ת�Ʒ���Ϊ
	dp[i][j] = (dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]) + (grid[i-1][j] = 0 && grid[i][j-1] = 0 && grid[i][j] = 1) ? 1 : 0;
	dp[0][0] = grid[0][0]
��2������ͨ��ͼ����������������ȱ���, �ݹ齫ͬһ����ͼ��Ԫ������
*/

class Solution {
public:
     //����һ˼·����dp[i][j]����i,j�����Ԫ������ϵ
    int numIslands(vector<vector<char > >& grid) {
        if(grid.size() == 0) return 0;
		int m = grid.size(), n = grid[0].size();
		vector<vector<int > > dp(m, vector<int >(n, 0));
	    dp[0][0] = grid[0][0]-'0';
		for(int i = 1; i < n; i++) dp[0][i] = dp[0][i-1] + ((grid[0][i-1] == '0' && grid[0][i] == '1') ? 1 : 0);
		for(int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + ((grid[i-1][0] == '0' && grid[i][0] == '1') ? 1 : 0);
		for(int i = 1; i < m; i++){
			for(int j = 1; j < n; j++){
				dp[i][j] = (dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]) + ((grid[i-1][j] == '0' && grid[i][j-1] == '0' && grid[i][j] == '1') ? 1 : 0);
			}
		}
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}	
		return dp[m-1][n-1];
    }
	//������ȱ�������ͨ��ͼ���������鼯��
	int _numIslands(vector<vector<char > > &grid){
        if(grid.size() == 0) return 0;
		int m = grid.size(), n = grid[0].size(), ans = 0;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				if(grid[i][j] == '1'){
					dfs(grid, i, j);
					ans++;
				}
		return ans;
		
	}
	void dfs(vector<vector<char > > &grid, int x, int y){
		if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != '1') return;
		grid[x][y] = '0';
		dfs(grid, x+1, y); //�ĸ�����
		dfs(grid, x, y+1);
		dfs(grid, x-1, y);
		dfs(grid, x, y-1);
	}
};

int main(){
	Solution c;
	const int n = 3;
	int A[][n] = {
		{1,1,1},
		{0,1,0},
		{1,1,1}
		//{1,1,0,0,0},
		//{0,0,1,0,0},
		//{0,0,0,1,1},
	};
	vector<vector<char > > grid;
	for(int i = 0; i < sizeof(A)/(4*n); i++){
		vector<char > cur;
		for(int j = 0; j < n; j++){
			cur.push_back(A[i][j]+'0');
		}
		grid.push_back(cur);
	}
	
	cout << c._numIslands(grid);
	return 0;
}
