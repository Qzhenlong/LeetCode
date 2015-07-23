#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

解析：
二叉树有两个元素位置被弄错了，在不改变其结构的情况下还原该树，空间复杂度为O(n)的解法不难，能否实现空间复杂度为O(1)的解法

思路：
（1）中序遍历BST，找出两个非递增结点交换两个结点值, 使用了递归，所以空间为O(n)
（2）Morris inorder traversal. O(1) space. with only auxiliary two pointers。                                                                                                                                                            本文地址

//因为只有两个结点值交换了，那么判断二叉树是否正确，只需要观察前后两个结点的取值就行了，那么就参考线索二叉树思路

1. 如果当前节点的左子树为空，则对比当前结点与前驱结点的值，有问题就记录下来， 然后遍历右子树。

2. 如果当前节点的左孩子不为空，线索化二叉树，将左子树最右方结点的右指针指向其中序序列中的后继结点。
   
   线索化完成后，继续将当前结点设置为当前结点的左结点，继续第1步，直到出现当前结点为左子树某一结点的右结点，进行正确性判断，去除线索化。
   
   由于原树的最右结点都已被线索化了，那么当出现当前结点等于左子树某一结点的右结点时，说明那个结点是中序序列中上一个访问过的结点，当前结点是其后继，
   
   自然就可以继续判断这两个结点是否有误。
3. 直到当前结点为空，即出以上两步循环。

参考：二叉树Mirror遍历算法。

   */
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    TreeNode *pre;
    void recoverTree(TreeNode* root) {
        TreeNode *ma = NULL, *mb = NULL, *next = NULL;
		pre = NULL;
		InTra(root, ma, mb, next);
		if(ma != NULL){
			if(mb == NULL) mb = next;
			int tmp = ma->val;
			ma->val = mb->val;
			mb->val = tmp;
		}
    }
	void InTra(TreeNode *b, TreeNode *&ma, TreeNode *&mb, TreeNode *&next){
		if(b != NULL){
			InTra(b->left, ma, mb, next);	
			if(pre != NULL && pre->val > b->val){
				if(ma == NULL){
					ma = pre;
					next = b;
				}
				else mb = b;
			}
			pre = b;
			InTra(b->right, ma, mb, next);
		}
	}
   //Mirror中序遍历，源于：https://github.com/leetcoders/LeetCode/blob/master/RecoverBinarySearchTree.h， 自己分析了一下
    void _recoverTree(TreeNode *root) {
        TreeNode *cur = root, *prev = NULL;
        TreeNode *first = NULL, *second = NULL, *last = NULL;
        while (cur != NULL)
        {
            if (cur->left == NULL)   //如果当前结点的左子树为空，则当前结点与上一结点在中序序列中为前后关系，当前结点值应该小于上一节点值
            {
                compare(last, cur, first, second); //对比上一个结点，与当前结点的取值， first记录上一结点，second记录当前结点，如果后面无错误结点，则交换这两个结点值
                last = cur;        //记录当前结点
                cur = cur->right;  //遍历了左子树和当前结点，到右子树
            }
            else //当前结点左子树不为空，那么继续在左子树中查找其在中序序列中的前驱结点，即当前节点的左子树的最右节点
            {
                prev = cur->left;  //记录当前结点的左结点
                while (prev->right != NULL && prev->right != cur) //如果其右子树不为空，则一直找到最右下角
                    prev = prev->right;

                if (prev->right == NULL) //找到最右下角元素
                {
                    prev->right = cur; //利用线索二叉树的想法，将没用的指针指向其中序序列中的后继结点
                    cur = cur->left; //当前结点指向左结点
                }
                else //如果前驱结点的右结点不为空，说明它指向了其后继结点，找到了，可以用来判断了
                {
                    compare(last, cur, first, second); //判断前后两个结点是否正常，不正常则记录下来
                    last = cur;                        //更新上一结点
                    prev->right = NULL;                //恢复树原有结构，去除线索化
                    cur = cur->right;                 //可以继续搜索右子树了
                }
            }
        }
        swap(first->val, second->val);  //交换结点值
    }

    void compare(TreeNode *last, TreeNode *cur, TreeNode *&first, TreeNode *&second)
    {
        if (last && last->val > cur->val)
        {
            if (!first)
                first = last;
            second = cur;
        }
    }
	void InPrint(TreeNode *b){
		if(b != NULL){
			InPrint(b->left);
			cout << b->val << " ";
			InPrint(b->right);
		}
	}
};

int main(){
	Solution c;
	TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(1);
	/*root->right = new TreeNode(8);
	root->left->left = new TreeNode(1);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(7);
*/
	c.InPrint(root);
	cout << endl;
	c._recoverTree(root);
	cout << endl;
	c.InPrint(root);
	return 0;
}


