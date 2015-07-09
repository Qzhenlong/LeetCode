#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

����������һ������һ�����ָ�루ָ��ջ��������㣩���������������һ�����

˼·����ָoffer�ϵ�һ���⣬��ÿ�����нڵ��ϲ���һ���½�㣬Ȼ�󹹽��½������ָ�뼴�ɣ�ÿһ���½������ָ��ָ����һ��������ָ��ָ�������һ����
	  �ٷֽ������ɡ�


/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = head, *q = NULL, *r = NULL;
		while(p != NULL){ //ÿ�����н������һ���½��
			RandomListNode *s = new RandomListNode(p->label);
			s->next = p->next;
			p->next = s;
			p = s->next;
		}
		p = head;
		while(p != NULL){ //�����¼���������ָ��
			q = p->random;
			r = p->next;
			if(q != NULL)
				r->random = q->next;
			p = r->next;
		}
		RandomListNode *newhead = NULL; //��������
		p = head;
		q = newhead;
		while(p != NULL){
			r = p->next;
			p->next = r->next;
			p = p->next;
			if(newhead == NULL){
				newhead = q = r;
			}
			else{
				q->next = r;
				q = r;
			}	
		}
		if(q != NULL) q->next = NULL;
		return newhead;
    }
};

int main(){
	Solution c;
	RandomListNode *head = NULL;
/*	head = new RandomListNode(1);
	head->next = new RandomListNode(2);
	head->next->next = new RandomListNode(3);
	head->next->next->next = new RandomListNode(4);
	head->random = head->next;
	head->next->random = head->next->next;
	*/
	RandomListNode *p = head;


	p = c.copyRandomList(head);
	
	while(p != NULL){
		cout << p->label << " ";
		p = p->next;
	}
	cout << endl;
	p = head;
	while(p != NULL){
		cout << p->label << " ";
		p = p->next;
	}
	return 0;
}
