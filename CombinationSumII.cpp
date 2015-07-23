#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
��Ŀ��
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

����������һ����ѡ����C��һ��Ŀ������T���ҳ�C�����к�ΪT���Ӽ��ϣ��Ӽ�����������

˼·������ϵķ�����ͬ��ֻȡ���������ļ��ϼ��ɣ��ȶ�C�����ٵݹ����, ȥ���ظ��Ӽ�

*/

class Solution {
public:
    //ȥ�ش���̫��, ��ʱ
    vector<vector<int > > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int > > ans;
		vector<int > cur;
		set<vector<int > > ans_set;
		if(candidates.size() == 0) return ans;
		sort(candidates.begin(), candidates.end());
		for(int k = 1; k <= candidates.size(); k++)
			getCom(candidates, ans, cur, k, 0, target, ans_set);
		return ans;
    }
	void getCom(vector<int > candidates, vector<vector<int > > &ans, vector<int > &cur, int k, int i, int target, set<vector<int > > &ans_set){
		if(k == 0){
			for(int j = 0; j < cur.size(); j++)
				target -= cur[j];
			if(target == 0 && ans_set.find(cur) == ans_set.end()){
				ans.push_back(cur);
				ans_set.insert(cur);
			}
			return;
		}
		if(i >= candidates.size()) return;
		cur.push_back(candidates[i]);
		getCom(candidates, ans, cur, k-1, i+1, target, ans_set);
		cur.pop_back(); //�ع�
		getCom(candidates, ans, cur, k, i+1, target, ans_set);
	}
	//��д�ݹ��㷨 
	vector<vector<int > > _combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int > > ans;
		vector<int > cur;
		if(candidates.size() == 0) return ans;
		sort(candidates.begin(), candidates.end());
		getCom1(candidates, ans, cur, 0, target);
		return ans;
    }
	void getCom1(vector<int > candidates, vector<vector<int > > &ans, vector<int > &cur, int i, int div){
		if(div == 0){
			ans.push_back(cur);
			return;
		}
		int pre = INT_MIN;
		for(int j = i; j < candidates.size(); j++){
			if(pre == candidates[j]) continue; //ֻ��һ��
			if(div < candidates[j]) return; //���������򣬺���һ������div�����Կ��Է�����
			pre = candidates[j];
			cur.push_back(candidates[j]);
			getCom1(candidates, ans, cur, j+1, div-candidates[j]);
			cur.pop_back();
			
		}
	}
};

int main(){
	Solution c;
	int A[] = {10,1,2,7,6,1,2,5};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	vector<vector<int > > ans = c._combinationSum2(nums,8);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
