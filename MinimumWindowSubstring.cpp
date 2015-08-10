#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
/*
��Ŀ��
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

�����������ַ���S��T���ҳ�S�а���T����С���ڣ� Ҫ��O(n)���Ӷ�

˼·��360ʵϰ����ʱ������һ���㷨�⣬�����ժҪ�ַ�������
��1��
a.��һ����ϣ��m�洢t���ַ����ֵĴ�����ɨ��s,�ù�ϣ��has�洢t�г��ֵ��ַ�����������ʼ��Ϊ0������һ������q�洢has�г��ֵ��ַ�����λ��, 
  ��һ��������n����ʼ��Ϊt�ĳ���
b.ɨ���ַ���s, ����ǰ�ַ��ڹ�ϣ��m�У������ڹ�ϣ��has�е�������1����++has[s[i]]������s[i]��i���������q�У�
c.��s[i]Ҫhas�е�����С�ڵ���m�е��������������n��1.
d.��n=0ʱ��˵���ҵ�һ�����ڣ��Ӷ���q�Ķ��׿�ʼ���ң���������ַ���has�е���������m�����������������has�е�������1��
  �������ַ���has�е�����С�ڵ���m�У�����ַ�Ϊ������㣬��֮ǰ����С���ڴ�С�Աȣ�С�������С���ڴ�С���䴰����㡣
e. �ظ�b-d��ֱ��sɨ�������
*/

class Solution {
public:
    string minWindow(string s, string t) {
		if(s.empty() || t.empty() || t.size() > s.size()) return "";		
		map<char, int> m;
		map<char, int> has;
		queue<pair<char,int> > q; //ʹ�ö��д洢��s�г��ֵ�t�е��ַ���λ��
		for(int i = 0; i < t.size(); ++i) ++m[t[i]];
		int n = t.size(), minLen = INT_MAX, begin = -1;
		for(int i = 0; i < s.size(); ++i){
			if(m.find(s[i]) != m.end()){
				++has[s[i]]; 
				q.push(make_pair(s[i],i));
				if(has[s[i]] <= m[s[i]]) --n;
				if(n == 0){
					while(has[q.front().first] > m[q.front().first]){
						--has[q.front().first];
						q.pop(); //�ҵ���һ��ȥ������Ԫ��
					}
					if(minLen > i - q.front().second + 1){
						minLen = i-q.front().second+1;
						begin = q.front().second;
					}
					--has[q.front().first];
					q.pop();
					++n;
				}
			}
		}
		if(begin == -1 || minLen <= 0) return "";
		return s.substr(begin, minLen);
	}

};
int main(){
	Solution c;
	string S = "ADOBEABCODEBANC";
	string T = "ABC";
	cout << c.minWindow(S, T);
	return 0;
}
