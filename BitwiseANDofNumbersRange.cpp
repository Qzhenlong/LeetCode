#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
int rangeBitwiseAnd(int m, int n) {
        if(m == 0 || n == 0) return 0;
        int mb=0, nb = 0, ans = 0;
        while(mb == nb)
        {
                 if(m == 0 || n == 0) break;
                 mb = (int)(log(m)/log(2));
                 nb = (int)(log(n)/log(2));
                 if(mb == nb){
                       int tmp = (1 << nb);
                       ans += tmp;
                       m -= tmp;
                       n -= tmp; 
                       }
                
        }
        return ans;
    }

};
int main()
{
  Solution c;                                                                                 
  cout << c.rangeBitwiseAnd(1,2) << endl;
  while(1);
  return 1;   
}
