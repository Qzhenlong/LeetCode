#include<iostream>
#include<map>
using namespace std;
/*
��¼�ظ��ַ���λ�ã���s[0]****s[i]****s[j] ,start = 0, ˳��ɨ�裬��s[i] = s[j]ʱ����һ��ɨ�����������Ϊj; 
��start = i + 1, ����ɨ�裬 ������󳤶ȼ��ɣ� 
 ��̰���㷨 
*/
class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        map<char, int> s_map; 
        int len = 0, start = 0;
        for(int i = 0; i < 26; i++) s_map[i + 'a'] = -1; //��ʼ��
        for(int i = 0; i < s.size(); i++)
        {
                if(s_map[s[i]] >= start)
                {
                     len = (len > i-start)? len : i-start;
                     start = s_map[s[i]] + 1;
                }
                s_map[s[i]] = i;
        } 
        len = (len > s.size()-start)? len : s.size()-start; //���һ���ظ�Ԫ��Ҫ�������� 
        return len;
    }      
};

int main()
{
    Solution c;
    string s = "ab";
    cout << c.lengthOfLongestSubstring(s);
    while(1);
    return 0;
}
