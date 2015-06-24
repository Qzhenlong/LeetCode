#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
ԭ�⣺
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

������ʵ��һ�������������ĵ�����������������ʹ�ø������г�ʼ��������next()ʱ������һ�����е���Сֵ��
	Ҫ��ʱ�临�Ӷ�O��1���ռ临�Ӷ�O(h)
	
˼·������BST����������������ص㣬�����пռ�Ҫ�����ֱ�ӽ���������ȫ���洢����ռ临�Ӷȳ���Ҫ��
	  ���ǵ���������������ķǵݹ��㷨��ʹ����һ����СΪh��ջ����˸�˼·���ɽ���⡣
	  ������һ����СΪh��ջ�����ڵ㿪ʼ���������㣬����next()ʱ��ջ��Ԫ�س�ջ�����ջ��Ԫ�����ҽ�㣬
	  ����ͬ���ķ�ʽ�����������ν�ջ������������ķǵݹ���̡�
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
	stack<TreeNode* > s; //ջ�ṹ
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
 