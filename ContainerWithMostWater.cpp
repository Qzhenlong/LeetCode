#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;
/*
������ָ��i��j�ֱ�ָ��ͷ��β�� ���a[i]<a[j], ��i++,����j--:

֤����

�������<j��

����(k-i)*min(a[k],a[i]) < (j-i)min(a[j],a[i]) = (j-i)a[i]

��Ϊ��
(k-i) < (j-i)

min(a[k],a[i]) < a[i] < min(a[j],a[i])

���Դ�������ƶ�jֻ�ܵõ���С��ֵ�� �ƶ�j���ã� ֻ���ƶ�i�� ��֮��Ȼ��
*/ 

class Solution {
public:
    int maxArea(vector<int >& height) {
        int i = 0, j = height.size()-1;
        int tmp_area, ans = INT_MIN;
        while(i < j)
        {
                tmp_area = (j-i) * ((height[i] < height[j]) ? height[i] : height[j]);
                if(height[i] < height[j]) i++;
                else j--;
                if(ans < tmp_area) ans = tmp_area; 
        }
        return ans;
    }
};
int main()
{
  Solution c;
  vector<int > height;
  height.push_back(1);
  height.push_back(1);
  height.push_back(2);
  height.push_back(1);
  cout << c.maxArea(height) << endl;
  while(1);
  return 1;   
}
