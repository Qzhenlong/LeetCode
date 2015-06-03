#include<iostream>
using namespace std;

struct ListNode{
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) { }
};
/*
���ͣ�������㵽�����ľ���ΪX, ��������������ΪK�����ĳ���ΪY������ָ���ߵľ���Ϊt,˫��ָ����2t
��
t = X + nY + K;
2t = X + mY + K;
������
X = ��m-2n)Y - K;
��ô�����󵥲�ָ�뵽��㣬��ʼ��X����˫��ָ��������㿪ʼ��X(�����ߣ������ڻ���㴦���� 
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
