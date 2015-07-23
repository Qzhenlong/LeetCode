#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
/*
��Ŀ��
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.

�������Ͱ汾1���ƣ�ֻ��������������������ⷨ��һ���ģ�ת���ɺ�׺���ʽ�������

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
				if(s[i] == ')'){ //���������ţ���������ǰ�������ȫ����ջ
					while(op.top() != '('){
						postExp.push_back(getOperator(op.top()));
						op.pop();
					}
					op.pop();
				}
				else{//�Ա�������������ȼ�
					if(op.empty()){ op.push(s[i]); continue; } //ջ����ֱ�ӽ�ջ
					if(lpri[op.top()] < rpri[s[i]]) op.push(s[i]); //����������ȼ��ߣ�ֱ�ӽ�ջ
					else{
						while(!op.empty() && lpri[op.top()] > rpri[s[i]]){ //ջ������������ȼ��ߣ���ջ�����ַ���������,ֱ���ҵ������ȼ�С�����������λ��ʱ�������������ջ
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
	map<char, int> lpri; //����������ȼ�
	map<char, int> rpri; //����������ȼ�
	void setPriority(){ //�������ȼ�
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
	int string2int(string s){ //�򵥵��ַ���ת��������
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
