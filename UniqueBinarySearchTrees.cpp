#include<iostream>
#include<vector>
using namespace std;
/*
原题：
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
解析：给定n,计算二叉排序树的数量,事实上就是将节点i的左子树和右子树的种类相乘就是对应i为根节点的二叉排序树种类。
（1）f(1) = f(0) = 1; //只有一种可能
（2）f(2) = f(0) * f(1)   //左子树为0个结点，右子树1个节点
          + f(1) * f(0);  //左子树为1个节点，右子树0个节点
（3）f(3) = f(0) * f(2) ，//左子树0个节点，右子树2个节点
	      + f(1) * f(1) ，//左子树1个节点，右子树1个节点
	      + f(2) * f(0) ，//左子树2个节点，右子树0个节点
所以，由此观察，可以得出 f 的递推公式为
f(i) =∑f(k-1)*f(i-k) (f(0)=f(1)=1)
至此，问题划归为一维动态规划。
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
