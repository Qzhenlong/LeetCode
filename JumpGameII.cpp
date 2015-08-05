#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

����������һ�����飬��ʾһ�����ߵ��������Ŀ����ʹ�����ٵ����������յ�

˼·��
��1��minStep��¼���������赱ǰ��i�ɵ������Զ����Ϊdist, ����һ�����Ե�����Զ�ľ���Ϊmax(nums[k]+k+i), k = i+1,i+2.., ��������
    a. ��ʼ��i = 0, dist = nums[0] = 2, minStep = 1;
	b. max(1+3, 2+1) = 4, ����minStep = 2, dist = 4, i = 3;
	c. dist�ɵ����յ㣬����, ����������Ϲ���

*/

class Solution {
public:
    //AC
    int jump(vector<int >& nums) {
        if(nums.size() <= 1) return 0;
		int minStep = 1, dist = nums[0], i = 0, k = 0;
		while(i < nums.size() && dist < nums.size()-1){
			int tmp = 0;
			for(k = i; k <= dist && k < nums.size()-1; ++k) //��ǰ��ɵ����������
				tmp = max(tmp, nums[k]+k);
			dist = tmp;  //������Զ����
			++minStep;   //�������ò���
			i = k;    //�������
		}
		return minStep;
    }
};

int main(){
	Solution c;
	int A[] = {2,3,1,1,4};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.jump(nums) << endl;
	return 0;
}

