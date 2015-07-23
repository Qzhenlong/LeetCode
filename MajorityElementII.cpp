#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
Given an integer array of size n, find all elements that appear more than ? n/3 ? times. The algorithm should run in linear time and in O(1) space.

解析：给定一个大小为n的数组，找出所有出现次数大于n/3的元素

思路：
（1）如果不考虑空间，直接用哈希表存储出现次数即可, 也能AC
（2）找出两个候选众数，再判断两数是否满足要求，超过1/3的元素不会超过2个
*/

class Solution {
public:
    vector<int> majorityElement(vector<int >& nums) {
         map<int, int> IntMap;
		 vector<int > ans;
        int major;
        for(int i = 0; i < nums.size(); i++) IntMap[nums[i]] = 0;
        for(int i = 0; i < nums.size(); i++) IntMap[nums[i]]++;
        for(map<int, int>::iterator it = IntMap.begin(); it != IntMap.end(); it++)
                if(it->second > nums.size()/3){ 
                             ans.push_back(it->first);
                          }
        return ans;       
    }
    vector<int> _majorityElement(vector<int >& nums) {
        vector<int> ans;
		int a = 0, b = 0, an = 0, bn = 0;
		for(int i = 0; i < nums.size(); i++){
			if(a == nums[i]) an++;
			else if(b == nums[i]) bn++;
			else if(an == 0){
				a = nums[i];
				an++;
			}
			else if(bn == 0){
				b = nums[i];
				bn++;
			}
			else{
				an--;
				bn--;
			}
		}
		an = bn = 0;
		for(int i = 0; i < nums.size(); i++){
			if(a == nums[i]) an++;
			else if(b == nums[i]) bn++;
		}
		if(an > nums.size()/3) ans.push_back(a);
		if(bn > nums.size()/3) ans.push_back(b);
		return ans;
	}
     vector<int> __majorityElement(vector<int >& nums) {
        vector<int> ans;
		int a = 0, b = 0, an = 0, bn = 0;
		for(int i = 0; i < nums.size(); i++){
			if(an == 0 || a == nums[i]){
				a = nums[i];
				an++;
			}
			else if(bn == 0 || b == nums[i]){
				b = nums[i];
				bn++;
			}
			else{
				an--;
				bn--;
			}
		}
		an = bn = 0;
		for(int i = 0; i < nums.size(); i++){
			if(a == nums[i]) an++;
			else if(b == nums[i]) bn++;
		}
		if(an > nums.size()/3) ans.push_back(a);
		if(bn > nums.size()/3) ans.push_back(b);
		return ans;
	}
};

int main()
{
  Solution c;
  int el[] = {8,8,7,7,7};
  vector<int > num;
  for(int i = 0; i < sizeof(el)/4; i++) num.push_back(el[i]);
  vector<int > ans = c.__majorityElement(num);
  for(int i = 0; i < ans.size(); i++)
	cout << ans[i] << " ";
  return 1;   
}
