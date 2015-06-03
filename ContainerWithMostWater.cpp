#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;
/*
有两个指针i和j分别指向头和尾， 如果a[i]<a[j], 则i++,否则j--:

证明：

对任意ｋ<j：

都有(k-i)*min(a[k],a[i]) < (j-i)min(a[j],a[i]) = (j-i)a[i]

因为：
(k-i) < (j-i)

min(a[k],a[i]) < a[i] < min(a[j],a[i])

所以此种情况移动j只能得到更小的值， 移动j无用， 只能移动i。 反之亦然。
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
