#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
题目：Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
解析：给定一个升序排列的单链表，将成转换成一棵高度平衡的二叉搜索树
思路：
（1）将链表每个节点放入数组中，二分，递归构建平衡的BST，空间复杂度O(n)
（2）不使用额外空间只能是对链表进行直接扫描，如果还是二分查找并至顶向下构建二叉树，查找复杂度为O(n^2)
	采用至底向上则时间复杂度为O(n),链表开始的元素一定在树的最左侧
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //Result:Memory Limit Exceeded, 不能使用额外存储
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int > nums;
		if(head == NULL) return NULL;
		while(head != NULL){
			nums.push_back(head->val);
			head = head->next;
		}
		return toBST(nums, 0, nums.size()-1);
    }
	TreeNode* toBST(vector<int > A, int low, int high){
		if(low > high) return NULL;
		int mid = (low+high)/2;
		TreeNode *b = new TreeNode(A[mid]);
		b->left = toBST(A, low, mid-1);
		b->right = toBST(A, mid+1, high);
		return b;
	}
	//至底向上构造二叉树
    TreeNode* sortedListToBST1(ListNode* head) {
		if(head == NULL) return NULL;
		ListNode *p = head;
		int n = 0;
		while(p != NULL){
			n++;
			p = p->next;
		}
		return bottomTotop(head, 0, n-1);
    }
	//
	TreeNode* bottomTotop(ListNode *&list, int low, int high){
		if(low > high) return NULL;
		int mid = (low+high)/2;
		TreeNode *leftNode = bottomTotop(list, low, mid-1);
		TreeNode *b = new TreeNode(list->val);
		b->left = leftNode;
		list = list->next;
		TreeNode *rightNode = bottomTotop(list, mid+1, high);
		b->right = rightNode;
		return b;
	}
	void Inprint(TreeNode *b){
		if(b != NULL){
			Inprint(b->left);
			cout << b->val << " ";
			Inprint(b->right);
		}
	}
	void LevelPrintTree(TreeNode *root){
		queue<TreeNode* > q;
		if(root == NULL) return;
		q.push(root);
		while(!q.empty()){
			TreeNode *p = q.front();
			q.pop();
			cout << p->val << " ";
			if(p->left != NULL) q.push(p->left);
			if(p->right != NULL) q.push(p->right);
		}
	}
};

int main(){
	Solution c;
	ListNode *head = NULL;
	ListNode *p = head;
	for(int i = 0; i < 8; i++){
		ListNode *s = new ListNode(i+1);
		if(head == NULL){ head = s; p = s; }
		else{
			p->next = s;
			p = s;
			}
	}
	p->next = NULL;
	TreeNode *root = c.sortedListToBST1(head);
	c.Inprint(root);
	cout << endl;
	c.LevelPrintTree(root);
	return 0;
}
