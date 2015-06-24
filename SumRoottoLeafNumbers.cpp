#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

�����������������ÿ�����ֵֻ����0-9���Ӹ���㵽Ҷ�ӽ���ʾһ�����������������������Щ����֮�͡�

˼·������������ȱ�����������ÿ�ε�Ҷ�ӽ��ʱ����Ӹ���Ҷ�ӽ������������ۼ���͡�
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //�����������¼��ÿ��Ҷ�ӽ���·����ʱ��ռ临�Ӷ�O(n)
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
		int sum = 0;
		vector<int > nums;
		getSum(root, sum, nums);
		return sum;
    }
	void getSum(TreeNode *b, int &sum, vector<int > &nums){
		nums.push_back(b->val);
		if(b->left == NULL && b->right == NULL) sum += calVal(nums);
		if(b->left != NULL) getSum(b->left, sum, nums);
		if(b->right != NULL) getSum(b->right, sum, nums);
		nums.pop_back();
	}
	int calVal(vector<int > nums){
		int result = 0, n = nums.size();
		for(int i = 0; i < n; i++){
			result = result*10 + nums[i];
		}
		return result;
	}
	//������ȱ�����ʱ�临�Ӷ�O(n),�ռ�O(logn)
	int sumNumbers1(TreeNode* root){
		return dfs(root, 0);
	}	
	int dfs(TreeNode* b, int sum){
		if(b == NULL) return 0;
		if(b->left == NULL && b->right == NULL) return sum*10 + b->val;
		return dfs(b->left, sum*10+b->val) + dfs(b->right, sum*10+b->val);
	}
	TreeNode* tran(int A[], int n, int i){
		if(i >= n) return NULL;
		TreeNode *b = new TreeNode(A[i]);
		b->left = tran(A, n, 2*i);
		b->right = tran(A, n, 2*i+1);
		return b;
	}
	void printTree(TreeNode *b){
		if(b != NULL){
			cout << b->val << " ";
			printTree(b->left);
			printTree(b->right);
		}
	}
};

int main(){
	Solution c;
	int A[] = {0,1,2};
	//TreeNode *root = c.tran(A, sizeof(A)/4, 1);
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);
	root->right->right = new TreeNode(1);
	root->right->right->right = new TreeNode(5);
	c.printTree(root);
	cout << endl;
	cout << "sum: " << endl;
	cout << c.sumNumbers(root) << endl;
	cout << c.sumNumbers1(root) << endl;
	return 0;
}
