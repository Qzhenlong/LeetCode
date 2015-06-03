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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prior, *ahead, *cur;
        if(head == NULL) return head;
        cur = head;
        prior = cur;
        ahead = head;
        for(int i = 0; i < n; i++)
                ahead = ahead->next;
        if(ahead == NULL){head = head->next; free(cur); return head;}  //Important
        while(ahead != NULL)
        {
                    ahead = ahead->next;
                    prior = cur;
                    cur = cur->next;
        }
        prior->next = cur->next;
        free(cur);
        return head;
    }
};

int main()
{
  Solution c;
  int e[] = {5};
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
  
  p = c.removeNthFromEnd(head, 1);
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
