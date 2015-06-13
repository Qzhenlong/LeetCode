#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
ԭ�⣺Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, 

with the colors in the order red, white and blue. Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

��������n����������ɫ��ɵ�������з��࣬ʹ�䰴�졢�ס���˳�����У� ������ɫ�ֱ���0��1��2��ʾ������ʹ�ÿ⺯��

˼·���ù�ϣ���¼������ɫ��������Ȼ�����ԭ���鼴��
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
		map<int, int> colorNum; //���Բ��ù�ϣ��ֱ�������鼴��
		for(int i = 0; i < 3; i++) colorNum[i] = 0;
		for(int i = 0; i < nums.size(); i++) colorNum[nums[i]]++;
		nums.clear();
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < colorNum[i]; j++)
				nums.push_back(i);
    }
};
int main(){
	Solution c;
	int A[] = {0, 1, 2, 2, 1, 1, 0};
	vector<int > n;
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
	c.sortColors(n);
	for(int i = 0; i < n.size(); i++)
		cout << n[i] << " ";
	return 0;
}

