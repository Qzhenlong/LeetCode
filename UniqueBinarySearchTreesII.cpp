#include<iostream>
#include<vector>
using namespace std;
/*
题目：Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
解析：与之前一道题目Unique Binary Search Trees描述相同，即找出所有二叉查找树，上次是返回树的总数，这次是返回所有树
思路：不同的插入顺序可能产生不同的二叉搜索树,遍历所有区间，在区间[l,r]中找其中一个数作为根结点，其它数划入左子树和右子树, 递归构建所有可能的BST
*/

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return getBST(1,n);
    }
	vector<TreeNode* > getBST(int l, int r){
		vector<TreeNode *> ans;
		if(l > r){
			ans.push_back(NULL);
			return ans;
		}
		for(int i = l; i <= r; i++){
			vector<TreeNode* > left = getBST(l, i-1); //递归得到左子树所有可能
			vector<TreeNode* > right = getBST(i+1, r); //递归得到右子树所有可能
			for(int j = 0; j < left.size(); j++){
				for(int k = 0; k < right.size(); k++){ //总的BST数为左子树的数量乘以右子树数量
					TreeNode *root = new TreeNode(i);
					root->left = left[j];
					root->right = right[k];
					ans.push_back(root);
				}
			}
		}
		return ans;
	}
	void InPrint(TreeNode *b){ //中序遍历，用于验证所有生成的数
		if(b != NULL){
			InPrint(b->left);
			cout << b->val << " ";
			InPrint(b->right);
		}
	}
};

int main(){
	Solution c;
	vector<TreeNode *> ans;
	ans = c.generateTrees(3);
	for(int i = 0; i < ans.size(); i++){
		c.InPrint(ans[i]);
		cout << endl;
	}
}