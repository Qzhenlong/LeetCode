#include<iostream>
#include<map>
using namespace std;
/*
记录重复字符的位置，当s[0]****s[i]****s[j] ,start = 0, 顺序扫描，当s[i] = s[j]时，第一次扫描结束，长度为j; 
将start = i + 1, 继续扫描， 计算最大长度即可， 
 ：贪心算法 
*/
class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        map<char, int> s_map; 
        int len = 0, start = 0;
        for(int i = 0; i < 26; i++) s_map[i + 'a'] = -1; //初始化
        for(int i = 0; i < s.size(); i++)
        {
                if(s_map[s[i]] >= start)
                {
                     len = (len > i-start)? len : i-start;
                     start = s_map[s[i]] + 1;
                }
                s_map[s[i]] = i;
        } 
        len = (len > s.size()-start)? len : s.size()-start; //最后一个重复元素要包含在内 
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
