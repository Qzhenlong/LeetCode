#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
ԭ�⣺Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

������ʵ��ǰ׺��������һ����Ŀ���� Add and Search Word��������ǰ׺��ʵ�ֵ����ݽṹ���������һ�㣬��Ϊû��.��Լ����ֻ������ĸa-z

*/

class TrieNode {
public:
	bool isWord;  //��ǵ�ǰ�ַ����Ľṹ��
	vector<TrieNode* > Node; 
    // Initialize your data structure here.
    TrieNode() {
		isWord = false;
		Node.resize(26);
		for(int i = 0; i < 26; i++) Node[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
		TrieNode *p = root;
        for(int i = 0; i < s.size(); i++){
			int cur = s[i] - 'a';
			if(p->Node[cur] == NULL) p->Node[cur] = new TrieNode();
			p = p->Node[cur];
		}
		p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        return mysearch(root, 0, key);
    }
	//�ݹ����
	bool mysearch(TrieNode *t, int cur, string key){ // Memory Limit Exceeded
		if(t == NULL) return false;
		if(cur >= key.size()) return t->isWord; //��cur == key.size()ʱ����ǰ�ڵ�t�����һ����ĸ
		int i = key[cur] - 'a';
		return mysearch(t->Node[i], cur+1, key);
	}
    //�ǵݹ����
	bool mysearch1(string key){ // AC
		TrieNode *p = root;
		for(int i = 0; i < key.size(); i++){
			int cur = key[i] - 'a';
			if(p->Node[cur] == NULL) return false;
			p = p->Node[cur];
		}
		return p->isWord;
	}
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
 		TrieNode *p = root;
		for(int i = 0; i < prefix.size(); i++){
			int cur = prefix[i] - 'a';
			if(p->Node[cur] == NULL) return false;
			p = p->Node[cur];
		}
		return true;       
    }

private:
    TrieNode* root;
};

int main()
{
    Trie wd;
    wd.insert("bad");
	wd.insert("dad");
	wd.insert("mad");
	cout << wd.mysearch1("pad") << endl;// -> false
	cout << wd.mysearch1("bad") << endl;// -> true
	cout << wd.search("pad") << endl;// -> false
	cout << wd.search("bad") << endl;// -> true
	cout << wd.startsWith("pad") << endl;// -> false
	cout << wd.startsWith("") << endl;// -> true
	return 0;
}
