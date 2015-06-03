#include <iostream>
#include <vector>
#include <string> 
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) { //∑«µ›πÈÀ„∑® 
         vector<int > ans;
         stack<TreeNode* > s;
         TreeNode *p;
         if(root != NULL)
         {
                 p = root;
                 while(p != NULL || !s.empty())
                 {
                         while(p != NULL)
                         {
                              s.push(p);
                              ans.push_back(p->val); 
                              p = p->left;
                         }
                         if(!s.empty())
                         {
                              p = s.top();
                              s.pop();
                              p = p->right;
                         }
                 }
         }
         return ans;
    }
    vector<int> preorderTraversal1(TreeNode* root){ //µ›πÈÀ„∑® 
         vector<int > ans;
         PreSeq(root, ans);
         return ans;
     }
    void PreSeq(TreeNode *b, vector<int > &seq)
    {
         if(b != NULL){
             seq.push_back(b->val);
             PreSeq(b->left, seq);
             PreSeq(b->right, seq);
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
  int A[] = {0,1,2,3,4,5,6,7};
  root = c.trans(A,1,sizeof(A)/4);
  c.printTree(root);
  printf("\n");                                                                                                  
  vector<int > ans = c.preorderTraversal1(root);
  for(int i = 0; i < ans.size(); i++)
          cout << ans[i] << " ";
  while(1);
  return 1;   
}
