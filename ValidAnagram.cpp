#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

�����������ַ���s��t���ж�t�Ƿ�Ϊs�ı�λ��

˼·��ֻҪs��t��ӵ����ͬ��ĸ����tΪs�ı�λ�ʣ�ͨ��һ����ϣ��洢��ĸ���ִ������ɡ�
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        //if(s.compare(t) == 0 || s.size() != t.size()) return false; //���
		if(s.size() != t.size()) return false; //���Ҳ�Ǳ�λ��
		map<char, int> m;
		for(int i = 0; i < s.size(); ++i) m[s[i]] = 0;
		for(int i = 0; i < s.size(); ++i) m[s[i]]++;
		for(int i = 0; i < t.size(); ++i){
			if(m.find(t[i]) == m.end()) return false;
			else m[t[i]]--;
		}
		for(map<char, int>::iterator it = m.begin(); it != m.end(); it++)
			if(it->second > 0) return false;
		return true;
    }
};

int main(){
	Solution c;
	cout << c.isAnagram("rat", "cat");
	return 0;
}
