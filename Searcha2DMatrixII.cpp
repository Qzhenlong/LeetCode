#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

解析：行列都递增，查找特定元素是否在矩阵当中

思路：剑指offer上的题，每次与右上角元素，如果比该元素大，则删除所在列，如果比该元素小，则删除所在行，在同样的方式继续查找压缩后的矩阵即可
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int > >& matrix, int target) {
        if(matrix.size() == 0) return false;
		int m = matrix.size(), n = matrix[0].size(), i = 0, j = n-1;
		while(i < m && j >= 0){
			if(matrix[i][j] == target) return true;
			else if(matrix[i][j] > target) --j;
			else ++i;
		}
		return false;
    }
};

int main() {
	Solution c;
	vector<vector<int > > matrix;
	int A[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	vector<int > cur;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++)
			cur.push_back(A[i][j]);
		matrix.push_back(cur);
		cur.clear();
	}
	cout << c.searchMatrix(matrix, 1);
	return 0;
}
