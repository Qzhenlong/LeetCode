#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
�����������֮ǰ����򵥣���Ϊ�൱����һ��n*n������������֮ǰ��˼·��Ȼ�ɽ�
˼·������һ��n*n�ľ��󣬰���һ���ɨ�跽ʽ����ֵ�������������,��������ָ�룬һ����ָ��i��һ����ָ��j��
	�������б߽磬������������ͬ�����ֻ��Ҫһ���Ͻ�low��һ���½�up��
1��������ָ��j,��j�ߵ�ͷʱ��i��ʼ�ߣ���i����ͷʱ��j��ʼ�����ߣ�j�ߵ�ͷʱ��i��ʼ����
2��ÿ��j�ص��������ʱ�������б߽����м�ѹ����low++, up--;
3) ֱ��low >= up�� ����
*/

class Solution {
public:
    vector<vector<int > > generateMatrix(int n) {
        vector<vector<int > > matrix(n, vector<int >(n, 0));
		if(n <= 0) return matrix;
		int i = 0, j = 0, low = 0, up = n, num = 1;
		while(low < up){
			while(j < up) matrix[i][j++] = num++; //���ϱ��ظ�ֵ
			j--; i++;
			while(i < up) matrix[i++][j] = num++; //���ұ��ظ�ֵ
			j--; i--;
			while(j >= low) matrix[i][j--] = num++; //���±��ظ�ֵ
			j++; i--;
			while(i > low) matrix[i--][j] = num++; //������ظ�ֵ
			low++; up--;
			i = low;
			j = low;
		}
		return matrix;
    }
};

int main(){
	Solution c;
	vector<vector<int > > m = c.generateMatrix(4);
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[i].size(); j++)cout << m[i][j] << " ";
		cout << endl;
	}
	return 0;
}
