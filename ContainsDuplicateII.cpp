#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*
给定一个整数数组nums与一个整数k，当且仅当存在两个不同的下标i和j满足nums[i] = nums[j]并且| i - j | <= k时返回true，否则返回false。
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> n_map;
		int c = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(n_map.find(nums[i]) != n_map.end() && (i-n_map[nums[i]]) <= k) c++;
			n_map[nums[i]] = i;
		}
		if(c == 1) return true;
		return false;        
    }
};

int main()
{
	Solution c;
	vector<int > nums;
	int A[] = {1,2,1,4,5,4};
	for(int i = 0; i < sizeof(A)/4; i++)
		nums.push_back(A[i]);
	cout << (c.containsNearbyDuplicate(nums,2)? "true" : "false") << endl;
	return 0;
}
