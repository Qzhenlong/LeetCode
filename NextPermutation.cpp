#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1

��������������е���һ�����У������б�ԭ������ɵ�����Ҫ�����û�����������У��򷵻���С�����У����������У�Ҫ��ʹ�ø����ռ�

˼·�����������ҵ���һ��������λ��i��Ȼ����������ҳ���һ���������Ԫ��λ��j����i,j����λ��Ԫ�ؽ������ٰ�i֮���Ԫ�ط�ת���ɣ�
�����������һֱ����,��ô���������ǽ������У�û����һ�ֱ�֮������У���ֱ�ӽ���תΪ�������У�
	  
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n-1, j = i;
		while(i > 0 && nums[i] <= nums[i-1]) i--;
		if(i == 0) sort(nums.begin(), nums.end());
		else{
			while(j > 0 && nums[j] <= nums[i-1]) j--;
			int tmp = nums[j];
			nums[j] = nums[i-1];
			nums[i-1] = tmp;
			//��ת����Ԫ��
			for(int k = 0; k < (n-i)/2; k++){
				tmp = nums[i+k];
				nums[i+k] = nums[n-k-1];
				nums[n-k-1] = tmp;
			}
		}
    }
};

int main(){
	Solution c;
	int A[] = {3,2,3,6,5,4};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	c.nextPermutation(nums);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	return 0;
}
