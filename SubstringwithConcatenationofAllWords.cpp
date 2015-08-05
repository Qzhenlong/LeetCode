#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
/*
��Ŀ��
You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).

����������һ���ַ���s��һ�������б��б��ڵ��ʳ�����ͬ�����б������е��ʴ�������s���ҳ����д����Ӵ�����ʼλ�ã������Ӵ��е�˳�򲻶�

˼·��
��1�������б���ÿ�����ʳ�����ȣ�ͬʱҪ����s���������֣���ôֻҪ���б�����ϣ����ϣ���¼��ÿ���������б��г��ֵĴ�����������һ���ܼ����������б���
    ���������ֵĵ��������ﵽ�ܼ�����������ʱ��˵���ҵ��Ϸ��⡣
	���⴦����ͬ���ʵ����������һ����ϣ����¼�ѳ��ֵ��ʵĳ��ִ���

*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> wmap;
		map<string, int> wapp; //���ֹ��ĵ�������
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
