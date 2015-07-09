#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 �� k �� BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

��������һ�ö����������в��ҵ�kС��Ԫ��,���� 1 <= k <= ����Ԫ�ظ���
     ���BST�������޸ģ��Ƿ���ҪƵ���ҵ�kСԪ�أ�Ҫ����Ż������㷨

˼·��
��1���Ȳ�����follow up��Ҫ�󣬿�����������ҵ���kСԪ�ط��أ� ��BST�����䶯��ֻ��Ҫ�жϲ���Ԫ�ش��ڻ���С�ڵ�kСԪ�أ� ���뵽���������о��У�����������ɨ���������
��2�����߼��㵱ǰ����������Ľ���������Ϊk-1,�򷵻ص�ǰ��㼴�ɣ� ��BST�����䶯����������һ�����ԣ���¼�������н������ÿ�β����ʱ��ı��ֵ
ע��������Ч�ʲ��ߣ�����������ʱ��Ҫ�ظ������ܶ��㡣
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int > seq;
		InScan(root, seq);
		return seq[k-1];
    }
	int InScan(TreeNode *b, vector<int > &seq){
		if(b != NULL){
			InScan(b->left, seq);
			seq.push_back(b->val);
			InScan(b->right, seq);
		}
	}
	int kthSmallest1(TreeNode *root, int k){
	
	}
	int 
};

int main(){
	Solution c;
	TreeNode *root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	cout << c.kthSmallest(root, 2);
	return 0;
}
