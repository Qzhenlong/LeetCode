#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 1;
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++)
        {
                int tmp = (n >> i) & x;
                int tmp1 = tmp << (31-i);
                ans += tmp1;
        }
        return ans;
    }
};
int main()
{
  Solution c;
  cout << c.reverseBits(43261596) << endl;
  while(1);
  return 1;   
}
