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

解析：给定字符串s和t，判断t是否为s的变位词

思路：只要s和t的拥有相同字母，则t为s的变位词，通过一个哈希表存储字母出现次数即可。
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        //if(s.compare(t) == 0 || s.size() != t.size()) return false; //相等
		if(s.size() != t.size()) return false; //相等也是变位词
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
