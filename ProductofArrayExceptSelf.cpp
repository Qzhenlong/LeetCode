#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

������
����һ�����飬����һ������output,ʹ��output[i]���ڳ�nums[i]�������Ԫ�صĳ˻���Ҫ��ʹ�ó����Ҹ��Ӷ�ΪO(n)

˼·��
��1��ʹ����������A,B��A[i]��ʾ��0-i-1�ĳ˻���B[i] ��ʾ��i+1�����һ��Ԫ�صĳ˻�������������Ķ�Ӧλ�õ�Ԫ����˼��ɡ�
��2���Ż��ռ�Ļ�����ֱ����output�������ݴ棬��������ɨ��

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int > ans(nums.size(), 0);
		vector<int > A(nums.size(), 1), B(nums.size(), 1);
		int p1 = nums[0], p2 = nums[nums.size()-1];
		for(int i = 1, j = nums.size()-2; i < nums.size(); i++, j--){
			A[i] = p1; p1 *= nums[i]; 
			B[j] = p2; p2 *= nums[j]; 
		}
		for(int i = 0; i < nums.size(); i++) ans[i] = A[i]*B[i];
		return ans;
    }
	 vector<int> _productExceptSelf(vector<int>& nums) {
        vector<int > ans(nums.size(), 1);	
		for(int i = 1; i < nums.size(); i++) ans[i] = ans[i-1]*nums[i-1];
		int tmp = nums[nums.size()-1];
		for(int i = nums.size()-2; i >= 0; i--){
			ans[i] *= tmp;
			tmp *= nums[i];
		}
		return ans;
    }
};

int main(){
	Solution c;
	vector<int > nums;
	for(int i = 0; i < 5; i++) nums.push_back(i+1);
	vector<int > ans = c._productExceptSelf(nums);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}
