#include<iostream>
#include<vector>
using namespace std;
/*
原题：A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
m and n will be at most 100.

解析：从m*n(行*列)大小的网格的左上角到达右下角，只能向上或者向右走，总共的路径数，m和n都不超过100
思路：动态规划，dp[i][j]表示从（0，0）到（i,j）的路径数
dp[0][0] = 0;  //只能向下或者向右
dp[0][1] = 1;
dp[1][0] = 1;
dp[1][1] = 2; 
...
状态转移方程：dp[i][j] = dp[i-1][j]+dp[i][j-1];
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
		if(m <= 0 || n <= 0) return 0;
		int dp[m][n];
		dp[0][0] = 0;
		for(int i = 0; i < m; i++) dp[i][0] = 1;
		for(int j = 0; j < n; j++) dp[0][j] = 1;
		for(int i = 1; i < m; i++){
			for(int j = 1; j < n; j++){
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
    }
	int uniquePaths1(int m, int n) {
		vector<int> dp(n, 0); //一个数组可以搞定
		dp[0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 1; j < n; j++) {
				// 左边的 dp[j]，表示更新后的 dp[j]，与公式中的 dp[i[[j] 对应
				// 右边的 dp[j]，表示老的 dp[j]，与公式中的 dp[i-1][j] 对应
				dp[j] = dp[j - 1] + dp[j];
			}
		}
		return dp[n - 1];
	}
};

int main(){
	Solution c;
	cout << c.uniquePaths1(3,3);
	return 0;
}
