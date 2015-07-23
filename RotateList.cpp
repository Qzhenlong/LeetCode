#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

解析：给定一个单链表，将其循环右移k个位置，k为非负整数

思路：就是将链表最尾的k个元素头插到链表头
*/

struct ListNode {
	int val;
	ListNode *next; 
	ListNode(int x) : val(x), next(NULL){}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
		int n = 0; 
		ListNode *p = head, *q = NULL, *tail = NULL, *ntail = NULL;
		while(p != NULL){ //统计总结点数
			tail = p;
			p = p->next;
			n++;
		}
		k = k % n; //防止比结点数大
		if(k == 0) return head;
		//查找末尾k个结点
		p = head;
		for(int i = 0; i < k-1; i++) p = p->next;
		while(p != NULL){
			ntail = q;
			if(q == NULL) q = head;
			else q = q->next;
			p = p->next;
		}
		tail->next = head;
		ntail->next = NULL;
		head = q;
		return head;
    }
};

int main(){
	Solution c;
	int A[] = {1,2,3,4};
	ListNode *head = NULL, *p = NULL;
	for(int i = 0; i < sizeof(A)/4; i++){
		ListNode *s = new ListNode(A[i]);
		if(head == NULL) head = p = s;
		else{
			p->next = s;
			p = s;
		}
	}
	p->next = NULL;
	p = head;
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	p = c.rotateRight(head, 3);
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}
