#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

解析：将一个字符串每次拆分成两个非空子串，从而构成一棵二叉树，交换该二叉树的任意两个非叶子结点的子结点，可以生成一个新的乱序串，还可以继续交换~
      给定相同长度的两个字符串s1和s2，判断s2是否为s1的一个乱序串
	  
思路：
（1）如果这种方式可以找出所有乱序排列，那么直接判断s1和s2中相同字符的数量是否相等即可（两者相等也算），思路错误，如abcd成bdac
（2）神奇的动态规划算法：

转自：http://blog.sina.com.cn/s/blog_b9285de20101gy6n.html

dp[i][j][k] 代表了s1从i开始，s2从j开始，长度为k的两个substring是否为scramble string。

有三种情况需要考虑：

1. 如果两个substring相等的话，则为true

2. 如果两个substring中间某一个点，左边的substrings为scramble string，同时右边的substrings也为scramble string，则为true

3. 如果两个substring中间某一个点，s1左边的substring和s2右边的substring为scramble string, 同时s1右边substring和s2左边的substring也为scramble string，则为true

状态转移方程：
dp(i, j, n) = || ((dp(i, j, m) && dp(i + m, j + m, n - m)) || dp(i, j + n - m, m) && dp(i + m, j, n - m)) for 1 < m < n
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        //if(s1.compare(s2) == 0) return false;
		map<char, int> ns1, ns2;
		for(int i = 0; i < s1.size(); i++){
			ns1[s1[i]] = 0; ns2[s2[i]] = 0;
		}
		for(int i = 0; i < s1.size(); i++){
			ns1[s1[i]]++; ns2[s2[i]]++;
		}
		for(int i = 0; i < s1.size(); i++){
			if(ns2.find(s1[i]) == ns2.end() || ns2[s1[i]] != ns1[s1[i]]) return false;
		}
		return true;
    }
	bool _isScramble(string s1, string s2){
		int n = s1.size();
		vector<vector<vector<bool > > > dp(n, vector<vector<bool > >(n, vector<bool >(n+1, false)));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				dp[i][j][0] = true;
				dp[i][j][1] = (s1[i]==s2[j]);
			}
		for(int i = n-1; i >= 0; i--)
			for(int j = n-1; j >= 0; j--)
				for(int k = 2; k <= min(n - i, n - j); k++)  
					for(int m = 1; m < k; m++){  
						dp[i][j][k] = dp[i][j][k] || dp[i][j][m] && dp[i + m][j + m][k - m] ||  
								dp[i][j + k - m][m] && dp[i + m][j][k - m];  
						if(dp[i][j][k])  break;  //已经是一个乱序串了，可以跳出当前循环
					}  
		return dp[0][0][n];
	}
};

int main(){
	Solution c;
	cout << c._isScramble("abcd", "bdac");
	return 0;
}
