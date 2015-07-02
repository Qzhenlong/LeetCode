#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

����������һ��������һ��x��������ȡֵС��x�Ľ���ƶ���ȡֵ���ڵ���x�Ľ��֮ǰ�����ֽ��ԭ�е����λ�ò���
˼·��ɨ��������xp��¼��һ�����ڵ���x�Ľ���ǰһ����㣬������С��x�Ľ�㣬��ýڵ���뵽�ýڵ�֮�󼴿�

*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *xp = NULL, *p = NULL, *q = NULL; //�ύ����Running Time Error, ָ��δָ��գ���ȫ���������ʱӦ�ö���ΪNULL
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
			    q->next = p->next; //��¼��һ�����
				if(xp == NULL){ //˵��ͷ����ֵ���ڵ���3�������õ�xpΪNULL,��˱��붨��ʱ����ΪNULL
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
