#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

����������һ������������1-n�����зǸ�������1���ֵĴ���

˼·����ָoffer�ϵ�һ����Ŀ�����ɿ�ѭ���ӵ�λ����λ�ֱ����1�ĸ���������1-100
��λ��Ϊ1����10����1��11��21��31��41��51��61��71��81��91
ʮλ��Ϊ1����10����10, 11, 12, 13,..., 19,
��λ��Ϊ1����1����100

���ɺܺÿ�������
��λΪ1��ÿ��10��������1��
ʮλΪ1��ÿ��100��������10��
��λΪ1��ÿ��1000��������100��
��������...

����:
��iλ��Ϊ1��ÿ��10*mul��������mul�Σ���������Ϊn, �趨a = n/mul, b = n%mul, cΪ��һλ����������ʼΪ0;
iλ��1������: 
���1�����b < mul, Ϊa*mul��;
���2����� mul<= b < mul*2, Ϊa*mul + c + 1��; 1Ϊ����λ�ϵ�1����10���1δ��������һ�ε������С�
���3����� b >= mul*2�� Ϊmul*(a+1)
c = b, �ظ����Ϲ���ֱ��a < 0

�ٸ����ӣ�
��n = 115, 
(1) a = 115/10 = 11, b = 5, c = 0, ��λ��1������Ϊ11*1+1;�����3��
(2) a = 115/100 = 1, b = 15, c = 5, ʮλ��1������Ϊ1*10+5+1;�����2��
(3) a = 115/1000 = 0, b = 115, c = 15, ��λ��1������Ϊ0*100+15+1;(���2��;
(4) ����
����12+16+16= 44
*/

class Solution {
public:
    int countDigitOne(int n) {
        int mul = 1, a = -1, b = 1, c = 0, ans = 0;
		if(n <= 0) return 0;
		while(a != 0){
			if(a == 1){ //���Ǳ߽���������mul*10�ѳ����ɱ�ʾ��Χ
				a = 0;
				b = n;
			}
			else{
				a = n / (mul*10);
				b = n % (mul*10);
			}
			cout << a << " " << b << " " << (mul*10) << endl;
			if(b < mul) ans += a * mul;
			else if(b >= mul && b < mul*2) ans += (a*mul+c+1);
			else ans += (mul*a + mul);
			mul *= 10;
			c = b;
		}
		return ans;
    }
};

int main(){	
	Solution c;
	int n = 1660065408;//INT_MAX;//1410065408;
	cout << INT_MAX << endl;
	cout << c.countDigitOne(n) << endl;
	return 0;}
