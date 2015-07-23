#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

解析：所有的DNA由A，C，G，T组成的序列来表示，找出DNA序列中长度为10的字符串出现超过1次的子串

思路：http://www.cnblogs.com/grandyang/p/4284205.html
由于只有四种字符，因此没有必要用KMP算法求解，先对四种字符进行编码
A:0 , C:1, G:2, T:3
那么2位就可以表示一个字符，10个字符只需20位，用一个整型就可以表示了，每次增加一个字符，将已有整数左移2位再上该字符的编码即可
用一个哈希表存储出现的次数

*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		map<int, int> m;
		vector<string > ans;
		int mask = 0x000fffff;
		int cur = 0;
		for(int i = 0; i < 10; i++)
			cur = (cur << 2) + encoding(s[i]);
		m[cur & mask] = 1;
		for(int i = 10; i < s.size(); i++){
			cur = ((cur << 2) + encoding(s[i])) & mask;
			m[cur]++;
		}
		for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
			if(it->second > 1) ans.push_back(decoding(it->first));
		return ans;
    }
	int encoding(char s){
		if(s == 'A') return 0;
		if(s == 'C') return 1;
		if(s == 'G') return 2;
		if(s == 'T') return 3;
	}
	string decoding(int x){
		string s = "";
		for(int i = 0; i < 10; i++){
			int y = x & 3;
			if(y == 0) s = 'A' + s;
			if(y == 1) s = 'C' + s;
			if(y == 2) s = 'G' + s;
			if(y == 3) s = 'T' + s;
			x = x >> 2;
		}
		return s;
	}
};

int main(){
	Solution c;
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string > ans = c.findRepeatedDnaSequences(s);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
