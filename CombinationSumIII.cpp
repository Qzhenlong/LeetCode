#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 
can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]

分析：给定数字n,给出1到9之间，和为n且元素个数为k的所有集合，集合内元素不重复且递增排列

思路：比前两个都要简单，就是求特定组合种类。

*/

class Solution {
public:
    vector<vector<int > > combinationSum3(int k, int n) {
        vector<vector<int > > ans;
		vector<int > cur;
		if(n <= 0) return ans;
		//getCom(ans, cur, k, 1, n);
		dfs(ans, cur, k, 1, n);
		return ans;
    }
	void getCom(vector<vector<int > > &ans, vector<int > &cur, int k, int i, int n){
		if(k == 0){
			for(int j = 0; j < cur.size(); j++) n -= cur[j];
			if(n == 0) ans.push_back(cur);
			return;
		}
		if(i > 9) return;
		cur.push_back(i);
		getCom(ans, cur, k-1, i+1, n);
		cur.pop_back();
		getCom(ans, cur, k, i+1, n);
	}
	
	void dfs(vector<vector<int > > &ans, vector<int > &cur, int k, int start, int div){
		if(div == 0 && cur.size() == k){
			ans.push_back(cur);
			return;
		}
		for(int j = start; j <= 9; j++){
			if(div < j) return;
			if(cur.size() > k) return;
			cur.push_back(j);
			dfs(ans, cur, k, j+1, div-j);
			cur.pop_back();
		}
	}
};


int main(){
	Solution c;
	vector<vector<int > > ans = c.combinationSum3(3,9);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}

