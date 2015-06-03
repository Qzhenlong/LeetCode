#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

/** Definition for binary tree **/
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL) return true;
        else if(p != NULL && q == NULL) return false;
        else if(p == NULL && q != NULL) return false;
        else
        {
            if(p->val != q->val) return false;
            else return (isSameTree(p->left, q->left) && isSameTree(q->right, p->right));
        }
    }
};
int main()
{
  Solution c;
  
  while(1);
  return 1;   
}
