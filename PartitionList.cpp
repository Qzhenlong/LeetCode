#include<iostream>
#include<vector>
using namespace std;
/*
题目：Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

解析：给定一个单链表及一个x，将所有取值小于x的结点移动到取值大于等于x的结点之前。保持结点原有的相对位置不变
思路：扫描链表，用xp记录第一个大于等于x的结点的前一个结点，当遇到小于x的结点，则该节点插入到该节点之后即可

*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *xp = NULL, *p = NULL, *q = NULL; //提交出现Running Time Error, 指针未指向空，安全起见，定义时应该都置为NULL
		if(head == NULL || head->next == NULL) return head;
		q = head;
		while(q->val < x){
			xp = q;
			q = q->next;
			if(q == NULL) return head;
		}
		p = q->next;
		while(p != NULL){   
			if(p->val < x){		
			    q->next = p->next; //记录下一个结点
				if(xp == NULL){ //说明头结点的值大于等于3，这里用到xp为NULL,因此必须定义时都置为NULL
					xp = p;
					p->next = head;
					head = xp;
				}
				else{
					p->next = xp->next;
					xp->next = p;
					xp = p;
				}
				p = q->next;
			}
			else{
				q = p;
				p = q->next;
			}
		}
		return head;
    }
};

int main(){
	Solution c;
	ListNode *head = NULL, *p = NULL;
	int A[] = {2,1};
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
	cout <<endl;
	p = c.partition(head,2);
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	cout <<endl;
	return 0;
}
