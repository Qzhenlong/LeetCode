#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*
Anagrams:即是一个单词中的字母顺序改变，长度不变，如"eat ate tea"就是
思路：
1）不对：由于只是顺序改变，但是所有字母的和应该是相等且长度相同。可由字母和和长度先缩小范围，再进行详细对比

应该是对每个字符串按从中到排序，排序后应该是相等的
*/
class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        map<string, vector<string > > m_str;
		vector<string > ans;
		for(int i = 0; i < strs.size(); i++)
		{
			string tmp = strs[i];
			sort(tmp.begin(), tmp.end());
			m_str[tmp].push_back(strs[i]);
		}
		for(map<string, vector<string > >::iterator it = m_str.begin(); it != m_str.end(); it++)
		{
			if(it->second.size() > 1) //迭代器用法 key : it->first, value : it->second
				ans.insert(ans.end(), it->second.begin(), it->second.end());
		}
		return ans;
    }
};

int main()
{
	Solution c;
	vector<string > strs;
	strs.push_back("abc");
	strs.push_back("tea");
	strs.push_back("ate");
	strs.push_back("tea");
	strs.push_back("bac");
	vector<string > ans = c.anagrams(strs);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	while(1);
	return 0;
}
