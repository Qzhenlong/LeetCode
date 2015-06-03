#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //平均时间复杂度O(k*n), 最坏O(n^2)
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() <= 1) return nums[0];
		for(int i = 0; i < k; i++)
		{
			int kmax = nums[0];
			int tmpi = 0;
			for(int j = 1; j < nums.size(); j++)
			{
				if(kmax < nums[j]){ kmax = nums[j]; tmpi = j; }
			}
			if(i == k-1) return kmax;
			else nums.erase(nums.begin()+tmpi);
		}
    }
    //利用快排思路，平均时间复杂度O(n), 最坏O(n^2)
    int findKthLargest1(vector<int>& nums, int k) {
        int low = 0, high = nums.size()-1;
		while(low < high)
		{
			int i = low, j = high, key = nums[i];
			while(i != j)
			{
				while(i < j && key >= nums[j]) j--; //降序
				nums[i] = nums[j];
				while(i < j && key < nums[i]) i++;
				nums[j] = nums[i];
			}
			nums[i] = key;
			if(i == k-1) return key;
			if(i < k-1) low = i+1;
			else high = i-1;
		}
		return nums[k-1];
    }
};

int main()
{
	Solution c;
	vector<int > n;
	int A[] = {2,1};
	for(int i = 0; i < sizeof(A)/4; i++)
		n.push_back(A[i]);
	cout << c.findKthLargest1(n, 2);
	return 0;
}
