#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    bool isPalindrome1(string s) {
        if(s.size()==0) return true;
        char c[s.size()];
        int cn=0,i,j;
        for(i = 0; i < s.size(); i++)
        {
                if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                {
                         if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
                         c[cn] = s[i];
                         cn++;
                } 
        }
        printf("%s\n", c);
        for(i = 0, j = cn-1; i < cn/2; i++,j--)
        {
                if(c[i] != c[j]) return false;
        }
        return true;
    }
};
int main()
{
  Solution c;
  string s = "A";
  cout << (c.isPalindrome1(s) ? "true" : "false") << endl;
  while(1);
  return 1;   
}
