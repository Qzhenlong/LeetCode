#include<iostream>
#include<vector>
using namespace std;
/*
原题：Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
解析：给定两个整数n和k,返回所有k个数的组合。
思路：递归求解，与Permutation一题相似

*/
class Solution {
public:
    vector<vector<int > > combine(int n, int k) {
        vector<vector<int > > ans;
		vector<int > cur;
		if(n <= 0 || k <= 0 || k > n) return ans;
		getCombination(ans, cur, n, k, 1);
		return ans;
    }
	void getCombination(vector<vector<int > > &ans, vector<int > &cur, int n, int k, int i){
		if(k == 0){ //递归终点
			ans.push_back(cur);
			return;
		}
		if(i > n) return;
		cur.push_back(i);
		getCombination(ans, cur, n, k-1, i+1);
		cur.pop_back();
		getCombination(ans, cur, n, k, i+1);
	}
};

int main(){
	Solution c;
	vector<vector<int > > ans = c.combine(4,2);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}

