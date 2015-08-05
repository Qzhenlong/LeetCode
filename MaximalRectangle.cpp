#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
题目：Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

解析：给定一个只有0和1和矩阵，返回由1构成的最大矩形的面积

思路：Largest Rectangle in Histogram这一题的一个变形，对于矩阵每一行，我们将其看作直方图，立柱的高度就是行中元素往上数包含的连续1的个数。

因此每一行都可以利用上一题方法计算最大矩形，最后求出各行结果的最大值就好了

*/

class Solution {
public:
    int maximalRectangle(vector<vector<char > >& matrix) {
		if(matrix.size() == 0) return 0;
		vector<int > height(matrix[0].size(), 0); //记录每一行对应的直方图
		int ans = 0;
		for(int i = 0; i < matrix.size(); ++i){
			for(int j = 0; j < matrix[0].size(); ++j){
				if(matrix[i][j] == '1') ++height[j];
				else height[j] = 0;
			}
			ans = max(ans, maxArea(height)); 
		}
		return ans;
    }
	int maxArea(vector<int > heights){ //维护一个递增的栈, 求最大的直方图面积
		heights.push_back(0);
		stack<int > s;
		int maxArea = 0, i = 0;
		while(i < heights.size()){
			if(s.empty() || heights[i] > heights[s.top()]) s.push(i++);
			else{
				int j = s.top(); s.pop();
				maxArea = max(maxArea, heights[j] * (s.empty() ? i : (i-s.top()-1)));
			}
		}
		return maxArea;
	}
};

int main(){
	Solution c;
	const int n = 4;
	char A[][n] = {
      {'0','0','1','0'},
	  {'0','0','0','1'},
	  {'0','1','1','1'},
	  {'0','0','1','1'}
	};
	vector<vector<char > > grid;
	for(int i = 0; i < sizeof(A)/ n; i++){
		vector<char > cur;
		for(int j = 0; j < n; j++){
			cur.push_back(A[i][j]);
			//cout << A[i][j] << " ";
		}
		//cout << endl;
		grid.push_back(cur);
	}
	cout << c.maximalRectangle(grid);
	return 0;
}
