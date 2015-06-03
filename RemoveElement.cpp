#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int > _nums;
        int ans;
        if(nums.size() == 0) return 0;
        for(int i = 0; i < nums.size(); i++)
                if(nums[i] != val) _nums.push_back(nums[i]);
        ans = _nums.size();
        nums.clear();
        nums.resize(ans);
        for(int i = 0; i < _nums.size(); i++) nums[i] = _nums[i];
        return ans;
    }
    int removeElement1(vector<int>& nums, int val) {
        int ans = 0, n = nums.size();
        if(n == 0) return ans;
        ans = n;
        for(int i = 0, pos = 0; i < n; i++)
        {
                if(nums[i] == val) ans--;
                else{
                     nums[pos++] = nums[i];
                     }
        }
        return ans;
    }
    

};
int main()
{
  Solution c;
  vector<int > a, b;

  a.push_back(2);
  a.push_back(0);
  a.push_back(3);
  cout << c.removeElement(a,0) << endl;
    for(int i = 0; i < a.size(); i++)
          cout << a[i] << " ";
  while(1);
  return 1;   
}
