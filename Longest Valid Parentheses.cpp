#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
题目：
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

解析：给定一个只包含(和)的字符串，找出最长的有效子括号串

思路：
（1）括号问题可采用栈来实现，当遇到右括号时出栈，用一个数组来记录哪些字符匹配成功，最后统计连续的匹配成功的字符数量，找出最大值即可。
    
（2）动态规划，
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int > ps;
		int maxLen = 0, curLen = 0, i = 0;
		if(s.empty()) return 0;
		for(i = 0; i < s.size(); ++i) 
			if(s[i] == '(') break;
		ps.push(i++);
		vector<bool > L(s.size(), false); //标记匹配过的字符 
		while(i < s.size()){
			if(s[i] == '(') ps.push(i);
			else{
				if(!ps.empty()){
					L[i] = true;
					L[ps.top()] = true;
					ps.pop();
				}
			}
			++i;
		}
		for(i = 0; i < L.size(); ++i){
			if(!L[i]) curLen = 0;
			else curLen += L[i];
			maxLen = max(maxLen, curLen);	
		}
	    return  maxLen;
    }
    // Dp Solution. By Andy.
    int _longestValidParentheses_3(string s) {
        int n = s.size();
        if(s.empty()) return 0;
        if(n<=1) return 0;
        int res = 0;
        vector<int> f(n,0);
        for(int i=n-2;i>=0;i--){
            int match = i + f[i+1] + 1;
            if(match<n&&s[i]=='('&&s[match]==')'){
                f[i]=f[i+1]+2;
                if(match+1<n) f[i]+=f[match+1];
            }
            res = max(res,f[i]);
        }
        return res;
    }
};

int main(){
	Solution c;
	string s = "(()(((()";
	cout << c.longestValidParentheses(s);
	return 0;
}
