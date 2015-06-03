#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int > plusOne(vector<int > &digits) 
    {
        if(digits.size()==0) return digits;
        int c = 1;
        vector<int > ans;
        for(int i = digits.size()-1; i >= 0; i--)
        {
                int cur = digits[i] + c;
                ans.push_back(cur%10);
                c = cur / 10;
        }
        if(c != 0) ans.push_back(c); //最后进位
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};
int main()
{
  Solution c;
  vector<int > digits;
  for(int i = 0; i < 10; i++) digits.push_back(i);
  vector<int > ans = c.plusOne(digits);
  for(int i = 0; i < ans.size(); i++)
          cout << ans[i] << " ";
  while(1);
  return 1;   
}

