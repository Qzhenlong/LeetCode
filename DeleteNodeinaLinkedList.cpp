#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 

the linked list should become 1 -> 2 -> 4 after calling your function.

������ֻ����Ҫɾ���Ľ�㣬���Ҳ�����β��㣬��ָoffer�ϵ�һ���⣬��Ҫɾ������ֵ����һ���ֵ��������ɾ����һ��㼴��


*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *p = node->next;
		int tmp = node->val;
		node->val = p->val;
		p->val = tmp;
		node->next = p->next;
		free(p);
    }
};

int main(){
	Solution c;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	ListNode *p = head->next->next;
	c.deleteNode(p);
	while(head != NULL){
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}
