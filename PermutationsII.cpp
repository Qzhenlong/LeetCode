#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

解析：给定一个可能包含相同数字的数组，返回所有唯一的组合
思路：
（1）不考虑空间，用一个哈希表去重即可，结果：超时，不能使用哈希表去重
（2）统计数组中重复数字的数量，保证相同数字只出现一次就行了,AC
*/
class Solution {
public:
	//超时， 哈希表遍历搜索时间过长
    vector<vector<int > > permuteUnique(vector<int>& nums) {
        map<vector<int >, bool> uniqueAns;
		vector<vector<int > > ans;
		vector<int > cur; 
		if(nums.size() <= 0) return ans;
		dfs(uniqueAns, cur, nums, 0);
		for(map<vector<int >, bool>::iterator it = uniqueAns.begin(); it != uniqueAns.end(); it++)
			ans.push_back(it->first);
		return ans;
    }
	void dfs(map<vector<int >, bool> &uniqueAns, vector<int > &cur, vector<int > nums, int i){
		if(i == nums.size()){
			vector<int > ans;
			for(int k = 0; k < nums.size(); k++) ans.push_back(nums[cur[k]]);
			if(uniqueAns.find(ans) == uniqueAns.end())
				uniqueAns[ans] = true;
			return;
		}
		for(int j = 0; j < nums.size(); j++){
		    //去掉重复的
			bool isExist = false;
			for(int k = 0; k < cur.size(); k++)
				if(cur[k] == j) isExist = true;
			if(!isExist){
				cur.push_back(j); //保存下标即可
				dfs(uniqueAns, cur, nums, i+1);
				cur.pop_back();
			}
		}
	}
	//AC
    vector<vector<int > > permuteUnique1(vector<int>& nums) {
		vector<vector<int > > ans;
		vector<int > cur; 
		if(nums.size() <= 0) return ans;
		_dfs(ans, cur, nums);
		return ans;
    }
	void _dfs(vector<vector<int > > &ans, vector<int > &cur, vector<int > nums){
		if(cur.size() == nums.size()){
		    vector<int > oneans;
			for(int k = 0; k < nums.size(); k++) oneans.push_back(nums[cur[k]]);
			ans.push_back(oneans);
			return;
		}
		map<int, bool> visited;
		for(int i = 0; i < nums.size(); i++) visited[nums[i]] = false;
		for(int j = 0; j < nums.size(); j++){
		    //相同数字仅使用一次	
			bool isExist = false;
			for(int k = 0; k < cur.size(); k++)
				if(cur[k] == j) isExist = true;
				
			if(!isExist && !visited[nums[j]]){
				visited[nums[j]] = true;
				cur.push_back(j);
				_dfs(ans, cur, nums);
				cur.pop_back();
			}
		}
	}
};

int main(){
	Solution c;
	vector<int > nums;
	int A[] = {1,1,1,2};
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	vector<vector<int > > ans = c.permuteUnique1(nums);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
