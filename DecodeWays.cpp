#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

��������Ϣ�е�A-Z������Ϊ1-26������һ��������˵���Ϣ��ȷ���ܹ��ж��������뷽ʽ

˼·��
��1�� ���ڱ����а�������λ��ֻ��10-26����ôֻ����1��2��ʼ�����ֿ��ܲ����������뷽ʽ��
      ��ͳ�Ƹ�������Ϣ�а�����1��2�����������û��1��2�������һ�����뷽ʽ�������1����2��ᵼ��������������ӣ�
	  1��2�ĺ����п����������������һ�ַ�0�����¸��ַ�Ϊ0��Ϊ��(ĩβ��������һ���ַ���������26�� Ϊ������
	  ǰ���ֶ���������������������ӣ����һ�ֲŻᣬ��ô����1��2��������λ����Ϣ������ͳ��0��λ����Ϣ
	  ע���ж��޷���������������������0�����޷�����,������λΪ0,����0ǰ����ֱ�2�����Ҳ�޷�����
��2�������˼·���ԣ�Ӧ�ò��ö�̬�滮���������������
	  dp[i] ��ʾ�ַ�s[0.i-1]֮���ж��������뷽ʽ
      ��̬ת�Ʒ��̣�dp[i] = dp[i-1] + dp[i-2];
	  a.��ȥ��֮ǰ����˼·�и������޷���������
	  b.�����ǰ�ַ�s[i-1]Ϊ��0���Ļ�����������һ�ַ����룬�����Լ���dp[i-1], �����ж�s[i-2]
	  c.���s[i-2]Ϊ1������Ϊ2��s[i-1] <= '6', ��ɼ���dp[i-2]
*/

class Solution {
public:
	//˼·����
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
		if(s.size() == 1) return 1;
		int ans = 1, i = 0; //
		for(i = 0; i < s.size()-1; i++) //����޷���������
			if((s[i] == '0' && s[i+1] == '0') || (s[i] > '2' && s[i+1] == '0')) return 0;
			
		for(i = 0; i < s.size()-2; i++)
			if(s[i] == '1' && s[i+1] != '0' && s[i+2] != '0') ans++;
			else if(s[i] == '2' && s[i+1] <= '6' && s[i+1] != '0' && s[i+2] != 0) ans++;

		if((s[i] == '1' && s[i+1] != '0') || (s[i] == '2' && s[i+1] != '0' && s[i+1] <= '6')) ans++;
		return ans;
    }
    int _numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
		vector<int > dp(s.size()+1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 0; i < s.size()-1; i++) //����޷���������
			if((s[i] == '0' && s[i+1] == '0') || (s[i] > '2' && s[i+1] == '0')) return 0;
		for(int i = 2; i <= s.size(); i++){
		    if(s[i-1] != '0') dp[i] += dp[i-1]; //�����ǰ�ַ�Ϊ��0���Ļ�����������һ�ַ����룬�����Լ���dp[i-1],
			if(s[i-2] == '1'||(s[i-2] == '2' && s[i-1] <= '6')) dp[i] += dp[i-2]; //�����һ�ַ�������������ô���Լ���dp[i-2]
		}
		return dp[s.size()];
	}			
};

int main(){
	Solution c;
	cout << c._numDecodings("1212");
	return 0;
}
