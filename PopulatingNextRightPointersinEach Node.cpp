#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*原题：
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
解析：对满二叉树的每一层节点加入next指针，要求空间复杂度O(1)
思路：采用使用层次遍历算法
*/

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
	//非递归， 时间O(n),空间O(logn) 
    void connect(TreeLinkNode *root) {
		if(root == NULL) return;
		queue<TreeLinkNode* > q;
		TreeLinkNode *pre = NULL; //上一节点
		q.push(root);
		q.push(NULL); //分隔层
		while(q.size() > 1){
			TreeLinkNode *p = q.front();
			q.pop();
			if(pre != NULL) pre->next = p;
			pre = p;
			if(p == NULL){ q.push(NULL); continue; }
			if(p->left != NULL) q.push(p->left);
			if(p->right != NULL) q.push(p->right);
		}
    }
	//递归实现，Output Limit Exceeded 
	void connect1(TreeLinkNode *root){
		myconnect(root, NULL);
	}
	void myconnect(TreeLinkNode *b, TreeLinkNode *bNext){
		if(b == NULL) return;
		else b->next = bNext;
		myconnect(b->left, b->right);
		if(bNext != NULL) myconnect(b->right, bNext);
		else myconnect(b->right, NULL);
	}
    TreeLinkNode * trans(int A[], int i, int n)
    {
        TreeLinkNode *b;
        if(i >= n) return NULL;
        b = new TreeLinkNode(A[i]);
        b->left = trans(A, 2*i, n);
        b->right = trans(A, 2*i+1, n);
        return b;
    }
};
int main()
{
  Solution c;
  TreeLinkNode *root;
  int A[] = {0,1,2,3,4,5,6,7};
  root = c.trans(A,1,sizeof(A)/4);
  c.connect1(root);
  while(root != NULL){
	TreeLinkNode *p = root;
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	root = root->left;
	cout << endl;
  }
  return 0;   
}

