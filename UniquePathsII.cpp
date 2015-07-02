#include<iostream>
#include<vector>
using namespace std;
/*
题目：Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

解析：延续上一题，上题是说从m*n(行*列)大小的网格的左上角到达右下角，只能向上或者向右走，总共的路径数，m和n都不超过100
	这一题是在路径中加入了障碍物， 障碍物用1标记，无障碍为0

思路：还是动态规划，不过当遇到1时，则到当前点没有路径，将其置0
dp[0][0] = 0;  //只能向下或者向右
dp[0][1] = dp[0][2] = 1;
dp[1][0] = dp[2][0] = 1;
dp[1][1] = 0; 
dp[2][1] = 1
...
状态转移方程：dp[i][j] = dp[i-1][j]+dp[j][i-1];

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int > >& obstacleGrid) {
        int m = obstacleGrid.size();
		if(m <= 0) return 0;
		int n = obstacleGrid[0].size();
		int dp[m][n];
		dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;  //注意边界，如果开始就1，则没有路径了
		if(dp[0][0] == 0) return 0;
		for(int i = 1; i < m; i++) 
			if(dp[i-1][0] == 0 || obstacleGrid[i][0] == 1) dp[i][0] = 0; //前面有过障碍，则第一行都没有路了
			else dp[i][0] = 1;
		for(int j = 1; j < n; j++) 
			if(dp[0][j-1] == 0 || obstacleGrid[0][j] == 1) dp[0][j] = 0; //前面有过障碍，则第一列都没有路了
			else dp[0][j] = 1;
		for(int i = 1; i < m; i++){
			for(int j = 1; j < n; j++){
				if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
				else dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
    }
	//仍然可以采用滚动数组来降低空间复杂度， 因为dp[i][j]只和前面的行列相关，因此可以采用滚动数组
    int uniquePathsWithObstacles1(vector<vector<int > >& obstacleGrid) {
        int m = obstacleGrid.size();
		if(m <= 0) return 0;
		int n = obstacleGrid[0].size();
		vector<int > dp(n, 0); //必须初始化为0
		if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
		dp[0] = obstacleGrid[0][0] == 1 ? 0 : 1;  //注意边界，如果开始就1，则没有路径了
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				dp[j] = (obstacleGrid[i][j]==1) ? 0 : (j == 0 ? 0 : dp[j - 1]) + dp[j]; //注意转移方程中的dp[0][j]不都是1，与前面元素有关，所以要加判断
		return dp[n-1];
    }	
};

int main(){
	Solution c;
	vector<vector<int > > grid;
	int A[][3] = {{0,0},{0,0}};
	for(int i = 0; i < 2; i++){
		vector<int > cur;
		for(int j = 0; j < 2; j++) cur.push_back(A[i][j]);
		grid.push_back(cur);
	}
	cout << c.uniquePathsWithObstacles(grid) << endl;
	cout << c.uniquePathsWithObstacles1(grid) << endl;
	return 0;
}
