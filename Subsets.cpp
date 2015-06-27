#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
原题：Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
解析：给定一个集合，集合中元素各不相同，返回所有可能的子集合，所有子集合升序排列
思路：事实上就是返回集合的所有组合，C(n,0)+C(n,1)...+C(n,n), 借此Combination一题的思路，对其进行n+1次调用即可。
*/

class Solution {
public:
    vector<vector<int > > subsets(vector<int >& nums) {
        vector<vector<int > > ans;
		vector<int > cur;
		ans.push_back(cur); //空集
		sort(nums.begin(), nums.end());
		for(int k = 1; k <= nums.size(); k++){
			getCombination(ans, cur, nums, k, 0);
			cur.clear();
		}
		return ans;
    }
	void getCombination(vector<vector<int > > &ans, vector<int > &cur, vector<int > &nums, int k, int i){
		//for(int j = 0; j < cur.size(); j++) cout << cur[j] << " ";
		if(k == 0){
			ans.push_back(cur);
			return;
		}
		if(i >= nums.size()) return;
		cur.push_back(nums[i]);
		getCombination(ans, cur, nums, k-1, i+1);
		cur.pop_back(); //回滚
		getCombination(ans, cur, nums, k, i+1);
	}
	//为了更清楚了解递归过程，写一个非递归算法 
    vector<vector<int > > subsets1(vector<int >& nums) {
        vector<vector<int > > ans;
		vector<int > cur;
		ans.push_back(cur); //空集
		sort(nums.begin(), nums.end());
		for(int k = 1; k <= nums.size(); k++){
			getCombination1(ans, cur, nums, k);
			cur.clear();
		}
		return ans;
    }
	void getCombination1(vector<vector<int > > &ans, vector<int > &cur, vector<int > &nums, int k){
		stack<int > s; //用于存储坐标的栈
		int i = 0;
		s.push(i);
		while(!s.empty()){
		    i = s.top();	
			s.pop();
		    while(cur.size() < k && i < nums.size()){ //连续进栈，直到找到一个排列
				cur.push_back(nums[i]);
				i++;
				s.push(i);
		    }
			if(cur.size() == k) ans.push_back(cur); //找到一个组合，存储
			
			cur.pop_back();   //回滚一个元素	
		}
	}
};

int main(){
	Solution c;
	vector<int > nums,cur;
	int A[] = {1,2,3};
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	vector<vector<int > > ans, ans1;
	ans = c.subsets(nums);
	ans1 = c.subsets1(nums);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << " *** ";
		for(int j = 0; j < ans1[i].size(); j++)
			cout << ans1[i][j] << " ";
		cout << endl;
	}
	return 0;
}
