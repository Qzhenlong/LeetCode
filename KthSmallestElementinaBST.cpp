#include<iostream>
#include<vector>
using namespace std;
/*
题目：Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

解析：在一棵二叉搜索树中查找第k小的元素,假设 1 <= k <= 所有元素个数
     如果BST经常被修改，是否需要频繁找第k小元素？要如何优化查找算法

思路：
（1）先不考虑follow up的要求，可中序遍历，找到第k小元素返回， 若BST经常变动，只需要判断插入元素大于或者小于第k小元素， 插入到已有序列中就行，不用再重新扫描二叉树。
（2）或者计算当前结点左子树的结点数，如果为k-1,则返回当前结点即可， 若BST经常变动，可以增加一个属性，记录左子树中结点数，每次插入的时候改变该值
注：方法二效率不高，计算结点数的时候要重复遍历很多结点。
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int > seq;
		InScan(root, seq);
		return seq[k-1];
    }
	int InScan(TreeNode *b, vector<int > &seq){
		if(b != NULL){
			InScan(b->left, seq);
			seq.push_back(b->val);
			InScan(b->right, seq);
		}
	}
	int kthSmallest1(TreeNode *root, int k){
	
	}
	int 
};

int main(){
	Solution c;
	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	cout << c.kthSmallest(root, 2);
	return 0;
}
