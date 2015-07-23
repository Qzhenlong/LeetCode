#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��Ŀ��Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

Note: Do not use the eval built-in library function.

������ʵ��һ�������ļ�����������һ���򵥵��ַ������ʽ�����ʽ�����������š��Ӽ��ŷǸ����������ո�

˼·������ֻ�мӼ��������Ͻ����ʣ����ǲ���ֱ�Ӻ������ŵ����ã���Ϊ�и�����������"2-(5-6)""���������ǰΪ���ţ���Ҫ�����������������ȡ��
��1������ⷨ������׺���ʽת���ɺ�׺���ʽ������ջ��⣬�����������������еļӼ������ȼ���ͬ����������������ȼ������������
   a. ����һ��ջ�洢�������һ���ַ������飬�洢��׺���ʽ
   b. ���Ϊ���֣�ƴ�ӳ����ֺ�ֱ�ӷ����ַ������� 
   c. ���Ϊ'('��ֱ�ӽ�ջ,
   b. ���Ϊ�Ӽ������������ջ��Ԫ�����ȼ����жԱȣ�ջ����������ȼ��ߣ����ջ�����ַ������飬����ֱ�ӽ�ջ
   d. ���Ϊ')'����ջ���������ջ�������ַ������飬ֱ��ջ��Ϊ'('�������ջ������ɨ�衣
*/

class Solution {
public:
    //֮ǰ�Ĵ���˼·
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
	//��ջʵ�֣�����׺���ʽת���ɺ�׺���ʽ
	int _calculate(string s){
		int ans = 0;
		stack<int > nums;
	    vector<string > postExp = genPostExp(s);
		if(postExp.size() == 0) return 0;
		for(int i = 0; i < postExp.size(); i++){
			if(postExp[i] == "-" || postExp[i] == "+"){ //�����׺���ʽ��ֵ
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
				if(s[i] == ')'){ //Ϊ�����ţ���������֮ǰ�������������ջ
					char op = oper.top(); oper.pop();
					while(op != '('){
						postExp.push_back(((op == '+') ? "+" : "-")); 
						op = oper.top(); oper.pop();
					}
				}
				else if(s[i] == '(') oper.push(s[i]); //Ϊ������ֱ�ӽ�ջ
				else{   //��ǰ�ַ�Ϊ���������ջ���ַ������ȼ����жԱ�
					if(!oper.empty() && oper.top() != '('){ //ֻ�Ա������
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
