#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

解析：给定一个未排序的数组，找出在有序情况下连续元素的最大差异值，要求线性时间与空间，如果数组小于两个元素则返回0，假定数组中全为正数

思路：没想出来，查了一下答案，应该使用桶排序
思路是这样的：数组中有N个元素，最小的元素为min，最大的元素为max，那么最大的间距将不小于ceil((max-min)/(N-1))。（其中，ceil(x)指的是不小于x的最小整数）。
假设平均间距为gap=ceil((max-min)/(N-1))，把所有的元素放进N-1个桶里，第k(0<=k<=N-2)个桶里放所有位于区间[min+k*gap, min+(k+1)*gap)内的元素。
因此除了最大的元素max和最小的元素min，其余的N-2个元素都被放进这N-1个桶里，因此至少有一个桶是空的，我们只需要存储每个桶里最大的元素和最小
的元素就可以算出最大的间距是多少。
注：一个区间内元素的差异不会超过gap, 而最大差异不会小于gap， 同时上一区间的最大值与下一区间的最小值在有序排列中必然是相邻
*/

class Solution {
public:
int maximumGap(vector<int> &nums) {
        if (nums.empty() || nums.size() == 1) return 0;
 
        int min = nums[0], max = nums[0];
        for(int i = 0; i < nums.size(); i++)  {
            if (nums[i] < min) min = nums[i];
            if (nums[i] > max) max = nums[i];
        }
 
        int gap = (max - min - 1) / (nums.size() - 1) + 1; //平均间隔
        vector<int> bucketMins(nums.size() - 1, INT_MAX); //用于将区间内最大值与最小值的桶
        vector<int> bucketMaxs(nums.size() - 1, INT_MIN);
 
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] != min && nums[i] != max) {
                int bucketIdx = (nums[i] - min) / gap;
                if (nums[i] < bucketMins[bucketIdx]) bucketMins[bucketIdx] = nums[i];
                if (nums[i] > bucketMaxs[bucketIdx]) bucketMaxs[bucketIdx] = nums[i];
            }
        }
 
        int maxGap = INT_MIN, prev = min;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (bucketMins[i] == INT_MAX && bucketMaxs[i] == INT_MIN) continue;
            if (bucketMins[i] - prev > maxGap) maxGap = bucketMins[i] - prev;
            prev = bucketMaxs[i];
        }
 
        return std::max(max - prev, maxGap);
    }
};

int main(){
	Solution c;
	int A[] = {5,7,4,3};
	vector<int > numss;
	for(int i = 0; i < sizeof(A)/4; i++) numss.push_back(A[i]);
	cout << c.maximumGap(numss);
	return 0;
}
