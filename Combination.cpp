#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

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
������������������n��k,��������k��������ϡ�
˼·���ݹ���⣬��Permutationһ������

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
		if(k == 0){ //�ݹ��յ�
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

