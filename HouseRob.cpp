#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) { // MV[i] = Max( MV[i-2] + num[i] , MV[i-1]); ¶¯Ì¬¹æ»® 
        int MV[nums.size()];
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        MV[0] = nums[0];
        MV[1] = (nums[1]>nums[0])?nums[1]:nums[0];
        for(int i = 2; i < nums.size(); i++)
        {
                MV[i] = ((MV[i-2] + nums[i]) > MV[i-1]) ? MV[i-2] + nums[i] : MV[i-1];
        }
        return MV[nums.size()-1]; 
    }
};
int main()
{
  Solution c;
  vector<int > nums;
  
//  cout << (c.isPalindrome(-2147483648) ? "true" : "false") << endl;
  while(1);
  return 1;   
}
