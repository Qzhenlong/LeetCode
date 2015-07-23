#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

���������е�DNA��A��C��G��T��ɵ���������ʾ���ҳ�DNA�����г���Ϊ10���ַ������ֳ���1�ε��Ӵ�

˼·��http://www.cnblogs.com/grandyang/p/4284205.html
����ֻ�������ַ������û�б�Ҫ��KMP�㷨��⣬�ȶ������ַ����б���
A:0 , C:1, G:2, T:3
��ô2λ�Ϳ��Ա�ʾһ���ַ���10���ַ�ֻ��20λ����һ�����;Ϳ��Ա�ʾ�ˣ�ÿ������һ���ַ�����������������2λ���ϸ��ַ��ı��뼴��
��һ����ϣ��洢���ֵĴ���

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
