#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> num_map;
        for(int i = 0; i < nums.size(); i++)
        {
                num_map[nums[i]] = 0;        
        }
        for(int i = 0; i < nums.size(); i++)
        {
                num_map[nums[i]]++;        
        }
        for(int i = 0; i < nums.size(); i++)
        {
                if(num_map[nums[i]] == 1) 
                     return nums[i];        
        }
    }
	int singleNumber1(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) ans ^= nums[i];         
		return ans;
    }
};
int main()
{
  Solution c;
  int A[] = {2,2,3,3,1};
  vector<int > n;
  for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
  cout << c.singleNumber(n) << endl;
  cout << c.singleNumber1(n) << endl;
  while(1);
  return 1;   
}
