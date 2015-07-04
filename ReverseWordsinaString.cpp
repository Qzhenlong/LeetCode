#include<iostream>
#include<string>
using namespace std;
/*
题目：Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

解析：输入一个英文句子，翻转句子中的单词顺序，但单词内字符的顺序不变

思路：两次翻转，一次整体翻转，一次局部翻转即可

*/
class Solution {
public:
	//空间O(n)
    void reverseWords(string &s) {
        string rs = "";
		int i = s.size() - 1;
		while(i >= 0)
		{
			while(i >= 0 && s[i] == ' ') i--;
			if(i < 0) break; //边界注意
			if(!rs.empty()) rs += ' ';//rs.append(" ");
		    string tmp = "";
			while(i >= 0 && s[i] != ' ') tmp += s[i--];
			reverse(tmp.begin(), tmp.end());
			rs.append(tmp);
		}
		s = rs;
    }
	//空间O(1)
    void reverseWords1(string &s) {
		int i = 0, j=0, blank = 0;
		//去多余空格
		i = s.find(' ', 0); //找第一个空格的位置
		while(j < s.size()){
			j = s.find(' ', i+1);
			if(j-i == 1) s.erase(j, 1);
			else i = j;
		}
		if(s.size() > 0 && s[0] == ' ') s.erase(0,1);
		if(s.size() > 0 && s[s.size()-1] == ' ') s.erase(s.size()-1, 1);
		int n = s.size();
		for(i = 0; i < n/2; i++){ //整体翻转一次
			char tmp = s[i];
			s[i] = s[n-i-1];
			s[n-i-1] = tmp;
		}
		i = 0; j = 0;
		while(j <= n){ //局部翻转一次
			if(j < n && s[j] != ' ') j++;
			else{
				for(int k = 0; k < (j-i)/2; k++){
					char tmp = s[i+k];
					s[i+k] = s[j-k-1];
					s[j-k-1] = tmp;
				}
				j++;
				i = j;
			}
		}
    }
};

int main()
{
	Solution c;
	string s = "   ";
	cout << s << "|" << endl;
	c.reverseWords1(s);
	cout << s << "|" << endl;
	while(1);
	return 0;
}
