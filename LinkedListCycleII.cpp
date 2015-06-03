#include<iostream>
using namespace std;

struct ListNode{
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) { }
};
/*
解释：假设起点到环起点的距离为X, 环起点距离相遇点为K，环的长度为Y，单步指针走的距离为t,双步指针走2t
则：
t = X + nY + K;
2t = X + mY + K;
联立：
X = （m-2n)Y - K;
那么相遇后单步指针到起点，开始走X步，双步指针从相遇点开始走X(单步走），必在环起点处相遇 
*/
class Solution{
public:
   ListNode *detectCycle(ListNode *head) {
        ListNode *p, *q, *meet;
        int counter = 0;
        if(head == NULL || head->next == NULL) return NULL;
        p = q = head; 
        meet = NULL;
        while( p != NULL && q != NULL)
        {
               p = p->next;
               q = q->next;
               if(q == NULL) break;
               q = q->next;
               if((p == q) && p != NULL && q != NULL)
               {
                     cout << p->val << endl;
                     p = head; 
                     counter++;

               }
               if(counter == 1){
                   while(p != q)
                   {
                         p = p->next;
                         q = q->next;
                   } 
                   meet = p;
                   break;
               }
        }
        return meet;
    }
};

int main()
{
    Solution c;
    int A[] = {1,2,3,4};
    ListNode *head,*p;
    for(int i = 0; i < sizeof(A)/4; i++)
    {
         ListNode *s = (ListNode *)malloc(sizeof(ListNode));
         s->val = A[i];
         if(i == 0) { head =  s; p = head; }
         else{
              p->next = s;
              p = s;
         } 
    }
    ListNode *q = head->next;
    p->next = q;
    p = head;
     for(int i = 0; i < sizeof(A)/2; i++)
    {
           // cout << p->val << " ";
            p = p->next;
    }
    
    p = c.detectCycle(head);
    cout << p->val << endl;
    while(1);
    return 0;
}
