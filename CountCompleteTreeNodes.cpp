#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is 
completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

分析：计算完全二叉树的结点数
(1)直接遍历，这显然复杂度太高了
(2)利用完全二叉树的性质，如果最左边的叶子结点的高度和最右边叶子结点高度相同，那么就是一棵满二叉树，结点数量等于2^h-1，可借此性质递归求解
(3)二分,http://bookshadow.com/weblog/2015/06/06/leetcode-count-complete-tree-nodes/
对二叉树h层（最后一层）元素进行编号，0..2^h-1, 编号正好代表从根结点到该结点的路径，
找到从0到2^h-1的第一空结点的编号正好就是最后一层的非空结点数
对0到2^h-1进行二分查找即可，假设有其中一个数为x = 0010,宽度为h = 4, 那么它代表的从根结点到它的路径为：左-左-右-左，确定x的每一位即可。
当x对应结点为空时，则往前二分查找，否则往后二分查找


*/

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //直接遍历
    int _countNodes(TreeNode* root) {
		int numNode = 0;
		travelTree(root, numNode);
		return numNode;
    }
	void travelTree(TreeNode *b, int &numNode){
		if(b != NULL){
			numNode++;
			travelTree(b->left, numNode);
			travelTree(b->right, numNode);
		}
	}
	//利用满二叉树
    int countNodes(TreeNode* root) {
		if(root == NULL) return 0;
		TreeNode *p = root, *q = root;
		int lh = 0, rh = 0;
		while(p != NULL){ p = p->left; lh++; }
		while(q != NULL){ q = q->right; rh++; }
		if(lh == rh) return (1 << lh) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right); 
    }
    //二分查找
    int __countNodes(TreeNode* root) {
        int depth = 0;
        TreeNode* node = root;
        while (node) {
            depth++;
            node = node->left;
        }
        if (depth == 0) {
            return 0;
        }
        int left = 0, right = (1 << (depth - 1)) - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (getNode(root, mid, depth - 1)) { //最后一层的该结点不为空
                left = mid + 1;
            } else {
                right = mid - 1;  //循环结束时，right代表最后一层，从左到右最后一个叶子结点的下一结点。
            }
        }
        return (1 << (depth - 1)) + right;
    }
    TreeNode* getNode(TreeNode* root, int path, int depth) {
        while (depth-- && root) {
            if (path & (1 << depth)) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root;
    }
	TreeNode *tran(int A[], int i, int n){
		if(i >= n) return NULL;
		TreeNode *b = new TreeNode(A[i]);
		b->left = tran(A, 2*i, n);
		b->right = tran(A, 2*i+1, n);
		return b;
	}
};

int main(){
	Solution c;
	int A[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
	TreeNode *root = c.tran(A, 1, sizeof(A)/4);
	cout << c.__countNodes(root);
	return 0;
}
