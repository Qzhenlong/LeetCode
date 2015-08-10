#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "*") �� true
isMatch("aa", "a*") �� true
isMatch("ab", "?*") �� true
isMatch("aab", "c*a*b") �� false

������?�ſ��Ա�ʾ���ⵥ���ַ���*���Ա�ʾ�����ַ����У����������У��ж�s��p�Ƿ�ƥ��

˼·����Regular Expression Matching�����࣬��һ�㣬��Ϊ*�ɱ�ʾ�������У�������ǰ����ֹ������У�
	���Բ��ö�̬�滮ʱ���ж���������һ��
	dp[i][j]��ʾs[0..,i)��p[0...j)�ܷ�ƥ�䣬
	a. ��ʼdp[0][0]Ϊtrue
	b. ��s[i-1] == '?' �� p[i-1] == '?'ʱ����ǰ��Ȼ��ƥ�䣬����dp[i][j] = dp[i-1][j-1];
	c. ��s[i-1] == '*'ʱ��s[i-1]�ɱ�ʾ�����ַ����У�s[i-1]�ɵ��ڿմ����ߵ���p[j-1]������dp[i][j] = dp[i-1][j] || dp[i-1][j-1];
	d. ��p[j-1] == '*'ʱ��p[i-1]�ɱ�ʾ�����ַ����У�p[i-1]�ɵ��ڿմ�(dp[i][j] = dp[i][j-1]), �ɵ���s[i-1](dp[i][j] = dp[i-1][j-1] || dp[i-1][j])
	   dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1] 
	e. ������������жϵ�ǰ�ַ��Ƿ���ȣ�����dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
	
	��������ù������齵�Ϳռ临�Ӷ�
*/

class Solution {
public:
	//AC
    bool isMatch(string s, string p) {
 	    int ns = s.size(), np = p.size();
	    vector<vector<bool> > dp(ns+1,vector<bool>(np+1,false));
	    dp[0][0]=true; //���ַ�����ƥ��
	    for(int i = 1; i <= ns; ++i) //sҲ���ܴ���Ϊ*�����
		    if (s[i-1]=='*') //���Ϊ*��˵�����Ժ��ԣ�*����Ϊ�ջ�ǰ�������ַ�
			    dp[i][0]=dp[i-1][0];
	    
	    for(int j = 1; j <= np; ++j) //��ͬ����
		    if ( p[j-1]=='*')
			    dp[0][j]=dp[0][j-1];
		 
	    for(int i = 1; i <= ns; ++i){
		    for(int j = 1;j <= np; ++j){
			    if (s[i-1]=='?'|| p[j-1]=='?') //?�ſ��Ա�ʾ�����ַ������ֱ�ӵ�����ǰ������
				    dp[i][j] = dp[i-1][j-1];
			    else if (s[i-1]=='*') //���s[i-1]��*�ţ� ����i�����ѭ������pȥƥ��s
				    dp[i][j] = dp[i-1][j] || dp[i-1][j-1]; 
			    else if ( p[j-1]=='*') //���p[j-1]��*�ţ�ͬ���ɺ���Ҳ�ɲ���
				    dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1];
			    else   //����Ϳ���ǰ�ַ��Ƿ����
				    dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
		    }
	    }
	    return dp[ns][np];       
    }
};

int main(){
	Solution c;
	cout << c.isMatch("aba", "a*b") << endl;
	return 0;
}
