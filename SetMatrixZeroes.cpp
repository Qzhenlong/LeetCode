#include<iostream>
#include<vector>
using namespace std;
/*
原题：Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
解析：给定一个m*n的矩阵，如果有一个元素为0，则将其所在行和列全置成0，能否不使用额外空间
思路：
关键问题：对行列置0时，要保证原矩阵里的0元素不受影响，如果某个元素为0，若该元素所在行列没有其它0，则可将所在行列置0，并不再扫描该行列
（1）如果可以使用额外空间，则先对矩阵进行一次扫描，并将存在0的行列全部置0即可，用两个数组分别存储行列，空间复杂度O(m+n)
（2）如果要考虑额外空间，即空间复杂度为O(1),那可以借助第一行第一列来作为思路（1）这两个数组，因为若某行为0，则该列第一个元素最后肯定会成为0，
	列也一样，因此可以用作标记位。
*/

class Solution {
public:
    void setZeroes(vector<vector<int > >& matrix) {
		if(matrix.size() == 0) return;
		int row = matrix.size(), col = matrix[0].size();
		vector<int > r(row,0);
		vector<int > c(col,0);
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(matrix[i][j] == 0){
					r[i]++;
					c[j]++;
				}
			}
		}
		for(int i = 0; i < row; i++)
			if(r[i] > 0) for(int j = 0; j < col; j++) matrix[i][j] = 0;
		for(int j = 0; j < col; j++)
			if(c[j] > 0) for(int i = 0; i < row; i++) matrix[i][j] = 0;
    }
    void setZeroes1(vector<vector<int > >& matrix) {
		if(matrix.size() == 0) return;
		int row = matrix.size(), col = matrix[0].size();
		bool rowZ = false, colZ = false; //记录第一行，第一列是否有0， 有则最后全置0
		for(int i = 0; i < row; i++) 
			if(matrix[i][0] == 0){
				rowZ = true;
				break;
			}
		for(int j = 0; j < col; j++)
			if(matrix[0][j] == 0){
				colZ = true;
				break;
			}
		for(int i = 1; i < row; i++) //用第一行和第一列来标记
			for(int j = 1; j < col; j++)
				if(matrix[i][j] == 0){
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
		for(int i = 1; i < row; i++)
			for(int j = 1; j < col; j++)
				if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
		if(rowZ)
			for(int i = 0; i < row; i++) matrix[i][0] = 0;
		if(colZ)
			for(int j = 0; j < col; j++) matrix[0][j] = 0;
    }
};

int main(){
	Solution c;
	int A[][3] = {{1,2,0},{3,4,6}};
	vector<vector<int > > m;
	for(int i = 0; i < 2; i++){
		vector<int > cur;
		for(int j = 0; j < 3; j++){
			cout << A[i][j] << " ";
			cur.push_back(A[i][j]);
		}
		cout << endl;
		m.push_back(cur);
	}
	cout << endl;
	c.setZeroes1(m);
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[i].size(); j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
	return 0;
}

