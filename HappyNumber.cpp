#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        map<int, int> loop_c;
        int x = 0;
        loop_c[n] = 1;
        while(x != 1)
        {
                x = 0;
                while(n > 0)
                {
                        x += (n%10)*(n%10);
                        n = n/10;
                }
                if(loop_c[x] == 1 && x != 1) return false;
                n = x;
                loop_c[x] = 1;
                cout << x << endl;
        }
        return true;
    }
};
int main()
{
  Solution c;
  cout << (c.isHappy(2)? "true" : "false") << endl;
  while(1);
  return 1;   
}
