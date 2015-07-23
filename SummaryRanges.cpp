#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

解析：给定一个有序无重复的整数数组，返回连续数范围的总结

思路：从左往右扫描，遇到未连续的内容，则存储之前的内容

考察：整数范围，边界问题等
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string > ans;
		if(nums.size() == 0) return ans;
		string cur = convert(nums[0]);
		int range = 0; //区间长度
		for(int i = 1; i < nums.size(); i++){
			range++;
			long long tmp1 = nums[i]; //注意整数范围
			long long tmp2 = nums[i-1];
			if(tmp1-tmp2 > 1){
				if(range > 1){
					cur += "->";
					cur += convert(nums[i-1]);
				}
				ans.push_back(cur);
				cur = convert(nums[i]);
				range = 0;
			}
		}
		range++;
		if(range > 1){
			cur += "->";
			cur += convert(nums[nums.size()-1]);
		}
		ans.push_back(cur);
		return ans;
    }
	string convert(int n){
		string s = "";//(n >= 0) ? "" : "-";
		char str[32];
		s += itoa(n, str, 10);//std::to_string(n);
		return s;
	}
};

int main(){
	Solution c;
	int A[] = {-2147483648,-2147483647,2147483647};
	cout << INT_MAX << endl;
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	vector<string > ans = c.summaryRanges(nums);
	for(int i = 0 ; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
