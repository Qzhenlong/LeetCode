#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

�����������������ַ���������������֣������������ֵĳ˻���������һ���ַ����������������Ϊ�Ǹ�

˼·���������Ǹ��������㣬���ܼ򵥵Ľ��ַ���ת�������ֽ������㣬Ӧ������������ݽṹ���洢����
��1����һ�������������洢���֣��˻���ת��Ϊ�ַ������ɣ����ӶȱȽϸߣ�AC
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int > ans(num1.size()+num2.size(), 0); //�������
		string ln = (num1.size() >= num2.size())? num1 : num2; //���ȴ��
	    string sn = (num1.size() < num2.size())? num1 : num2; //����С��
		vector<int > num(ln.size(), 0); //��ߴ����λ
		for(int i = 0; i < ln.size(); i++) num[i] = ln[ln.size()-i-1]-'0';
		for(int i = 0; i < sn.size(); i++){
			vector<int > tmp = mul(num, sn[sn.size()-i-1]-'0', i, ans.size());
			add(ans, tmp);
		}
		string res = "";
		for(int i = ans.size()-1; i >= 0; i--){
			if(res == "" && ans[i] == 0) continue;
			res += (ans[i]+'0');
		}
		if(res == "") res = "0";
		return res;

    }
	vector<int > mul(vector<int > num, int times, int bit, int len){
		vector<int > ans(len, 0);
		int c = 0, i = 0, j = bit; //��λ
		for(i = 0, j = bit; i < num.size(); i++, j++){
			ans[j] = (num[i]*times+c) % 10;
			c = (num[i]*times+c) / 10;
		}
		ans[j] = c;
		return ans;
	}
	void add(vector<int > &ans, vector<int > num){
		int c = 0, s = 0; //��λ
		for(int j = 0; j < ans.size(); j++){
			s = (num[j] + ans[j] + c) % 10;
			c = (num[j] + ans[j] + c) / 10;
			ans[j] = s;
		}
	}
	int string2int(string s){
		int ans = 0; 
		for(int i = 0; i < s.size(); i++) ans = ans*10 + (s[i]-'0');
		return ans;
	}
};

int main(){
	Solution c;
	string n1 = "12732414237333333", n2 = "1";
	cout << c.multiply(n1,n2) << endl;
	cout << c.string2int(n1)*c.string2int(n2) << endl;
	return 0;
}
