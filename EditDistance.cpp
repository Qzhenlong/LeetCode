#include<iostream>
#include<vector>
using namespace std;
/*
题目：Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

解析：给定两个词word1和word2，找出将word1转换成word2的最小步数， 一种操作代表一步
	 有三种操作，插入，删除，替换
	 
思路：动态规划， dp[i][j]表示word1[0,i]与word2[0,j]的最小可编辑距离
当word1[i] = word[j]时： dp[i][j] = dp[i-1][j-1];
当word1[i] != word[j]时: 
  a.将word1[i]替换成word2[j]，dp[i][j] = dp[i-1][j-1] + 1;
  b.将word1[i]删除，dp[i][j] = dp[i-1][j] + 1;
  c.将word1[i]后面添加一个word2[j], dp[i][j] = dp[i][j-1]+1
  
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
		vector<vector<int > > dp(m+1, vector<int >(n+1, 0));
		for(int i = 0; i <= m; i++) dp[i][0] = i;
		for(int i = 0; i <= n; i++) dp[0][i] = i;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
				else{
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
				}
			}
		}
		return dp[m][n];
    }
};

int main(){
	Solution c;
	cout << c.minDistance("b","a");
	return 0;
}

