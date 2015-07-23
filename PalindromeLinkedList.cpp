#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

解析： 给定一个单链表，判断它是否为回文序列，要求时间O(n)，空间O(1)

思路：题设并没有说不能改变链表结构，可将链表前半部分，或者后半部分翻转，然后扫描对比即可

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
		ListNode *p = head, *q = head, *s = NULL; //使用快慢指针
		while(q != NULL && q->next != NULL){
			s = p;
			p = p->next; 
			q = q->next->next;
		}
		if(q != NULL) s = p; //记录后半段起点
		while(p != NULL){
			q = p; //q指向链表尾
			p = p->next;
		}
		
		p = s->next;
		while(p != q && p != NULL){ //前半段翻转
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
