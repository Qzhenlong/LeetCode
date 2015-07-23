#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
	
解析：续之前的一题，但条件改为任意二叉树，而不是满二叉树

思路：之前一题中使用的层次遍历，对树的结构并没有要求，但空间达不到O(1);
	  如果为任意二叉树，之前的广度优先遍历


*/
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
		while (root) {
		   TreeLinkNode * next = NULL; // 下一层的首个结点
		   TreeLinkNode * prev = NULL; // 同一层暂存上一结点，用于指向当前结点
			while(root) {
				if (!next) next = root->left ? root->left : root->right;
				if (root->left) {
					if (prev) prev->next = root->left;
					prev = root->left;
				}
				if (root->right) {
					if (prev) prev->next = root->right;
					prev = root->right;
					}
				root = root->next;
			}
			root = next; // turn to next level
		}
    }
	TreeLinkNode* trans(int A[], int i, int n){
		if(i >= n) return NULL;
		TreeLinkNode *b = new TreeLinkNode(A[i]);
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
  //root = c.trans(A,1,sizeof(A)/4);
  root = new TreeLinkNode(1);
  root->left = new TreeLinkNode(2);
  root->right = new TreeLinkNode(3);
  root->right->left = new TreeLinkNode(4);
  root->right->right = new TreeLinkNode(5);
  root->left->left = new TreeLinkNode(6);
  c.connect(root);
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

