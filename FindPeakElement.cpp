#include<iostream>
#include<vector>
using namespace std;
/*
原题：
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

解析：查找数组中的峰值点，返回其中一个峰值点坐标，峰值点定义：比相邻元素都大.
要求：时间复杂度需要达到O(logn)

思路：
(1)若不考虑时间复杂度，直接找出最大值必然为峰值点，此时复杂度为O(n)，不满足要求
(2)考虑O(logn)复杂度的话，应该采用二分查找，事实上如果出现峰值点之前，数组应该是单调递增的，二分查找就是将区间向峰值点压缩

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
		while(low <= high){
			int mid = (low+high)/2;
			if(low == high) return low;
			if(nums[mid] < nums[mid+1]) low = mid + 1; //对比相邻两个元素，将峰值点所在区间不断压缩
			else high = mid;
		}
		return low;
    }
};

int main(){
	Solution c;
	int A[] = {1,2,3,8,4,5,6};
	vector<int > n;
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
	cout << c.findPeakElement(n);
	return 0;
}
