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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode *p = head, *q;
        head = head->next;
        p->next = NULL;
        while(q != NULL)
        {
                q = head->next;
                head->next = p;
                p = head;
                head = q;
        }
        return p;
    }
};

int main()
{
  Solution c;
  int e[] = {1,2,3,4,5};
  ListNode *head,*s;
  head = NULL;
 // head = (ListNode *)malloc(sizeof(ListNode));
  for(int i = 0; i < sizeof(e)/4; i++)
  {
          s = (ListNode *)malloc(sizeof(ListNode));
          s->val = e[i];
          //if(i == 0){ head = s; continue;}
          s->next = head;
          head = s;
  }
  
  ListNode *p = head;
  while(p != NULL)
  {
          cout << p->val << " ";
          p = p->next;
  }
  printf("\n");
  
  p = c.reverseList(head);
  while(p != NULL)
  {
          cout << p->val << " ";
          p = p->next;
  }
  printf("\n");
 
  //cout << (c.isPalindrome1(s) ? "true" : "false") << endl;
  while(1);
  return 1;   
}
