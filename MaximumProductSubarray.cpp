#include<iostream>
#include<vector>
using namespace std;
/*
相关题目：Minimum Size Subarray Sum

我的思路：O(n)
记录0和-1的位置, 两个0之间为一个区间，若没有0则区间为原数组起止位置，则在区间内有以下几种情况：
1）当区间内-1数量为偶数时，所有值乘积即为最大值；
2）当区间内-1数量为奇数时，设区间起点为start, 结束点为end,第一个-1的位置为i, 最后一个-1的位置为j,则 区间的乘积最大值为MAX{[start,j-1] , [i,end]}
3）统计所有区间内最大值，即可得出最后的最大值

注：边界情况，用一个数组来记录两个0之间的长度，长度为0则当前区间最值为0，区间为1则最值为区间内唯一元素。

其它思路： 动态规划 O(n)
便于理解，先考虑最大局部和子序列的情况：如果遇到负数，相加之后的值肯定比原值小，
但可能比当前值大，也可能小，所以，对于相加的情况，只要能够处理局部最大和全局最大之间的关系即可，对此，写出转移方程式如下：
local[i + 1] = Max(local[i] + A[i], A[i]);
global[i + 1] = Max(local[i + 1], global[i]);

对于积的情况，考虑到一种特殊情况，即负数和负数相乘；
如果前面得到一个较小的负数，和后面一个较大的负数相乘，得到的反而是一个较大的数，
如{2，-3，-7}，所以，我们在处理乘法的时候，除了需要维护一个局部最大值，
同时还要维护一个局部最小值，由此，可以写出如下的转移方程式：
max_copy[i] = max_local[i]
max_local[i + 1] = Max(Max(max_local[i] * A[i], A[i]),  min_local * A[i])
min_local[i + 1] = Min(Min(max_copy[i] * A[i], A[i]),  min_local * A[i])
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {	
        int max = nums[0], product = nums[0], cur = -1;
		if(nums.size() == 1) return max;
		vector<int > zero, tmp, seg;//seg存放两个0之间的长度，若两个0之间长度为0或者1，则返回中间元素
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
		int pmax = nums[0], pmin = nums[0], ans = nums[0]; //局部最大值，局部最小值及总共最大值
		for(int i = 1; i < nums.size(); i++)
		{
			int tmin = pmin * nums[i];
			int tmax = pmax * nums[i];
			pmax = max(nums[i], max(tmax, tmin));//相乘后可能为正数，因此要考虑前一个最小值与当前值乘积
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
