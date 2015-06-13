#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

����������һ������������ÿ�������ڽڵ㣬����������ͷָ�룬ֻ��ʹ�����Կռ��Ҳ���ֱ���޸Ľڵ�ֵ��

˼·��ʹ���ĸ�ָ�룬p,q����ָ��Ե�ǰ�����ڵ���н���������һ��ָ��s��¼�������� һ��ָ��r��¼ǰ������ֱ��p,q��һ������Ϊ��ʱ������

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
			if(r == head) head = q; //�ı�ͷָ��λ��
			else r->next = q;     //�����м�ڵ�
			if(s == NULL) break; //��������β
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
