#include <iostream>
#include <vector>
#include <string> 
#include <map>
using namespace std;
/**
 * Definition for a binary tree node.
 **/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
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
  int A[] = {0,1,2,3,4,5,6,7,8,9};
  root = c.trans(A,1,sizeof(A)/4);
  c.printTree(root);
  printf("\n");   
  c.levelOrder(root);                                                                                    
 // cout <<  (c.isBalanced(root) ? "true" : "false") << endl;
  while(1);
  return 1;   
}
