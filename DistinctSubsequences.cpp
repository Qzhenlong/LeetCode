#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters
 without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

�����������ַ���S��T������S��������T��������������ΪS�а���T�������ַ������ǵ����λ�ò������ı䣬 ��ACE��ABCDE�������ж�AEC����

˼·��
��1���ݹ飬��������������ҵ�һ�����������Ĵ���������1���������
��2����̬�滮, dp[i][j] ��ʾT[0,j] ��S[0, i]�г��ֵĴ�������̬ת�Ʒ���Ϊ��
	 S[i] != T[j] : dp[i][j] = dp[i-1][j] //�����ǰ�ַ����ȣ���ô��ֻ��������ǰ����ַ���
	 S[i] == T[j] : dp[i][j] = dp[i-1][j]+dp[i-1][j-1]; //�����ǰS[i]==T[j]����ô��ǰ�����ĸ�����Ա���Ҳ����������

DP������Ϊ��ά��ͼ���߷����⡣

 

      r  a  b  b  i  t

   1  0  0  0  0  0  0

r  1  1  0  0  0  0  0

a  1  1  1  0  0  0  0

b  1  1  1  1  0  0  0

b  1  1  1  2  1  0  0

b  1  1  1  3  3  0  0

i  1  1  1  3  3  3  0

t  1  1  1  3  3  3  3

�������齵�͸��Ӷȣ������������
*/

class Solution {
public:
   //��ʱ
    int numDistinct(string s, string t) {
        int total = 0;
		if(s.size() == 0 || t.size() == 0) return 0;
		dfs(total, s, t, 0, 0);
		return total;
    }
	void dfs(int &sum, string s, string t, int i, int j){
		if(i >= t.size()){
			sum++; //�ҵ�һ���
			return;
		}
	    if(j >= s.size()) return;
		for(int k = j; k < s.size(); k++){
			if(t[i] == s[k])
				dfs(sum, s, t, i+1, k+1);
		}
	}
	int numDistinct1(string s, string t){
		int m = s.size(), n = t.size();
		vector<vector<int > > dp(m+1, vector<int >(n+1, 0));
		for(int i = 0; i <= m; i++) dp[i][0] = 1;
		for(int j = 1; j <= n; j++) dp[0][j] = 0;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				if(s[i-1] != t[j-1]) dp[i][j] = dp[i-1][j]; //����ȣ�����t[j], 
				else dp[i][j] = dp[i-1][j] + dp[i-1][j-1]; //��ȣ���ȡ�ɲ�ȡ
			}
		}
		return dp[m][n];
	}
	//��������
	int numDistinct2(string s, string t){
		int m = s.size(), n = t.size();
		vector<int > dp(n+1, 0);
		dp[0] = 1;
		for(int i = 0; i <= m; i++){
			for(int j = n-1; j >= 0; j--){
				dp[j+1] += (s[i] == t[j]) ? dp[j] : 0;
			}
		}
		return dp[n];
	}	
};

int main(){
	Solution c;
	cout << c.numDistinct("a", "b") << endl;
	cout << c.numDistinct1("a", "b") << endl;
	cout << c.numDistinct2("rabbbit", "rabbit") << endl;
	return 0;
}


