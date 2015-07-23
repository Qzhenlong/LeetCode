#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
Given an integer array of size n, find all elements that appear more than ? n/3 ? times. The algorithm should run in linear time and in O(1) space.

����������һ����СΪn�����飬�ҳ����г��ִ�������n/3��Ԫ��

˼·��
��1����������ǿռ䣬ֱ���ù�ϣ��洢���ִ�������, Ҳ��AC
��2���ҳ�������ѡ���������ж������Ƿ�����Ҫ�󣬳���1/3��Ԫ�ز��ᳬ��2��
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
