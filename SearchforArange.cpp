#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

����������һ����������������һ��Ŀ���������ҳ��������������г��ֵ������յ㣬���δ�ҵ��򷵻�[-1,-1]��Ҫ��ʱ�临�Ӷ�ΪO(logn)

˼·�����ֲ��ң���¼�����յ�����
���ö����ҵ�һ��Ŀ��������λ�ã��ٶԸ�λ�õ����߽��ж��ֲ��ң�ȷ�����½�

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int > range(2, -1);
		int low = 0, high = nums.size()-1, mid;
		while(low <= high){
			mid = (low+high)/2;
			if(nums[mid] == target){
				range[0] = range[1] = mid;
				break;
			}
			if(nums[mid] < target) low = mid+1;
			else high = mid-1;
		}
		//cout << low << " " << mid << " " << high << endl;
		if(range[0] == -1) return range; //���ҵ�һ��Ŀ��������λ�ã� �ٶԸ�λ�õ����߽��ж��ֲ��ң�ȷ�����½�
		int i = low, j = mid-1;
		while(i <= j){ //����[low,mid]��Ԫ��С�ڵ���Ŀ������
			int _mid = (i+j)/2;
			if(nums[_mid] == nums[mid]){
				range[0] = _mid;
				j = _mid-1;
			}
			else i = _mid+1;
		}
		i = mid+1; j = high;
		while(i <= j){ //����[mid,high]��Ԫ�ش��ڵ���Ŀ������
			int _mid = (i+j)/2;
			if(nums[_mid] == nums[mid]){
				range[1] = _mid;
				i = _mid+1;
			}
			else j = _mid-1;
		}
		return range;
    }

};

int main(){
	Solution c;
	vector<int > nums;
	int A[] = {7};
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	vector<int > ans = c.searchRange(nums,7);
	cout << "[" << ans[0] << " , " << ans[1] << "]" <<  endl;
	return 0;
}
