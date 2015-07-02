#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
题目：Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
	
解析：给定一个字符串s, 将字符串进行划分，使每个子串都是回文串，返回所有可能的划分集合

思路：
（1）动态规划，dp[i][j]用于表示s[i..j]是否为回文数，状态转移方程
dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
应该从后开始往前计算，才能顺利递推状态转移方程, 
生成dp后，深度优先遍历dp,产生所有可能组合
（2）直接采用深度优先遍历，边遍历边判断
  
*/

class Solution {
public:
    vector<vector<string > > partition(string s) {
		int n = s.size();
        vector<vector<string > > ans;
		if(n == 0) return ans;
		vector<vector<bool > > dp(n, vector<bool >(n, false));
		for(int i = n-1; i >= 0; i--){
			for(int j = i; j < n; j++){
				if(i == j) dp[i][j] = true;
				else if(i+1 > j-1) dp[i][j] = (s[i] == s[j]);
				else dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
			}
		}
		vector<string > cur;
		cout << dp[0][n-1] << endl;
		for(int i = 0; i < n; i++)
			if(dp[0][i]){
				dfs(s, ans, cur, dp, 0, i, n);
				cur.pop_back();
			}
		return ans;
    }
	void dfs(string s, vector<vector<string > > &ans, vector<string > &cur, vector<vector<bool > > dp, int i, int j, int n){
		cur.push_back(s.substr(i, j-i+1));
		if(j == n-1){
			ans.push_back(cur);
			return;
		}
		for(int k = j+1; k < n; k++){
			if(dp[j+1][k]){
				dfs(s, ans, cur, dp, j+1, k, n);
				cur.pop_back();
			}
		}
	}
};

int main(){
	Solution c;
	string s = "aabaa";
	vector<vector<string > > ans = c.partition(s);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}

