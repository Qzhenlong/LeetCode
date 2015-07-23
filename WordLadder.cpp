#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;
/*
��Ŀ��
Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

����������������beginWord��endWord,��һ���ʵ䣬�ҳ���beginWord�任��endWord�����ת�����ȣ�ÿ��ֻ�ܱ任һ�����ʣ�
	  ���û��ת��������0�� ת��·���е����е��ʳ�����ͬ,ÿһ���м�״̬�ĵ��ʶ��������ֵ���

˼·��������ȱ�������ʱ��Ӧ�ò��ù�����ȱ���
*/

class Solution {
public:
/*
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        int minLen = INT_MAX;
		dfs(minLen, beginWord, endWord, 0, 1, wordDict);
		return minLen;
    }
	void dfs(int &minLen, string &word, string &endword, int i, int curLen, unordered_set<string>& wordDict){
		if(i >= word.size()) return;
		for(int j = 0; j < endword.size(); j++){
			word[i] = endword[j];
			if(compare(word, endword) == 0){
				minLen = (minLen < curLen) ? minLen : curLen;
				continue;
			}
			else if(wordDict.find(word) != wordDict.end()) dfs(minLen, word, endword, i+1, curLen+1, wordDict);
		}
	}
*/
    int ladderLength(string beginWord, string endWord, set<string>& wordDict) {
        int minLen = 1, levelcount = 1; //levelcount��ʾ�������һ�������������ַ�����
		if(beginWord.size() != endWord.size() || beginWord.compare(endWord) == 0) return 0;
		queue<string > q;
		set<string > visited; //�Ƿ���ʹ�
		q.push(beginWord);
		while(!q.empty()){
			string cur = q.front();
			q.pop(); levelcount--;

			for(int i = 0; i < cur.size(); i++){
				for(char c = 'a'; c <= 'z'; c++){
					string tmp = cur;
					if(tmp[i] == c) continue;
					tmp[i] = c;
					if(tmp.compare(endWord)==0) return minLen+1;
					if(visited.find(tmp) == visited.end() && wordDict.find(tmp) != wordDict.end()){
						q.push(tmp); visited.insert(tmp);
					}
				}
			}
			if(levelcount == 0){
				levelcount = q.size();
				minLen++;
			}
		}
		return 0;
    }
	//������ȱ����� Time Limit Exceeded
    int _ladderLength(string beginWord, string endWord, set<string>& wordDict) {
        int minLen = 0;
		set<string > dfs_visited;
		if(beginWord.size() != endWord.size() || beginWord.compare(endWord) == 0) return 0;
		dfs(minLen, beginWord, endWord, 1, wordDict, dfs_visited);
		return minLen;
	}
	void dfs(int &minLen, string word, string endword, int curLen, set<string>& wordDict, set<string > &dfs_visited){
		for(int i = 0; i < word.size(); i++){
			for(char c = 'a'; c <= 'z'; c++){
				string tmp = word;
				if(tmp[i] == c) continue;
				tmp[i] = c;				
				if(tmp.compare(endword) == 0){
					minLen = (minLen > curLen+1 || minLen == 0) ? curLen+1 : minLen;
					continue;
				}
				else if(dfs_visited.find(tmp) == dfs_visited.end() && wordDict.find(tmp) != wordDict.end()){
				    dfs_visited.insert(tmp);
					dfs(minLen, tmp, endword, curLen+1, wordDict, dfs_visited);
					dfs_visited.erase(tmp);
				}
			}
		}
	}
};

int main(){
	Solution c;
	set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	cout << c._ladderLength("hit", "cog", dict);
	return 0;
}
