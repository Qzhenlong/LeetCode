#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
题目：Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

解析：假设你站在一棵二叉树的右侧，返回你能看到的所有结点值，顺序为至顶向下

思路：站在右侧所能看到的所有节点就是由层次遍历中每一层的最后一个结点构成
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int > rightSideView(TreeNode* root) {
        queue<TreeNode* > q;
		vector<int > ans;
		if(root == NULL) return ans;
		q.push(root);
		q.push(NULL); //每层的分割点
		TreeNode *pre = NULL; //上一结点，在分割点的上一个节点即为某一层的最右边的结点
		while(!q.empty()){ //仍一个剩余分割点
			TreeNode *p = q.front();
			q.pop();
			if(p == NULL){
				ans.push_back(pre->val);
				if(q.empty()) break; //最后一层不能忘记处理
				q.push(NULL);
				continue;
			}
			if(p->left != NULL) q.push(p->left);
			if(p->right != NULL) q.push(p->right);
			pre = p;
		}
		return ans;
    }
};

int main(){
	Solution c;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(4);
	vector<int > ans = c.rightSideView(root);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}
