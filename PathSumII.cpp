#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

�����������и���㵽Ҷ�ӽ��ĺ�Ϊsum�����п���·��
˼·��������ȱ������洢���з���������·��
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
class Solution {
public:
    vector<vector<int > > pathSum(TreeNode* root, int sum) {
        vector<vector<int > > ans;
		vector<int > cur;
		if(root == NULL) return ans;
		dfs(ans, cur, root, 0, sum);
		return ans;
    }
	void dfs(vector<vector<int > > &ans, vector<int > &cur, TreeNode *b, int cursum, int sum){
		cur.push_back(b->val);
		cursum += b->val;
		if(b->left == NULL && b->right == NULL)
			if(cursum == sum){
				ans.push_back(cur);
				//return; //��Ҫ�ع��������ڴ˷���
			}
		if(b->left != NULL) dfs(ans, cur, b->left, cursum, sum);
		if(b->right != NULL) dfs(ans, cur, b->right, cursum, sum);
		cur.pop_back(); //�ع�
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
	int A[] = {0,0,1,1};
	TreeNode *root = c.tran(A, 1, sizeof(A)/4);
	vector<vector<int > > ans = c.pathSum(root, 1);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
