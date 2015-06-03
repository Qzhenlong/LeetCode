#include<iostream>
using namespace std;

struct ListNode{
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) { }     
};
class Solution{
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *p, *q;
        p = q = head;
        while(p != NULL && q != NULL)
        {
            p = p->next;
            q = q->next;
            if(q == NULL) break;
            q = q->next;
            if((p == q) && p != NULL && q != NULL) return true; 
        }
        return false;
    }
}; 

int main()
{
    Solution c;
    ListNode *head;
    ListNode *p;
    int A[] = {1,2,3,5,6,8,9};
    for(int i = 0; i < sizeof(A)/4; i++)
    {
            ListNode *s = (ListNode*)malloc(sizeof(ListNode));
            s->val = A[i];
            if(i == 0){ head = s; p = head; }
            else{
                  p->next = s;
                  p = s;
            }    
    }
    p->next = NULL;

    cout << (c.hasCycle(head) ? "true" : "false") <<endl;
    while(1);
    return 0;
}
