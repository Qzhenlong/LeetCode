#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

����������������������·���ϵ�Ȩֵ��ӵ����ֵ

˼·�������⣺����������������ͣ�Ӧ�õ���������Ӧ��ʹ��������ȱ����㷨��
      ��������������Ľ��L��R�����L����0����ô�Ժ�������������ģ����Ǽ���L�����R����0���Ժ������Ҳ�������ģ���������R��

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
        if (l > 0) sum += l; //�������߶�Ҫ����
        if (r > 0) sum += r;
        max_sum = max(max_sum, sum);
        return max(r, l) > 0 ? max(r, l) + root->val : root->val;
    }
};
