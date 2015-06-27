#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
ԭ�⣺Given a set of distinct integers, nums, return all possible subsets.

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
����������һ�����ϣ�������Ԫ�ظ�����ͬ���������п��ܵ��Ӽ��ϣ������Ӽ�����������
˼·����ʵ�Ͼ��Ƿ��ؼ��ϵ�������ϣ�C(n,0)+C(n,1)...+C(n,n), ���Combinationһ���˼·���������n+1�ε��ü��ɡ�
*/

class Solution {
public:
    vector<vector<int > > subsets(vector<int >& nums) {
        vector<vector<int > > ans;
		vector<int > cur;
		ans.push_back(cur); //�ռ�
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
		cur.pop_back(); //�ع�
		getCombination(ans, cur, nums, k, i+1);
	}
	//Ϊ�˸�����˽�ݹ���̣�дһ���ǵݹ��㷨 
    vector<vector<int > > subsets1(vector<int >& nums) {
        vector<vector<int > > ans;
		vector<int > cur;
		ans.push_back(cur); //�ռ�
		sort(nums.begin(), nums.end());
		for(int k = 1; k <= nums.size(); k++){
			getCombination1(ans, cur, nums, k);
			cur.clear();
		}
		return ans;
    }
	void getCombination1(vector<vector<int > > &ans, vector<int > &cur, vector<int > &nums, int k){
		stack<int > s; //���ڴ洢�����ջ
		int i = 0;
		s.push(i);
		while(!s.empty()){
		    i = s.top();	
			s.pop();
		    while(cur.size() < k && i < nums.size()){ //������ջ��ֱ���ҵ�һ������
				cur.push_back(nums[i]);
				i++;
				s.push(i);
		    }
			if(cur.size() == k) ans.push_back(cur); //�ҵ�һ����ϣ��洢
			
			cur.pop_back();   //�ع�һ��Ԫ��	
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
