#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

����������һ���ַ���������ʹ��ÿ���Ӵ����ǻ��Ĵ�����С��ִ���

˼·������һ���˼·���ƣ��������ҳ���С�����
��1��ʹ�ö�̬�滮, dp[i][j]��ʾs[i,..,j]�Ƿ�Ϊ���Ĵ���״̬ת�Ʒ���Ϊ��
	dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
�õ�dp�󣬼�����С������� ������ȱ���һ�¾�Okay��
��2������dfs�ᳬʱ����ʵ����Ҫ������ȱ������������ö�̬�滮��˼·��
	f[i]��¼s[i..n]����С�������״̬ת�Ʒ��̣�
	f[i] = min(1+f(j+1)), i <= j < n �� dp[i][j] == true;

*/

class Solution {
public:
   
    int minCut(string s) {
        int n = s.size();
		if(n == 0) return 0;
		vector<vector<bool > > dp(n, vector<bool >(n, false));
		for(int i = n-1; i >= 0; --i)
			for(int j = i; j < n; ++j){
				if(i == j) dp[i][j] = true;
				else if(i+1 > j-1) dp[i][j] = (s[i] == s[j]);
				else dp[i][j] = (dp[i+1][j-1] && (s[i] == s[j]));
			}
		/* dfs��ʱ
		int gMin = INT_MAX;
		for(int i = 0; i < n; ++i)
			if(dp[0][i]) dfs(dp, 0, gMin, 0, i, n);
		return gMin;
		*/
		vector<int > f(n+1, INT_MAX);
		f[n] = 0;
		for(int i = n-1; i >= 0; --i)
			for(int j = i; j < n; ++j)
				if(dp[i][j]) f[i] = min(f[i], 1+f[j+1]);
		return f[0]-1; //�����=���Ĵ���-1
		
    }
	 //Time Limit Exceeded����ʱ
	void dfs(vector<vector<bool > > dp, int curMin, int &gMin, int i, int j, int n){
		if(j == n-1){
			gMin = min(gMin, curMin);
			return;
		}
		for(int k = j+1; k < n; ++k)
			if(dp[j+1][k]) dfs(dp, curMin+1, gMin, j+1, k, n);
	}
};

int main(){
	Solution c;
	string s = "aab";
	cout << c.minCut(s);
	return 0;
}
