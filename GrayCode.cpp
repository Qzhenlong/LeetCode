#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
��Ŀ��The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

������������ؿ�ȣ����ظ��������У������������ڵ�����ֻ��һλ����������ͬ��

˼·���˽�������ת�����򼴿ɣ�������������ֵĵ�iλ��i+1λ��ͬ�����Ӧ�ĸ�����ĵ�iλΪ0������Ϊ1,�����λ��0��
���£�
00 -- (0^0)(0^0) -- 00
01 -- (0^0)(0^1) -- 01
10 -- (0^1)(1^0) -- 11
11 -- (0^1)(1^1) -- 00
��ʵ����n ^ (n >> 1);
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
			int cur = (i & 1); //ȡ���λ
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
