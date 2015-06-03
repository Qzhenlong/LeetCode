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
    vector<vector<int > > levelOrderBottom(TreeNode* root) {
        vector<vector<int > > ans;
        if(root == NULL) return ans;
        int MAX = 65535;
        TreeNode *qu[MAX];
        int front, rear;
        front = rear = -1;
        rear = (rear + 1) % MAX;
        qu[rear] = root;
        rear = (rear + 1) % MAX;
        qu[rear] = NULL; //标记树的每层结束位置 
        vector<int > cur;
        TreeNode *p;
        while((rear-front) > 1)
        {
                  front = (front + 1) % MAX;     
                  p = qu[front];
                  if(p != NULL)
                       printf("%d ", p->val);
      
                  if(p == NULL){
                       ans.insert(ans.begin(),cur);
                       cur.clear();
                       rear = (rear + 1) % MAX;   
                       qu[rear] = NULL; 
                       continue;
                  }
                  
                  cur.push_back(p->val);
                  if(p->left != NULL){
                             rear = (rear + 1) % MAX;
                             qu[rear] = p->left;           
                  }
                  if(p->right != NULL){
                              rear = (rear + 1) % MAX;
                              qu[rear] = p->right;            
                  }
                 
                  
        }
        ans.insert(ans.begin(), cur);
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
  c.levelOrderBottom(root);
                                                                                             
 // cout <<  (c.isBalanced(root) ? "true" : "false") << endl;
  while(1);
  return 1;   
}
