#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;

class Solution {
public:
/*
主要思想是二分查找，对于num[beg .. end]数组，命mid=(beg+end)/2,那么存在一下三种情况：

1)num[beg]<num[end]： 这时，整个数组是有序的，因此直接返回num[beg]即可；否则进行2）和3）

2)num[beg]>num[mid]：这时，num[mid..end]有序，那么最小值一定出现在num[beg..mid]之中，抛弃num[mid+1..end]；

3)num[beg]<=num[mid] : 这时,num[beg..mid]是有序的，所以最小值一点个出现在num[mid+1..end]中,抛弃num[beg..mid];
*/
    int findMin(vector<int>& nums) { //没有重复值 
        int low = 0, high = nums.size()-1;
        int mid;
        if(high == -1) return NULL;
        if(high == 0 || nums[low] < nums[high]) return nums[0]; //直接有序 
        while(low < high)
        {
                  mid = (low+high) / 2;
                  if(nums[low] < nums[high]) return nums[low]; //直接有序 
                    
                  if(nums[low] > nums[mid]) high = mid;
                  else low = mid + 1; 
        }
        return nums[low];
    }
 /*
可重复的情况，主要思想是二分查找，对于num[beg .. end]数组，命mid=(beg+end)/2,那么存在一下三种情况：

1)num[beg]<num[end]： 这时仍然有效，整个数组是有序的，因此直接返回num[beg]即可；

2)num[beg]==num[end]： 这时，end = end - 1; 

3)num[beg]==num[mid]; 这时， low = mid + 1; 

4)num[beg]>num[mid]：这时，num[mid..end]有序，那么最小值一定出现在num[beg..mid]之中，抛弃num[mid+1..end]；

5)num[beg]<num[mid] : 这时,num[beg..mid]是有序的，所以最小值一点个出现在num[mid+1..end]中,抛弃num[beg..mid];
*/   
    int findMin1(vector<int>& nums) { //允许重复值 
        int low = 0, high = nums.size()-1;
        int mid;
        if(high == -1) return NULL;
        if(high == 0 || nums[low] < nums[high]) return nums[0]; //直接有序 
        while(low < high)
        {
                  mid = (low+high) / 2;
                  if(nums[low] < nums[high]) return nums[low]; //直接有序仍然有效 
                  
                  if(nums[low] == nums[high]){ high--; continue;}
                  
                  if(nums[low] == nums[mid]) { low = mid + 1; continue;}
                  
                  if(nums[low] > nums[mid]) high = mid;
                  else low = mid + 1;
                            
        }
        return nums[low];
    }


};
int main()
{
  Solution c;
  vector<int > n;
  int sn = 7;
  for(int i = 0; i < sn; i++)
  {
          //cout << (i+3)% sn << " ";
           //n.push_back((i+3)% sn);
           if(i != 5) n.push_back(0);
           else n.push_back(1);
           
  }
  for(int i = 0; i < n.size(); i++) cout << n[i] << " "; 
  cout << endl;
  cout << c.findMin1(n) << endl;
  while(1);
  return 1;   
}
