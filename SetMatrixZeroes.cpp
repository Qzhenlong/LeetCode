#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
����������һ��m*n�ľ��������һ��Ԫ��Ϊ0�����������к���ȫ�ó�0���ܷ�ʹ�ö���ռ�
˼·��
�ؼ����⣺��������0ʱ��Ҫ��֤ԭ�������0Ԫ�ز���Ӱ�죬���ĳ��Ԫ��Ϊ0������Ԫ����������û������0����ɽ�����������0��������ɨ�������
��1���������ʹ�ö���ռ䣬���ȶԾ������һ��ɨ�裬��������0������ȫ����0���ɣ�����������ֱ�洢���У��ռ临�Ӷ�O(m+n)
��2�����Ҫ���Ƕ���ռ䣬���ռ临�Ӷ�ΪO(1),�ǿ��Խ�����һ�е�һ������Ϊ˼·��1�����������飬��Ϊ��ĳ��Ϊ0������е�һ��Ԫ�����϶����Ϊ0��
	��Ҳһ������˿����������λ��
*/

class Solution {
public:
    void setZeroes(vector<vector<int > >& matrix) {
		if(matrix.size() == 0) return;
		int row = matrix.size(), col = matrix[0].size();
		vector<int > r(row,0);
		vector<int > c(col,0);
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(matrix[i][j] == 0){
					r[i]++;
					c[j]++;
				}
			}
		}
		for(int i = 0; i < row; i++)
			if(r[i] > 0) for(int j = 0; j < col; j++) matrix[i][j] = 0;
		for(int j = 0; j < col; j++)
			if(c[j] > 0) for(int i = 0; i < row; i++) matrix[i][j] = 0;
    }
    void setZeroes1(vector<vector<int > >& matrix) {
		if(matrix.size() == 0) return;
		int row = matrix.size(), col = matrix[0].size();
		bool rowZ = false, colZ = false; //��¼��һ�У���һ���Ƿ���0�� �������ȫ��0
		for(int i = 0; i < row; i++) 
			if(matrix[i][0] == 0){
				rowZ = true;
				break;
			}
		for(int j = 0; j < col; j++)
			if(matrix[0][j] == 0){
				colZ = true;
				break;
			}
		for(int i = 1; i < row; i++) //�õ�һ�к͵�һ�������
			for(int j = 1; j < col; j++)
				if(matrix[i][j] == 0){
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
		for(int i = 1; i < row; i++)
			for(int j = 1; j < col; j++)
				if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
		if(rowZ)
			for(int i = 0; i < row; i++) matrix[i][0] = 0;
		if(colZ)
			for(int j = 0; j < col; j++) matrix[0][j] = 0;
    }
};

int main(){
	Solution c;
	int A[][3] = {{1,2,0},{3,4,6}};
	vector<vector<int > > m;
	for(int i = 0; i < 2; i++){
		vector<int > cur;
		for(int j = 0; j < 3; j++){
			cout << A[i][j] << " ";
			cur.push_back(A[i][j]);
		}
		cout << endl;
		m.push_back(cur);
	}
	cout << endl;
	c.setZeroes1(m);
	for(int i = 0; i < m.size(); i++){
		for(int j = 0; j < m[i].size(); j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
	return 0;
}

