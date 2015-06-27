#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
原题：Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

解析：给定一个未排序的整数数组，找出最长连续序列的长度，要求算法复杂度为O(n);

思路：
（1）以时间换空间，定义一个大小为n的哈希表a，以数组元素为键，取值为数组元素值加1，扫描一次数组可将哈希表构建完毕。
	 对哈希表进行一次扫描，定义另一个哈希表b表示a中元素是否被访问过，当对a扫描完成时，可得到最长连续序列的长度。
	 时间复杂度 O(n)，空间复杂度 O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.size() <= 1) return nums.size();
		map<int, int> a; //存储连续关系
		map<int, bool> b; //标记a中元素是否被访问过。
		for(int i = 0; i < nums.size(); i++){
			a[nums[i]] = nums[i]+1;
			b[nums[i]] = false; //初始化，都未被访问
		}
		int maxLen = 0, visitNum = 0;
		map<int, bool>::iterator it = b.begin();
		while(visitNum < a.size()){
			int curMax = 1, index;
			while(it->second) it++; //找到未访问过的元素
			it->second = true; //已访问
		    index = a[it->first];
			visitNum++;
			while(a.find(index) != a.end() && !b[index]) { //下一个连续元素存在，且未被访问过
				curMax++;   //连续元素的长度
				visitNum++; //访问数
				b[index] = true; //已访问
				index = a[index]; //查找下一个连续元素
			}
			if(maxLen < curMax) maxLen = curMax;
		}
		return maxLen;
    }
};

int main(){
	Solution c;
	vector<int > nums;
	int A[] = {100, 4, 200, 1, 3, 2, 8, 9, 101,102,10,11,201,12,5,6};
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.longestConsecutive(nums);
	return 0;
}
