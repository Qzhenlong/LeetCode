#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

����������һ��m*n�ľ��󣬰�����˳�򷵻�����Ԫ��
˼·����������ָ�룬һ����ָ��i��һ����ָ��j���������б߽磬;
1��������ָ��j,��j�ߵ�ͷʱ��i��ʼ�ߣ���i����ͷʱ��j��ʼ�����ߣ�j�ߵ�ͷʱ��i��ʼ����
2��ÿ��j�ص��������ʱ�������б߽����м�ѹ����rlow++��clow++, m--, n--;
3) ֱ��rlow >= m���� clow >= n�� ����

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int > >& matrix) {
		vector<int > ans;
		if(matrix.size() == 0) return ans;
		int i = 0, j = 0, rlow = 0, clow = 0, m = matrix.size(), n = matrix[0].size();
		while(rlow < m && clow < n){
		    rlow++;                                        //�б߽�����
			while(j < n) ans.push_back(matrix[i][j++]);    //�����ϱ���
			--j; ++i; 									   //�����ظ�
			if(j < clow || i < rlow) break;                //���в���ȵľ��󣬿�����ǰ�����յ�
			while(i < m) ans.push_back(matrix[i++][j]);    //�����ұ���
			--i; --j;                                      //�����ظ�
			if(j < clow || i < rlow) break;                //���в���ȵľ��󣬿�����ǰ�����յ�
			while(j >= clow) ans.push_back(matrix[i][j--]);//�����±���
			++j; --i; 									   //�����ظ�
			while(i >= rlow) ans.push_back(matrix[i--][j]);//���������
			clow++; 									   //�б߽�����
			m--; n--;                     			       //ѹ���߽�
			i = rlow; j = clow; 						   //�������
		}
		return ans;
    }
};

int main()
{
  Solution c;
  vector<vector<int > > n;
  vector<int > cur;
  for(int i = 0; i < 9; i++){
	cur.push_back(i+1);
	if((i+1) % 3 == 0){
		n.push_back(cur);
		cur.clear();
	}
  }
  vector<int > ans = c.spiralOrder(n);
  for(int i = 0; i < ans.size(); i++)
	cout << ans[i] << " ";

  n.clear(); 
  cout << endl;
   for(int i = 0; i < 1; i++){
	cur.push_back(i+1);
	if((i+1) % 1 == 0){
		n.push_back(cur);
		cur.clear();
	}
  }
  ans.clear();
  ans = c.spiralOrder(n);
  for(int i = 0; i < ans.size(); i++)
	cout << ans[i] << " ";
  return 1;   
}

