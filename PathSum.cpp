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
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum, 0);
    }
    bool dfs(TreeNode* root, int sum, int cursum)
    {
       if(root == NULL) return false;
       if(root->left == NULL && root->right == NULL) 
                     return (cursum + root->val == sum);
       return dfs(root->left, sum, cursum+root->val) || dfs(root->right, sum, cursum+root->val);
             
    }
};
int main()
{
  Solution c;
  string s = "MCMLXXXIV";
  //cout << c.romanToInt(s)<< endl;
  while(1);
  return 1;   
}
