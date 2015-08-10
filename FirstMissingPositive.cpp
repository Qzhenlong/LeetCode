#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

������������������������飬�ҳ���һ��ȱ�ٵ�������Ҫ���Ӷ�O(n)���ռ临�Ӷ�O(1)

˼·����ȱʧ��������˵���ɺ��Ը�����ͬʱ��һ��ȱ�ٵ�����֮ǰ��������ģ�
��1����������ƿռ䣬ֱ����һ����ϣ����¼�������ֵĴ��������ڹ�ϣ��ļ�ֵ��������ǰ������������ʱ����˵���ҵ���ȱʧ������λ����
��2�����ֻ��O(1)�Ŀռ䣬�и����ʣ���������ֵ��������Ĵ�С�����͵ȼ���һ����ϣ�����Կɽ�i�ŵ�A[i-1]��λ�ã� ɨ��һ�ο�ȫ����λ
	���ǿ��������鱾�����䵱��ϣ����΢��ͨһ�£��ڱ�������Ĺ����а����� i ����A[i-1]��λ�á�
	������A[k] != k+1��˵��k+1�������û�г��ֹ�����������Ĵ�С��n��������ԭʼ�����е�������1��2��n�������Ӧ�÷���n+1��
	����Ҫע�����if���ж�������A[i] != A[A[i]-1]�������ĳ��λ��A[i]�Ѿ�������i+1��������A[i]����Ҫ�����λ��(A[A[i]-1])
	ԭ������A[i]�����������������Ա��������ѭ����������[1,2]��[1,1]��

*/

class Solution {
public:
	//AC, �ռ�O(n)
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> m;
		if(nums.empty()) return 1;
		for(int i = 0; i < nums.size(); ++i) ++m[nums[i]];
		int prev = 0;
		for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
			if(it->first <= 0) continue;
			if(it->first - prev != 1) break;
			prev = it->first;
		}
		return prev+1;
    }
    int _firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n)
        {
            if (A[i] != (i+1) && A[i] >= 1 && A[i] <= n && A[A[i]-1] != A[i]) //��i�ŵ�A[i-1]����
                swap(A[i], A[A[i]-1]);
            else
                i++;
        }
        for (i = 0; i < n; ++i)
            if (A[i] != (i+1))
                return i+1;
        return n+1;
    }
};


int main(){
	Solution c;
	int A[] = {2};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; ++i) nums.push_back(A[i]);
	cout << c.firstMissingPositive(nums);
	return 0;
}
