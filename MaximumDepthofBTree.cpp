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
    int maxDepth(TreeNode *root) {
        int lh,rh;
        if(root == NULL) return 0;
        else 
        {
             lh = maxDepth(root->left);
             rh = maxDepth(root->right);
             return (lh>rh)?(lh+1):(rh+1);
        }
    }
};
int main()
{
  Solution c;
  
  while(1);
  return 1;   
}
