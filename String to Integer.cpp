#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        
        long long ans = 0;
        int neg = 0, pos = 0;
        int j = 0;
        while(str[j] == ' ') j++;
        for(int i = j; i < str.size(); i++)
        {
                if(str[i] == ' ') break;
                else if(str[i] == '-'){neg++; continue;}
                else if(str[i] == '+') {pos++; continue;}
                else if(str[i] >= '0' && str[i] <= '9') ans = ans*10 + (str[i] - '0'); 
                else break;
                   
                if((neg+pos) > 1) return 0;
                if(ans > INT_MAX) return (neg == 1) ? INT_MIN : INT_MAX; 
                  
        }    
        
        if(neg == 1) return -ans;
        return ans;

    }
};
int main()
{
  Solution c;
  cout << c.myAtoi("9223372036854775809") << endl;
  while(1);
  return 1;   
}
