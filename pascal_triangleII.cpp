#include <iostream>
#include <vector>
using namespace std;
/*
原题：
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1]

解析：给定行数，生成杨辉三角对应行：

思路：
1）当行号为0或者行列号相等时，将数组值置为1；
2）否则，利用规律ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
3）返回指定行
*/
class Solution {
public:
       vector<int> getRow(int rowIndex) {
       vector<vector<int> > ans;
       vector<int > res;
        for(int i = 0;i < rowIndex+1;i++)
        {
            vector<int > cur;
            if(i == 0) cur.push_back(1);
            else{
                 for(int j = 0; j <= i; j++){
                         if(j == 0 || j == i) cur.push_back(1);
                         else{
                              cur.push_back(ans[i-1][j-1] + ans[i-1][j]);
                              }      
                 }
            }
            ans.push_back(cur);
            if(i == rowIndex){
                  res.insert(res.end(),cur.begin(),cur.end());
                  break;
                  }
        }
        
        return res;
    }
};
int main()
{
  Solution c;
  int num = 10;
  vector<int> x = c.getRow(num);
  for(int i = 0; i <= num; i++){
                  printf("%d ",x[i]);
          }
  while(1);
  return 1;   
}
