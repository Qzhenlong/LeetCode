#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;
/*
原题：
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

解析：在集合S中，找出三个之和最接近目标的数，返回该值

我的思路：
利用3Sum的思路找出所有大于或者小于目标的数的临界值，求这些数与目标的差值，并找出最小值即可。

*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int > ans;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size()-2; i++)
		{
			int j = i+1, k = nums.size()-1, sign = 0, pre;
			while(j < k)
			{
				if((nums[i] + nums[j] + nums[k]) < target){ //由于nums已经有序，因此不用回溯
					if(sign == 2) ans.push_back(pre);
					pre = nums[i] + nums[j] + nums[k];
				    j++; sign = 1; 
				}
				else{
				    if(sign == 1) ans.push_back(pre); //交替存入上次的临界值
					pre = nums[i] + nums[j] + nums[k];
					k--; sign = 2;
				}
				if(j == k) ans.push_back(pre); //到边界
			}
		}
		int min = abs(target-ans[0]), res = ans[0];
		for(int i = 1; i < ans.size(); i++)
			if(min > abs(target-ans[i])){ min = abs(target-ans[i]); res = ans[i]; }
		return res;
    }

};

int main()
{
	Solution c;
	int A[] = {2,2,2,4};
	vector<int > num;
	for(int i = 0; i < sizeof(A)/4; i++)
		num.push_back(A[i]);
	cout << c.threeSumClosest(num, 1) << endl;

	return 0;
}
