#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

解析：求给定排列的下一种排列，新排列比原排列组成的数字要大，如果没有这样的排列，则返回最小的排列，即升序排列，要求不使用辅助空间

思路：从右往左找到第一个非增的位置i，然后从右往左找出第一个比它大的元素位置j，将i,j所在位置元素交换，再把i之后的元素翻转即可，
如果从右往左一直递增,那么给定排列是降序排列，没有下一种比之大的排列，可直接将其转为升序排列，
	  
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n-1, j = i;
		while(i > 0 && nums[i] <= nums[i-1]) i--;
		if(i == 0) sort(nums.begin(), nums.end());
		else{
			while(j > 0 && nums[j] <= nums[i-1]) j--;
			int tmp = nums[j];
			nums[j] = nums[i-1];
			nums[i-1] = tmp;
			//翻转后序元素
			for(int k = 0; k < (n-i)/2; k++){
				tmp = nums[i+k];
				nums[i+k] = nums[n-k-1];
				nums[n-k-1] = tmp;
			}
		}
    }
};

int main(){
	Solution c;
	int A[] = {3,2,3,6,5,4};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	c.nextPermutation(nums);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	return 0;
}
