#include<iostream>
#include<vector>
using namespace std;
/*
题目：
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

解析：信息中的A-Z被编码为1-26，给定一个编码好了的信息，确定总共有多少种译码方式

思路：
（1） 由于编码中包含的两位数只有10-26，那么只有以1，2开始的数字可能产生多种译码方式，
      先统计给定的信息中包含的1和2的数量，如果没有1或2，则仅有一种译码方式，如果有1或者2则会导致译码种类的增加，
	  1或2的后面有可能有五种情况：下一字符0，下下个字符为0，为空(末尾），与下一个字符相连大于26， 为其它，
	  前三种都不会引起译码种类的增加，最后一种才会，那么除了1和2的数量和位置信息，还得统计0的位置信息
	  注：判断无法译码的情况，出现连续的0就是无法译码,或者首位为0,或者0前面出现比2大的数也无法译码
（2）上面的思路不对，应该采用动态规划，与阶梯问题类似
	  dp[i] 表示字符s[0.i-1]之间有多少种译码方式
      动态转移方程：dp[i] = dp[i-1] + dp[i-2];
	  a.先去除之前错误思路中给出的无法译码的情况
	  b.如果当前字符s[i-1]为‘0’的话，则不能与上一字符分离，不可以加上dp[i-1], 继续判断s[i-2]
	  c.如果s[i-2]为1，或者为2且s[i-1] <= '6', 则可加上dp[i-2]
*/

class Solution {
public:
	//思路错误
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
		if(s.size() == 1) return 1;
		int ans = 1, i = 0; //
		for(i = 0; i < s.size()-1; i++) //检测无法编码的情况
			if((s[i] == '0' && s[i+1] == '0') || (s[i] > '2' && s[i+1] == '0')) return 0;
			
		for(i = 0; i < s.size()-2; i++)
			if(s[i] == '1' && s[i+1] != '0' && s[i+2] != '0') ans++;
			else if(s[i] == '2' && s[i+1] <= '6' && s[i+1] != '0' && s[i+2] != 0) ans++;

		if((s[i] == '1' && s[i+1] != '0') || (s[i] == '2' && s[i+1] != '0' && s[i+1] <= '6')) ans++;
		return ans;
    }
    int _numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
		vector<int > dp(s.size()+1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 0; i < s.size()-1; i++) //检测无法编码的情况
			if((s[i] == '0' && s[i+1] == '0') || (s[i] > '2' && s[i+1] == '0')) return 0;
		for(int i = 2; i <= s.size(); i++){
		    if(s[i-1] != '0') dp[i] += dp[i-1]; //如果当前字符为‘0’的话，则不能与上一字符分离，不可以加上dp[i-1],
			if(s[i-2] == '1'||(s[i-2] == '2' && s[i-1] <= '6')) dp[i] += dp[i-2]; //如果上一字符满足条件，那么可以加上dp[i-2]
		}
		return dp[s.size()];
	}			
};

int main(){
	Solution c;
	cout << c._numDecodings("1212");
	return 0;
}
