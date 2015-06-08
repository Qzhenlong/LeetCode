#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
����������01������ȫΪ1��������������ֵ
˼·����̬�滮��
״̬ת�Ʒ��̣�
dp[x][y] = min(dp[x - 1][y - 1], dp[x][y - 1], dp[x - 1][y]) + 1
��ʽ�У�dp[x][y]��ʾ������(x, y)Ϊ���½�Ԫ�ص�ȫ1�������󳤶ȣ���ȣ�

*/

class Solution {
public:
    int maximalSquare(vector<vector<char > >& matrix) {
        if(matrix.size() == 0) return 0;
		int row = matrix.size(), col = matrix[0].size(), maxs = 0;
		int dp[row][col];
		for(int i = 0; i < row; i++){ dp[i][0] = (matrix[i][0] == '1') ? 1 : 0; maxs = max(maxs, dp[i][0]);}
		for(int i = 0; i < col; i++){ dp[0][i] = (matrix[0][i] == '1') ? 1 : 0; maxs = max(maxs, dp[0][i]);}
		for(int i = 1; i < row; i++){
			for(int j = 1; j < col; j++){
				if(matrix[i][j] == '1'){
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
					maxs = max(maxs, dp[i][j]);
				}
				else dp[i][j] = 0;
			}
		}
		return maxs*maxs;
    }
};

int main(){
	Solution c;
	vector<vector<char > > m;
	vector<char > x;
	vector<char > y;
	x.push_back('1'); //x.push_back('1');
	//y.push_back('1'); y.push_back('1');
	m.push_back(x); //m.push_back(y);
	cout << c.maximalSquare(m);
	return 0;
}
