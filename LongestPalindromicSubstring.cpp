 #include<iostream>
#include<map>
using namespace std;
/*
相关：最长不重复子串
思路：
动态规划，
用一个矩阵T来记录i-j之间是不是回文串，若是则T[i][j] = true;
若i~j是回文串，那么i+1~j-1必然是回文串，T[i][j] = (T[i+1][j-1] 且 s[i] == s[j])
1）T[i][j] = true; 若i = j;
2) T[i][j] = s[i]== s[j]; 若j = i+1;
2) T[i][j] = (s[i] == s[j]) && T[i+1][j-1];

最优算法：O(n) KMP算法的变种
http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
*/
class Solution {
public:
	string longestPalindrome(string s)
	{
		int n = s.size(), maxlen = 1, max_index = 0;
		bool T[n][n];
		if(s.size() == 0) return s;
		for(int j = 0; j < n; j++)
		{
			T[j][j] = true;
			for(int i = 0; i < j; i++)
			{
				if(s[i] == s[j])
				{
					T[i][j] = (j-i<2) || T[i+1][j-1];
					if(maxlen < j-i+1 && T[i][j])
					{
						maxlen = j-i+1;
						max_index = i;
					}
				}
				else
					T[i][j] = false;
			}
		}
		return s.substr(max_index, maxlen);
	}
};

int main()
{
	Solution c;
	string s = "a";
	cout << c.longestPalindrome(s) << endl;
	while(1);
	return 0;
}

