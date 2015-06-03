#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, cur = s.size()-1;
        if(s.size() == 0) return 0;
        while(s[cur] == ' ') cur--;
        for(int i = cur; i >= 0; i--)
        {
                if(s[i] != ' '){ ans++; continue;}
                break; 
        }
        return ans;
    }

};
int main()
{
  Solution c;
  string s = "a ";                                                                                 
  cout << c.lengthOfLastWord(s)<< endl;
  while(1);
  return 1;   
}
