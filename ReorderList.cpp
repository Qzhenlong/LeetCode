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
    void reorderList(ListNode* head) { //�Ȳ��� 
        ListNode *headB, *p, *q, *s, *cur;
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        int n = 0, bound;
        p = head;
        while(p != NULL){ n++; p = p->next; } //�����ܽڵ���
        bound = n / 2; //�ֽ��
        p = head;
        for(int i = 0; i < bound; i++) p = p->next; 
        headB = p->next;
        p->next = NULL;
        //������B����
        s = headB->next;
        headB->next = NULL;
        while(s != NULL)
        {
                q = s->next;
                s->next = headB;
                headB = s;
                s = q;
        } 

        //�ع�����,��headB����head�� 
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
