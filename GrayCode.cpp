#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
题目：The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

解析：输入比特宽度，返回格雷码序列（任意两个相邻的序列只有一位二进制数不同）

思路：了解格雷码的转换规则即可，如果二进制码字的第i位和i+1位相同，则对应的格雷码的第i位为0，否则为1,（最高位补0）
如下：
00 -- (0^0)(0^0) -- 00
01 -- (0^0)(0^1) -- 01
10 -- (0^1)(1^0) -- 11
11 -- (0^1)(1^1) -- 00
其实就是n ^ (n >> 1);
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int > ans;
		if(n < 0) return ans;
		double total = pow(2.0, n);
		ans.push_back(0);
		for(int i = 1; i < total; i++){
			int t_ans = 0;
			int cur = (i & 1); //取最低位
			for(int j = 1; j <= n; j++){
				int tmp = (i >> j) & 1;
				t_ans += (((tmp ^ cur) & 1) << (j-1));
				cur = tmp;
			}
			ans.push_back(t_ans);
		}
		return ans;
    }
    vector<int> grayCode1(int n) {
        vector<int > ans;
		if(n < 0) return ans;
		int total = 1 << n;
		ans.push_back(0);
		for(int i = 1; i < total; i++){
			ans.push_back(i ^ (i >> 1));
		}
		return ans;
    }
};

int main(){
	Solution c;
	vector<int > ans = c.grayCode1(4);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
