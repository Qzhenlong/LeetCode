#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

解析：给定一个m*n的矩阵，按螺旋顺序返回所有元素
思路：定义两个指针，一个行指针i，一个列指针j，定义行列边界，;
1）先走列指针j,当j走到头时，i开始走，当i增到头时，j开始往回走，j走到头时，i开始往回
2）每次j回到出发起点时，将行列边界往中间压缩，rlow++，clow++, m--, n--;
3) 直到rlow >= m或者 clow >= n， 结束

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int > >& matrix) {
		vector<int > ans;
		if(matrix.size() == 0) return ans;
		int i = 0, j = 0, rlow = 0, clow = 0, m = matrix.size(), n = matrix[0].size();
		while(rlow < m && clow < n){
		    rlow++;                                        //行边界增大
			while(j < n) ans.push_back(matrix[i][j++]);    //先走上边沿
			--j; ++i; 									   //避免重复
			if(j < clow || i < rlow) break;                //行列不相等的矩阵，可能提前到达终点
			while(i < m) ans.push_back(matrix[i++][j]);    //再走右边沿
			--i; --j;                                      //避免重复
			if(j < clow || i < rlow) break;                //行列不相等的矩阵，可能提前到达终点
			while(j >= clow) ans.push_back(matrix[i][j--]);//再走下边沿
			++j; --i; 									   //避免重复
			while(i >= rlow) ans.push_back(matrix[i--][j]);//再走左边沿
			clow++; 									   //列边界增加
			m--; n--;                     			       //压缩边界
			i = rlow; j = clow; 						   //重置起点
		}
		return ans;
    }
};

int main()
{
  Solution c;
  vector<vector<int > > n;
  vector<int > cur;
  for(int i = 0; i < 9; i++){
	cur.push_back(i+1);
	if((i+1) % 3 == 0){
		n.push_back(cur);
		cur.clear();
	}
  }
  vector<int > ans = c.spiralOrder(n);
  for(int i = 0; i < ans.size(); i++)
	cout << ans[i] << " ";

  n.clear(); 
  cout << endl;
   for(int i = 0; i < 1; i++){
	cur.push_back(i+1);
	if((i+1) % 1 == 0){
		n.push_back(cur);
		cur.clear();
	}
  }
  ans.clear();
  ans = c.spiralOrder(n);
  for(int i = 0; i < ans.size(); i++)
	cout << ans[i] << " ";
  return 1;   
}

