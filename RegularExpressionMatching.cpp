#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true ,..="aa"
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true 

解析：实现通配符表达式，.表示任意单个字符，*表示它可以匹配之前的0个或者任意多个字符，0个说明前面的字符没有了。

思路：做不出来，
（1）官网答案，看不太懂
（2）动态规划，还比较好理解, 考虑p去匹配s
     dp[i][j]表示字串 s[0...i), p[0...j) 是否可以匹配。
	a. 初始dp[0][0]为true
	b. 当s[i-1] == '.' 或 p[i-1] == '.'时，当前必然能匹配，所以dp[i][j] = dp[i-1][j-1];
	c. 当s[i-1] == '*'时，s[i-1]可忽略也可不忽略，代表0个前个字符，说明前一个字符被忽略，则dp[i][j] = dp[i-2][j]
	   如果*代表1个前一个字符,即s[i-1]当作没有字符,则dp[i][j] = dp[i-1][j]，所以dp[i][j] = dp[i-1][j] || dp[i-2][j];
	   注：由于我们只考虑s[0..i)与p[0...j)是否匹配，因此只需要考虑*表示0个或者1个前一个字符的情况就可以了~
	d. 当p[j-1] == '*'时，p[i-1]可忽略也可不忽略，与上面的情况一样，dp[i][j-1] || dp[i][j-2]
	   同时如果s[0..i-1)与p[0...j)可以匹配的话，由于*可以表示n个前面之前的字符，所以p[j-1]可表示任意多个p[j-2]，
	   当s[i-1]==p[j-2] || p[j-2]=='.'， p[j-1]必然能与s[i-1]匹配， 
	   所以dp[i][j] = dp[i][j-1] || dp[i][j-2] || (dp[i-1][j] && (s[i-1] = p[j-2] || p[j-2] = '.'));
	e. 其它情况就是判断当前字符是否相等，所以dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];

*/

class Solution {
public:
    bool _isMatch(string s, string p) {
		const char *ss = s.c_str();
		const char *pp = p.c_str();
		return stdMatch(ss, pp);
    }
	//动态规划
    bool isMatch(string s, string p) {
	    int ns = s.size(), np = p.size();
	    vector<vector<bool> > dp(ns+1,vector<bool>(np+1,false));
	    dp[0][0]=true; //空字符可以匹配
	    for(int i = 1; i <= ns; ++i) //s也可能存在为*的情况
		    if (s[i-1]=='*'  && i > 1) //如果为*，说明可以忽略，*可以为空或前面任意字符
			    dp[i][0]=dp[i-2][0];
	    
	    for(int j = 1; j <= np; ++j) //相同道理
		    if ( p[j-1]=='*' && j > 1)
			    dp[0][j]=dp[0][j-2];
		 
	    for(int i = 1; i <= ns; ++i){
		    for(int j = 1;j <= np; ++j){
			    if (s[i-1]=='.'|| p[j-1]=='.') //.号可以表示任意字符，因此直接等于上前面的情况
				    dp[i][j] = dp[i-1][j-1];
			    else if (s[i-1]=='*' && i > 1) //如果s[i-1]是*号， 可以忽略也可以不忽略，所以dp[i][j]=dp[i-1][j](不忽略）或dp[i-1][j]（忽略）
				    dp[i][j] = dp[i-1][j] || dp[i-2][j]; 
			    else if ( p[j-1]=='*' && j > 1) //如果s[i]是普通字符且p[j-1]是*号，同样可忽略也可不忽略，同时
				    dp[i][j] = dp[i][j-1] || dp[i][j-2] || (dp[i-1][j] && (s[i-1]==p[j-2]||p[j-2]=='.'));
			    else   //否则就看当前字符是否相等
				    dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
		    }
	    }
	    return dp[ns][np];
    }
/*
递归解法的思路：
两个指针i, j，i指regular expression，j指真的string。
观察p[i+1]，
如果它不是*，说明没法skip p[i]，则p[i]和s[j]必须match（相等或者p[i]是’.’ which matches everything）。如果不满足，直接返回false，没法matche了。
如果它是*，说明当前位置可以是0个p[i], 1个p[i], 2个p[i]..
先试试“用0个p[i]“，即把p[i]和他后面的* skip掉。若recurse (i + 2, j)成功了，直接返回true，不成功，接着做第二步。
从“用1个p[i]“开始while循环，若p[i]和s[j] match, recurse on (i + 2, j + 1)（把*用掉了所以i+2），如果返回true就直接成了，否则就while继续循环“用2个p[i]“，
即recurse on (i + 2, j + 2), recurse on (i + 2, j + 3)…循环的终止条件是p[i]和s[j]不match了，直接返回false。
*/
	bool stdMatch(const char *s, const char *p){
         if (*p == '\0') return *s == '\0';
        
        if (*(p+1) == '*') // next is '*'
        {
            while ((*s == *p || *p == '.') && *s != '\0') // 用i个*p开始循环，如果能与s匹配则继续 
            {
                if (isMatch(s, p+2))
                    return true;
                s++;
            }
            return isMatch(s, p+2); //不能匹配就直接用0个*ps
        }
        
        if (*s == '\0') return false;
        return (*s == *p || *p == '.') && isMatch(s+1, p+1);  //如果*(p+1)不是*
	}

};

int main(){
	Solution c;
	cout << c.isMatch("aba", "a*b") << endl;
	return 0;
}
