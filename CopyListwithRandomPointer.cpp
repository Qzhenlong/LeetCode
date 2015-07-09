#include<iostream>
#include<vector>
using namespace std;
/*
题目：
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

解析：给定一个含有一个随机指针（指向空或者任意结点）的链表，返回链表的一个深复制

思路：剑指offer上的一道题，在每个已有节点上插入一个新结点，然后构建新结点的随机指针即可，每一个新结点的随机指针指向上一个结点随机指针指向结点的下一个。
	  再分解链表即可。


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
		while(p != NULL){ //每个已有结点后插入一个新结点
			RandomListNode *s = new RandomListNode(p->label);
			s->next = p->next;
			p->next = s;
			p = s->next;
		}
		p = head;
		while(p != NULL){ //构建新加入结点的随机指针
			q = p->random;
			r = p->next;
			if(q != NULL)
				r->random = q->next;
			p = r->next;
		}
		RandomListNode *newhead = NULL; //分离链表
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
