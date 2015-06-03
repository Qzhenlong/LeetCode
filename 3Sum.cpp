#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;
/*
ԭ�⣺
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a �� b �� c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
	
�����������������������a+b+c=0�������������и���Ԫ�鼯�ϣ�ÿ����Ԫ���������С�

�ҵ�˼·��
�ҳ����и��������ų���������£�Ȼ���ҳ��ø���ȡ��������������������֮�͵��ڸ����������������twoSum
ƽ��ʱ�临�Ӷ�Ӧ��ΪO(n^2)����������Ӷ�ΪO(n^3)�Σ���ʱ��

����˼·��
��������ָ�룬�ȶ���������һ��ָ��a��ͷ��β������a��������������ָ��b,c�ֱ�ָ��a���λ�ü�����λ�ã���a���沿�����м���мбƣ�
����С��Ŀ��ʱb��ǰ�ƣ�������Ŀ��ʱc�����, ������Ŀ��ʱb��ǰc���ͬʱ�ơ�
��Ȼ��ʱ��ԭ������ʹ�����ڲ�STL����ȥ�ء�


*/
class Solution {
public:
    vector<vector<int > > threeSum(vector<int>& nums) {
        vector<vector<int > > ans;
		map<int, int> neg;
		for(int i = 0; i < nums.size(); i++) 
			if(nums[i] < 0) neg[nums[i]] = i; //��ֹ�ظ�
		for(map<int, int>::iterator it = neg.begin(); it != neg.end(); it++)
		{
			int tmp = nums[it->second];
			vector<int > ts = twoSum(nums, 0-tmp, it->second);
			vector<int > cur; 
			for(int j = 0; j < ts.size() / 2; j++)
			{
				int m1 = max(ts[2*j], ts[2*j+1]);
				int m2 = min(ts[2*j], ts[2*j+1]);
				int m3 = min(m2, tmp);
				cur.push_back(m3); cur.push_back(m2); cur.push_back(m1);
				ans.push_back(cur); cur.clear();
			}
		}
		return ans;
    }
    vector<int > twoSum(vector<int>& nums, int target, int exc) {
        map<int, int> index;
		vector<int > ans;
		for(int i = 0; i < nums.size(); i++)
		{
			if(exc == i) continue; 
		    if(index.find(target-nums[i]) != index.end()){ ans.push_back(target-nums[i]); ans.push_back(nums[i]); }
			if(index.find(nums[i]) == index.end()) index[nums[i]] = i+1; //ע�⸺��
		}
		return ans;
    }
    vector<vector<int > > threeSum1(vector<int>& nums) {
        vector<vector<int > > ans;
		set<vector<int > > exist; //��setȥ��
		vector<int > cur;
		if(nums.size() < 3) return ans;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size()-2; i++)
		{
			int j = i+1, k = nums.size()-1;
			while(j < k)
			{
				if((nums[i] + nums[j] + nums[k]) < 0) j++;
				else if((nums[i] + nums[j] + nums[k]) > 0) k--;
				else{
					cur.clear();
					cur.push_back(nums[i]);
					cur.push_back(nums[j]);
					cur.push_back(nums[k]);
					sort(cur.begin(), cur.end());
					if(exist.find(cur) ==  exist.end()) ans.push_back(cur);
					exist.insert(cur);
					j++; k--;
				}
			}
		}
		return ans;
    }	
    vector<vector<int > > threeSum2(vector<int>& nums) {
        vector<vector<int > > ans;
		//set<vector<int > > exist; //��setȥ��
		if(nums.size() < 3) return ans;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size()-2; i++)
		{
			int j = i+1, k = nums.size()-1;
			while(j < k)
			{
				if((nums[i] + nums[j] + nums[k]) < 0) j++;
				else if((nums[i] + nums[j] + nums[k]) > 0) k--;
				else{
					ans.push_back({ nums[i], nums[j], nums[k] });
					//if(exist.find(cur) ==  exist.end()) ans.push_back(cur);
					//exist.insert(cur);
					j++; k--;
					while(j < k && nums[j] == nums[j-1]) j++; //����nums������ģ����Խ���������Ԫ���Ƿ��ظ�����
					while(j < k && nums[k] == nums[k+1]) k--; 
				}
			}
			while(i < nums.size()-2 && nums[i] == nums[i+1]) i++;
		}
		return ans;
    }	
};

int main()
{
	Solution c;
	int A[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int > num;
	for(int i = 0; i < sizeof(A)/4; i++)
		num.push_back(A[i]);
	vector<vector<int > > ans = c.threeSum2(num);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
