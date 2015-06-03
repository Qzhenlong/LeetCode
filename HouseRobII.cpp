#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) { // ����DP���� 
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int rob1 = _rob(nums); //���ǵ�һ����ȥ�����һ�� 
        nums.erase(nums.begin()); //ȥ���һ��
        nums.push_back(0);
        int rob2 = _rob(nums);
        return (rob1 > rob2)? rob1 : rob2;
         
    }
    int _rob(vector<int>& nums) { // MV[i] = Max( MV[i-2] + num[i] , MV[i-1]); ��̬�滮 
        int MV[nums.size()];
        MV[0] = nums[0];
        MV[1] = (nums[1]>nums[0])?nums[1]:nums[0];
        for(int i = 2; i < nums.size()-1; i++)
        {
                MV[i] = ((MV[i-2] + nums[i]) > MV[i-1]) ? MV[i-2] + nums[i] : MV[i-1];
        }
        return MV[nums.size()-2]; 
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
