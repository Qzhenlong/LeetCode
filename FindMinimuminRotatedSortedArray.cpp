#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;

class Solution {
public:
/*
��Ҫ˼���Ƕ��ֲ��ң�����num[beg .. end]���飬��mid=(beg+end)/2,��ô����һ�����������

1)num[beg]<num[end]�� ��ʱ����������������ģ����ֱ�ӷ���num[beg]���ɣ��������2����3��

2)num[beg]>num[mid]����ʱ��num[mid..end]������ô��Сֵһ��������num[beg..mid]֮�У�����num[mid+1..end]��

3)num[beg]<=num[mid] : ��ʱ,num[beg..mid]������ģ�������Сֵһ���������num[mid+1..end]��,����num[beg..mid];
*/
    int findMin(vector<int>& nums) { //û���ظ�ֵ 
        int low = 0, high = nums.size()-1;
        int mid;
        if(high == -1) return NULL;
        if(high == 0 || nums[low] < nums[high]) return nums[0]; //ֱ������ 
        while(low < high)
        {
                  mid = (low+high) / 2;
                  if(nums[low] < nums[high]) return nums[low]; //ֱ������ 
                    
                  if(nums[low] > nums[mid]) high = mid;
                  else low = mid + 1; 
        }
        return nums[low];
    }
 /*
���ظ����������Ҫ˼���Ƕ��ֲ��ң�����num[beg .. end]���飬��mid=(beg+end)/2,��ô����һ�����������

1)num[beg]<num[end]�� ��ʱ��Ȼ��Ч����������������ģ����ֱ�ӷ���num[beg]���ɣ�

2)num[beg]==num[end]�� ��ʱ��end = end - 1; 

3)num[beg]==num[mid]; ��ʱ�� low = mid + 1; 

4)num[beg]>num[mid]����ʱ��num[mid..end]������ô��Сֵһ��������num[beg..mid]֮�У�����num[mid+1..end]��

5)num[beg]<num[mid] : ��ʱ,num[beg..mid]������ģ�������Сֵһ���������num[mid+1..end]��,����num[beg..mid];
*/   
    int findMin1(vector<int>& nums) { //�����ظ�ֵ 
        int low = 0, high = nums.size()-1;
        int mid;
        if(high == -1) return NULL;
        if(high == 0 || nums[low] < nums[high]) return nums[0]; //ֱ������ 
        while(low < high)
        {
                  mid = (low+high) / 2;
                  if(nums[low] < nums[high]) return nums[low]; //ֱ��������Ȼ��Ч 
                  
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
