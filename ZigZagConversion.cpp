#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
       string convert(string s, int nRows){
          if(nRows <=1 ) return s;
          int index[nRows-1];
          int inv_index[nRows-1];
          int re_index[s.size()];
          int c = 0;
          string s1="";
          for(int i = 0; i < nRows-1; i++)
          {
                  inv_index[i] = 2*(i+1);
                  index[nRows-2-i] = inv_index[i];
                 // cout << index[nRows-2-i] << " ";
          }
          for(int i = 0; i < nRows; i++)
          {
                  int j = i;
                  if(i == 0 || i == nRows-1){
                      while(j < s.size()){
                              re_index[c] = j;
                              j += index[0];
                              c++;
                              }
                  }
                  else{
                       while(j < s.size()){
                               re_index[c] = j;
                               j += index[i];
                               c++;
                               if(j < s.size()){
                                      re_index[c] = j;
                                      j += inv_index[i-1];
                                      c++;
                                    }
                               }     
                  }
          }
          for(int i = 0; i < s.size(); i++)
          {
                 // cout << re_index[i] << endl;
                  s1 += s[re_index[i]];       
                  }
          return s1;
       }
};
int main()
{
  Solution c;
  string s = "ABC";
  cout << s << endl;
  cout << c.convert(s,1) << endl;
  while(1);
  return 1;   
}
