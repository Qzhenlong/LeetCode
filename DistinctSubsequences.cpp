#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters
 without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

解析：给定字符串S和T，计算S中子序列T的数量，子序列为S中包含T的所有字符且它们的相对位置不发生改变， 如ACE是ABCDE的子序列而AEC不是

思路：
（1）递归，深度优先搜索，找到一组满足条件的答案则数量加1，否则回溯
（2）动态规划, dp[i][j] 表示T[0,j] 在S[0, i]中出现的次数，动态转移方程为：
	 S[i] != T[j] : dp[i][j] = dp[i-1][j] //如果当前字符不等，那么就只能抛弃当前这个字符。
	 S[i] == T[j] : dp[i][j] = dp[i-1][j]+dp[i-1][j-1]; //如果当前S[i]==T[j]，那么当前这个字母即可以保留也可以抛弃，

DP，化归为二维地图的走法问题。

 

      r  a  b  b  i  t

   1  0  0  0  0  0  0

r  1  1  0  0  0  0  0

a  1  1  1  0  0  0  0

b  1  1  1  1  0  0  0

b  1  1  1  2  1  0  0

b  1  1  1  3  3  0  0

i  1  1  1  3  3  3  0

t  1  1  1  3  3  3  3

滚动数组降低复杂度，从外往里滚动
*/

class Solution {
public:
   //超时
    int numDistinct(string s, string t) {
        int total = 0;
		if(s.size() == 0 || t.size() == 0) return 0;
		dfs(total, s, t, 0, 0);
		return total;
    }
	void dfs(int &sum, string s, string t, int i, int j){
		if(i >= t.size()){
			sum++; //找到一组解
			return;
		}
	    if(j >= s.size()) return;
		for(int k = j; k < s.size(); k++){
			if(t[i] == s[k])
				dfs(sum, s, t, i+1, k+1);
		}
	}
	int numDistinct1(string s, string t){
		int m = s.size(), n = t.size();
		vector<vector<int > > dp(m+1, vector<int >(n+1, 0));
		for(int i = 0; i <= m; i++) dp[i][0] = 1;
		for(int j = 1; j <= n; j++) dp[0][j] = 0;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				if(s[i-1] != t[j-1]) dp[i][j] = dp[i-1][j]; //不相等，舍弃t[j], 
				else dp[i][j] = dp[i-1][j] + dp[i-1][j-1]; //相等，可取可不取
			}
		}
		return dp[m][n];
	}
	//滚动数组
	int numDistinct2(string s, string t){
		int m = s.size(), n = t.size();
		vector<int > dp(n+1, 0);
		dp[0] = 1;
		for(int i = 0; i <= m; i++){
			for(int j = n-1; j >= 0; j--){
				dp[j+1] += (s[i] == t[j]) ? dp[j] : 0;
			}
		}
		return dp[n];
	}	
};

int main(){
	Solution c;
	cout << c.numDistinct("a", "b") << endl;
	cout << c.numDistinct1("a", "b") << endl;
	cout << c.numDistinct2("rabbbit", "rabbit") << endl;
	return 0;
}


