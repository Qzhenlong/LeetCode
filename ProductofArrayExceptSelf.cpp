#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

解析：
给定一个数组，返回一个数组output,使得output[i]等于除nums[i]外的所有元素的乘积，要求不使用除法且复杂度为O(n)

思路：
（1）使用两个数组A,B：A[i]表示从0-i-1的乘积，B[i] 表示从i+1到最后一个元素的乘积，这两个数组的对应位置的元素相乘即可。
（2）优化空间的话，就直接用output数组做暂存，进行两次扫描

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
