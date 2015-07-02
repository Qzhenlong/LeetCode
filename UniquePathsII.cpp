#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

������������һ�⣬������˵��m*n(��*��)��С����������Ͻǵ������½ǣ�ֻ�����ϻ��������ߣ��ܹ���·������m��n��������100
	��һ������·���м������ϰ�� �ϰ�����1��ǣ����ϰ�Ϊ0

˼·�����Ƕ�̬�滮������������1ʱ���򵽵�ǰ��û��·����������0
dp[0][0] = 0;  //ֻ�����»�������
dp[0][1] = dp[0][2] = 1;
dp[1][0] = dp[2][0] = 1;
dp[1][1] = 0; 
dp[2][1] = 1
...
״̬ת�Ʒ��̣�dp[i][j] = dp[i-1][j]+dp[j][i-1];

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int > >& obstacleGrid) {
        int m = obstacleGrid.size();
		if(m <= 0) return 0;
		int n = obstacleGrid[0].size();
		int dp[m][n];
		dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;  //ע��߽磬�����ʼ��1����û��·����
		if(dp[0][0] == 0) return 0;
		for(int i = 1; i < m; i++) 
			if(dp[i-1][0] == 0 || obstacleGrid[i][0] == 1) dp[i][0] = 0; //ǰ���й��ϰ������һ�ж�û��·��
			else dp[i][0] = 1;
		for(int j = 1; j < n; j++) 
			if(dp[0][j-1] == 0 || obstacleGrid[0][j] == 1) dp[0][j] = 0; //ǰ���й��ϰ������һ�ж�û��·��
			else dp[0][j] = 1;
		for(int i = 1; i < m; i++){
			for(int j = 1; j < n; j++){
				if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
				else dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
    }
	//��Ȼ���Բ��ù������������Ϳռ临�Ӷȣ� ��Ϊdp[i][j]ֻ��ǰ���������أ���˿��Բ��ù�������
    int uniquePathsWithObstacles1(vector<vector<int > >& obstacleGrid) {
        int m = obstacleGrid.size();
		if(m <= 0) return 0;
		int n = obstacleGrid[0].size();
		vector<int > dp(n, 0); //�����ʼ��Ϊ0
		if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
		dp[0] = obstacleGrid[0][0] == 1 ? 0 : 1;  //ע��߽磬�����ʼ��1����û��·����
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				dp[j] = (obstacleGrid[i][j]==1) ? 0 : (j == 0 ? 0 : dp[j - 1]) + dp[j]; //ע��ת�Ʒ����е�dp[0][j]������1����ǰ��Ԫ���йأ�����Ҫ���ж�
		return dp[n-1];
    }	
};

int main(){
	Solution c;
	vector<vector<int > > grid;
	int A[][3] = {{0,0},{0,0}};
	for(int i = 0; i < 2; i++){
		vector<int > cur;
		for(int j = 0; j < 2; j++) cur.push_back(A[i][j]);
		grid.push_back(cur);
	}
	cout << c.uniquePathsWithObstacles(grid) << endl;
	cout << c.uniquePathsWithObstacles1(grid) << endl;
	return 0;
}
