#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
��Ŀ��Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

������������վ��һ�ö��������Ҳ࣬�������ܿ��������н��ֵ��˳��Ϊ��������

˼·��վ���Ҳ����ܿ��������нڵ�����ɲ�α�����ÿһ������һ����㹹��
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
		q.push(NULL); //ÿ��ķָ��
		TreeNode *pre = NULL; //��һ��㣬�ڷָ�����һ���ڵ㼴Ϊĳһ������ұߵĽ��
		while(!q.empty()){ //��һ��ʣ��ָ��
			TreeNode *p = q.front();
			q.pop();
			if(p == NULL){
				ans.push_back(pre->val);
				if(q.empty()) break; //���һ�㲻�����Ǵ���
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
