#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
解析：这个比之前那题简单，因为相当于求一个n*n的螺旋矩阵，用之前的思路仍然可解
思路：定义一个n*n的矩阵，按上一题的扫描方式，将值依次填入矩阵当中,定义两个指针，一个行指针i，一个列指针j，
	定义行列边界，由于行列数相同，因此只需要一个上界low和一个下界up，
1）先走列指针j,当j走到头时，i开始走，当i增到头时，j开始往回走，j走到头时，i开始往回
2）每次j回到出发起点时，将行列边界往中间压缩，low++, up--;
3) 直到low >= up， 结束
*/

class Solution {
public:
    vector<vector<int > > generateMatrix(int n) {
        vector<vector<int > > matrix(n, vector<int >(n, 0));
		if(n <= 0) return matrix;
		int i = 0, j = 0, low = 0, up = n, num = 1;
		while(low < up){
			while(j < up) matrix[i][j++] = num++; //对上边沿赋值
			j--; i++;
			while(i < up) matrix[i++][j] = num++; //对右边沿赋值
			j--; i--;
			while(j >= low) matrix[i][j--] = num++; //对下边沿赋值
			j++; i--;
			while(i > low) matrix[i--][j] = num++; //对左边沿赋值
			low++; up--;
			i = low;
			j = low;
		}
		return matrix;
    }
};

int main(){
	Solution c;
	vector<vector<int > > m = c.generateMatrix(4);
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[i].size(); j++)cout << m[i][j] << " ";
		cout << endl;
	}
	return 0;
}
