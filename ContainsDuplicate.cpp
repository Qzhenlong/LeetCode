#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> n_map;
		for(int i = 0; i < nums.size(); i++)
		{
			if(n_map.find(nums[i]) != n_map.end()) return true;
			n_map[nums[i]] = i;
		}
		return false;
    }
};

int main()
{
	Solution c;
	vector<int > nums;
	int A[] = {1,1};
	for(int i = 0; i < sizeof(A)/4; i++)
		nums.push_back(A[i]);
	cout << (c.containsDuplicate(nums)? "true" : "false") << endl;
	return 0;
}
