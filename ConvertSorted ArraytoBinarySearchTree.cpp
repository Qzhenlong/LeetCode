#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
����������һ���������е����飬����ת���ɿø߶�ƽ��Ķ��������
˼·������ֱ�Ӳ��ò���ķ���������Ӧ���ö��ַ��������м俪ʼ���������γɸ߶�ƽ��Ķ�������
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
			 cout << b->val << " "; //�������������������Ϊ��������
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
