#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;
/* Roman Number
1����ͬ��������д������ʾ����������Щ������ӵõ��������磺�� = 3��
2��С�������ڴ�����ֵ��ұߣ�����ʾ����������Щ������ӵõ������� �磺�� = 8���� = 12��
3��С�����֣������ڢ�X ��C���ڴ�����ֵ���ߣ�����ʾ�������ڴ�����С���õ��������磺��= 4����= 9��
4������ʹ��ʱ����д�������ظ����ó������Ρ��������ϵ��ĵ��ӡ�IIII�����⣩
*/
class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0) return 0;
        map<char, int> r_map;
        int istack[s.size()];
        char cstack[s.size()];
        int top = -1;
        int ans = 0;
        r_map['I'] = 1; r_map['X'] = 10; r_map['C'] = 100;
        r_map['M'] = 1000; r_map['V'] = 5; r_map['L'] = 50; r_map['D'] = 500;
        top++;
        istack[top] = r_map[s[0]];
        cstack[top] = s[0];
        for(int i = 1; i < s.size(); i++)
        {
             if(cstack[top] == s[i]) istack[top] += r_map[s[i]];
             else{ top++; istack[top] = r_map[s[i]]; cstack[top] = s[i]; }
        }
        ans = istack[top];
        top--;
        while(top >= 0)
        {
           if(ans <= istack[top]) ans += istack[top];
           else ans -= istack[top];
           top--;
        }
        return ans;
    }
    int romanToInt1(string s) {
        int n = s.size();
        int ans = toNumber(s[n-1]);
        for(int i = n-2; i >= 0; i--)
        {
                if(toNumber(s[i+1]) <= toNumber(s[i])) ans += toNumber(s[i]);
                else ans -= toNumber(s[i]);
        } 
        return ans;
    }
    int toNumber(char ch) {  
        switch (ch) {  
            case 'I': return 1;  
            case 'V': return 5;  
            case 'X': return 10;  
            case 'L': return 50;  
            case 'C': return 100;  
            case 'D': return 500;  
            case 'M': return 1000;  
        }  
        }
};
int main()
{
  Solution c;
  string s = "MCMLXXXIV";
  cout << c.romanToInt(s)<< endl;
  while(1);
  return 1;   
}
