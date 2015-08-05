#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
/*
题目：
You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).

解析：给定一个字符串s及一个单词列表，列表内单词长度相同，将列表中所有单词串联，在s中找出所有串联子串的起始位置，串联子串中的顺序不定

思路：
（1）由于列表中每个单词长度相等，同时要求在s中连续出现，那么只要将列表存入哈希表，哈希表记录在每个单词在列表中出现的次数，再设置一个总计数器等于列表长度
    当连续出现的单词数量达到总计算器的数量时，说明找到合法解。
	特殊处理：相同单词的情况，增加一个哈希表，记录已出现单词的出现次数

*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> wmap;
		map<string, int> wapp; //出现过的单词数量
		vector<int > ans;
		if(words.empty() || s.size() == 0) return ans;
		for(int i = 0; i < words.size(); ++i){
			wmap[words[i]]++;
			wapp[words[i]] = 0;
		}
		int wordlen = words[0].size();
	    int searchEnd = s.size() - wordlen * words.size();

	  for (int i = 0; i <= searchEnd; ++i)
	  {
		int j = i;
		wapp.clear();
		int iword = 0;
		for (; iword < words.size(); ++iword)
		{
		  string sub = s.substr(j, wordlen);
		  //not in L
		  if(wmap[sub] == 0)
			break;
		  //in L, but redundancy
		  if(++wapp[sub] > wmap[sub])
			break;
		  j += wordlen;
		}
		if(iword == words.size())
		{
		  ans.push_back(i);
		}
	  }
		return ans;
    }
};

int main(){
	Solution c;
	string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
	vector<string > words;
	words.push_back("fooo");
	words.push_back("barr");
	words.push_back("wing");
	words.push_back("ding");
	words.push_back("wing");
	vector<int > ans = c.findSubstring(s, words);
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	return 0;
}
