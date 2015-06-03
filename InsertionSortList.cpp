#include<stdio.h>
#include<iostream>
using namespace std;

struct ListNode{
       int val;
       ListNode* next;
       ListNode(int x) : val(x), next(NULL) { }
};

class Solution{
  public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p, *q, *s;
        s = q = head->next;
        head->next = NULL;
        p = head;
        
        while(s != NULL)
        {
               q = s->next;
               ListNode *pre = p;
               while(p != NULL && p->val < s->val){
                             pre = p;
                             p = p->next;
               }  
               s->next = p;
               if(p == head) head = s; //¿¼ÂÇ±ß½ç 
               else pre->next = s;
               
               p = head;
               s = q;
        } 
        return head;
    }    
};

int main()
{
    Solution c;
    ListNode *head;
    int A[] = {2,4,3};
    for(int i = 0; i < sizeof(A)/4; i++)
    {
            ListNode *s = (ListNode *) malloc(sizeof(ListNode));
            s->val = A[i];
            if(i == 0){head = s; head->next = NULL;}
            else{
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
    p = c.insertionSortList(head);
    while(p != NULL)
    {
            cout << p->val << " ";
            p = p->next;
    }
    while(1);
    return 0;
}
