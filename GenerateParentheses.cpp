#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
题目：Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

解析：给出n对括号对，返回可能的组合种类

递归思路：
括号匹配问题与栈结构相符，因此肯定能通过递归算法求解；
递归增加左括号，当左括号的数量大于右括号的数量时，添加右括号，直到左括号的数量到达n，get一个组合

事实上递归过程如下：
l r s (l:当前左括号数量， r:当前右括号数量， s：当时栈顶元素）
0 0
1 0 (
2 0 ((
3 0 (((

出栈：((()))

2 1 (()
3 1 (()(

出栈：(()())

2 2 (())
3 2 (())(

出栈：(())()

1 1 ()
2 1 ()(
3 1 ()((

出栈：()(())

2 2 ()()
3 2 ()()(

出栈：()()()

非递归思路：
使用栈实现以上过程，即为非递归算法，
（1）每次使用到右括号时，栈顶元素都要出栈,拼接右括号后进栈
（2）每次拼接左括号都得进栈，拼接一个左括号进一次栈。
（3）当加入左括号时，栈顶元素的左右括号数量相等，则将栈顶元素出栈，拼接左括号后进栈

*/

class Solution {
public:
	//递归实现，AC
    vector<string> generateParenthesis(int n) {
		vector<string > ans;
		string cur = "";
		if(n > 0) getCombination(n, 0, 0, cur, ans); //cur不能在函数内被改变，不能用引用方式传值
		return ans;
    }
	void getCombination(int n, int l, int r, string cur, vector<string > &ans){
		cout << l << " " << r << " " << cur << endl;
		if(l == n){
			ans.push_back(cur.append(n-r, ')')); //在最后插入n-r个右括号
			cout << endl;
			cout << cur << endl;
			cout << endl;
			return;
		}
		getCombination(n, l+1, r, cur + '(', ans);
		if(l > r) getCombination(n, l, r+1, cur + ')', ans);
	}
	//非递归实现， AC
    vector<string> generateParenthesis1(int n) {
		vector<string > ans;
		stack<string > s;
		string cur = "";
		for(int l = 0; l < n; l++) s.push(cur.append("(")); //将左括号全部进栈，进栈顺序(, ((, (((, ...
		while(!s.empty()){ //栈不为空则执行以下操作
			string _ans = s.top();
			int l = getNum(_ans);
			int r = _ans.size() - l;
			if(l == n){
				ans.push_back(_ans.append(n-r, ')')); //拼接右括号
				s.pop(); 
				continue;
			}
			if(l > r){ 
				s.pop();  //每次增加右括号时，替换栈顶元素
				_ans.append(")");
				s.push(_ans);
				r++;
			}
			while(l < n){
				if(l == r) s.pop(); //当左右括号数相等时替换栈顶元素
				_ans.append("("); //每拼接一个左括号时便进栈一次。
				s.push(_ans);
				l++;
			}
			
		}
		return ans;
    }	
	int getNum(string s){
		int num = 0;
		for(int i = 0; i < s.size(); i++)
			if(s[i] == '(') num++;
		return num;
	}
};

int main(){
	Solution c;
	vector<string > ans = c.generateParenthesis1(4);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
