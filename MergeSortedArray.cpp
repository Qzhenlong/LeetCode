#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        if(n == 0) return;
        if(m == 0){
             nums1.resize(n);
             for(j = 0; j < n; j++)
                   nums1[j] = nums2[j];
             return;                
        }
        vector<int > m_num;
        while(j < n && i < m)
        {
                if(nums1[i] <= nums2[j]){ m_num.push_back(nums1[i]); i++; }
                else { m_num.push_back(nums2[j]); j++;}
        }
        while(j < n){ m_num.push_back(nums2[j]); j++; }
        while(i < m){ m_num.push_back(nums1[i]); i++; }
        nums1.resize(m+n);
        for(k = 0; k < m+n; k++)
              nums1[k] = m_num[k];
        /*
         nums1.resize(m+n);
        k = 0;
        while(j < n)
        {
                if(nums1[i] <= nums2[j]){ i++; k++;}
                else{
                     nums1.insert(nums1.begin()+i,nums2[j]);
                     i++; j++;
                }
                
                if(k == m)
                {
                     while(j < n)
                     {
                             nums1[i++] = nums2[j++];
                     }
                     break;
                }
        } 
        */
        
    }

};
int main()
{
  Solution c;
  vector<int > a, b;

  a.push_back(2);
  a.push_back(0);
  b.push_back(1);                                                                              
  c.merge(a,1,b,1);
  for(int i = 0; i < a.size(); i++)
          cout << a[i] << " ";
  while(1);
  return 1;   
}
