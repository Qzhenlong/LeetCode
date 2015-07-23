#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is 
completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

������������ȫ�������Ľ����
(1)ֱ�ӱ���������Ȼ���Ӷ�̫����
(2)������ȫ�����������ʣ��������ߵ�Ҷ�ӽ��ĸ߶Ⱥ����ұ�Ҷ�ӽ��߶���ͬ����ô����һ�����������������������2^h-1���ɽ�����ʵݹ����
(3)����,http://bookshadow.com/weblog/2015/06/06/leetcode-count-complete-tree-nodes/
�Զ�����h�㣨���һ�㣩Ԫ�ؽ��б�ţ�0..2^h-1, ������ô���Ӹ���㵽�ý���·����
�ҵ���0��2^h-1�ĵ�һ�ս��ı�����þ������һ��ķǿս����
��0��2^h-1���ж��ֲ��Ҽ��ɣ�����������һ����Ϊx = 0010,���Ϊh = 4, ��ô������ĴӸ���㵽����·��Ϊ����-��-��-��ȷ��x��ÿһλ���ɡ�
��x��Ӧ���Ϊ��ʱ������ǰ���ֲ��ң�����������ֲ���


*/

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //ֱ�ӱ���
    int _countNodes(TreeNode* root) {
		int numNode = 0;
		travelTree(root, numNode);
		return numNode;
    }
	void travelTree(TreeNode *b, int &numNode){
		if(b != NULL){
			numNode++;
			travelTree(b->left, numNode);
			travelTree(b->right, numNode);
		}
	}
	//������������
    int countNodes(TreeNode* root) {
		if(root == NULL) return 0;
		TreeNode *p = root, *q = root;
		int lh = 0, rh = 0;
		while(p != NULL){ p = p->left; lh++; }
		while(q != NULL){ q = q->right; rh++; }
		if(lh == rh) return (1 << lh) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right); 
    }
    //���ֲ���
    int __countNodes(TreeNode* root) {
        int depth = 0;
        TreeNode* node = root;
        while (node) {
            depth++;
            node = node->left;
        }
        if (depth == 0) {
            return 0;
        }
        int left = 0, right = (1 << (depth - 1)) - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (getNode(root, mid, depth - 1)) { //���һ��ĸý�㲻Ϊ��
                left = mid + 1;
            } else {
                right = mid - 1;  //ѭ������ʱ��right�������һ�㣬���������һ��Ҷ�ӽ�����һ��㡣
            }
        }
        return (1 << (depth - 1)) + right;
    }
    TreeNode* getNode(TreeNode* root, int path, int depth) {
        while (depth-- && root) {
            if (path & (1 << depth)) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root;
    }
	TreeNode *tran(int A[], int i, int n){
		if(i >= n) return NULL;
		TreeNode *b = new TreeNode(A[i]);
		b->left = tran(A, 2*i, n);
		b->right = tran(A, 2*i+1, n);
		return b;
	}
};

int main(){
	Solution c;
	int A[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
	TreeNode *root = c.tran(A, 1, sizeof(A)/4);
	cout << c.__countNodes(root);
	return 0;
}
