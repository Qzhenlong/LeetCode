#include <iostream>
#include <vector>
#include <string> 
#include <stack>
using namespace std;
/**
ԭ�⣺Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

���������ض������������������

˼·��
��1���ݹ���߷ǵݹ�ʵ�֣��ռ临�Ӷȶ�ΪO(n)
��2���ռ临�Ӷ�ΪO(1)�Ľⷨ������Recover Binary Search Treeһ��󣬷�����Mirror����������������������˼·����

 **/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int > inorderTraversal(TreeNode* root) {
        vector<int > ans;
		inorderScan(root, ans);
		return ans;
    }
	//�ݹ����
	void inorderScan(TreeNode* b, vector<int > &inorder){
		if(b != NULL){
			inorderScan(b->left, inorder);
			inorder.push_back(b->val);
			inorderScan(b->right, inorder);
		}
	}
	//�ǵݹ����
    vector<int > inorderTraversal1(TreeNode* root) {
        vector<int > ans;
		stack<TreeNode* > s; //ջ�洢���ڵ�
		TreeNode *b = root;
		while(b != NULL){
				s.push(b); //�������ڵ����ν�ջ
				b = b->left;
		}
		while(!s.empty()){ //ջ��Ϊ��ʱѭ��
			b = s.top();
			s.pop();
			ans.push_back(b->val); //���������Ԫ��
			if(b->right != NULL) b = b->right;
			else b = NULL;
			while(b != NULL){
				s.push(b); //�������ڵ����ν�ջ
				b = b->left;
			}
		}
		return ans;
    }	
	//Mirror����
	vector<int > inorderTraversal2(TreeNode* root) {
        vector<int > ans;
		TreeNode *cur = root, *pre = NULL;
		while(cur != NULL){
			if(cur->left == NULL){ //������Ϊ�գ�����ֱ�ӷ���
				ans.push_back(cur->val);
				cur = cur->right; //����������
			}
			else{
				pre = cur->left;
				while(pre->right != NULL && pre->right != cur)	pre = pre->right; //�ҳ������������·����
				if(pre->right == NULL){
					pre->right = cur; //������������
					cur = cur->left; //���������������
				}
				else{ //�ҵ��������ɷ��ʵ�ǰ
					ans.push_back(cur->val); //���ʵ�ǰ���,�������������ĸ����
					pre->right = NULL; //����������
					cur = cur->right; //�������������
				}
			}
		}
		return ans;
    }	
    TreeNode * trans(int A[], int i, int n)
    {
        TreeNode *b;
        if(i >= n) return NULL;
        b = (TreeNode *)malloc(sizeof(TreeNode));
        b->val = A[i];
        b->left = trans(A, 2*i, n);
        b->right = trans(A, 2*i+1, n);
        return b;
    }
    
    void printTree(TreeNode *b)
    {
         if(b != NULL){
		     printTree(b->left);
             cout << b->val << " ";
             printTree(b->right);
         }
    }

};
int main()
{
  Solution c;
  TreeNode *root;
  int A[] = {0,1,2,3,4,5,6,7,8,9};
  root = c.trans(A,1,sizeof(A)/4);
  c.printTree(root);
  printf("\n");   
  vector<int > ans = c.inorderTraversal2(root);
  for(int i = 0; i < ans.size(); i++)
	cout << ans[i] << " ";
  return 1;   
}
