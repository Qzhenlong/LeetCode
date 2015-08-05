#include<iostream>
#include<vector>
#include<set>
#include<stack>
using namespace std;
/*
��Ŀ��
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

����������һ���ַ�����һ���ֵ䣬���ַ������ֳ�һ�����ӣ������еĵ��ʶ������ֵ����ҵ�

˼·��
��1��ʹ��ǰ׺�������ֵ��еĵ��ʷ���ǰ׺���У����л��֣��д����ظ��ַ���ʱ�򣬳�ʱ
��2��������һ�⶯̬�滮��˼·�ж��ַ����ܷ�ִʣ�������ִ�У�1��,dp[i]��ʾǰi���ַ��ܷ�ִʣ�����Ϊs[0..j)���Էִ���s[j,..,i]���ֵ���
��3����dfsҲ���ԣ�ͬ����ʹ�ã�2�����ж�һ��

*/

struct TrieNode{
	bool isWord;
	TrieNode *next[26];
	TrieNode() : isWord(false){
		for(int i = 0; i < 26; ++i) next[i] = NULL;
	}
};
class Trie{
public:
	Trie(){
		root = new TrieNode();
	}
	void insert(string word){
		TrieNode *p = root;
		for(int i = 0; i < word.size(); ++i){
			int index = word[i] - 'a';
			if(p->next[index] == NULL) p->next[index] = new TrieNode();
			p = p->next[index];
		}
		p->isWord = true;
	}
	bool search(string word){
		TrieNode *p = root;
		for(int i = 0; i < word.size(); ++i){
			int index = word[i] - 'a';
			if(p->next[index] == NULL) return false;
			p = p->next[index];
		}
		return p->isWord;
	}
	bool startWith(string prefix){
		TrieNode *p = root;
		for(int i = 0; i < prefix.size(); ++i){
			int index = prefix[i] - 'a';
			if(p->next[index] == NULL) return false;
			p = p->next[index];		
		}
		return true;
	}
private:
	TrieNode *root;
};

class Solution {
public:
    // AC��12ms
    //vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
	vector<string> wordBreak(string s, set<string >& wordDict) {
        vector<string > ans;
		Trie trie; //����ǰ׺���洢�ֵ�����
		if(s.empty() || wordDict.empty() || !isValid(s, wordDict)) return ans;
		for(set<string>::iterator it = wordDict.begin(); it != wordDict.end(); ++it) trie.insert(*it); //���ֵ����ǰ׺��
		stack<int > split_stack; //��ջ�洢�ָ���
		vector<string > words; //�洢�����еĵ���
		split_stack.push(0);
		words.push_back("");
		while(!split_stack.empty()){
			int index = split_stack.top(); split_stack.pop();
			string word = words.back(); words.pop_back();
			while(index < s.size()){
				word += s[index++];
				if(trie.search(word)){
					words.push_back(word);
					split_stack.push(index);
					word = "";
				}
				if(!trie.startWith(word)) break;
			}
			if(!split_stack.empty() && split_stack.top() == s.size()){ //�ҵ�һ���
				string cur_ans = "";
				for(int i = 0; i < words.size()-1; ++i) cur_ans += (words[i] + " ");
				ans.push_back(cur_ans + words[words.size()-1]);
			}
		}
		return ans;
    }
	//AC, 28 ms, �ݹ��Ч�ʻ��ǱȽϵ�
	vector<string> _wordBreak(string s, set<string >& wordDict) {	
        vector<string > ans;
		if(s.empty() || wordDict.empty() || !isValid(s, wordDict)) return ans;	
		dfs(ans, "", s, 0, wordDict);
		return ans;
	}
	void dfs(vector<string > &ans, string sentence, string s, int i, set<string > dict){
		if(i == s.size()){
			ans.push_back(sentence);
			return;
		}
		if(i != 0) sentence += " ";
		for(int j = i; j < s.size(); ++j){
			string word = s.substr(i, j-i+1);
			if(dict.find(word) != dict.end()) dfs(ans, sentence+word, s, j+1, dict);
		}
	}
private:
	bool isValid(string s, set<string >& wordDict){
		vector<bool > dp(s.size()+1, false);
		dp[0] = true;
		for(int i = 1; i <= s.size(); ++i)
			for(int j = i-1; j >= 0; --j)
				if(dp[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()){
					dp[i] = true;
					break; //����һ�ִַʾ���
				}
		return dp[s.size()];
	}
};

int main(){
	Solution c;
	set<string > dict;
	dict.insert("a");
	dict.insert("aa");
	dict.insert("aaa");
	dict.insert("aaaa");
	dict.insert("aaaaa");
	dict.insert("aaaaaa");
	dict.insert("aaaaaaa");
	dict.insert("aaaaaaaa");
	dict.insert("aaaaaaaaa");
	dict.insert("aaaaaaaaaa");
	//vector<string > ans = c.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict);
	vector<string > ans = c._wordBreak("aaa", dict);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
	return 0;
}

