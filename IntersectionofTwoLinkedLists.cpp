#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef struct Node
{
        int value;
        struct Node *next;
}ListNode;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       // if(headA == NULL || headB == NULL || headA->next == NULL || headB->next == NULL) return NULL;
       if(headA == NULL || headB == NULL) return NULL;
        ListNode *p, *pp, *q, *pq;
        int AN=1, BN=1;
        //pp = headA->next;
        pp = headA;
        p = pp->next;
        //pq = headB->next;
        pq = headB;
        q = pq->next;
        while(p != NULL){pp = pp->next; p = p->next; AN++; }
        while(q != NULL){pq = pq->next; q = q->next; BN++;}
        if(pp != pq) return NULL; //终点不等，则不相交
        int div = AN - BN;
       // p = headA->next;
       // q = headB->next; //无头指针 
        p = headA;
        q = headB;
        if(div > 0) 
               for(int i = 0; i < div; i++) p = p->next;
        else   for(int i = 0; i < abs(div); i++) q = q->next;
        while(p != q){p = p->next; q = q->next;}
        
        return p;
    }
};
int main()
{
  Solution c;
  int num;
  ListNode *headA = (ListNode *)malloc(sizeof(ListNode));
  ListNode *headB = (ListNode *)malloc(sizeof(ListNode));
  ListNode *s,*p,*q, *x,*y;
  int A[] = {1,2,3,4,5,6};
  int B[] = {2,6,4,5};
  int C[] = {4,3,34,52};
  int An = -1, Bn = -1, Cn = 1;
  /*headA->next = NULL;
  headB->next = NULL;
  
  for(int i = 0; i < An; i++){
          s = (ListNode *)malloc(sizeof(ListNode));
          s->value = A[i];
          s->next = headA->next;
          headA->next = s;
  }
  for(int i = 0; i < Bn; i++){
          s = (ListNode *)malloc(sizeof(ListNode));
          s->value = B[i];
          s->next = headB->next;
          headB->next = s;
  }
  p = headA->next;
  q = headB->next;
  for(int i = 0; i < An-1; i++){
          cout << p->value << " ";
          p = p->next;
  }
  printf("\n");
  for(int i = 0; i < Bn-1; i++){ 
          cout << q->value << " ";
          q = q->next;
  }*/
  p = headA;
  q = headB;
  for(int i = 0; i < Cn; i++){
          s = (ListNode *)malloc(sizeof(ListNode));
          s->value = C[i];
          p->next = s;
          p = s;
          q->next = s;
          q = s;
  }
  p->next = NULL;
  q->next = NULL;
  
  p = headA->next;
  q = headB->next;
  printf("\nIntersecting:\n");
  while(p != NULL){
          cout << p->value << " ";
          p = p->next;
  }
  printf("\n");
  while(q != NULL){ 
          cout << q->value << " ";
          q = q->next;
  }
  printf("\nIntersection Node:\n");
  p = c.getIntersectionNode(headA,headB);
  cout<< p->value << endl;
  while(1);
  return 1;   
}
