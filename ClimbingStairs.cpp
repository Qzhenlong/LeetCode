#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        return (climbStairs(n-1)+climbStairs(n-2));
    }
   int climbStairs1(int n) {
        int cur = 1, prior = 1, ans;
         if(n == 0 || n == 1) return 1; 
        for(int i = 2; i <= n; i++)
        {
                ans = cur + prior;
                prior = cur;
                cur = ans;
        }
        return ans;
    }
};
int main()
{
  Solution c;
  int n = 2;
  cout << c.climbStairs(n) << endl;
  while(1);
  return 1;   
}

