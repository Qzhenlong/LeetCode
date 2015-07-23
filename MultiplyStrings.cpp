#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

解析：给定两个由字符串代表的两个数字，计算两个数字的乘积，并返回一个字符串，数字任意大且为非负

思路：本质上是个大数运算，不能简单的将字符串转换成数字进行运算，应采用特殊的数据结构来存储数字
（1）用一个整数数组来存储数字，乘积再转换为字符串即可，复杂度比较高，AC
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int > ans(num1.size()+num2.size(), 0); //结果数组
		string ln = (num1.size() >= num2.size())? num1 : num2; //长度大的
	    string sn = (num1.size() < num2.size())? num1 : num2; //长度小的
		vector<int > num(ln.size(), 0); //左边代表低位
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
		int c = 0, i = 0, j = bit; //进位
		for(i = 0, j = bit; i < num.size(); i++, j++){
			ans[j] = (num[i]*times+c) % 10;
			c = (num[i]*times+c) / 10;
		}
		ans[j] = c;
		return ans;
	}
	void add(vector<int > &ans, vector<int > num){
		int c = 0, s = 0; //进位
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
