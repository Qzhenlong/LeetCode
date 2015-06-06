#include<iostream>
#include<vector>
using namespace std;
/*
原题：Given preorder and inorder traversal of a tree, construct the binary tree.
解析：给定先序和中序序列，重建二叉树
思路：通过先序序列确定树的根节点，对中序序列进行拆分，得到左右子树，再递归构建即可
*/
/**
 * Definition for a binary tree node.
*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return createTree(preorder, inorder, 0, 0, preorder.size());
    }
	TreeNode* createTree(vector<int > &preorder, vector<int > &inorder, int plow, int ilow, int n){
		if(n <= 0) return NULL;
		TreeNode *s = new TreeNode(preorder[plow]);
		int k = 0;
		while(k < n){
			if(inorder[k+ilow] == preorder[plow]) break;
			k++;
		}
		s->left = createTree(preorder, inorder, plow+1, ilow, k);
		s->right = createTree(preorder, inorder, plow+k+1, ilow+k+1, n-k-1); 
		return s;
	}	
	//层次遍历算法 
	vector<vector<int > > levelOrder(TreeNode* root) {
        vector<vector<int > > ans;
        if(root == NULL) return ans;
        int MAX = 65535;
        TreeNode *qu[MAX];
        int rear, front;
        front = rear = -1;
        qu[++rear] = root;
        rear = (rear + 1) % MAX;
        qu[rear] = NULL;
        vector<int > cur;
        TreeNode *p;
        while(abs(front-rear) > 1)
        {
                   front = (front + 1) % MAX;
                   p = qu[front];
                   if(p == NULL)
                   {
                        rear = (rear+1) % MAX;
                        qu[rear] = NULL;
                        ans.push_back(cur);
                        cur.clear();
                        continue;
                   }
                   cur.push_back(p->val);
                   if(p->left != NULL)
                   {
                        rear = (rear+1) % MAX;
                        qu[rear] = p->left;
                   }
                   if(p->right != NULL)
                   {
                        rear = (rear+1) % MAX;
                        qu[rear] = p->right;
                   } 
        }
        ans.push_back(cur);
        for(int i = 0; i < ans.size(); i++){
                for(int j = 0; j < ans[i].size(); j++)
                        cout << ans[i][j] << " ";
                cout << "" << endl;
                }
        return ans;
    }
};

int main()
{
  Solution c;
  TreeNode *root;
  int A[] = {1,2,4,7,3,5,6,8};
  int B[]  = {4,7,2,1,5,3,8,6};
  vector<int > pre, in;
  for(int i = 0; i < sizeof(A)/4; i++){
	pre.push_back(A[i]);
	in.push_back(B[i]);
  }
  root = c.buildTree(pre, in);
  cout << "Pre+In Rebuild: " << endl;
  c.levelOrder(root);

  return 0;   
}
