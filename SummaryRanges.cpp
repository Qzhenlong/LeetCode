#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

����������һ���������ظ����������飬������������Χ���ܽ�

˼·����������ɨ�裬����δ���������ݣ���洢֮ǰ������

���죺������Χ���߽������
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string > ans;
		if(nums.size() == 0) return ans;
		string cur = convert(nums[0]);
		int range = 0; //���䳤��
		for(int i = 1; i < nums.size(); i++){
			range++;
			long long tmp1 = nums[i]; //ע��������Χ
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
