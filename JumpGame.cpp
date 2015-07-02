#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

解析：给定一个非负整数数组，你位于数组起点，每个元素代表你可以跳的最大步数，判断你能否走到最后一个元素

思路：
(1)事实上，如果果数组中没有0，则必然能走到最后一个元素，所以只需要记录前n-1个元素中0出现的位置，并判断0之前是否存储路径通过跳过0即可
(2)动态规划，状态转移方程：dp[i] = max(dp[i-1]-1, A[i]) ,dp[i]表示到达第i个位置时，剩余可走的最大步数
(3)贪心算法：，一层一层往前跳，看最后能不能超过最后一个位置，能超过，说明能到达，否则不能到达，和动规差不多。

*/

class Solution {
public:
    //AC,复杂度O(n)
    bool canJump(vector<int>& nums) {
        vector<int > zeroIndex;
		if(nums.size() == 0) return false;
		for(int i = 0; i < nums.size()-1; i++) //去除最后一个元素
			if(nums[i] == 0) zeroIndex.push_back(i);
		if(zeroIndex.size() == 0) return true; //不存在0
		for(int i = 0; i < zeroIndex.size(); i++){
		    bool exist = false;
			for(int j = 0; j < zeroIndex[i]; j++){
				if(nums[j] > (zeroIndex[i]-j)){  //存在一条路径就行
					exist = true;
					break;
				}
			}
			if(!exist) return false;
		}
		return true;
    }
	//动态规划，时间O(n),空间O(1)
	bool canJump1(vector<int > &nums){
		if(nums.size() == 0) return false;
		if(nums.size() == 1 && nums[0] == 0) return true;
		int dp = nums[0];
		for(int i = 1; i < nums.size()-1; i++){
			if(dp <= 0) return false;
			dp = max(dp-1, nums[i]) ;
			
		}
		return (dp > 0);
	}
	//贪心算法
	bool canJump2(vector<int > &nums){
		int reach = 1, n = nums.size(); // reach表示最右到哪个位置
		for (int i = 0; i < reach && reach < n; ++i)
				reach = max(reach, i + 1 + nums[i]); //
		return (reach >= n);
	}
};

int main(){
	Solution c;
	int A[] = {0,0};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.canJump(nums) << endl;
	cout << c.canJump1(nums) << endl;
	cout << c.canJump2(nums) << endl;
	return 0;
}

