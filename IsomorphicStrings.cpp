#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> pair;
        map<char, char> inv_pair;
        map<char, int>  pair_c;
        map<char, int> inv_pair_c;
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++)
        {
               pair_c[s[i]] = -1;
               inv_pair_c[t[i]] = -1;
        }
        for(int i = 0; i < s.size(); i++)
        {
               if(pair[s[i]] != t[i]) 
               {
                             pair_c[s[i]]++;
                             pair[s[i]] = t[i];
               }
               if(inv_pair[t[i]] != s[i])
               {
                             inv_pair_c[t[i]]++;
                             inv_pair[t[i]] = s[i];
               }
               if(pair_c[s[i]] > 0 || inv_pair_c[t[i]] > 0) return false;
        }
        return true;
    }
};
int main()
{
  Solution c;
  string s = "title", t = "paper";
  cout << (c.isIsomorphic(s,t)? "true" : "false") << endl;
  while(1);
  return 1;   
}
