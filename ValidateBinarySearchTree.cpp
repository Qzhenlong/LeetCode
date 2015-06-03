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
//判断BST，BST的中序序列为递增序列 
class Solution { 
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)) return true;
        vector<int > pre = getPreScan(root);
       //cout << pre.size() << endl;

        for(int i = 0; i < pre.size()-1; i++){
                 cout << pre[i] << " ";
                 if(pre[i] >= pre[i+1]) return false; //注意等号 
        }
        return true;
        
    }
    vector<int > getPreScan(TreeNode* root) //非递归 中序遍历 
    {
         vector<int > pre_seq;
         stack<TreeNode* > t_stack;
         TreeNode *p;
         if(root != NULL)
         {
                 p = root;
                 while(!t_stack.empty() ||  p != NULL)
                 {
                     while(p != NULL)
                     {
                          t_stack.push(p);
                          p = p->left;
                     }
                     if(!t_stack.empty())
                     {
                          p = t_stack.top();
                          t_stack.pop();
                          pre_seq.push_back(p->val);
                          p = p->right;
                     }
                 }
         }
       
       return pre_seq;            
    }
    bool isValidBST1(TreeNode* root) { //错误，边界情况无法解决 
        int Val = INT_MIN;
        if(root == NULL || (root->left == NULL && root->right == NULL)) return true;
        return isBST(root, Val);
        
    }
    bool isBST(TreeNode* p, int &Val) //递归
    {
          if(p == NULL) return true;
          if(isBST(p->left, Val))
          {
              if(p->val > Val || (p->left == NULL && Val == INT_MIN)){
                          Val = p->val;
                          return isBST(p->right, Val);
                        }
              else return false;
          }
          else return false;
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
  int A[] = {0,-2147483648,0,-2147483647};
  root = c.trans(A,1,sizeof(A)/4);
  c.printTree(root);
  printf("\n");                                                                                                  
  cout <<  (c.isValidBST1(root)? "true" : "false") << endl;
  while(1);
  return 1;   
}
