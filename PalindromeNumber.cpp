#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int len = 0, tmp = x;
        if(x < 0) return false;
        while(tmp > 0)
        {
                  tmp = tmp / 10;
                  len++;
        }
        for(int i = 0; i < len/2; i++)
        {
                double y = len-2*i-1;
                int high = x / pow(10, y);
                int low  = x % 10;
                x = (x-(high*pow(10, y))) / 10;
                if(high != low) return false;
        }
        return true;
    }
};
int main()
{
  Solution c;
  cout << (c.isPalindrome(-2147483648) ? "true" : "false") << endl;
  while(1);
  return 1;   
}
