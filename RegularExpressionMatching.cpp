#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "a*") �� true
isMatch("aa", ".*") �� true ,..="aa"
isMatch("ab", ".*") �� true
isMatch("aab", "c*a*b") �� true 

������ʵ��ͨ������ʽ��.��ʾ���ⵥ���ַ���*��ʾ������ƥ��֮ǰ��0�������������ַ���0��˵��ǰ����ַ�û���ˡ�

˼·������������
��1�������𰸣�����̫��
��2����̬�滮�����ȽϺ����, ����pȥƥ��s
     dp[i][j]��ʾ�ִ� s[0...i), p[0...j) �Ƿ����ƥ�䡣
	a. ��ʼdp[0][0]Ϊtrue
	b. ��s[i-1] == '.' �� p[i-1] == '.'ʱ����ǰ��Ȼ��ƥ�䣬����dp[i][j] = dp[i-1][j-1];
	c. ��s[i-1] == '*'ʱ��s[i-1]�ɺ���Ҳ�ɲ����ԣ�����0��ǰ���ַ���˵��ǰһ���ַ������ԣ���dp[i][j] = dp[i-2][j]
	   ���*����1��ǰһ���ַ�,��s[i-1]����û���ַ�,��dp[i][j] = dp[i-1][j]������dp[i][j] = dp[i-1][j] || dp[i-2][j];
	   ע����������ֻ����s[0..i)��p[0...j)�Ƿ�ƥ�䣬���ֻ��Ҫ����*��ʾ0������1��ǰһ���ַ�������Ϳ�����~
	d. ��p[j-1] == '*'ʱ��p[i-1]�ɺ���Ҳ�ɲ����ԣ�����������һ����dp[i][j-1] || dp[i][j-2]
	   ͬʱ���s[0..i-1)��p[0...j)����ƥ��Ļ�������*���Ա�ʾn��ǰ��֮ǰ���ַ�������p[j-1]�ɱ�ʾ������p[j-2]��
	   ��s[i-1]==p[j-2] || p[j-2]=='.'�� p[j-1]��Ȼ����s[i-1]ƥ�䣬 
	   ����dp[i][j] = dp[i][j-1] || dp[i][j-2] || (dp[i-1][j] && (s[i-1] = p[j-2] || p[j-2] = '.'));
	e. ������������жϵ�ǰ�ַ��Ƿ���ȣ�����dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];

*/

class Solution {
public:
    bool _isMatch(string s, string p) {
		const char *ss = s.c_str();
		const char *pp = p.c_str();
		return stdMatch(ss, pp);
    }
	//��̬�滮
    bool isMatch(string s, string p) {
	    int ns = s.size(), np = p.size();
	    vector<vector<bool> > dp(ns+1,vector<bool>(np+1,false));
	    dp[0][0]=true; //���ַ�����ƥ��
	    for(int i = 1; i <= ns; ++i) //sҲ���ܴ���Ϊ*�����
		    if (s[i-1]=='*'  && i > 1) //���Ϊ*��˵�����Ժ��ԣ�*����Ϊ�ջ�ǰ�������ַ�
			    dp[i][0]=dp[i-2][0];
	    
	    for(int j = 1; j <= np; ++j) //��ͬ����
		    if ( p[j-1]=='*' && j > 1)
			    dp[0][j]=dp[0][j-2];
		 
	    for(int i = 1; i <= ns; ++i){
		    for(int j = 1;j <= np; ++j){
			    if (s[i-1]=='.'|| p[j-1]=='.') //.�ſ��Ա�ʾ�����ַ������ֱ�ӵ�����ǰ������
				    dp[i][j] = dp[i-1][j-1];
			    else if (s[i-1]=='*' && i > 1) //���s[i-1]��*�ţ� ���Ժ���Ҳ���Բ����ԣ�����dp[i][j]=dp[i-1][j](�����ԣ���dp[i-1][j]�����ԣ�
				    dp[i][j] = dp[i-1][j] || dp[i-2][j]; 
			    else if ( p[j-1]=='*' && j > 1) //���s[i]����ͨ�ַ���p[j-1]��*�ţ�ͬ���ɺ���Ҳ�ɲ����ԣ�ͬʱ
				    dp[i][j] = dp[i][j-1] || dp[i][j-2] || (dp[i-1][j] && (s[i-1]==p[j-2]||p[j-2]=='.'));
			    else   //����Ϳ���ǰ�ַ��Ƿ����
				    dp[i][j] = dp[i-1][j-1] && s[i-1] == p[j-1];
		    }
	    }
	    return dp[ns][np];
    }
/*
�ݹ�ⷨ��˼·��
����ָ��i, j��iָregular expression��jָ���string��
�۲�p[i+1]��
���������*��˵��û��skip p[i]����p[i]��s[j]����match����Ȼ���p[i]�ǡ�.�� which matches everything������������㣬ֱ�ӷ���false��û��matche�ˡ�
�������*��˵����ǰλ�ÿ�����0��p[i], 1��p[i], 2��p[i]..
�����ԡ���0��p[i]��������p[i]���������* skip������recurse (i + 2, j)�ɹ��ˣ�ֱ�ӷ���true�����ɹ����������ڶ�����
�ӡ���1��p[i]����ʼwhileѭ������p[i]��s[j] match, recurse on (i + 2, j + 1)����*�õ�������i+2�����������true��ֱ�ӳ��ˣ������while����ѭ������2��p[i]����
��recurse on (i + 2, j + 2), recurse on (i + 2, j + 3)��ѭ������ֹ������p[i]��s[j]��match�ˣ�ֱ�ӷ���false��
*/
	bool stdMatch(const char *s, const char *p){
         if (*p == '\0') return *s == '\0';
        
        if (*(p+1) == '*') // next is '*'
        {
            while ((*s == *p || *p == '.') && *s != '\0') // ��i��*p��ʼѭ�����������sƥ������� 
            {
                if (isMatch(s, p+2))
                    return true;
                s++;
            }
            return isMatch(s, p+2); //����ƥ���ֱ����0��*ps
        }
        
        if (*s == '\0') return false;
        return (*s == *p || *p == '.') && isMatch(s+1, p+1);  //���*(p+1)����*
	}

};

int main(){
	Solution c;
	cout << c.isMatch("aba", "a*b") << endl;
	return 0;
}
