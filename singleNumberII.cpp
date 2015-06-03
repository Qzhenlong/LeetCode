#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
本题和上一题 Single Number，考察的是位运算。
方法 1：创建一个长度为 sizeof(int) 的数组 count[sizeof(int)]，count[i] 表示在在 i 位
出现的 1 的次数。如果 count[i] 是 3 的整数倍，则忽略；否则就把该位取出来组成答案。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = sizeof(int)*8;
		int ans = 0, bn[len];
		for(int i = 0; i < len; i++) bn[i] = 0;
		for(int i = 0; i < nums.size(); i++)
			for(int j = 0; j < len; j++)
				bn[j] += ((nums[i] >> j) & 1);
		for(int i = 0; i < len; i++) bn[i] %= 3;
		for(int i = 0; i < len; i++) ans += (bn[i] << i);
		return ans;
    }
};
int main()
{
  Solution c;
  int A[] = {2,3,2,2,3,3,1};
  vector<int > n;
  for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
  cout << c.singleNumber(n) << endl;
  return 1;   
}
