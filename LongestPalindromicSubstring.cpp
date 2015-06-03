 #include<iostream>
#include<map>
using namespace std;
/*
��أ�����ظ��Ӵ�
˼·��
��̬�滮��
��һ������T����¼i-j֮���ǲ��ǻ��Ĵ���������T[i][j] = true;
��i~j�ǻ��Ĵ�����ôi+1~j-1��Ȼ�ǻ��Ĵ���T[i][j] = (T[i+1][j-1] �� s[i] == s[j])
1��T[i][j] = true; ��i = j;
2) T[i][j] = s[i]== s[j]; ��j = i+1;
2) T[i][j] = (s[i] == s[j]) && T[i+1][j-1];

�����㷨��O(n) KMP�㷨�ı���
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

