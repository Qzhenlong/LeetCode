#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".

解析：给定两个整数，表示分子和分母，计算分数字符串，如果有循环部分，将循环部分用括号括起来。

思路：为了保证不溢出，用long long来存储整数，用一个哈希表存储小数的部分，如果出现循环，则加上括号，并输出结点


*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0"; //分数为0
		if(denominator == 0) return ""; //分母为0,无法表示
		string ans = "";
		if((numerator < 0) ^ (denominator < 0)) ans += "-"; //负数,负负得正
		//long long int n = abs(numerator), d = abs(denominator);  //最小值会溢出
		long long int n = numerator, d = denominator;
		n = abs(n); d = abs(d);
		long long re = n % d;
		ans += to_string(n/d); //整数部分
		if(re == 0) return ans; //整除，无余数
		ans += "."; //后面计算小数部分
		map<long long int, int> pos; 
		while(re > 0){
			if(pos.find(re) != pos.end()){
				ans.insert(ans.begin()+pos[re], '(');
				ans += ')';
				break;
			}
			pos[re] = ans.size();
			re *= 10; // 左移一位再除
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
