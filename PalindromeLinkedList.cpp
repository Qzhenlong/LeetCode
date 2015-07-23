#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

������ ����һ���������ж����Ƿ�Ϊ�������У�Ҫ��ʱ��O(n)���ռ�O(1)

˼·�����貢û��˵���ܸı�����ṹ���ɽ�����ǰ�벿�֣����ߺ�벿�ַ�ת��Ȼ��ɨ��Աȼ���

*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if(head == NULL || head->next == NULL) return true;
		ListNode *p = head, *q = head, *s = NULL; //ʹ�ÿ���ָ��
		while(q != NULL && q->next != NULL){
			s = p;
			p = p->next; 
			q = q->next->next;
		}
		if(q != NULL) s = p; //��¼�������
		while(p != NULL){
			q = p; //qָ������β
			p = p->next;
		}
		
		p = s->next;
		while(p != q && p != NULL){ //ǰ��η�ת
			ListNode *r = p->next;
			p->next = q->next;
			q->next = p;
			p = r;
		}
		s->next = q;
		p = head;
		while(q != NULL){
		    cout << p->val << " " << q->val << endl;
			if(p->val != q->val) return false;
			p = p->next;
			q = q->next;
		}
		return true;
    }
};

int main(){
	Solution c;
	ListNode *head;
    head = new ListNode(8);
	head->next = new ListNode(8);
	//head->next->next = new ListNode(8);
	//head->next->next->next = new ListNode(5);
	//head->next->next->next->next = new ListNode(2);
	//head->next->next->next->next->next = new ListNode(8);
	cout << c.isPalindrome(head);
	return 0;
}
