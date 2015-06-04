#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
ԭ�⣺
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

���������һ�����ݽṹ��ʵ�ֵ��ʵļ�������ң������ֵ䣬�����еı��ʽ����26����ĸ������.,.��ʾ�����ַ���

˼·������ǰ׺���洢�����ҡ�
ǰ׺������һ�������������ڱ���������飬���еļ�ͨ�����ַ�����������������ͬ��
������ֱ�ӱ����ڽڵ��У������ɽڵ������е�λ�þ�����һ���ڵ���������ﶼ ����ͬ��ǰ׺��
Ҳ��������ڵ��Ӧ���ַ����������ڵ��Ӧ���ַ�����һ������£��������еĽڵ㶼�ж�Ӧ��ֵ��
ֻ��Ҷ�ӽڵ�Ͳ����ڲ��ڵ�����Ӧ�ļ����� ��ص�ֵ��

���������ж�Ӧ��Ҫ��ǰ׺��������֧����26�֣��ַ��������������ַ����Ƚϼ򵥣�������ʱ��.�ļ��룬��˲��û��ݷ�
*/

struct TrieNode{
	bool isWord; //��ǵ�ǰ�����Ƿ�Ϊһ��word
	int index; //��ǰ��ĸ���
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
	//�ݹ�汾
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
	//�ǵݹ�汾
    bool search1(string word){
        if(word.size() == 0 || trieRoot == NULL) return false;
		stack<TrieNode* > s; //����ջ�����ڻ���
		int i = 0, tar;
		TrieNode *p = trieRoot; 
		s.push(trieRoot);
		while(i < word.size() && !s.empty())
		{
			p = s.top(); s.pop(); i = p->index + 1;
			//if(i >= word.size()) break;
			if(word[i] == '.'){
				for(int j = 0; j < 26; j++){
					if(p->next[j] != NULL && i == word.size()-1 && p->next[j]->isWord) return true; //�ж���ȷ���
					if(p->next[j] != NULL && i < word.size()-1) s.push(p->next[j]); //����.���򽫸ò�ȫ����ջ������Ѿ����˺�һ���ַ�����Ҫ�ٽ�ջ��
				}
			}
			else{
				tar = word[i] - 'a';
				if(p->next[tar] == NULL && s.empty()) return false;
				if(p->next[tar] != NULL && p->next[tar]->isWord && i == word.size()-1) return true;
				if(p->next[tar] != NULL && i < word.size()-1) s.push(p->next[tar]);//����������չ, ����ȷƥ������Ѿ����ַ���ĩβ�����
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
