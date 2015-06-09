#include<iostream>
#include<vector>
using namespace std;
/*
原题：
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

解析：查找累加和最大的子数组，返回对应最大和
思路：动态规划，用一个数组来记录以当前元素为结尾的子数组的最大和， 
dp[i] = max(dp[i-1]+nums[i], nums[i]);
*/
class Solution {
public:
    int maxSubArray(vector<int >& nums) {
        int max[nums.size()], i = 1, ans = nums[0];
		if(nums.size() == 0) return 0;
		max[0] = nums[0];
		while(i < nums.size()){
			max[i] = (max[i-1] + nums[i] > nums[i]) ? max[i-1] + nums[i] : nums[i];
			if(ans < max[i]) ans = max[i];
			i++;
		}			
		return ans;
    }
};

int main(){
	Solution c;
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int > n;
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
	cout << c.maxSubArray(n);
	return 0;
}
