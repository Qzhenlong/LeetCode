#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
原题：
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

解析：设计一种数据结构来实现单词的加入与查找，类似字典，查找中的表达式除了26个字母还包括.,.表示任意字符、

思路：采用前缀树存储并查找。
前缀树：是一种有序树，用于保存关联数组，其中的键通常是字符串。与二叉查找树不同，
键不是直接保存在节点中，而是由节点在树中的位置决定。一个节点的所有子孙都 有相同的前缀，
也就是这个节点对应的字符串，而根节点对应空字符串。一般情况下，不是所有的节点都有对应的值，
只有叶子节点和部分内部节点所对应的键才有 相关的值。

对于题设中对应的要求，前缀树的最大分支数有26种（字符总数），插入字符串比较简单，而查找时有.的加入，因此采用回溯法
*/

struct TrieNode{
	bool isWord; //标记当前序列是否为一个word
	int index; //当前字母序号
	TrieNode *next[26];
	TrieNode(int _index){
		isWord = false;
		index = _index;
		for(int i = 0; i < 26; i++) next[i] = NULL;
	}
};


class WordDictionary {
public:
	WordDictionary(){
		trieRoot = new TrieNode(-1);
	}
    // Adds a word into the data structure.
    void addWord(string word) {
		TrieNode *p = trieRoot;
		for(int i = 0; i < word.size(); i++)
		{
			int tar = word[i] - 'a';
			if(p->next[tar] == NULL) p->next[tar] = new TrieNode(i);
			p = p->next[tar];
		}
		p->isWord = true;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
		searchIteration(trieRoot, word, 0);
    }
	//递归版本
    bool searchIteration(TrieNode* node, string& word, int i){  
        if(node==NULL){  
            return false;  
        }  
        int len = word.size();  
        if(i>=len){  
            return node->isWord;  
        }  
          
        if(word[i]!='.'){  
            return searchIteration(node->next[word[i]-'a'], word, i+1);  
        }else{  
            for(int k=0; k<26; k++){  
                if(searchIteration(node->next[k], word, i+1)){  
                    return true;  
                }  
            }  
            return false;  
        }  
    }  
	//非递归版本
    bool search1(string word){
        if(word.size() == 0 || trieRoot == NULL) return false;
		stack<TrieNode* > s; //定义栈，用于回溯
		int i = 0, tar;
		TrieNode *p = trieRoot; 
		s.push(trieRoot);
		while(i < word.size() && !s.empty())
		{
			p = s.top(); s.pop(); i = p->index + 1;
			//if(i >= word.size()) break;
			if(word[i] == '.'){
				for(int j = 0; j < 26; j++){
					if(p->next[j] != NULL && i == word.size()-1 && p->next[j]->isWord) return true; //判断正确情况
					if(p->next[j] != NULL && i < word.size()-1) s.push(p->next[j]); //遇到.，则将该层全部进栈，如果已经到了后一个字符则不需要再进栈了
				}
			}
			else{
				tar = word[i] - 'a';
				if(p->next[tar] == NULL && s.empty()) return false;
				if(p->next[tar] != NULL && p->next[tar]->isWord && i == word.size()-1) return true;
				if(p->next[tar] != NULL && i < word.size()-1) s.push(p->next[tar]);//继续向下扩展, 无正确匹配或者已经到字符串末尾则回溯
			}
		}
		return false;
	}
private:
	TrieNode *trieRoot;
};

int main()
{
    WordDictionary wd;
	/*
    wd.addWord("bad");
	wd.addWord("dad");
	wd.addWord("mad");
	cout << wd.search1("pad") << endl;// -> false
	cout << wd.search1("bad") << endl;// -> true
	cout << wd.search1(".ad") << endl;// -> true
	cout << wd.search1(".") << endl;// -> true
	*/
    wd.addWord("ran");
	wd.addWord("rune");
	wd.addWord("runner");
	wd.addWord("runs");
	cout << wd.search1("a.d.") << endl;// -> false
	cout << wd.search1("b.") << endl;// -> false
	cout << wd.search1("r.n") << endl;// -> true
	cout << wd.search1("ru.n.e") << endl;// -> false	
	return 0;
}
