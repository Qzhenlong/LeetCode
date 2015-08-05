#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. 
Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".

����������һ���ַ��������������ǰ����������ַ������ز�����������̻��Ĵ�

˼·��
(1) �ҳ��ַ����������ǰ׺s[0..i]�������ַ�����ǰ�油��s[i+1,..n]���ɣ���ʱ
(2) KMP�㷨��next����ķ���, ���ַ��������Ϊ_s����ԭ�ַ���ƴ�ӣ��м�����������롰#����־��������Next���飬�õ����һ��λ�õ�nextֵ����Ϊn
    ��ԭ�ַ���ǰ��ƴ����_s[0...s.size()-n]���ɡ�
*/

class Solution {
public:
    // Time Limit Exceeded
    string shortestPalindrome(string s) {
        if(s.size() == 0) return s;
		int i = 0, j = s.size()-1, prefix = j, n = s.size();
		while(j >= 0){
			prefix = j;
			while(i < j && s[i] == s[j]){ ++i; --j;}
			if(i >= j) break;
			i = 0; 
			j = prefix-1;
		}
		string prev = "";
		for(int k = prefix+1; k < n; ++k) prev = s[k] + prev; 
		s = prev + s;
		return s;
    }
	string _shortestPalindrome(string s) {
		if(s.size() <= 1) return s;
		string _s = s;
		reverse(_s.begin(), _s.end());
		string t = s + "#" + _s + "#";
		int n = getNext(t);
		return _s.substr(0, s.size()-n)+s;
	}
	int getNext(string s){ //�Ľ������Next����ķ���
		vector<int > next(s.size(), -1);
		int i = 0, j = -1;
		while(i < s.size()-1){
			if(j == -1 || s[i] == s[j]){
				++i; ++j;
				next[i] = j;
				//if(s[i] != s[j]) next[i] = j;
				//else next[i] = next[j];
			}
			else j = next[j];
		}
		return next[s.size()-1];
	}
/*
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> p(t.size(), 0);
        for (int i = 1; i < t.size(); ++i) {
            int j = p[i - 1];
            while (j > 0 && t[i] != t[j]) j = p[j - 1];
            p[i] = (j += t[i] == t[j]);
        }
        return r.substr(0, s.size() - p[t.size() - 1]) + s;
    }
*/	
};

int main(){
	Solution c;
	cout << c._shortestPalindrome("aace");
	return 0;
}
