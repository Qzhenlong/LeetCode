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
    int minDepth(TreeNode* root) {
        int lh,rh;
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        else{
             lh = minDepth(root->left);
             rh = minDepth(root->right);
             if(lh == 0) return rh+1;
             if(rh == 0) return lh+1;
             return (lh < rh) ? (lh+1) : (rh+1);     
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
  cout << "min Path:" << endl;                                                                                                    
  cout << c.minDepth(root) << endl;
  while(1);
  return 1;   
}
