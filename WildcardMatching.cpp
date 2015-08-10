#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

解析：?号可以表示任意单个字符，*可以表示任意字符序列，包括字序列，判断s和p是否匹配

思路：与Regular Expression Matching那题差不多，简单一点，因为*可表示任意序列，而不是前面出现过的序列，
	所以采用动态规划时，判断条件少了一点
	dp[i][j]表示s[0..,i)与p[0...j)能否匹配，
	a. 初始dp[0][0]为true
	b. 当s[i-1] == '?' 或 p[i-1] == '?'时，当前必然能匹配，所以dp[i][j] = dp[i-1][j-1];
	c. 当s[i-1] == '*'时，s[i-1]可表示任意字符序列，s[i-1]可等于空串或者等于p[j-1]，所以dp[i][j] = dp[i-1][j] || dp[i-1][j-1];
	d. 当p[j-1] == '*'时，p[i-1]可表示任意字符序列，p[i-1]可等于空串(dp[i][j] = dp[i][j-1]), 可等于s[i-1](dp[i][j] = dp[i-1][j-1] || dp[i-1][j])
	   dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1] 
	e. 其它情况就是判断当前字符是否相等，所以dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
	
	这里可以用滚动数组降低空间复杂度
*/

class Solution {
public:
	//AC
    bool isMatch(string s, string p) {
 	    int ns = s.size(), np = p.size();
	    vector<vector<bool> > dp(ns+1,vector<bool>(np+1,false));
	    dp[0][0]=true; //空字符可以匹配
	    for(int i = 1; i <= ns; ++i) //s也可能存在为*的情况
		    if (s[i-1]=='*') //如果为*，说明可以忽略，*可以为空或前面任意字符
			    dp[i][0]=dp[i-1][0];
	    
	    for(int j = 1; j <= np; ++j) //相同道理
		    if ( p[j-1]=='*')
			    dp[0][j]=dp[0][j-1];
		 
	    for(int i = 1; i <= ns; ++i){
		    for(int j = 1;j <= np; ++j){
			    if (s[i-1]=='?'|| p[j-1]=='?') //?号可以表示任意字符，因此直接等于上前面的情况
				    dp[i][j] = dp[i-1][j-1];
			    else if (s[i-1]=='*') //如果s[i-1]是*号， 由于i是外层循环，即p去匹配s
				    dp[i][j] = dp[i-1][j] || dp[i-1][j-1]; 
			    else if ( p[j-1]=='*') //如果p[j-1]是*号，同样可忽略也可不忽
				    dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1];
			    else   //否则就看当前字符是否相等
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
