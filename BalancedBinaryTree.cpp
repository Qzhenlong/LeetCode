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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(TreeHeight(root->left)-TreeHeight(root->right)) > 1) return false;
        return (isBalanced(root->left) && isBalanced(root->right)); 
    }

    int TreeHeight(TreeNode *b)
    {
        int rh, lh;
        if(b == NULL) return 0;
        else{
             lh = TreeHeight(b->left);
             rh = TreeHeight(b->right);
             return (lh > rh) ? (lh+1) : (rh+1);
        }
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
  int A[] = {0,1,2};
  root = c.trans(A,1,sizeof(A)/4);
  c.printTree(root);
  printf("\n");                                                                                                  
  cout <<  (c.isBalanced(root) ? "true" : "false") << endl;
  while(1);
  return 1;   
}
