#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��Ŀ��
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ��The lowest common ancestor is defined between two nodes v 
and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).��

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, 
since a node can be a descendant of itself according to the LCA definition.

�������ڶ���������������͹������Ƚ��

˼·����Ŀ�����Ƕ������������ȿ���BST�����ԣ��ٿ��ǲ���BST������
��1������BST�����ԵĻ�����ʵֱ�ӱ���ÿ����㣬��������һ�����������������ȡֵ֮���ֵʱ(���ݶ��������ȣ����ý�㼴Ϊ��͹�������
��2��������BST���Ӹ���㿪ʼ���������������·�����ҵ�����·����һ������������͹������Ƚ�㣬���ݶ��������������һ��·���ϣ���ô�ȳ��ֵĽ�㼴Ϊ����

*/

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //����BST����
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
	//������BST����
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
