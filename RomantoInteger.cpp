#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;
/* Roman Number
1、相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
2、小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
3、小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；
4、正常使用时，连写的数字重复不得超过三次。（表盘上的四点钟“IIII”例外）
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
