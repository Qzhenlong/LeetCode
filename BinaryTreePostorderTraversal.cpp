#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

����������һ�ö����������������������У�ע��������ݹ鷽���򵥲���Ҫ����Ҫ���Ƿǵݹ�ĵ���ʵ�֡�

˼·����������������ķǵݹ�ʵ�֣�ʹ��һ��ջ��ʵ��, ͬʱ��������Ƚϸ��ӵ���Ҫ�趨һ���������¼��ǰ�ҽڵ��Ƿ��Ѿ����ʹ��ˣ�
����ҽڵ㱻���ʹ�˵�������������ѱ����ʣ�ֻ��Ҫ��¼�շ��ʹ��Ľڵ㣬����շ��ʹ��Ľڵ���ڵ�ǰ�ڵ���Һ��ӣ�˵�������������ѷ��ʣ��ɷ��ʵ�ǰ�ڵ㡣
1���Ƚ���ڵ����ν�ջ��ֱ����������ˣ���ڵ�Ϊ��ֹͣ��
2���ж�ջ��Ԫ���Ƿ����޷��ʹ����ҽڵ㣬�����¼ջ��Ԫ�ز������ջ�� 
3�����ҽڵ������ν��估����ڵ����ν�ջ��ֱ����ڵ�Ϊ�ա�
3���ظ�ִ��2����ֱ��ջΪ�գ�����������
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//��������ǵݹ�ʵ��
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode* > s; //��Žڵ��ջ
		vector<int > ans; //�����������
		TreeNode *p = root, *cur=NULL;
		while(p != NULL){ s.push(p); p = p->left; } //��1��������ڵ����ν�ջ
		while(!s.empty()){
			p = s.top(); //ȡջ��Ԫ��s		
			if(p->right == cur){ //���������ѷ��ʣ���ֱ�ӷ��ʵ�ǰ�ڵ�
				ans.push_back(p->val);
				s.pop();
				cur = p;
			}
			else{
				cur = NULL;
				if(p->right != NULL){
					p = p->right;
					while(p != NULL){s.push(p); p = p->left; }
				}
			}
		
		}
		return ans;
    }
	//�ݹ��ӡ��������֤
	void postPrint(TreeNode *root){
		if(root != NULL){
			postPrint(root->left);
			postPrint(root->right);
			cout << root->val << " ";
		}
	}
	//��˳���ŵĶ�����ת������ʽ�洢
	TreeNode* tranTree(int A[], int n, int i){
		if(i >= n) return NULL;
		TreeNode *b = new TreeNode(A[i]);
		b->left = tranTree(A, n, 2*i);
		b->right = tranTree(A, n, 2*i+1);
		return b;
	}
};

int main(){
	Solution c;
	TreeNode *root = NULL;
	int A[] = {0,1,2,3,4,5,6,7};
	root = c.tranTree(A, sizeof(A)/4, 1);
	c.postPrint(root);
	cout << endl;
	vector<int> ans = c.postorderTraversal(root);
	
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}

