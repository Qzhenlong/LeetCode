#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
		vector<int > ans;
		for(int i = 0; i < nums.size(); i++)
		{
		    if(index.find(target-nums[i]) != index.end()){ ans.push_back(index[target-nums[i]]); ans.push_back(i+1);  break; }
			//if(nums[i] <= target && index.find(nums[i]) == index.end()) index[nums[i]] = i+1; //找不到则加入哈希表,并记录坐标 
			if(index.find(nums[i]) == index.end()) index[nums[i]] = i+1; //注意负数
		}
		return ans;
    }
};

int main()
{
	Solution c;
	int A[] = {-1,-2,-3,-4,-5}, target=-8;
	vector<int > num;
	for(int i = 0; i < sizeof(A)/4; i++)
		num.push_back(A[i]);
	vector<int > ans = c.twoSum(num, target);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	while(1);
	return 0;
}
