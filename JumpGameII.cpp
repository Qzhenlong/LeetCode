#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

解析：给定一个数组，表示一次能走的最大步数，目标是使用最少的跳数到达终点

思路：
（1）minStep记录步数，假设当前点i可到达的最远距离为dist, 则下一步可以到达最远的距离为max(nums[k]+k+i), k = i+1,i+2.., 依次类推
    a. 初始化i = 0, dist = nums[0] = 2, minStep = 1;
	b. max(1+3, 2+1) = 4, 更新minStep = 2, dist = 4, i = 3;
	c. dist可到达终点，结束, 否则继续以上过程

*/

class Solution {
public:
    //AC
    int jump(vector<int >& nums) {
        if(nums.size() <= 1) return 0;
		int minStep = 1, dist = nums[0], i = 0, k = 0;
		while(i < nums.size() && dist < nums.size()-1){
			int tmp = 0;
			for(k = i; k <= dist && k < nums.size()-1; ++k) //求当前点可到达的最大距离
				tmp = max(tmp, nums[k]+k);
			dist = tmp;  //更新最远距离
			++minStep;   //更新所用步数
			i = k;    //更新起点
		}
		return minStep;
    }
};

int main(){
	Solution c;
	int A[] = {2,3,1,1,4};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.jump(nums) << endl;
	return 0;
}

