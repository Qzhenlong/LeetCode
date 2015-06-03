#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL){}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      
        ListNode *l3, *p,*q,*s;
        int i=0;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        l3 = NULL;
        
        while(l1 != NULL && l2 != NULL)
        {
                if(l1->val < l2->val){ p = l1; l1 = l1->next; }
                else  { p = l2; l2 = l2->next;}
              
                if(l3 == NULL){ l3 = p; q = l3; }
                else{ q->next = p; q = p;    }   

        } 
    

        if(l1 != NULL) q->next = l1;
        else if(l2 != NULL) q->next = l2;
        else q->next = NULL;

      
        return l3;
        
      /*       s = p;
        while(p != NULL && q != NULL)
        {
                while((p->val < q->val) && p != NULL)
                {
                              s = p; 
                              p = p->next;
                              cout << s->val << endl;
                }
                //while(1);
                if(p == NULL){ s->next = q; break;}
                
                l2 = l2->next;
                q->next = s->next;
                s->next = q;
            
                s = q; 
                q = l2;
        } 

        return l1;
*/
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        /*
        if (l1 == NULL)
            return l2;
            
        if (l2 == NULL)
            return l1;
            
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *head = NULL;
        ListNode *curNode = NULL;
        
        while(p && q)
        {
            if (head == NULL)
            {
                if (p->val < q->val)
                {
                    head = curNode = p;
                    p = p->next;
                    curNode->next = NULL;
                }
                else
                {
                    head = curNode = q;
                    q = q->next;
                    curNode->next = NULL;
                }
            }
            else
            {
                if (p->val < q->val)
                {
                    curNode->next = p;
                    curNode = p;
                    p = p->next;
                    curNode->next = NULL;
                }
                else
                {
                    curNode->next = q;
                    curNode = q;
                    q = q->next;
                    curNode->next = NULL;
                }
            }
        }
        
        if (p)
            curNode->next = p;
        else if (q)
            curNode->next = q;
            
        return head; 
*/
    }
};

int main()
{
  Solution c;
  ListNode *headA,*headB;
  ListNode *s;
  int A[] = {4,3,2,1};

  int An = 2;
  headA = NULL;
  headB = NULL;
  for(int i = 0; i < sizeof(A)/4; i++){
          s = (ListNode *)malloc(sizeof(ListNode));
          s->val = A[i];
          s->next = headA;
          headA = s;  
  }
    for(int i = 0; i < sizeof(A)/4; i++){
          s = (ListNode *)malloc(sizeof(ListNode));
          s->val = A[i];
          s->next = headB;
          headB = s;     
  }
  ListNode *p = headA;
  ListNode *q = headB;
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  while(q != NULL){
          cout << q->val << " ";
          q = q->next;
  }
  
  printf("\n");
  p = c.mergeTwoLists(headA,headB);
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  
  while(1);
  return 1;   
}
