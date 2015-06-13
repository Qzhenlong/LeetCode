#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

解析：给定一棵二叉树，返回其后序遍历序列，注意在这里递归方法简单不重要，主要考虑非递归的迭代实现。

思路：二叉树后序遍历的非递归实现，使用一个栈来实现, 同时后序遍历比较复杂的是要设定一个标记来记录当前右节点是否已经访问过了，
如果右节点被访问过说明整棵右子树已被访问，只需要记录刚访问过的节点，如果刚访问过的节点等于当前节点的右孩子，说明右左子树都已访问，可访问当前节点。
1）先将左节点依次进栈，直到树的最左端，左节点为空停止；
2）判断栈顶元素是否有无访问过的右节点，无则记录栈顶元素并将其出栈， 
3）有右节点则依次将其及其左节点依次进栈，直到左节点为空。
3）重复执行2），直到栈为空，遍历结束。
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//后序遍历非递归实现
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode* > s; //存放节点的栈
		vector<int > ans; //后序遍历序列
		TreeNode *p = root, *cur=NULL;
		while(p != NULL){ s.push(p); p = p->left; } //第1）步，左节点依次进栈
		while(!s.empty()){
			p = s.top(); //取栈顶元素s		
			if(p->right == cur){ //左右子树已访问，可直接访问当前节点
				ans.push_back(p->val);
				s.pop();
				cur = p;
			}
			else{
				cur = NULL;
				if(p->right != NULL){
					p = p->right;
					while(p != NULL){s.push(p); p = p->left; }
				}
			}
		
		}
		return ans;
    }
	//递归打印，用于验证
	void postPrint(TreeNode *root){
		if(root != NULL){
			postPrint(root->left);
			postPrint(root->right);
			cout << root->val << " ";
		}
	}
	//将顺序存放的二叉树转换成链式存储
	TreeNode* tranTree(int A[], int n, int i){
		if(i >= n) return NULL;
		TreeNode *b = new TreeNode(A[i]);
		b->left = tranTree(A, n, 2*i);
		b->right = tranTree(A, n, 2*i+1);
		return b;
	}
};

int main(){
	Solution c;
	TreeNode *root = NULL;
	int A[] = {0,1,2,3,4,5,6,7};
	root = c.tranTree(A, sizeof(A)/4, 1);
	c.postPrint(root);
	cout << endl;
	vector<int> ans = c.postorderTraversal(root);
	
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}

