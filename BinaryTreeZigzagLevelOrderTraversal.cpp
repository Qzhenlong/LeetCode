#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
原题：
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
解析：二叉树层次遍历，并蛇行输出；
思路：和Binary Tree Level Order Traversal I和II的思路相似，只不过输出时有差异。
1）采用层次遍历算法，使用队列进行存储
2）使用NULL来分隔每一层
3）单数层从左向右输出，双数层从右往左输出。

*/
/**
 * Definition for a binary tree node.
 */
 struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int > > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int > > ans;
		if(root == NULL) return ans;
		queue<TreeNode* > q;
		vector<int > cur; //存储当前层数结点
		int level = 1; //记录当前层数，保证蛇行输出
		q.push(root);
		q.push(NULL); //使用NULL进行分层
		while(q.size() > 1) { //考虑到分层用的NULL
			TreeNode *p = q.front();
			q.pop();
			if(p == NULL){
				if(level % 2 == 0) reverse(cur.begin(), cur.end());
				ans.push_back(cur);
				cur.clear();
				level++;
				q.push(NULL);
				continue;
			}
			cur.push_back(p->val);
			if(p->left  != NULL) q.push(p->left);
			if(p->right != NULL) q.push(p->right);
			
		}
		if(level % 2 == 0) reverse(cur.begin(), cur.end());
		ans.push_back(cur); //最后一层的结果不能遗漏
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
             cout << b->val << " ";
             printTree(b->left);
             printTree(b->right);
         }
    }
};

int main()
{
	  Solution c;
	  TreeNode *root;
	  int A[] = {0,1,2,3};
	  root = c.trans(A,1,sizeof(A)/4);
	  for(int i = 0; i < sizeof(A)/4; i++)
		cout << A[i] << " ";
	  cout << endl;
	  vector<vector<int > > ans = c.zigzagLevelOrder(root);    	
        for(int i = 0; i < ans.size(); i++){
                for(int j = 0; j < ans[i].size(); j++)
                        cout << ans[i][j] << " ";
                cout << "" << endl;
                }
	  return 0;
}
