#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
/*
题目：
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

解析：给定字符串S和T，找出S中包含T的最小窗口， 要求O(n)复杂度

思路：360实习机试时遇到的一个算法题，“最短摘要字符串”，
（1）
a.用一个哈希表m存储t中字符出现的次数，扫描s,用哈希表has存储t中出现的字符的数量（初始化为0），用一个队列q存储has中出现的字符及其位置, 
  用一个记数器n，初始化为t的长度
b.扫描字符串s, 当当前字符在哈希表m中，将其在哈希表has中的数量加1，即++has[s[i]]，将（s[i]，i）放入队列q中，
c.当s[i]要has中的数量小于等于m中的数量，则记数器n减1.
d.当n=0时，说明找到一个窗口，从队列q的队首开始查找，如果队首字符在has中的数量大于m中数量，则出队且在has中的数量减1，
  当队首字符在has中的数量小于等于m中，则该字符为窗口起点，与之前的最小窗口大小对比，小则更新最小窗口大小及其窗口起点。
e. 重复b-d，直到s扫描结束。
*/

class Solution {
public:
    string minWindow(string s, string t) {
		if(s.empty() || t.empty() || t.size() > s.size()) return "";		
		map<char, int> m;
		map<char, int> has;
		queue<pair<char,int> > q; //使用队列存储在s中出现的t中的字符及位置
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
						q.pop(); //找到第一个去除多余元素
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
