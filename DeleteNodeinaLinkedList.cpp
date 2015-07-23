#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 

the linked list should become 1 -> 2 -> 4 after calling your function.

解析：只给出要删除的结点，而且不包含尾结点，剑指offer上的一个题，将要删除结点的值与下一结点值交换，再删除下一结点即可


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
