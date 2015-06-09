#include<iostream>
#include<vector>
using namespace std;
/*
原题：Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
解析：给定一个升序排列的数组，将其转换成棵高度平衡的二叉查找树
思路：不能直接采用插入的方法构建，应该用二分法从数组中间开始构建才能形成高度平衡的二叉树。
*/

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int >& nums) {
        TreeNode *root = NULL;
		InsertBST(root, nums, 0, nums.size());
		return root;
    }
	void InsertBST(TreeNode* &bt, vector<int > nums, int first, int end){
		if(first >= end) return;
		int mid = (first+end)/2;
		bt = new TreeNode(nums[mid]);
		InsertBST(bt->left, nums, first, mid);
		InsertBST(bt->right, nums, mid+1, end);
	}
	void printTree(TreeNode *b)
    {
         if(b != NULL){
		     printTree(b->left);
			 cout << b->val << " "; //二叉查找树的中序序列为递增序列
             printTree(b->right);
         }
    }
};

int main()
{
  Solution c;
  TreeNode *root;
  int A[] = {3,5,8};
  vector<int > n;
  for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
  root = c.sortedArrayToBST(n);
  c.printTree(root);
  return 1;   
}
