#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

解析：给定一个整数，计算1-n的所有非负整数中1出现的次数

思路：剑指offer上的一个题目，规律可循，从低位到高位分别计算1的个数，比如1-100
个位上为1的有10个：1，11，21，31，41，51，61，71，81，91
十位上为1的有10个：10, 11, 12, 13,..., 19,
百位上为1的有1个：100

规律很好看出来：
个位为1的每隔10个数出现1次
十位为1的每隔100个数出现10次
百位为1的每隔1000个数出现100次
依次类推...

步骤:
设i位上为1的每隔10*mul个数出现mul次，输入整数为n, 设定a = n/mul, b = n%mul, c为上一位的余数，初始为0;
i位上1的数量: 
情况1：如果b < mul, 为a*mul次;
情况2：如果 mul<= b < mul*2, 为a*mul + c + 1次; 1为整数位上的1，如10里的1未包含在上一次的余数中。
情况3：如果 b >= mul*2， 为mul*(a+1)
c = b, 重复以上过程直到a < 0

举个例子：
当n = 115, 
(1) a = 115/10 = 11, b = 5, c = 0, 个位上1的数量为11*1+1;（情况3）
(2) a = 115/100 = 1, b = 15, c = 5, 十位上1的数量为1*10+5+1;（情况2）
(3) a = 115/1000 = 0, b = 115, c = 15, 百位上1的数量为0*100+15+1;(情况2）;
(4) 结束
共：12+16+16= 44
*/

class Solution {
public:
    int countDigitOne(int n) {
        int mul = 1, a = -1, b = 1, c = 0, ans = 0;
		if(n <= 0) return 0;
		while(a != 0){
			if(a == 1){ //考虑边界情况，如果mul*10已超出可表示范围
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
