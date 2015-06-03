#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string rs = "";
		int i = s.size() - 1;
		while(i >= 0)
		{
			while(i >= 0 && s[i] == ' ') i--;
			if(i < 0) break; //±ß½ç×¢Òâ
			if(!rs.empty()) rs += ' ';//rs.append(" ");
		    string tmp = "";
			while(i >= 0 && s[i] != ' ') tmp += s[i--];
			reverse(tmp.begin(), tmp.end());
			rs.append(tmp);
		}
		s = rs;
    }
};

int main()
{
	Solution c;
	string s = " the sky is blue";
	c.reverseWords(s);
	cout << s << endl;
	while(1);
	return 0;
}
