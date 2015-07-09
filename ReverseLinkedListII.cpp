#include<iostream>
#include<vector>
using namespace std;
/*
题目：Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

解析：将链表从m到n之间的结点翻转， 1<= m <= n <= 链表长
思路：将第m个结点之后的结点逐个插入到其之前，直到第n个结点
      记录第m个结点的前一个结点，进行尾插
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL) return head;
		ListNode *pre = NULL, *p = NULL, *q = NULL;
		p = head;
		for(int i = 1; i < m && p != NULL; i++){
			pre = p;
			p = p->next;
		}
		if(p == NULL) return head; //最后一个结点
		int step = n-m;
		q = p;
		p = p->next;
		for(int i = 0; i < step && p != NULL; i++){
			ListNode *s = p;
			p = p->next;
			if(pre == NULL){ //插入到头结点前
				s->next = head;
				head = s;
			}
			else{
				s->next = pre->next;
				pre->next = s;
			}
		}
		q->next = p;
		return head;
    }
};

int main(){
	Solution c;
	ListNode *head = NULL;
	int A[] = {5,4};
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
	p = c.reverseBetween(head,1,2);
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}
