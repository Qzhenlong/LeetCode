#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
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

��������һ���ַ���ÿ�β�ֳ������ǿ��Ӵ����Ӷ�����һ�ö������������ö�����������������Ҷ�ӽ����ӽ�㣬��������һ���µ����򴮣������Լ�������~
      ������ͬ���ȵ������ַ���s1��s2���ж�s2�Ƿ�Ϊs1��һ������
	  
˼·��
��1��������ַ�ʽ�����ҳ������������У���ôֱ���ж�s1��s2����ͬ�ַ��������Ƿ���ȼ��ɣ��������Ҳ�㣩��˼·������abcd��bdac
��2������Ķ�̬�滮�㷨��

ת�ԣ�http://blog.sina.com.cn/s/blog_b9285de20101gy6n.html

dp[i][j][k] ������s1��i��ʼ��s2��j��ʼ������Ϊk������substring�Ƿ�Ϊscramble string��

�����������Ҫ���ǣ�

1. �������substring��ȵĻ�����Ϊtrue

2. �������substring�м�ĳһ���㣬��ߵ�substringsΪscramble string��ͬʱ�ұߵ�substringsҲΪscramble string����Ϊtrue

3. �������substring�м�ĳһ���㣬s1��ߵ�substring��s2�ұߵ�substringΪscramble string, ͬʱs1�ұ�substring��s2��ߵ�substringҲΪscramble string����Ϊtrue

״̬ת�Ʒ��̣�
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
						if(dp[i][j][k])  break;  //�Ѿ���һ�������ˣ�����������ǰѭ��
					}  
		return dp[0][0][n];
	}
};

int main(){
	Solution c;
	cout << c._isScramble("abcd", "bdac");
	return 0;
}
