#include<iostream>
#include<vector>
using namespace std;
/*
题目：Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

解析：给定一个三角数组，找出和最小的路径，每行一个元素，每一步只能往下一行的相邻位置走下去
	 从二维数组上看
  [2],
  [3,4],
  [6,5,7],
  [4,1,8,3]
下一行的元素的上一个元素一定位于其上方或者左上方
  
思路：动态规划，三角元素记为t[i][j], dp[i][j]表示从开始到第i行第j列元素的最小和
dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) +t[i][j] 

注：
第一列元素 dp[i][j] = dp[i-1][j] +t[i][j]
末尾元素   dp[i][j] = dp[i-1][j-1] + t[i][j]
dp[0][0] = t[i][j];

不考虑空间的情况下，需要O(n^2)复杂度，考虑滚动数组，可将空间降至O(n)
*/

class Solution {
public:
	//O(n^2)空间
    int minimumTotal(vector<vector<int > >& triangle) {
        if(triangle.size() == 0) return 0;
		int n = triangle.size(), ans = INT_MAX;
		vector<vector<int > > dp(n, vector<int >(n, INT_MAX));
		dp[0][0] = triangle[0][0]; //第一个元素
		if(n == 1) return dp[0][0];
		for(int i = 1; i < n; i++){
			for(int j = 0; j <= i; j++){
				if(j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j]; //第一列
				else if(j == i) dp[i][j] = dp[i-1][j-1] + triangle[i][j]; //末尾元素
				else dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]; //中间元素
			    
				if(i == n-1 && ans > dp[i][j]) ans = dp[i][j];
			}
		}
		return ans;
    }
	//采用滚动数组降低空间复杂度
    int minimumTotal1(vector<vector<int > >& triangle) {
        if(triangle.size() == 0) return 0;
		int n = triangle.size(), ans = INT_MAX;
		vector<int > dp(n, INT_MAX);
		dp[0] = triangle[0][0]; //第一个元素
		if(n == 1) return dp[0];
		for(int i = 1; i < n; i++){
			for(int j = i; j >= 0; j--){ //保证前面需要用的元素没被改变
				if(j == 0) dp[j] = dp[j] + triangle[i][j]; //第一列, dp[i][j] = dp[i-1][j] +t[i][j]
				else if(j == i) dp[j] = dp[j-1] + triangle[i][j]; //末尾元素, dp[i][j] = dp[i-1][j-1] + t[i][j]
				else dp[j] = min(dp[j-1], dp[j]) + triangle[i][j]; //中间元素
			    
				if(i == n-1 && ans > dp[j]) ans = dp[j];
			}
		}
		return ans;
    }	
};

int main(){
	Solution c;
	vector<vector<int > > t;
	vector<int > cur;
	cur.push_back(2); t.push_back(cur); cur.clear();
	cur.push_back(3); cur.push_back(4); t.push_back(cur); cur.clear();
	cur.push_back(6); cur.push_back(5); cur.push_back(7); t.push_back(cur); cur.clear();
	cur.push_back(4); cur.push_back(1); cur.push_back(8); cur.push_back(3); t.push_back(cur); cur.clear();
	cout << c.minimumTotal1(t) << endl;
	return 0;
}
