#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t x = 1;
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
                int tmp = (n >> i) & x;
                ans += tmp;
        }
        return ans;
    }
};
int main()
{
  Solution c;
  cout << c.hammingWeight(0xff)<< endl;
  while(1);
  return 1;   
}
