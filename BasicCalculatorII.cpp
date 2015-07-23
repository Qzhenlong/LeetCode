#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
/*
题目：
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.

解析：和版本1相似，只不过运算符多了两个，解法是一样的，转换成后缀表达式，再求解

*/

class Solution {
public:
    int calculate(string s) {
        stack<int > nums;
		vector<string > postExp = getPostExp(s);
		for(int i = 0; i < postExp.size(); i++){
			if(postExp[i] == "+" || postExp[i] == "-" || postExp[i] == "*" || postExp[i] == "/"){
				int a = nums.top(); nums.pop();
				int b = nums.top(); nums.pop();
				int c = cal(a, b, postExp[i]);
				nums.push(c);
			}
			else nums.push(string2int(postExp[i]));
		}
		return nums.top();
    }
	vector<string > getPostExp(string s){
		vector<string > postExp;
		stack<char > op;
		string numstr = "";
		setPriority();
		for(int i = 0; i < s.size(); i++){
			if(s[i] == ' ') continue;
			if(s[i] >= '0' && s[i] <= '9') numstr += s[i];
			else{
				if(numstr.size() > 0){
					postExp.push_back(numstr);
					numstr = "";
				}
				if(s[i] == ')'){ //遇到右括号，将左括号前的运算符全部出栈
					while(op.top() != '('){
						postExp.push_back(getOperator(op.top()));
						op.pop();
					}
					op.pop();
				}
				else{//对比左右运算符优先级
					if(op.empty()){ op.push(s[i]); continue; } //栈空则直接进栈
					if(lpri[op.top()] < rpri[s[i]]) op.push(s[i]); //右运算符优先级高，直接进栈
					else{
						while(!op.empty() && lpri[op.top()] > rpri[s[i]]){ //栈顶左运算符优先级高，出栈放入字符串数组中,直到找到比优先级小于右运算符的位置时，右运算符再入栈
							postExp.push_back(getOperator(op.top()));
							op.pop();
						}
						op.push(s[i]);
					}
				}
			}
		}
		if(numstr.size() > 0) postExp.push_back(numstr);
		while(!op.empty()){
			postExp.push_back(getOperator(op.top()));
			op.pop();
		}
		for(int i = 0; i < postExp.size(); i++)
			cout << postExp[i] << " ";
		cout << endl;
		return postExp;
	}
	

private:
	map<char, int> lpri; //左运算符优先级
	map<char, int> rpri; //右运算符优先级
	void setPriority(){ //设置优先级
		lpri['('] = 1; lpri['+'] = 3; lpri['-'] = 3; lpri['*'] = 5; lpri['/'] = 5; lpri[')'] = 6;
		rpri['('] = 6; rpri['+'] = 2; rpri['-'] = 2; rpri['*'] = 4; rpri['/'] = 4; rpri[')'] = 1; 
	}
	string getOperator(char c){
		if(c == '+') return "+";
		if(c == '-') return "-";
		if(c == '*') return "*";
		if(c == '/') return "/";
	}
	int cal(int a, int b, string op){
		if(op == "+") return a+b;
		if(op == "-") return b-a;
		if(op == "*") return a*b;
		if(op == "/") return b/a;
	}
	int string2int(string s){ //简单的字符串转换成整数
		int ans = 0;
		for(int i = 0; i < s.size(); i++) ans = ans*10 + (s[i]-'0');
		return ans;
	}
};

int main(){
	Solution c;
	cout << c.calculate("3+5 / 2 + 2/3 ");
	return 0;
}
