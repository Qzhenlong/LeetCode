#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
题目：
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

思路：
动态规划：
长度为n的字符串，应该有n+1个隔板
状态转移方程：
f(i) = any_of(f(j)&&s[j + 1, i] 属于 dict), 
f(i)表示[0,i]可以分词，f(i)可以分词的条件就是当[0,j]可以分词且[j+1,i]在字典中  
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string >& wordDict) {
        vector<bool > f(s.size()+1, false);
		f[0] = true;
		for(int i = 1; i <= s.size(); i++)
		{
			for(int j = i-1; j >= 0; j--)
			{
				if(f[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()){
					f[i] = true;
					break; //0-i已经可以分词，不用继续了
				}
			}
		}
		return f[s.size()];
    }
};

int main()
{
	Solution c;
	string s = "leetcode";
	unordered_set<string > dict;
	dict.insert("leet");
	dict.insert("code");
	cout << c.wordBreak(s, dict);
	return 0;
}
