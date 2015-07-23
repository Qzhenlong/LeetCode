#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
题目：Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function.

解析：实现一个基本的计算器来计算一个简单的字符串表达式，表达式包括左右括号、加减号非负整数，及空格。

思路：由于只有加减法，符合交换率，但是不能直接忽略括号的作用，因为有负负得正，如"2-(5-6)""，如果括号前为减号，则要把括号内所有运算符取反
（1）常规解法，将中缀表达式转换成后缀表达式，利用栈求解，左运算符和右运算符中的加减号优先级相同，且左运算符的优先级高于右运算符
   a. 定义一个栈存储运算符，一个字符串数组，存储后缀表达式
   b. 如果为数字，拼接成数字后直接放入字符串数组 
   c. 如果为'('，直接进栈,
   b. 如果为加减运算符，则与栈顶元素优先级进行对比，栈顶运算符优先级高，则出栈放入字符串数组，否则直接进栈
   d. 如果为')'，则将栈内运算符出栈，放入字符串数组，直到栈顶为'('，将其出栈，继续扫描。
*/

class Solution {
public:
    //之前的错误思路
    int calculate(string s) {
        int ans = 0, prev = 0;
		string num = "";
		for(int i = 0; i < s.size(); i++){
			if(s[i] != ' ' && s[i] != '(' && s[i] != ')'){
				if(s[i] >= '0' && s[i] <= '9') num += s[i];
				else{
					if(prev == -1) ans = string2int(num);
					else if(prev == 0) ans += string2int(num);
					else ans -= string2int(num);
					num = "";
					if(s[i] == '+') prev = 0;
					else prev = 1;
				}
			}
		}
		if(num.size() > 0){
			if(prev == -1) ans = string2int(num);
			else if(prev == 0) ans += string2int(num);
			else ans -= string2int(num);
		}
		return ans;
    }
	//用栈实现，将中缀表达式转换成后缀表达式
	int _calculate(string s){
		int ans = 0;
		stack<int > nums;
	    vector<string > postExp = genPostExp(s);
		if(postExp.size() == 0) return 0;
		for(int i = 0; i < postExp.size(); i++){
			if(postExp[i] == "-" || postExp[i] == "+"){ //计算后缀表达式的值
				int a = nums.top(); nums.pop();
				int b = nums.top(); nums.pop();
				int c = (postExp[i] == "+") ? b+a : b-a;
				nums.push(c);
			}
			else nums.push(string2int(postExp[i]));
		}
		return nums.top();
	}
	vector<string > genPostExp(string s){
		vector<string > postExp;
		stack<char > oper;
		string numstr = "";
		for(int i = 0; i < s.size(); i++){
		    if(s[i] == ' ') continue;
			if(s[i] >= '0' && s[i] <= '9') numstr += s[i];
			else{
			    if(numstr.size() > 0){
					postExp.push_back(numstr); 
					numstr = "";
				}
				if(s[i] == ')'){ //为右括号，将左括号之前的所有运算符出栈
					char op = oper.top(); oper.pop();
					while(op != '('){
						postExp.push_back(((op == '+') ? "+" : "-")); 
						op = oper.top(); oper.pop();
					}
				}
				else if(s[i] == '(') oper.push(s[i]); //为左括号直接进栈
				else{   //当前字符为运算符，与栈顶字符的优先级进行对比
					if(!oper.empty() && oper.top() != '('){ //只对比运算符
						postExp.push_back(((oper.top() == '+') ? "+" : "-")); 
						oper.pop();						
					}	
					oper.push(s[i]);
				}
			}
		}
		if(numstr.size() > 0) postExp.push_back(numstr);
		while(!oper.empty()){
			postExp.push_back(((oper.top() == '+') ? "+" : "-")); 
			oper.pop();
		}
		return postExp;
	}
	int string2int(string s){
		int ans = 0;
		for(int i = 0; i < s.size(); i++)
			ans = ans*10 + (s[i]-'0');
		return ans;
	}
};

int main(){
	Solution c;
	cout << c._calculate("    ");
	return 0;
}
