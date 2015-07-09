#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

����������һ���������һ��kֵ��һ�η�תk����㲢�����޸ĺ���������������������k�������������β���ֵĽ����Ժ���
	 �����޸Ľ��ֵ��O(1)�ռ�Ҫ��

˼·���������ֳɶ����������ת��ƴ�Ӽ���

*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *p = head, *q = NULL, *gHead = head, *gTail=NULL, *tail = NULL;
		int nodeNum = 0;
		while(p != NULL){
			nodeNum++;
			if(nodeNum % k == 0){
				q = p->next;
				p->next = NULL;
				gTail = reverseList(gHead);
				if(tail == NULL){
					head = gHead;
					tail = gTail;
				}
				else{
					tail->next = gHead;
					tail = gTail;
				}
				p = gHead = q;
			}
			else p = p->next;
		}
		if(tail != NULL) tail->next = gHead;
		return head;
    }
	ListNode* reverseList(ListNode *&head){ //���ط�ת�������β���
		ListNode *p = NULL, *q = NULL, *tail = NULL;
		tail = head;
		if(head == NULL || head->next == NULL) return tail;
		p = head->next;
		tail->next = NULL;
		while(p != NULL){
			q = p->next;
			p->next = head;
			head = p;
			p = q;
		}
		return tail;
	}
};

int main(){
	Solution c;
	ListNode *head = NULL;
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
	ListNode *p = head;
	
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	p = c.reverseKGroup(head, 6);
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}	
	
	return 0;
}
