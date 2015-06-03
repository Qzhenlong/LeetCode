#include<iostream>
using namespace std;
//而1-N中，5的倍数个数为|_N/5_|，|_ _|表示取下整数。
//又1-N中，25的倍数个数为|_N/25_|.需要注意到的是|_N/5_|已经包含了|_N/25_|。又25的倍数贡献了2，所以考虑到避免重复计算，则N!的素数分解中5的指数j为：
//j = |_N/5_|+|_N/25_|+|_N/5^3_|+...

class Solution{
      public:
      int trailingZeroes(int n) {
    /**    int zero=0; //复杂度不符合要求 
        int i=5;
        while(i<=n)
        {
            zero+=n/i;
            i*=5;
        }
        return zero;
        */
        int ret = 0; //时间复杂度为log(n) 
        while(n)
        {
            ret += n/5;
            n /= 5;
        }
        return ret;
    }
      
};

int main()
{
  Solution c;
  int n = 5;
  cout << c.trailingZeroes(n) <<endl;
  while(1);
  return 1;   
}
