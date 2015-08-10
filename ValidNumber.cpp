#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument,
 please click the reload button  to reset your code definition.
 
解析：给定一个字符串，判断其是否为有效数字
 
思路：LeetCode上通过率最低的一题，要考虑的情况比较多
 a.非法输入，字符串头尾的空格可以忽略，但是如果有空格则必然不合法, 
 b. 非数字，e和E是合法的，科学计数法e的前后，e后面可以出现符号，但是不能有多个e
 c. 多处小数点, 不合法
 d. 分数
 c. 正负符号
 
*/

class Solution {
public:
    bool isNumber(string s) {
		const char *ss = s.c_str();
		return isValid(ss);
    }
	bool isValid(const char *s){
        while (*s == ' ') ++s; //忽略起始空格
        while (*s == '+' || *s == '-') ++s; //忽略起始正负号
        bool exp = false, space = false, point = false;
        bool number = false;
        while (*s != '\0') {
            if (isdigit(*s)) { 
                if (space) return false; //数字中间出现空格，不合法
                else number = true; 
            } else if (*s == '.') { //小数点
                if (!point && !space && !exp) { //有小数点，不能是空格，不能之前有过小数点，科学计数法e后面不能出现小数点
                    point = true;
                } else {
                    return false;
                }
            } else if (*s == 'e') { //科学计数法
                if (!exp && number && !space) { //科学计数法不能有两次e，必须前面有数字，不能有空格
                    exp = true;
                    number = false; //科学计数法后面的数字重新判断
                    while (*(s+1) == '+' || *(s+1) == '-') ++s; //科学计数法后面可以有符号
                } else {
                    return false;
                }
            } else if (*s == ' ') { //空格
                if (!space) { //有可能是最后的空格，只有中间的空格不允许
                    space = true;
                }
            } else { //之前已经有空格了，又出现空格必然不合法
                return false;
            }
            ++s;
        }
        return number;  
	}
};

int main(){
	Solution c;
	cout << c.isNumber("  +++3.0");
	return 0;
}
