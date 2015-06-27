#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
ԭ�⣺Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

����������һ��δ������������飬�ҳ���������еĳ��ȣ�Ҫ���㷨���Ӷ�ΪO(n);

˼·��
��1����ʱ�任�ռ䣬����һ����СΪn�Ĺ�ϣ��a��������Ԫ��Ϊ����ȡֵΪ����Ԫ��ֵ��1��ɨ��һ������ɽ���ϣ������ϡ�
	 �Թ�ϣ�����һ��ɨ�裬������һ����ϣ��b��ʾa��Ԫ���Ƿ񱻷��ʹ�������aɨ�����ʱ���ɵõ���������еĳ��ȡ�
	 ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.size() <= 1) return nums.size();
		map<int, int> a; //�洢������ϵ
		map<int, bool> b; //���a��Ԫ���Ƿ񱻷��ʹ���
		for(int i = 0; i < nums.size(); i++){
			a[nums[i]] = nums[i]+1;
			b[nums[i]] = false; //��ʼ������δ������
		}
		int maxLen = 0, visitNum = 0;
		map<int, bool>::iterator it = b.begin();
		while(visitNum < a.size()){
			int curMax = 1, index;
			while(it->second) it++; //�ҵ�δ���ʹ���Ԫ��
			it->second = true; //�ѷ���
		    index = a[it->first];
			visitNum++;
			while(a.find(index) != a.end() && !b[index]) { //��һ������Ԫ�ش��ڣ���δ�����ʹ�
				curMax++;   //����Ԫ�صĳ���
				visitNum++; //������
				b[index] = true; //�ѷ���
				index = a[index]; //������һ������Ԫ��
			}
			if(maxLen < curMax) maxLen = curMax;
		}
		return maxLen;
    }
};

int main(){
	Solution c;
	vector<int > nums;
	int A[] = {100, 4, 200, 1, 3, 2, 8, 9, 101,102,10,11,201,12,5,6};
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.longestConsecutive(nums);
	return 0;
}
