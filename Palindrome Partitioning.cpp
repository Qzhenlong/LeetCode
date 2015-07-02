#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
��Ŀ��Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
	
����������һ���ַ���s, ���ַ������л��֣�ʹÿ���Ӵ����ǻ��Ĵ����������п��ܵĻ��ּ���

˼·��
��1����̬�滮��dp[i][j]���ڱ�ʾs[i..j]�Ƿ�Ϊ��������״̬ת�Ʒ���
dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
Ӧ�ôӺ�ʼ��ǰ���㣬����˳������״̬ת�Ʒ���, 
����dp��������ȱ���dp,�������п������
��2��ֱ�Ӳ���������ȱ������߱������ж�
  
*/

class Solution {
public:
    vector<vector<string > > partition(string s) {
		int n = s.size();
        vector<vector<string > > ans;
		if(n == 0) return ans;
		vector<vector<bool > > dp(n, vector<bool >(n, false));
		for(int i = n-1; i >= 0; i--){
			for(int j = i; j < n; j++){
				if(i == j) dp[i][j] = true;
				else if(i+1 > j-1) dp[i][j] = (s[i] == s[j]);
				else dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
			}
		}
		vector<string > cur;
		cout << dp[0][n-1] << endl;
		for(int i = 0; i < n; i++)
			if(dp[0][i]){
				dfs(s, ans, cur, dp, 0, i, n);
				cur.pop_back();
			}
		return ans;
    }
	void dfs(string s, vector<vector<string > > &ans, vector<string > &cur, vector<vector<bool > > dp, int i, int j, int n){
		cur.push_back(s.substr(i, j-i+1));
		if(j == n-1){
			ans.push_back(cur);
			return;
		}
		for(int k = j+1; k < n; k++){
			if(dp[j+1][k]){
				dfs(s, ans, cur, dp, j+1, k, n);
				cur.pop_back();
			}
		}
	}
};

int main(){
	Solution c;
	string s = "aabaa";
	vector<vector<string > > ans = c.partition(s);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}

