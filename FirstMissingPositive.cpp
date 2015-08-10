#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

分析：给定的无序的整数数组，找出第一个缺少的正数，要求复杂度O(n)，空间复杂度O(1)

思路：找缺失的正数，说明可忽略负数，同时第一个缺少的正数之前都是有序的，
（1）如果不限制空间，直接用一个哈希表，记录正数出现的次数，由于哈希表的键值递增，当前后正数不相邻时，则说明找到了缺失的正数位置了
（2）如果只有O(1)的空间，有个性质，数组的最大值等于数组的大小，即就等价于一个哈希表，所以可将i放到A[i-1]的位置， 扫描一次可全部归位
	我们可以用数组本身来充当哈希表。稍微变通一下，在遍历数组的过程中把数字 i 放在A[i-1]的位置。
	最后如果A[k] != k+1就说明k+1这个数字没有出现过。由于数组的大小是n，因此如果原始数组中的数字是1，2…n，则最后应该返回n+1。
	还需要注意的是if中判断条件：A[i] != A[A[i]-1]；即如果某个位置A[i]已经放置了i+1或者数字A[i]即将要放入的位置(A[A[i]-1])
	原本就是A[i]，则跳过。这样可以避免出现死循环（如数组[1,2]和[1,1]）

*/

class Solution {
public:
	//AC, 空间O(n)
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> m;
		if(nums.empty()) return 1;
		for(int i = 0; i < nums.size(); ++i) ++m[nums[i]];
		int prev = 0;
		for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
			if(it->first <= 0) continue;
			if(it->first - prev != 1) break;
			prev = it->first;
		}
		return prev+1;
    }
    int _firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n)
        {
            if (A[i] != (i+1) && A[i] >= 1 && A[i] <= n && A[A[i]-1] != A[i]) //把i放到A[i-1]处，
                swap(A[i], A[A[i]-1]);
            else
                i++;
        }
        for (i = 0; i < n; ++i)
            if (A[i] != (i+1))
                return i+1;
        return n+1;
    }
};


int main(){
	Solution c;
	int A[] = {2};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; ++i) nums.push_back(A[i]);
	cout << c.firstMissingPositive(nums);
	return 0;
}
