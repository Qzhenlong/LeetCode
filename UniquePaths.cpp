#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
m and n will be at most 100.

��������m*n(��*��)��С����������Ͻǵ������½ǣ�ֻ�����ϻ��������ߣ��ܹ���·������m��n��������100
˼·����̬�滮��dp[i][j]��ʾ�ӣ�0��0������i,j����·����
dp[0][0] = 0;  //ֻ�����»�������
dp[0][1] = 1;
dp[1][0] = 1;
dp[1][1] = 2; 
...
״̬ת�Ʒ��̣�dp[i][j] = dp[i-1][j]+dp[i][j-1];
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
		if(m <= 0 || n <= 0) return 0;
		int dp[m][n];
		dp[0][0] = 0;
		for(int i = 0; i < m; i++) dp[i][0] = 1;
		for(int j = 0; j < n; j++) dp[0][j] = 1;
		for(int i = 1; i < m; i++){
			for(int j = 1; j < n; j++){
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
    }
	int uniquePaths1(int m, int n) {
		vector<int> dp(n, 0); //һ��������Ը㶨
		dp[0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 1; j < n; j++) {
				// ��ߵ� dp[j]����ʾ���º�� dp[j]���빫ʽ�е� dp[i[[j] ��Ӧ
				// �ұߵ� dp[j]����ʾ�ϵ� dp[j]���빫ʽ�е� dp[i-1][j] ��Ӧ
				dp[j] = dp[j - 1] + dp[j];
			}
		}
		return dp[n - 1];
	}
};

int main(){
	Solution c;
	cout << c.uniquePaths1(3,3);
	return 0;
}
