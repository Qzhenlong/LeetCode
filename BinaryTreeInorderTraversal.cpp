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

思路：
（1）递归或者非递归实现，空间复杂度都为O(n)
（2）空间复杂度为O(1)的解法，做完Recover Binary Search Tree一题后，发现有Mirror遍历，利用线索二叉树的思路遍历

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
	//Mirror遍历
	vector<int > inorderTraversal2(TreeNode* root) {
        vector<int > ans;
		TreeNode *cur = root, *pre = NULL;
		while(cur != NULL){
			if(cur->left == NULL){ //左子树为空，可以直接访问
				ans.push_back(cur->val);
				cur = cur->right; //访问右子树
			}
			else{
				pre = cur->left;
				while(pre->right != NULL && pre->right != cur)	pre = pre->right; //找出左子树最右下方结点
				if(pre->right == NULL){
					pre->right = cur; //线索化二叉树
					cur = cur->left; //继续往左子树结点
				}
				else{ //找到线索，可访问当前
					ans.push_back(cur->val); //访问当前结点,可理解成是子树的根结点
					pre->right = NULL; //消除线索化
					cur = cur->right; //遍历右子树结点
				}
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
  vector<int > ans = c.inorderTraversal2(root);
  for(int i = 0; i < ans.size(); i++)
	cout << ans[i] << " ";
  return 1;   
}
