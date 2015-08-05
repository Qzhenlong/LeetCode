#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

����������������������ʾ���Ӻͷ�ĸ����������ַ����������ѭ�����֣���ѭ��������������������

˼·��Ϊ�˱�֤���������long long���洢��������һ����ϣ��洢С���Ĳ��֣��������ѭ������������ţ���������


*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0"; //����Ϊ0
		if(denominator == 0) return ""; //��ĸΪ0,�޷���ʾ
		string ans = "";
		if((numerator < 0) ^ (denominator < 0)) ans += "-"; //����,��������
		//long long int n = abs(numerator), d = abs(denominator);  //��Сֵ�����
		long long int n = numerator, d = denominator;
		n = abs(n); d = abs(d);
		long long re = n % d;
		ans += to_string(n/d); //��������
		if(re == 0) return ans; //������������
		ans += "."; //�������С������
		map<long long int, int> pos; 
		while(re > 0){
			if(pos.find(re) != pos.end()){
				ans.insert(ans.begin()+pos[re], '(');
				ans += ')';
				break;
			}
			pos[re] = ans.size();
			re *= 10; // ����һλ�ٳ�
			ans += to_string(re/d);
			re = re % d;
		}
		return ans;
    }
	string to_string(long long int n){
		string ans = "";
		if(n == 0) ans = "0";
		while(n > 0){
			char c = (n%10)+'0';
			ans = c + ans;
			n = n/10;
		}
		return ans;
	}
};

int main(){
	Solution c;
	cout << c.fractionToDecimal(-1, -2147483648) << endl;
	return 0;
}
