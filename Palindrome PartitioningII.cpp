#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

解析：给定一个字符串，返回使得每个子串都是回文串的最小拆分次数

思路：和上一题的思路相似，不过是找出最小拆分数
（1）使用动态规划, dp[i][j]表示s[i,..,j]是否为回文串，状态转移方程为：
	dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
得到dp后，计算最小拆分数， 深度优先遍历一下就Okay了
（2）采用dfs会超时，其实不需要深度优先遍历，还是利用动态规划的思路，
	f[i]记录s[i..n]的最小拆分数，状态转移方程：
	f[i] = min(1+f(j+1)), i <= j < n 且 dp[i][j] == true;

*/

class Solution {
public:
   
    int minCut(string s) {
        int n = s.size();
		if(n == 0) return 0;
		vector<vector<bool > > dp(n, vector<bool >(n, false));
		for(int i = n-1; i >= 0; --i)
			for(int j = i; j < n; ++j){
				if(i == j) dp[i][j] = true;
				else if(i+1 > j-1) dp[i][j] = (s[i] == s[j]);
				else dp[i][j] = (dp[i+1][j-1] && (s[i] == s[j]));
			}
		/* dfs超时
		int gMin = INT_MAX;
		for(int i = 0; i < n; ++i)
			if(dp[0][i]) dfs(dp, 0, gMin, 0, i, n);
		return gMin;
		*/
		vector<int > f(n+1, INT_MAX);
		f[n] = 0;
		for(int i = n-1; i >= 0; --i)
			for(int j = i; j < n; ++j)
				if(dp[i][j]) f[i] = min(f[i], 1+f[j+1]);
		return f[0]-1; //拆分数=回文串数-1
		
    }
	 //Time Limit Exceeded，超时
	void dfs(vector<vector<bool > > dp, int curMin, int &gMin, int i, int j, int n){
		if(j == n-1){
			gMin = min(gMin, curMin);
			return;
		}
		for(int k = j+1; k < n; ++k)
			if(dp[j+1][k]) dfs(dp, curMin+1, gMin, j+1, k, n);
	}
};

int main(){
	Solution c;
	string s = "aab";
	cout << c.minCut(s);
	return 0;
}
