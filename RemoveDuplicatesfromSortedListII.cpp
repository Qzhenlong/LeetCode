#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

����������һ��������ɾ�������ظ���㣬ֻ����û���ظ����Ľ��

˼·����¼��ǰ��㼰��һ��㣬�����������ͬ��㣬��ɾ��������ͬ���

*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = NULL, *p = NULL, *q = NULL;
		int sameNum = 0;
		if(head == NULL || head->next == NULL) return head;
		p = head;
		q = head->next;
		while(q != NULL){
			if(p->val == q->val)
				sameNum++;
			else{
				if(sameNum > 0){
					if(pre == NULL) head = q;
					else pre->next = q;
					p = q;
					sameNum = 0;
				}
				else{
					pre = p;
					p = q;
				}
			}
			q = q->next;
		}
		if(sameNum > 0){
			if(pre == NULL) head = q;
			else pre->next = q;
		}
		return head;
    }
};

int main()
{
  Solution c;
  ListNode *headA;
  ListNode *s;
  int A[] = {2,2,3};
  headA = NULL;
  for(int i = 0; i < sizeof(A)/4; i++){
          s = new ListNode(A[i]);
          s->next = headA;
          headA = s;
          
  }
  ListNode *p = headA;
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  printf("\n");
  p = c.deleteDuplicates(headA);
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  return 1;   
}


