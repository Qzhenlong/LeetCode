#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

����������һ���Ǹ��������飬��λ��������㣬ÿ��Ԫ�ش��������������������ж����ܷ��ߵ����һ��Ԫ��

˼·��
(1)��ʵ�ϣ������������û��0�����Ȼ���ߵ����һ��Ԫ�أ�����ֻ��Ҫ��¼ǰn-1��Ԫ����0���ֵ�λ�ã����ж�0֮ǰ�Ƿ�洢·��ͨ������0����
(2)��̬�滮��״̬ת�Ʒ��̣�dp[i] = max(dp[i-1]-1, A[i]) ,dp[i]��ʾ�����i��λ��ʱ��ʣ����ߵ������
(3)̰���㷨����һ��һ����ǰ����������ܲ��ܳ������һ��λ�ã��ܳ�����˵���ܵ�������ܵ���Ͷ����ࡣ

*/

class Solution {
public:
    //AC,���Ӷ�O(n)
    bool canJump(vector<int>& nums) {
        vector<int > zeroIndex;
		if(nums.size() == 0) return false;
		for(int i = 0; i < nums.size()-1; i++) //ȥ�����һ��Ԫ��
			if(nums[i] == 0) zeroIndex.push_back(i);
		if(zeroIndex.size() == 0) return true; //������0
		for(int i = 0; i < zeroIndex.size(); i++){
		    bool exist = false;
			for(int j = 0; j < zeroIndex[i]; j++){
				if(nums[j] > (zeroIndex[i]-j)){  //����һ��·������
					exist = true;
					break;
				}
			}
			if(!exist) return false;
		}
		return true;
    }
	//��̬�滮��ʱ��O(n),�ռ�O(1)
	bool canJump1(vector<int > &nums){
		if(nums.size() == 0) return false;
		if(nums.size() == 1 && nums[0] == 0) return true;
		int dp = nums[0];
		for(int i = 1; i < nums.size()-1; i++){
			if(dp <= 0) return false;
			dp = max(dp-1, nums[i]) ;
			
		}
		return (dp > 0);
	}
	//̰���㷨
	bool canJump2(vector<int > &nums){
		int reach = 1, n = nums.size(); // reach��ʾ���ҵ��ĸ�λ��
		for (int i = 0; i < reach && reach < n; ++i)
				reach = max(reach, i + 1 + nums[i]); //
		return (reach >= n);
	}
};

int main(){
	Solution c;
	int A[] = {0,0};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.canJump(nums) << endl;
	cout << c.canJump1(nums) << endl;
	cout << c.canJump2(nums) << endl;
	return 0;
}

