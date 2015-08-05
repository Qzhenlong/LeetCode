#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
/*
题目：
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].

Note:
You may assume that all inputs are consist of lowercase letters a-z.

解析：给定一个二维面板，由字母构成，给出一个字符串的列表，找出存在于面板中的字符串

思路：
（1）还是通过图的遍历，确定相应字符串是否在面板中，用之前的方法，超时
（2）每个字符串都由26个字母组成，可以使用前缀树存储
*/

struct TrieNode{
	bool isWord;
	TrieNode *next[26];
	TrieNode(bool iW) : isWord(iW) {
		for(int i = 0; i < 26; i++) next[i] = NULL;
	}
};
class Trie{
public:
	Trie(){
		root = new TrieNode(false);
	}
	//insert a word
	void insert(string word){
		TrieNode *p = root;
		for(int i = 0; i < word.size(); i++){
			int num = word[i]-'a';
			if(p->next[num] == NULL) p->next[num] = new TrieNode(false);
			p = p->next[num];
		}
		p->isWord = true;
	}
	//if a word exists in Trie
	bool search(string word){
		TrieNode *p = root;
		for(int i = 0; i < word.size(); i++){
			int num = word[i]-'a';
			if(p->next[num] == NULL) return false;
			p = p->next[num];
		}
		return p->isWord;
	}
    // Returns if there is any word in the trie
    // that starts with the given prefix.
	bool startWith(string prefix){
		TrieNode *p = root;
		for(int i = 0; i < prefix.size(); i++){
			int num = prefix[i]-'a';
			if(p->next[num] == NULL) return false;
			p = p->next[num];
		}
		return true;
	}
private:
	TrieNode *root;
};
class Solution {
public:
	//前缀树版本
    vector<string > _findWords(vector<vector<char > >& board, vector<string >& words) {
        vector<string > ans;
		set<string > res; //去重
		Trie trie;
		if(board.size() == 0 || words.size() == 0) return ans;
		for(int i = 0; i < words.size(); ++i) trie.insert(words[i]);
		
		for(int i = 0; i < board.size(); ++i)
			for(int j = 0; j < board[i].size(); ++j)
				_dfs(board, res, "", i, j, trie);
				
		for(set<string >::iterator it = res.begin(); it != res.end(); ++it) ans.push_back(*it);
				
		return ans;
    }	
	void _dfs(vector<vector<char > > &board, set<string > &ans, string word, int x, int y, Trie trie){ 
		if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '#') return;
		word += board[x][y];
		if(!trie.startWith(word)) return;
		if(trie.search(word)) ans.insert(word);
		char c = board[x][y];
		board[x][y] = '#';
		_dfs(board, ans, word, x+1, y, trie);
		_dfs(board, ans, word, x, y+1, trie);
		_dfs(board, ans, word, x-1, y, trie);
		_dfs(board, ans, word, x, y-1, trie);
		board[x][y] = c; //回滚
	}
    //超时
    vector<string > findWords(vector<vector<char > >& board, vector<string >& words) {
        vector<string > ans;
		map<char, vector<string > > m;
		map<string, bool> visited;
		if(board.size() == 0 || words.size() == 0) return ans;
		for(int i = 0; i < words.size(); ++i){
			m[words[i][0]].push_back(words[i]); //
			visited[words[i]] = false;
		}
		for(int i = 0; i < board.size(); ++i)
			for(int j = 0; j < board[i].size(); ++j)
				if(m.find(board[i][j]) != m.end())
					for(int k = 0; k < m[board[i][j]].size(); ++k)
						if(!visited[m[board[i][j]][k]] && dfs(board, m[board[i][j]][k], 0, i, j)){
							ans.push_back(m[board[i][j]][k]); //存在，记录
							visited[m[board[i][j]][k]] = true; //已经记录过了，不需要再判断了
						}
		return ans;
    }
	bool dfs(vector<vector<char > > &board, string word, int i, int x, int y){ /// Time Limit Exceeded, 超时
	    if(i == word.size()) return true;
		if(i >= word.size() || x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || word[i] != board[x][y]) return false;
		char c = board[x][y];
		board[x][y] = '#';
		bool Exist = dfs(board, word, i+1, x+1, y) || dfs(board, word, i+1, x, y+1) 
				  || dfs(board, word, i+1, x-1, y) || dfs(board, word, i+1, x, y-1);
		board[x][y] = c; //回滚
		return Exist;
	}
	
};


int main(){
	Solution c;
	const int n = 4;
	char A[][n] = {
      {'o','a','o','n'},
	  {'e','t','a','e'},
	  {'i','h','k','r'},
	  {'i','f','l','v'}
	};
	vector<vector<char > > grid;
	for(int i = 0; i < sizeof(A)/ n; i++){
		vector<char > cur;
		for(int j = 0; j < n; j++){
			cur.push_back(A[i][j]);
			//cout << A[i][j] << " ";
		}
		//cout << endl;
		grid.push_back(cur);
	}
	vector<string > words;
	words.push_back("oath");
	words.push_back("pea");
	words.push_back("eat");
	words.push_back("rain");
	vector<string > ans = c._findWords(grid, words);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}

