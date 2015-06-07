#include <iostream>
#include <vector>
#include <string> 
#include <stack>
using namespace std;
/**
原题：Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
解析：返回二叉树的中序遍历序列

 **/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int > inorderTraversal(TreeNode* root) {
        vector<int > ans;
		inorderScan(root, ans);
		return ans;
    }
	//递归遍历
	void inorderScan(TreeNode* b, vector<int > &inorder){
		if(b != NULL){
			inorderScan(b->left, inorder);
			inorder.push_back(b->val);
			inorderScan(b->right, inorder);
		}
	}
	//非递归遍历
    vector<int > inorderTraversal1(TreeNode* root) {
        vector<int > ans;
		stack<TreeNode* > s; //栈存储树节点
		TreeNode *b = root;
		while(b != NULL){
				s.push(b); //左子树节点依次进栈
				b = b->left;
		}
		while(!s.empty()){ //栈不为空时循环
			b = s.top();
			s.pop();
			ans.push_back(b->val); //访问最左侧元素
			if(b->right != NULL) b = b->right;
			else b = NULL;
			while(b != NULL){
				s.push(b); //左子树节点依次进栈
				b = b->left;
			}
		}
		return ans;
    }	
    TreeNode * trans(int A[], int i, int n)
    {
        TreeNode *b;
        if(i >= n) return NULL;
        b = (TreeNode *)malloc(sizeof(TreeNode));
        b->val = A[i];
        b->left = trans(A, 2*i, n);
        b->right = trans(A, 2*i+1, n);
        return b;
    }
    
    void printTree(TreeNode *b)
    {
         if(b != NULL){
		     printTree(b->left);
             cout << b->val << " ";
             printTree(b->right);
         }
    }

};
int main()
{
  Solution c;
  TreeNode *root;
  int A[] = {0,1,2,3,4,5,6,7,8,9};
  root = c.trans(A,1,sizeof(A)/4);
  c.printTree(root);
  printf("\n");   
  vector<int > ans = c.inorderTraversal1(root);
  for(int i = 0; i < ans.size(); i++)
	cout << ans[i] << " ";
  return 1;   
}
