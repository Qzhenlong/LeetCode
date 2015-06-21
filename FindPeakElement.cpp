#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] �� num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -��.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

���������������еķ�ֵ�㣬��������һ����ֵ�����꣬��ֵ�㶨�壺������Ԫ�ض���.
Ҫ��ʱ�临�Ӷ���Ҫ�ﵽO(logn)

˼·��
(1)��������ʱ�临�Ӷȣ�ֱ���ҳ����ֵ��ȻΪ��ֵ�㣬��ʱ���Ӷ�ΪO(n)��������Ҫ��
(2)����O(logn)���ӶȵĻ���Ӧ�ò��ö��ֲ��ң���ʵ��������ַ�ֵ��֮ǰ������Ӧ���ǵ��������ģ����ֲ��Ҿ��ǽ��������ֵ��ѹ��

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
		while(low <= high){
			int mid = (low+high)/2;
			if(low == high) return low;
			if(nums[mid] < nums[mid+1]) low = mid + 1; //�Ա���������Ԫ�أ�����ֵ���������䲻��ѹ��
			else high = mid;
		}
		return low;
    }
};

int main(){
	Solution c;
	int A[] = {1,2,3,8,4,5,6};
	vector<int > n;
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
	cout << c.findPeakElement(n);
	return 0;
}
