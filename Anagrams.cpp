#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*
Anagrams:����һ�������е���ĸ˳��ı䣬���Ȳ��䣬��"eat ate tea"����
˼·��
1�����ԣ�����ֻ��˳��ı䣬����������ĸ�ĺ�Ӧ��������ҳ�����ͬ��������ĸ�ͺͳ�������С��Χ���ٽ�����ϸ�Ա�

Ӧ���Ƕ�ÿ���ַ��������е����������Ӧ������ȵ�
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
			if(it->second.size() > 1) //�������÷� key : it->first, value : it->second
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
