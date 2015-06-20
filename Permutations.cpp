#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Given a collection of numbers, return all possible permutations.
For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

����������һ�����飬���ظ������е����е��������У�
˼·���ݹ飬������ȱ������������п�������

*/

class Solution {
public:
	//�ݹ�ʵ��
    vector<vector<int > > permute(vector<int >& nums){
        int n = nums.size();
		vector<vector<int > > ans;
		vector<int > cur;
		if(n == 0) return ans;
		//sort(nums.begin(), nums.end());
		getPermute(nums, ans, cur);
		return ans;
    }
	void getPermute(vector<int > &nums, vector<vector<int > > &ans, vector<int > &cur){
		if(nums.size() == cur.size()){
			ans.push_back(cur);
			return;
		}
		for(int i = 0; i < nums.size(); i++){ //����û���ظ�������
		    bool isAppear = false; //�Ƿ���ֹ�
			for(int j = 0; j < cur.size(); j++)
				if(cur[j] == nums[i]) isAppear = true;
			if(!isAppear){
				cur.push_back(nums[i]);
				getPermute(nums, ans, cur);
				cur.pop_back(); //�ع�
			}
		}
	}
	//�ǵݹ�ʵ��
	vector<vector<int > > permute(vector<int >& nums){
        int n = nums.size();
		vector<vector<int > > ans;
		vector<int > cur;
		if(n == 0) return ans;
		
		return ans;
    }
};

int main(){
	Solution c;
	vector<int > nums;
	int A[] = {4,2,3};
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	vector<vector<int > > ans = c.permute(nums);
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
