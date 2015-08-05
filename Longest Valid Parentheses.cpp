#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��Ŀ��
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

����������һ��ֻ����(��)���ַ������ҳ������Ч�����Ŵ�

˼·��
��1����������ɲ���ջ��ʵ�֣�������������ʱ��ջ����һ����������¼��Щ�ַ�ƥ��ɹ������ͳ��������ƥ��ɹ����ַ��������ҳ����ֵ���ɡ�
    
��2����̬�滮��
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
		vector<bool > L(s.size(), false); //���ƥ������ַ� 
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
