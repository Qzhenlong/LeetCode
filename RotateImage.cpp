#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺You are given an n*n 2D matrix representing an image
Rotate the image by 90 degrees(clockwise)
��������һ��n*n�Ķ�ά����˳ʱ����ת90��
˼·���������ȶ�ȡ�������ռ�O(n^2)���׽��������ת��ʱ�临�Ӷ�O(n^2)
1 2 3      7 4 1
4 5 6  ->  8 5 2
7 8 9      9 6 3

//���Ը����ռ�O(1), ���ԶԽ��߱任�������м�ˮƽ�߽���
1 2 -> 4 2 -> 3 1
3 4    3 1    4 2

1 2 3     9 6 3    7 4 1
4 5 6 ->  8 5 2 -> 8 5 2
7 8 9     7 4 1    3 6 3

*/
class Solution{
public:
	void rotate(vector<vector<int > > &matrix){
		int n = matrix.size();
		if(n == 0 || n == 1) return;
		int i = 0, k = n-1;
		while(i < n && k >= 0){ //�����Խ��߶Գ�ӳ�佻��Ԫ��
			for(int j = 0, l = n-1; j < n-i-1; j++, l--){
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[l][k];
				matrix[l][k] = tmp;
			}
			i++; k--;
		}
		i = 0; k = n-1;
		while(i < k){   //������ˮƽ�߶Գ�ӳ�佻��Ԫ��
			for(int j = 0; j < n; j++){
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[k][j];
				matrix[k][j] = tmp;
			}
			i++; k--;
		}
	}
};

int main(){
	Solution c;
	vector<vector<int > > matrix;
	int n = 4;
	for(int i = 0; i < n; i++){
		vector<int > cur;
		for(int j = 0; j < n; j++){
			cout << (i*n+j+1) << " ";
			cur.push_back(i*n+j+1);
		}
		matrix.push_back(cur);
		cout << endl;
	}
	cout << "Rotate: " << endl;
	c.rotate(matrix);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
