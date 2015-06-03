#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

struct ListNode{
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    void reorderList(ListNode* head) { //先拆后合 
        ListNode *headB, *p, *q, *s, *cur;
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        int n = 0, bound;
        p = head;
        while(p != NULL){ n++; p = p->next; } //计算总节点数
        bound = n / 2; //分界点
        p = head;
        for(int i = 0; i < bound; i++) p = p->next; 
        headB = p->next;
        p->next = NULL;
        //将链表B倒序
        s = headB->next;
        headB->next = NULL;
        while(s != NULL)
        {
                q = s->next;
                s->next = headB;
                headB = s;
                s = q;
        } 

        //重构链表,将headB插入head中 
        p = head; 
        q = headB;
        while(q != NULL)
        {
                headB = headB->next;
                q->next = p->next;
                p->next = q;
                p = q->next;
                q = headB;
        } 
    }

};

int main()
{
    ListNode *head;
    Solution c;
    int A[] = {4,3,2,1};
    for(int i = 0; i < sizeof(A)/4; i++)
    {
            ListNode *s = (ListNode*)malloc(sizeof(ListNode));
            s->val = A[i];
            if(i == 0){ head = s; head->next = NULL; }
            else
            {
                s->next = head;
                head = s;
            }  
            
    }
    ListNode *p = head;
    while(p != NULL) 
    {
            cout << p->val << " ";
            p = p->next;
    }
    cout << endl;
    c.reorderList(head);
    p = head;
   while(p != NULL) 
    {
            cout << p->val << " ";
            p = p->next;
    }
    cout << endl;
    while(1);
    return 0;
}
