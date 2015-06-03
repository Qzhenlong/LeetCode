#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
Sort a linked list in O(n log n) time using constant space complexity.
思路：考虑使用快速排序(较为复杂）或者归并排序(较易）
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	ListNode* sortList(ListNode* head)
	{
		if(head == NULL || head->next == NULL) return head;
		ListNode *slow = head, *fast = head; //快慢指针，快速找到中点（重要）
		while(fast->next != NULL && fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = NULL;
		
		ListNode *l1 = sortList(head);
		ListNode *l2 = sortList(fast);
		
		return Merge(l1,l2);
	}
	ListNode* Merge(ListNode *l1, ListNode *l2)
	{
		ListNode *ml = NULL;
		ListNode *p = ml;
		while(l1 != NULL && l2 != NULL)
		{
			if(l1->val < l2->val)
			{
				if(ml == NULL){ ml = l1; p = ml; }
				else { p->next = l1; p = l1; }
				l1 = l1->next;
			}
			else
			{
				if(ml == NULL){ ml = l2; p = ml; }
				else { p->next = l2; p = l2; }
				l2 = l2->next;
			}
		}
		while(l1 != NULL)
		{
			if(ml == NULL){ ml = l1; p = ml; }
			else { p->next = l1; p = l1; }
			l1 = l1->next;	
		}
		while(l2 != NULL)
		{
			if(ml == NULL){ ml = l2; p = ml; }
			else { p->next = l2; p = l2; }
			l2 = l2->next;		
		}
		//p->next = NULL;
		return ml;
	}
/*
    ListNode* sortList1(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;
		stack<ListNode* > ls;
		ListNode *low, *high, *mid, *p;
		low = head;
		p = head;
		while(p != NULL){ high = p; p = p->next;}
		//找出最小元素确定链表头节点
		ListNode *mid_pre = partition(NULL, low, high, NULL);
		mid = mid_pre->next;
		ls.push(NULL); //low的前指针 
		ls.push(low);
		ls.push(mid_pre);
		ls.push(mid); //high的后指针
		if(mid->next != NULL){
			ls.push(mid);
			ls.push(mid->next); 
			ls.push(high);
			ls.push(NULL);}
		while(!ls.empty())
		{
			ListNode *hn = ls.top(); ls.pop();
			ListNode *h  = ls.top(); ls.pop();
			ListNode *l = ls.top(); ls.pop();
			ListNode *lp  = ls.top(); ls.pop();
			ListNode *mp = partition(lp, l, h, hn);
			ListNode *m = mp->next;
			if(mp != l  &&  mp != NULL)
			{
				ls.push(lp); ls.push(l); ls.push(mp); ls.push(mp->next);
			}
			if(mp != NULL && m != NULL && m->next != NULL && m->next != h)
			{
				ls.push(m); ls.push(m->next); ls.push(h); ls.push(hn);
			}
			if(ls.empty()) head = l;
		}
		return head;
    }
	ListNode* partition(ListNode* &low_pre, ListNode* &low, ListNode* &high, ListNode* &high_next)
	{
		ListNode *mid = low, *tlow = mid, *thigh = mid, *mid_pre=NULL, *q = NULL;
		low = low->next; q = low;
		while(q != high && low != NULL)
		{
			q = low;
			low = low->next;
			if(q->val <= mid->val)
			{
				q->next = mid;
				if(mid_pre == NULL){ mid_pre = q; tlow = q; } //尾插法，tlow记录前半截链表头，mid_pre记录前半截链表尾
				else{ mid_pre->next = q; mid_pre = q; }
				mid->next = low;
			}
			else thigh = q;
		}
		low = tlow; 
		if(low_pre != NULL) low_pre->next = low;
		high = thigh; 
		high->next = high_next;
		return mid_pre;
	}	
	*/
};

int main()
{
	Solution c;
	int A[] = {1,2,-3,10};
	ListNode *head = NULL;
	for(int i = 0; i < sizeof(A)/4; i++)
	{
		ListNode *s = (ListNode *)malloc(sizeof(ListNode));
		s->val = A[i];
		s->next = head;
		head = s;
	}
	ListNode *p = head;
	while(p != NULL)
	{
		cout<< p->val << " ";
		p = p->next;
	}
	cout << endl;
	p = c.sortList(head);
	while(p != NULL)
	{
		cout<< p->val << " ";
		p = p->next;
	}	
	while(1);
	return 0;
}

