#include<iostream>
#include<vector>
using namespace std;
/*
原题：Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
解析：在二维矩阵中查找元素，二维矩阵每行有序，每行的第一个元素大于上一的最后一个元素,输入一个元素，快速判断该元素是否在矩阵当中。
思路: 分块查找思路，每一行为一个数据块，一行最后一个元素为索引,先用二分查找确定数据块，再进行块内查找即可,复杂度O(logn)
*/

class Solution {
public:
    //复杂度O(logn)
    bool searchMatrix(vector<vector<int > >& matrix, int target) {
		if(matrix.size() == 0) return false;
		int m = matrix.size(), n = matrix[0].size();
		int tarRow = 0, low = 0, high = m, mid;
		while(low < high){
			mid = (high+low) / 2;
			if(matrix[mid][n-1] == target) return true;
			if(matrix[mid][n-1] > target) high = mid;
			else low = mid+1;
		}
		if(low >= m || low < 0) return false;
		tarRow = low; 
		low = 0;
		high = n;
		while(low < high){
			mid = (high+low) / 2;
			if(matrix[tarRow][mid] == target) return true;
			if(matrix[tarRow][mid] > target) high = mid;
			else low = mid+1;
		}
		return false;
    }
};

int main()
{
	Solution c;
	int A[][4] = {{ 1, 3,  5,  7},
				 {10, 11, 16,  20},
				 {23, 30, 34,  50} };
	vector<vector<int > > m;
	for(int i = 0; i < 3; i++){
		vector<int > cur;
		for(int j = 0; j < 4; j++) cur.push_back(A[i][j]);
		m.push_back(cur);
	}
	cout << c.searchMatrix(m, 6);	
	return 0;
}
