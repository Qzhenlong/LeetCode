#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* ans = NULL, *s, *p, *q;
			int c = 0; //进位
			if(l1 == NULL && l2 == NULL) return ans;
			while(l1 != NULL && l2 != NULL)
			{
				l1->val = l1->val + l2->val + c;
				if(l1->val > 9){ l1->val -= 10; c = 1; }
				else c = 0;
				q = l2; p = l1;
				l1 = l1->next; l2 = l2->next;
				if(ans == NULL){ ans = p; s = ans; }
				else{ s->next = p; s = p;}
				free(q);
			}
			while(l1 != NULL){
				l1->val = l1->val + c;
				if(l1->val > 9){ l1->val -= 10; c = 1; }
				else c = 0;		
				p = l1;
				l1 = l1->next;
				if(ans == NULL){ ans = p; s = ans; }
				else{ s->next = p; s = p;}	
			}
			while(l2 != NULL){
				l2->val = l2->val + c;
				if(l2->val > 9){ l2->val -= 10; c = 1; }
				else c = 0;		
				p = l2;
				l2 = l2->next;
				if(ans == NULL){ ans = p; s = ans; }
				else{ s->next = p; s = p;}
			}
			if(c != 0){ //注意最后进位情况
				ListNode *t = (ListNode *)malloc(sizeof(ListNode));
				t->val = c;
				s->next = t;
				s = t;
			}
			s->next = NULL;
			return ans;
			
    }
};

int main()
{
	Solution c;
	int A[] = {5,5};
	int B[] = {5,5};
	ListNode *l1 = NULL, *l2 = NULL;
	for(int i = 0; i < sizeof(A)/4; i++)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		s->val = A[i];
		s->next = l1;
		l1 = s;
	}
	for(int i = 0; i < sizeof(B)/4; i++)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		s->val = B[i];
		s->next = l2;
		l2 = s;
	}
	ListNode *p = l1;
	while(p != NULL)
	{
		cout << p->val << " -> ";
		p = p->next;
	}
	cout << endl;
	p = l2;
	while(p != NULL)
	{
		cout << p->val << " -> ";
		p = p->next;
	}
	cout << endl;
	p = c.addTwoNumbers(l1,l2);
	while(p != NULL)
	{
		cout << p->val << " -> ";
		p = p->next;
	}
	while(1);
	return 0;
}
