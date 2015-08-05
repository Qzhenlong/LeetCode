#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��Ŀ��Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

����������һ��ֻ��0��1�;��󣬷�����1���ɵ������ε����

˼·��Largest Rectangle in Histogram��һ���һ�����Σ����ھ���ÿһ�У����ǽ��俴��ֱ��ͼ�������ĸ߶Ⱦ�������Ԫ������������������1�ĸ�����

���ÿһ�ж�����������һ�ⷽ�����������Σ����������н�������ֵ�ͺ���

*/

class Solution {
public:
    int maximalRectangle(vector<vector<char > >& matrix) {
		if(matrix.size() == 0) return 0;
		vector<int > height(matrix[0].size(), 0); //��¼ÿһ�ж�Ӧ��ֱ��ͼ
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
	int maxArea(vector<int > heights){ //ά��һ��������ջ, ������ֱ��ͼ���
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
