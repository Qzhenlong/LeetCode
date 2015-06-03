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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        int MAX = 65535;
        TreeNode *qu[MAX], *p, *end;
        end = (TreeNode *)malloc(sizeof(TreeNode)); //±ê¼Ç 
        int front = -1, rear = -1;
        vector<int > cur;
        qu[++rear] = root;
        rear = (rear+1) % MAX;
        qu[rear] = end;
        while(abs(rear-front) > 1)
        {
             front = (front+1) % MAX;
             p = qu[front];
             if(p == end)
             {
                  
                  //for(int i = 0; i < cur.size(); i++) cout << cur[i] << " ";
                  //cout << "test" <<endl;
                  if(cur.size() % 2 == 1 && cur.size() != 1) return false; 
                  for(int i = 0; i < cur.size()/2; i++)
                  {
                          if(cur[i] != cur[cur.size()-i-1]) return false;
                  }
                  
                  rear = (rear+1) % MAX;
                  qu[rear] = end;
                  cur.clear();
                  continue;
             }
             if(p == NULL)
             {
                  cur.push_back(MAX);
                  continue;
             }
             cur.push_back(p->val);
             rear = (rear+1) % MAX;
             qu[rear] = p->left;
             rear = (rear+1) % MAX;
             qu[rear] = p->right;
             
        }
        return true;
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
  int A[] = {0,1,1,1,2,2,2,2};
  root = c.trans(A,1,sizeof(A)/4);
  c.printTree(root);
  printf("\n");                                                                                                  
  cout <<  (c.isSymmetric(root)? "true" : "false") << endl;
  while(1);
  return 1;   
}
