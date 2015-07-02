#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
��Ŀ��Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
����������һ���������еĵ���������ת����һ�ø߶�ƽ��Ķ���������
˼·��
��1��������ÿ���ڵ���������У����֣��ݹ鹹��ƽ���BST���ռ临�Ӷ�O(n)
��2����ʹ�ö���ռ�ֻ���Ƕ��������ֱ��ɨ�裬������Ƕ��ֲ��Ҳ��������¹��������������Ҹ��Ӷ�ΪO(n^2)
	��������������ʱ�临�Ӷ�ΪO(n),����ʼ��Ԫ��һ�������������
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
    //Result:Memory Limit Exceeded, ����ʹ�ö���洢
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
	//�������Ϲ��������
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
