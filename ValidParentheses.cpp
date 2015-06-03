#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return false;
        char s_stack[s.size()];
        int top = -1;
        top++;
        s_stack[top] = s[0];
        for(int i = 1; i < s.size(); i++)
        {
               if(isSamePattern(s_stack[top],s[i])) top--;
               else{ top++; s_stack[top] = s[i]; }  
        }
        if(top == -1) return true;
        return false;
    }
    bool isSamePattern(char a, char b)
    {
         if(a == '(' && b == ')') return true;
         else if(a == '{' && b == '}') return true;
         else if(a == '[' && b == ']') return true;
         else return false;     
    }
};
int main()
{
  Solution c;
  string s = "";
  cout << (c.isValid(s)? "true": "false" ) << endl;
  while(1);
  return 1;   
}
