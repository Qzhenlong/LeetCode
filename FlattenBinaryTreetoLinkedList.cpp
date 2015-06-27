#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
原题：Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
解析：将一棵二叉树转换成一个链表形式，不能使用辅助空间
思路：转换后的链表为二叉树的先序序列，可使用递归方式或者非递归实现，非递归方式更加直观易懂。
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//递归
	TreeNode *cur;
    void flatten(TreeNode* root) { 
		cur = NULL; //尾指针必须定义成全局变量，如果通过递归传参，会出错
		Linked(root);
    }
	void Linked(TreeNode* b){
		if(b != NULL) {
			TreeNode *p = b->left;
			TreeNode *q = b->right;
			if(cur == NULL) cur = b;
			else{
				cur->right = b;
				cur->left = NULL;
				cur = cur->right;
			}
			Linked(p);
			Linked(q);
		}
	}
	//非递归，先序遍历的非递归实现
	void flatten1(TreeNode* root){
		if(root == NULL) return;
		stack<TreeNode* > s;
		s.push(root);
		while(!s.empty()){
			TreeNode *p = s.top();
			s.pop();
			if(p->right != NULL) s.push(p->right); //后访问的结点先进栈，右孩子先进栈
			if(p->left != NULL) s.push(p->left);
			p->left = NULL;
			if(!s.empty()) p->right = s.top();
		}
	}
	TreeNode* tran(int A[], int n, int i){
		if(i >= n) return NULL;
		TreeNode *b = new TreeNode(A[i]);
		b->left = tran(A, n, 2*i);
		b->right = tran(A, n, 2*i+1);
		return b;
	}
	void prePrint(TreeNode *b){
		if(b != NULL){
			cout << b->val << " ";
			prePrint(b->left);
			prePrint(b->right);
		}
	}
};

int main(){
	Solution c;
	int A[] = {0,1,2,5,3,4,6};
	TreeNode *root = c.tran(A, sizeof(A)/4, 1);
	c.prePrint(root);
	cout << endl;
	c.flatten1(root);
	cout << endl;
	while(root != NULL){
		cout << root->val << " ";
		root = root->right;
	}
	
	return 0;
}
