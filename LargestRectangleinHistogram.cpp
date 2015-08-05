#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
题目：
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

解析：给定n个非负整数，代表n条宽度为1柱，找出这柱状图中最大的长方形面积

思路：
（1）从下往上计算面积，求出每一层的最大面积，复杂度为O(n^2),可解，超时
（2）用栈实现，维护一个递增的栈，每当栈顶的柱高大于，当前柱高，说明可以出栈了，直到找到比当前柱高要低的元素，方可将当前元素入栈
     用栈存储柱的序号即可。

*/

class Solution {
public:
    //Time Limit Exceeded
    int largestRectangleArea(vector<int >& height) {
        int ans = 0, n = height.size();
		if(n <= 0) return 0;
		for(int i = 0; i < n; i++){
			int cur_max = 0, area = 0;
			for(int j = 0; j < n; j++){
				if(height[j] >= height[i]) area += height[i];
				else{
					cur_max = max(cur_max, area);
					area = 0;
				}
			}
			cur_max = max(cur_max, area); //第i层的最大面积
			ans = max(ans, cur_max);
		}
		return ans;
    }
    int _largestRectangleArea(vector<int >& height) {
        height.push_back(0); //补充最尾元素
		int ans = 0, n = height.size(), i = 0;
		if(n <= 0) return 0;
		stack<int > s;
		while(i < n){
			if(s.empty() || height[i] > height[s.top()]) s.push(i++);
			else{
				int j = s.top(); s.pop();
				ans = max(ans, height[j] * (s.empty() ? i : i-s.top()-1));
			}
		}
		return ans;
    }
};

int main(){
	Solution c;
	int A[] = {1};
	vector<int > h;
	for(int i = 0; i < sizeof(A)/4; i++) h.push_back(A[i]);
	cout << c._largestRectangleArea(h);
	return 0;
}
