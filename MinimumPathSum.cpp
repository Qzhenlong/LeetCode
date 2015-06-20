#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Given a m x n grid filled with non-negative numbers, find a path from top left to bottom 
	  right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
��������m*n�����Ͻ��ߵ����½ǣ�ʹ·����ÿ�����֮����С��
˼·����̬�滮���⣬sum(i,j)��ʾ��(0,0)��(i,j)��·���к͵���Сֵ
״̬ת�Ʒ��̣�
sum(0,0)=f(0,0);
sum(0,1)=f(0,0)+f(0,1);
sum(1,0)=f(0,0)+f(1,0);
sum(1,1)=min(sum(1,0),sum(0,1))+f(1,1);
sum(i,j)=min(sum(i-1,j),sum(i,j-1))+f(i,j);

ע��ʹ�ù������飬�ɽ��ռ临�ӶȽ�����O(n)�������̬�滮��״̬ת�Ʒ���ֻ�õ��������һ��Ľ�����������i-1Ϊ��һ�㣬j-1Ϊ���㣩��
�����ʹ�ù������飬�ɽ����Ϲ��̼򻯳ɰ�����д����״̬ת�Ʒ���,��������,sum[j]����֮ǰ����·���к͵���Сֵ��
��һ�㣺sum[j] = min(sum[j-1], sum[j])+f(i,j);
�ڶ��㣺sum[j] = min(sum[j-1], sum[j])+f(i,j);
.....

(2)������
���������ߵ�ʱ��ֻ�����»������ң���˿��Խ������������һ�ö���������ô����ͱ�ɴӸ���㵽Ҷ�ӽ��·���͵���Сֵ��
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
