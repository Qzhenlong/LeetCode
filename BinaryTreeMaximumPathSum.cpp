#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

解析：求二叉树任意两点的路径上的权值相加的最大值

思路：子问题：求数组的连续段最大和，应用到二叉树上应该使用深度优先遍历算法，
      先算出左右子树的结果L和R，如果L大于0，那么对后续结果是有利的，我们加上L，如果R大于0，对后续结果也是有利的，继续加上R。

*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
private:
    int max_sum;
    int dfs(const TreeNode *root) {
        if (root == NULL) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int sum = root->val;
        if (l > 0) sum += l; //右左两边都要计算
        if (r > 0) sum += r;
        max_sum = max(max_sum, sum);
        return max(r, l) > 0 ? max(r, l) + root->val : root->val;
    }
};
