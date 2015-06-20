#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��Ŀ��Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

����������n�����Ŷԣ����ؿ��ܵ��������

�ݹ�˼·��
����ƥ��������ջ�ṹ�������˿϶���ͨ���ݹ��㷨��⣻
�ݹ����������ţ��������ŵ��������������ŵ�����ʱ����������ţ�ֱ�������ŵ���������n��getһ�����

��ʵ�ϵݹ�������£�
l r s (l:��ǰ������������ r:��ǰ������������ s����ʱջ��Ԫ�أ�
0 0
1 0 (
2 0 ((
3 0 (((

��ջ��((()))

2 1 (()
3 1 (()(

��ջ��(()())

2 2 (())
3 2 (())(

��ջ��(())()

1 1 ()
2 1 ()(
3 1 ()((

��ջ��()(())

2 2 ()()
3 2 ()()(

��ջ��()()()

�ǵݹ�˼·��
ʹ��ջʵ�����Ϲ��̣���Ϊ�ǵݹ��㷨��
��1��ÿ��ʹ�õ�������ʱ��ջ��Ԫ�ض�Ҫ��ջ,ƴ�������ź��ջ
��2��ÿ��ƴ�������Ŷ��ý�ջ��ƴ��һ�������Ž�һ��ջ��
��3��������������ʱ��ջ��Ԫ�ص���������������ȣ���ջ��Ԫ�س�ջ��ƴ�������ź��ջ

*/

class Solution {
public:
	//�ݹ�ʵ�֣�AC
    vector<string> generateParenthesis(int n) {
		vector<string > ans;
		string cur = "";
		if(n > 0) getCombination(n, 0, 0, cur, ans); //cur�����ں����ڱ��ı䣬���������÷�ʽ��ֵ
		return ans;
    }
	void getCombination(int n, int l, int r, string cur, vector<string > &ans){
		cout << l << " " << r << " " << cur << endl;
		if(l == n){
			ans.push_back(cur.append(n-r, ')')); //��������n-r��������
			cout << endl;
			cout << cur << endl;
			cout << endl;
			return;
		}
		getCombination(n, l+1, r, cur + '(', ans);
		if(l > r) getCombination(n, l, r+1, cur + ')', ans);
	}
	//�ǵݹ�ʵ�֣� AC
    vector<string> generateParenthesis1(int n) {
		vector<string > ans;
		stack<string > s;
		string cur = "";
		for(int l = 0; l < n; l++) s.push(cur.append("(")); //��������ȫ����ջ����ջ˳��(, ((, (((, ...
		while(!s.empty()){ //ջ��Ϊ����ִ�����²���
			string _ans = s.top();
			int l = getNum(_ans);
			int r = _ans.size() - l;
			if(l == n){
				ans.push_back(_ans.append(n-r, ')')); //ƴ��������
				s.pop(); 
				continue;
			}
			if(l > r){ 
				s.pop();  //ÿ������������ʱ���滻ջ��Ԫ��
				_ans.append(")");
				s.push(_ans);
				r++;
			}
			while(l < n){
				if(l == r) s.pop(); //���������������ʱ�滻ջ��Ԫ��
				_ans.append("("); //ÿƴ��һ��������ʱ���ջһ�Ρ�
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
