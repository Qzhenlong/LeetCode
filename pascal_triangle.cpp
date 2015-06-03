#include <iostream>
#include <vector>
using namespace std;
/*
ԭ�⣺
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
��������������������������ǣ����뵽��ά����ʱ�ķֲ���ʵ�������ģ�
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
˼·��
1�����к�Ϊ0�������к����ʱ��������ֵ��Ϊ1��
2���������ù���ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
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
