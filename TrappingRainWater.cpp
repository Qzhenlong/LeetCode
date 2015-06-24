#include<iostream>
#include<vector>
using namespace std;
/*
原题：Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

解析：给定一组非负整数每个整数代表一个宽度为1的栅栏，计算总共可以接住多少水，如1，0，2可以累积1单位水，以上例子中可以累积6个单位的水
思路：总水量记为totol
（1）（a,i)记录当前栅栏的高度及其坐标；
（2）（b,j)记录i之后，且未遇到与高度大于等于a的栅栏之前，高度最高的栅栏;
（3）c记录i与j之间栅栏所占的空间
（4）当遇到比a更高或相等的栅栏，计算一次水量，total += a*(j-i-1)-c,更新当前（a,i）及(b,j)
（5）重复以上过程，直到j到达终点; 
（6）当j到达终点时，如果没有大于a的栅栏，则total += b*(j-i-1)-c.
时间复杂度为O(n)，空间复杂度为O(1);
以上思路错误：原因是没有考虑类似于5,4,1,2这种情况

思路二：
对于每个柱子，找到其左右两边最高的柱子，该柱子能容纳的面积就是 min(max_left,
max_right) - height。所以，
1. 从左往右扫描一遍，对于每个柱子，求取左边最大值；
2. 从右往左扫描一遍，对于每个柱子，求最大右值；
3. 再扫描一遍，每个柱子能盛水的大小为该柱左右最大值中的较小值与当前柱高之差。

思路三：
1. 扫描一遍，找到最高的柱子，这个柱子将数组分为两半；
2. 处理左边一半，从左扫描，当前柱子能盛水量等于当前最高柱与该柱高度之差；
3. 处理右边一半，从右往左，情况与2相同。

*/
class Solution {
public:
    int trap(vector<int >& height) {
		int total = 0;
		if(height.size() <= 2) return total; //只有两个栅栏，无法累积水
		int a=0,b=0,c=0,i,j;
		for(int k = 0; k < height.size(); k++)
			if(height[k] > 0){
				a = height[k];
				i = k;
				break;
			}
		int cur_c = 0;
		for(int k = i+1; k < height.size(); k++){
			if(height[k] >= b){
				b = height[k];
				j = k;
				c = cur_c;
			}
			if(a <= b){
				total += (a*(j-i-1)-c);
				c = 0;
				cur_c = 0;
				a = b;
				i = j;
				b = -1;
			}
			else cur_c += height[k];
			
		}
		if(b != -1) //最后一次栅栏不够高
			total += b*(j-i-1)-c;		
		return total;
    }
	//时间空间都为O(n)
	int trap1(vector<int > &height){
		int n = height.size(), total = 0;
		vector<int > maxL(n, 0); //当前栅栏左边的最大值
		vector<int > maxR(n, 0); //当前栅栏右边的最大值
		for(int i = 1; i < n; i++){
			maxL[i] = max(height[i-1], maxL[i-1]);
			maxR[n-i-1] = max(height[n-i], maxR[n-i]);
		}
		for(int i = 0; i < n; i++){
			int cur = min(maxL[i], maxR[i]);
			if(cur > height[i]) total += (cur-height[i]);
		}
		return total;
	}
	//时间O(n)，空间O(1)
	int trap2(vector<int > &height){
		int maxI = 0, n = height.size(),total = 0;
		for(int i = 1; i < n; i++)
			if(height[i] > height[maxI]) maxI = i;
		int peak1 = 0, peak2 = 0;
		for(int i = 0; i < maxI; i++){
			if(peak1 < height[i]) peak1 = height[i];
			else total += (peak1-height[i]);
		}
		for(int i = n-1; i > maxI; i--){
			if(peak2 < height[i]) peak2 = height[i];
			else total += (peak2-height[i]);			
		}
		return total;
	}
};

int main(){
	Solution c;
	vector<int > h;
	int A[] = {5,4,1,2};
	for(int i = 0; i < sizeof(A)/4; i++) h.push_back(A[i]);
	cout << c.trap2(h);
	return 0;
}
