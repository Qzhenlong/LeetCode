#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
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
	
��������֮ǰ��һ�⣬��������Ϊ�������������������������

˼·��֮ǰһ����ʹ�õĲ�α����������Ľṹ��û��Ҫ�󣬵��ռ�ﲻ��O(1);
	  ���Ϊ�����������֮ǰ�Ĺ�����ȱ���


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
		   TreeLinkNode * next = NULL; // ��һ����׸����
		   TreeLinkNode * prev = NULL; // ͬһ���ݴ���һ��㣬����ָ��ǰ���
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

