#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
����������n,�������������������,��ʵ�Ͼ��ǽ��ڵ�i������������������������˾��Ƕ�ӦiΪ���ڵ�Ķ������������ࡣ
��1��f(1) = f(0) = 1; //ֻ��һ�ֿ���
��2��f(2) = f(0) * f(1)   //������Ϊ0����㣬������1���ڵ�
          + f(1) * f(0);  //������Ϊ1���ڵ㣬������0���ڵ�
��3��f(3) = f(0) * f(2) ��//������0���ڵ㣬������2���ڵ�
	      + f(1) * f(1) ��//������1���ڵ㣬������1���ڵ�
	      + f(2) * f(0) ��//������2���ڵ㣬������0���ڵ�
���ԣ��ɴ˹۲죬���Եó� f �ĵ��ƹ�ʽΪ
f(i) =��f(k-1)*f(i-k) (f(0)=f(1)=1)
���ˣ����⻮��Ϊһά��̬�滮��
*/

class Solution {
public:
    int numTrees(int n) {
		vector<int > f(n+1,0);
		if(n <= 1) return 1;
		f[0] = 1; f[1] = 1;
		for(int i = 2; i < n+1; i++){
			for(int k = 1; k <= i; k++){
				f[i] += f[k-1]*f[i-k];
			}
		}
		return f[n];
    }
};

int main(){
	Solution c;
	cout << c.numTrees(3);
	return 0;
}
