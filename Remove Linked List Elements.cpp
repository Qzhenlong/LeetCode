#include <iostream>
#include <vector>
#include <string> 
#include <math.h>
using namespace std;

/**
 * Definition for singly-linked list.*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p, *q;
        while(head != NULL && head->val == val)
        {
                p = head;
                head = head->next;
                free(p);
                p = NULL;
        }
        if(head == NULL) return head;
        q = head;
        p = q->next;
        while(p != NULL)
        {
                if(p->val == val)
                {
                      q->next = p->next;
                      free(p);
                      p = NULL;
                      p = q->next;
                }
                else
                {
                    p = p->next;
                    q = q->next;
                }
        }
        return head;
    }
};
int main()
{
  Solution c;
  ListNode *headA;
  ListNode *s;
  int A[] = {6,6};

  int An = 2;
  headA = NULL;
  for(int i = 0; i < An; i++){
          s = (ListNode *)malloc(sizeof(ListNode));
          s->val = A[i];
          s->next = headA;
          headA = s;
          
  }
  ListNode *p = headA;
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  printf("\n");
  p = c.removeElements(headA, 6);
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  while(1);
  return 1;   
}
