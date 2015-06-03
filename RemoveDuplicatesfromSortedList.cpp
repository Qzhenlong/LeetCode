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
    ListNode* deleteDuplicates(ListNode* head) {
        int curVal;
        if(head == NULL) return head;
        ListNode *p, *q;
        p = head;
        q = p->next;
        curVal = p->val;
        while(q != NULL)
        {
                if(curVal == q->val){
                     p->next = q->next;
                     ListNode *tmp = q;
                     free(tmp);
                     q = p->next;
                }
                else{
                     curVal = q->val;
                     p = q;
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
  int A[] = {6,1};

  int An = 2;
  headA = NULL;
  for(int i = 0; i < sizeof(A)/4; i++){
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
  p = c.deleteDuplicates(headA);
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  while(1);
  return 1;   
}
