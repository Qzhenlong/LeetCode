#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
O(n)思路：
使用两个指针，start和end，end先往前移动，
当总和大于s时，开始移动start, 
当总和小于s时，再开始移动end，
记录当前最小区间长度
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0, min = nums.size(), sum = 0, exist = 0;
		if(nums.size() == 0) return 0;
		while(end <= nums.size())
		{
			if(end == nums.size() && sum < s) break;
			if(sum < s) sum += nums[end++];
			else{
				exist = 1;
				min = (min < (end-start)) ? min : (end-start);
				sum -= nums[start++];
			}
		}
		if(exist == 0) return 0;
		return min;
    }
};

int main()
{
	Solution c;
	vector<int > n;
	int A[] = {7};
	int s = 7;
	for(int i = 0; i < sizeof(A)/4; i++)
		n.push_back(A[i]);
	cout << c.minSubArrayLen(s, n) << endl;
	return 0;
}

