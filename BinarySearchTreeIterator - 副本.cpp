#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
原题：
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

解析：实现一个二叉搜索树的迭代器，迭代器必须使用根结点进行初始化，调用next()时返回下一个树中的最小值。
	要求时间复杂度O（1）空间复杂度O(h)
	
思路：利用BST的中序序列有序的特点，由于有空间要求，如果直接将中序序列全部存储，则空间复杂度超出要求。
	  考虑到二叉树中序遍历的非递归算法里使用了一个大小为h的栈，借此该思路，可解答本题。
	  可利用一个大小为h的栈，根节点开始的所有左结点，调用next()时，栈顶元素出栈，如果栈顶元素有右结点，
	  则以同样的方式将其左结点依次进栈，即中序遍历的非递归过程。
*/

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *p = root;
		while(p != NULL){
			s.push(p);
			p = p->left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = s.top();
		int ans = p->val;
		s.pop();
		if(p->right != NULL){
			p = p->right;
			while(p != NULL){
				s.push(p);
				p = p->left;
			}
		}
		return ans;
    }
private:
	stack<TreeNode* > s; //栈结构
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 int main(){
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	BSTIterator i = BSTIterator(root);
    while (i.hasNext()) cout << i.next() << " ";
	return 0;
 }
 