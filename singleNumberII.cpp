#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
�������һ�� Single Number���������λ���㡣
���� 1������һ������Ϊ sizeof(int) ������ count[sizeof(int)]��count[i] ��ʾ���� i λ
���ֵ� 1 �Ĵ�������� count[i] �� 3 ��������������ԣ�����ͰѸ�λȡ������ɴ𰸡�
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
