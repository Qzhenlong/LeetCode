#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size(); 
        double ans = 0;
        for(int i = 0; i < len; i++){
                ans += (fun(s[i])* pow(26,len-i-1));
                }
        return (int)ans;
        
    }
    int fun(char c){
        return (c-64);
    }
};
int main()
{
  Solution c;
  printf("%d", c.titleToNumber("ZZ"));
  while(1);
  return 1;   
}
