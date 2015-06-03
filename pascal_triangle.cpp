#include <iostream>
#include <vector>
using namespace std;
/*
原题：
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
解析：给定行数，生成杨辉三角，存入到二维容器时的分布其实是这样的：
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
思路：
1）当行号为0或者行列号相等时，将数组值置为1；
2）否则，利用规律ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
       vector<vector<int> > ans;
        for(int i = 0;i < numRows;i++)
        {
            vector<int> cur;
            if(i == 0)
                cur.push_back(1);
            else
            {
                for(int j = 0;j <= i;j++)
                {
                    if(j == 0 || j == i) cur.push_back(1);
                    else cur.push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
                }
            }
            ans.push_back(cur);
        }
        
        return ans;
    }
};
int main()
{
  Solution c;
  int num = 10;
  vector<vector<int> > x = c.generate(num);
  for(int i = 0; i < num; i++){
          for(int j = 0; j <= i; j++){
                  printf("%d ",x[i][j]);
                  } 
          printf("\n");
          }
  while(1);
  return 1;   
}
