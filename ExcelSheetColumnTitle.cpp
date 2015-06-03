#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int n){
        string ans="";
        while(n > 26){
                int tmp = n % 26;
                n = n/26;
                if(tmp == 0){ tmp = 26; n = n-1;}   //由于是整除，向下取整时-1 
                ans += (char)(tmp+64);
        }
        ans += (char)(n+64);
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main()
{
  Solution c;
  cout << c.convertToTitle(52) << endl;
  while(1);
  return 1;   
}

