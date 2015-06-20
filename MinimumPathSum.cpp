#include<iostream>
#include<vector>
using namespace std;
/*
原题：Given a m x n grid filled with non-negative numbers, find a path from top left to bottom 
	  right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
解析：从m*n的左上角走到右下角，使路径上每个结点之和最小。
思路：动态规划问题，sum(i,j)表示从(0,0)到(i,j)的路径中和的最小值
状态转移方程：
sum(0,0)=f(0,0);
sum(0,1)=f(0,0)+f(0,1);
sum(1,0)=f(0,0)+f(1,0);
sum(1,1)=min(sum(1,0),sum(0,1))+f(1,1);
sum(i,j)=min(sum(i-1,j),sum(i,j-1))+f(i,j);

注：使用滚动数组，可将空间复杂度降低至O(n)，如果动态规划中状态转移方程只用到本层和上一层的结果（如上面的i-1为上一层，j-1为本层），
则可以使用滚动数组，可将以上过程简化成按层进行处理的状态转移方程,从上至下,sum[j]保存之前所有路径中和的最小值：
第一层：sum[j] = min(sum[j-1], sum[j])+f(i,j);
第二层：sum[j] = min(sum[j-1], sum[j])+f(i,j);
.....

(2)二叉树
由于网格走的时候只能向下或者向右，因此可以将整张网格构造成一棵二叉树，那么问题就变成从根结点到叶子结点路径和的最小值；
*/

class Solution {
public:
    int minPathSum(vector<vector<int > >& grid) {
        if(grid.size()==0) return 0;
		int m = grid.size(), n = grid[0].size();
		vector<vector<int > > sum(m, vector<int >(n,0));
		sum[0][0] = grid[0][0];
		for(int i = 1; i < n; i++) sum[0][i] = sum[0][i-1] + grid[0][i];
		for(int i = 1; i < m; i++) sum[i][0] = sum[i-1][0] + grid[i][0];
		for(int i = 1; i < m; i++)
			for(int j = 1; j < n; j++)
				sum[i][j] = min(sum[i-1][j], sum[i][j-1])+grid[i][j];
		return sum[m-1][n-1];
    }
    int minPathSum1(vector<vector<int > >& grid) {
        if(grid.size()==0) return 0;
		int m = grid.size(), n = grid[0].size();
		vector<int > sum(n,INT_MAX);
		sum[0] = 0;
		for(int i = 0; i < m; i++){
			sum[0] += grid[i][0]; 
			for(int j = 1; j < n; j++)
				sum[j] = min(sum[j], sum[j-1])+grid[i][j];
		}
		return sum[n-1];
    }
	
};

int main(){
	Solution c;
	vector<vector<int > > grid;
	vector<int > cur;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			cur.push_back(i+j+1);
			cout << i+j+1 << " ";
		}
		cout << endl;
		grid.push_back(cur);
		cur.clear();
	}
	cout << "Min Path Sum: " << c.minPathSum(grid) << endl;
	cout << "Min Path Sum1: " << c.minPathSum1(grid) << endl;
	return 0;
}
