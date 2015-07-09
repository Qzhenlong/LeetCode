#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

����������������word1��word2���ҳ���word1ת����word2����С������ һ�ֲ�������һ��
	 �����ֲ��������룬ɾ�����滻
	 
˼·����̬�滮�� dp[i][j]��ʾword1[0,i]��word2[0,j]����С�ɱ༭����
��word1[i] = word[j]ʱ�� dp[i][j] = dp[i-1][j-1];
��word1[i] != word[j]ʱ: 
  a.��word1[i]�滻��word2[j]��dp[i][j] = dp[i-1][j-1] + 1;
  b.��word1[i]ɾ����dp[i][j] = dp[i-1][j] + 1;
  c.��word1[i]�������һ��word2[j], dp[i][j] = dp[i][j-1]+1
  
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
		vector<vector<int > > dp(m+1, vector<int >(n+1, 0));
		for(int i = 0; i <= m; i++) dp[i][0] = i;
		for(int i = 0; i <= n; i++) dp[0][i] = i;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
				else{
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
				}
			}
		}
		return dp[m][n];
    }
};

int main(){
	Solution c;
	cout << c.minDistance("b","a");
	return 0;
}

