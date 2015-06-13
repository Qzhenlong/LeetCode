#include<iostream>
#include<vector>
using namespace std;
/*
原题：Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

解析：输入一个单链表，交换每两个相邻节点，并返回链表头指针，只能使用线性空间且不能直接修改节点值。

思路：使用四个指针，p,q两个指针对当前两个节点进行交换，另外一个指针s记录后续链表， 一个指针r记录前续链表，直到p,q有一个以上为空时结束。

*/

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		ListNode *p, *q, *s, *r;
		r = p = head;
		q = p->next;
		while(p != NULL && q != NULL){
			s = q->next;
			q->next = p;
			p->next = s;
			if(r == head) head = q; //改变头指针位置
			else r->next = q;     //处理中间节点
			if(s == NULL) break; //到达链表尾
			r = p;
			p = s;
			q = p->next;
		}
		return head;
    }
};

int main(){
	Solution c;
	int A[] = {7,6,5,4,3,2,1};
	ListNode *head = NULL;
	for(int i = 0; i < sizeof(A)/4; i++){
		ListNode *s = new ListNode(A[i]);
		s->next = head;
		head = s;
	}
	ListNode *p = head;
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	p = c.swapPairs(head);
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}
