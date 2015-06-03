#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if(strs.size() == 0) return prefix;
        int n = strs.size();
        int sn = strs[0].size();
        for(int i = 0; i < sn; i++)
        {
                int x = 0;
                for(int j = 1; j < n; j++)
                {
                        if(strs[0][i] != strs[j][i]){x = 1; break;}       
                }
                if(x == 0) prefix += strs[0][i];
                else break;
        }
        return prefix;
    }
};
int main()
{
  Solution c;
  vector<string > strs;
  string a = "a";
  string b = "a";
  string d = "b";
  strs.push_back(a);
  strs.push_back(b);
  strs.push_back(d);
  cout << c.longestCommonPrefix(strs)<< endl;
  while(1);
  return 1;   
}
