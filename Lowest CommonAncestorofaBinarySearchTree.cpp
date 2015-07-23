#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
题目：
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v 
and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, 
since a node can be a descendant of itself according to the LCA definition.

解析：在二叉搜索树中找最低公共祖先结点

思路：题目给的是二叉搜索树，先考虑BST的特性，再考虑不是BST如何求解
（1）考虑BST的特性的话，其实直接遍历每个结点，当遇到第一个间于两个给定结点取值之间的值时(根据定义可以相等），该结点即为最低公共祖先
（2）不考虑BST，从根结点开始查找两个结点所在路径，找到两条路径的一个交汇点就是最低公共祖先结点，根据定义有两个结点在一条路径上，那么先出现的结点即为所求。

*/

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //考虑BST特性
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int low = min(p->val, q->val);
		int high = max(p->val, q->val);
		//TreeNode *ans = NULL;
		//dfs(root, ans, low, high);	
		//return ans;
		return dfs1(root, low, high);
    }
	void dfs(TreeNode *b, TreeNode *&ans, int low, int high){
		if(b == NULL) return;
		if(b->val >= low && b->val <= high){
			if(ans == NULL) ans = b;
			return;
		}
		if(b->val >= high)
			dfs(b->left, ans, low, high);
		else
			dfs(b->right, ans, low, high);
		
	}
	TreeNode *dfs1(TreeNode *b, int low, int high){
		if(b == NULL) return NULL;
		if(b->val >= low && b->val <= high){
			return b;
		}
		if(b->val >= high)
			return dfs1(b->left, low, high);
		else
			return dfs1(b->right, low, high);
		
	}
	//不考虑BST特性
	 TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(root == NULL) return NULL;
		vector<TreeNode* > s1, s2;
		dfs2(root, p, s1);
        dfs2(root, q, s2);
		TreeNode *pre = NULL;
		for(int i = s1.size()-1, j = s2.size()-1; i >= 0 && j >= 0; i--,j--){
			if(s1[i] == s2[j]) pre = s1[i];
			else return pre;
		}
		return pre;
    }
	bool dfs2(TreeNode *root, TreeNode *tar, vector<TreeNode* > &s)
	{
		 if (root == NULL)
			 return false;
	 
		 if (root == tar || dfs2(root->left, tar, s) || dfs2(root->right, tar, s))
		 {
			  s.push_back(root);
			  return true;
		 }
	 
		 return false;
	}

};

int main(){
	Solution c;
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);
	TreeNode *p = root->left->left, *q = root->right->right;
	cout << p->val << " " << q->val << endl;
	TreeNode *s = c.lowestCommonAncestor1(root, p, q);
	cout << s->val;
	return 0;
}
