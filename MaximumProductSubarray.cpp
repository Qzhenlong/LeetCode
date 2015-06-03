#include<iostream>
#include<vector>
using namespace std;
/*
�����Ŀ��Minimum Size Subarray Sum

�ҵ�˼·��O(n)
��¼0��-1��λ��, ����0֮��Ϊһ�����䣬��û��0������Ϊԭ������ֹλ�ã����������������¼��������
1����������-1����Ϊż��ʱ������ֵ�˻���Ϊ���ֵ��
2����������-1����Ϊ����ʱ�����������Ϊstart, ������Ϊend,��һ��-1��λ��Ϊi, ���һ��-1��λ��Ϊj,�� ����ĳ˻����ֵΪMAX{[start,j-1] , [i,end]}
3��ͳ���������������ֵ�����ɵó��������ֵ

ע���߽��������һ����������¼����0֮��ĳ��ȣ�����Ϊ0��ǰ������ֵΪ0������Ϊ1����ֵΪ������ΨһԪ�ء�

����˼·�� ��̬�滮 O(n)
������⣬�ȿ������ֲ��������е����������������������֮���ֵ�϶���ԭֵС��
�����ܱȵ�ǰֵ��Ҳ����С�����ԣ�������ӵ������ֻҪ�ܹ�����ֲ�����ȫ�����֮��Ĺ�ϵ���ɣ��Դˣ�д��ת�Ʒ���ʽ���£�
local[i + 1] = Max(local[i] + A[i], A[i]);
global[i + 1] = Max(local[i + 1], global[i]);

���ڻ�����������ǵ�һ������������������͸�����ˣ�
���ǰ��õ�һ����С�ĸ������ͺ���һ���ϴ�ĸ�����ˣ��õ��ķ�����һ���ϴ������
��{2��-3��-7}�����ԣ������ڴ���˷���ʱ�򣬳�����Ҫά��һ���ֲ����ֵ��
ͬʱ��Ҫά��һ���ֲ���Сֵ���ɴˣ�����д�����µ�ת�Ʒ���ʽ��
max_copy[i] = max_local[i]
max_local[i + 1] = Max(Max(max_local[i] * A[i], A[i]),  min_local * A[i])
min_local[i + 1] = Min(Min(max_copy[i] * A[i], A[i]),  min_local * A[i])
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {	
        int max = nums[0], product = nums[0], cur = -1;
		if(nums.size() == 1) return max;
		vector<int > zero, tmp, seg;//seg�������0֮��ĳ��ȣ�������0֮�䳤��Ϊ0����1���򷵻��м�Ԫ��
		vector<vector<int > > neg;
		for(int i  = 0; i < nums.size(); i++)
		{		
			if(nums[i] < 0)  tmp.push_back(i);
			if(nums[i] == 0 || i == nums.size()-1){
				if(i == nums.size()-1 && nums[i] != 0){ zero.push_back(i+1); seg.push_back(i-cur); }
				else{ zero.push_back(i); seg.push_back(i-cur-1); }
				neg.push_back(tmp);	
				cur = i;
				tmp.clear();
			}
		}
		if(zero.size()-1 == nums.size()) return 0;
		int start = 0;
		for(int i = 0; i < zero.size(); i++)
		{		    
			if(seg[i] == 0) max = (max > 0) ? max : 0; 
			if(seg[i] == 1){ max = (max > nums[zero[i]-1]) ? max : nums[zero[i]-1]; max = (max > 0) ? max : 0; }
			if(seg[i] <= 1){ start = (zero[i]+1 > nums.size()-1) ? nums.size()-1 : zero[i]+1; continue; }
			int neg_num = neg[i].size();
			
			if(neg_num % 2 == 0) 
				for(int j = start; j < zero[i]; j++) product = (j == start) ? nums[j] : product*nums[j];
			else{
				int p1, p2;
				for(int j = start; j < neg[i][neg_num-1]; j++) p1 = (j == start)? nums[j] : p1*nums[j];
				for(int j = neg[i][0]+1; j < zero[i]; j++) p2 = (j == neg[i][0]+1)? nums[j] : p2*nums[j];
				product = (p1 > p2) ? p1 : p2;
			}
			max = (max > product) ? max : product;
			
			start = (zero[i]+1 > nums.size()-1) ? nums.size()-1 : zero[i]+1;
		}
		return max;
    }
	
	int maxProduct1(vector<int > &nums)
	{
		int pmax = nums[0], pmin = nums[0], ans = nums[0]; //�ֲ����ֵ���ֲ���Сֵ���ܹ����ֵ
		for(int i = 1; i < nums.size(); i++)
		{
			int tmin = pmin * nums[i];
			int tmax = pmax * nums[i];
			pmax = max(nums[i], max(tmax, tmin));//��˺����Ϊ���������Ҫ����ǰһ����Сֵ�뵱ǰֵ�˻�
			pmin = min(nums[i], min(tmax, tmin));
			ans = max(ans, pmax);
		}
		return ans;
	}
};

int main()
{
	Solution c;
	vector<int > nums;
	int A[] = {-1};
	for(int i = 0; i < sizeof(A)/4; i++)
		nums.push_back(A[i]);
	cout << c.maxProduct1(nums) << endl;
	return 0;
}
