#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
��������֮ǰһ����ĿUnique Binary Search Trees������ͬ�����ҳ����ж�����������ϴ��Ƿ�����������������Ƿ���������
˼·����ͬ�Ĳ���˳����ܲ�����ͬ�Ķ���������,�����������䣬������[l,r]��������һ������Ϊ����㣬������������������������, �ݹ鹹�����п��ܵ�BST
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
			vector<TreeNode* > left = getBST(l, i-1); //�ݹ�õ����������п���
			vector<TreeNode* > right = getBST(i+1, r); //�ݹ�õ����������п���
			for(int j = 0; j < left.size(); j++){
				for(int k = 0; k < right.size(); k++){ //�ܵ�BST��Ϊ��������������������������
					TreeNode *root = new TreeNode(i);
					root->left = left[j];
					root->right = right[k];
					ans.push_back(root);
				}
			}
		}
		return ans;
	}
	void InPrint(TreeNode *b){ //���������������֤�������ɵ���
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