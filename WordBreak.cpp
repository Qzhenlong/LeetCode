#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
��Ŀ��
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

˼·��
��̬�滮��
����Ϊn���ַ�����Ӧ����n+1������
״̬ת�Ʒ��̣�
f(i) = any_of(f(j)&&s[j + 1, i] ���� dict), 
f(i)��ʾ[0,i]���Էִʣ�f(i)���Էִʵ��������ǵ�[0,j]���Էִ���[j+1,i]���ֵ���  
*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string >& wordDict) {
        vector<bool > f(s.size()+1, false);
		f[0] = true;
		for(int i = 1; i <= s.size(); i++)
		{
			for(int j = i-1; j >= 0; j--)
			{
				if(f[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()){
					f[i] = true;
					break; //0-i�Ѿ����Էִʣ����ü�����
				}
			}
		}
		return f[s.size()];
    }
};

int main()
{
	Solution c;
	string s = "leetcode";
	unordered_set<string > dict;
	dict.insert("leet");
	dict.insert("code");
	cout << c.wordBreak(s, dict);
	return 0;
}
