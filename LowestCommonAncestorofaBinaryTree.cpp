#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: ��The lowest common ancestor is defined between 
two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).��

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. 
Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

�������������������������͹������Ƚ��

˼·����ǰһ��Lowest Common Ancestor of a Binary Search Treeʱ������⻹û���������Ǹ�����Ҳд����������Ľ��
      ���Ǽ�¼�����ֵ�·����Ȼ����ҵ�һ���ֿ��Ľ����ߵ�������Ľ�㼴Ϊ������Ƚ��
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode* > p1, p2;
		getPath(p1, root, p);
		getPath(p2, root, q);
		TreeNode *ans = NULL;
		for(int i = p1.size()-1, j = p2.size()-1; i >= 0 && j >= 0; i--, j--){
			if(p1[i] == p2[j]) ans = p1[i]; //��¼������㣬��Ϊ������Ƚ��
			else return ans;
		}
		return ans;
    }
	bool getPath(vector<TreeNode* > &path, TreeNode* b, TreeNode *tar){
		if(b == NULL) return false;
		
		if(b == tar || getPath(path, b->left, tar) || getPath(path, b->right, tar)){
			path.push_back(b);
			return true;
		}
		
		return false;
	}
	//�����ҵ��Ĵ���Ľⷨ��̫�����
	TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q) {
	  if (!root) return NULL;
	  if (root == p || root == q) return root;
	  TreeNode *L = LCA(root->left, p, q);
	  TreeNode *R = LCA(root->right, p, q);
	  if (L && R) return root;  // if p and q are on both sides
	  return L ? L : R;  // either one of p,q is on one side OR p,q is not in L&R subtrees
}
};

int main(){
	Solution c;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	TreeNode *p = root->left, *q = root->left->right->right;
	cout << p->val << " " << q->val << endl;
	TreeNode *s = c.LCA(root,p,q);//c.lowestCommonAncestor(root, p, q);
	cout << s->val;
	return 0;
}

