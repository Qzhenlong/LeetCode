#include<iostream>
#include<vector>
using namespace std;
/*
题目：Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

解析：归并k个有序的单链表，返回一个有序链表，分析其复杂度

思路：
（1）每次归并两个链表，进行k次归并后可完成，需要重复扫描多次,超时
（2）一次归并k个链表，每次找出最小结点， 复杂度O(k*n)，仍然超时
（3）自顶向下归并，与归并排序解法一样，至底向上归并，还是调用归并两个链表的算法，复杂度为O(nlogk)

*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    //超时
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *mergeHead = NULL;
		if(lists.size() == 0) return mergeHead;
		mergeHead = lists[0];
		for(int i = 1; i < lists.size(); i++){
			mergeHead = mergeTwoLists(mergeHead, lists[i]);
		}
		return mergeHead;
    }
	ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
		ListNode *l3 = NULL, *p = NULL;
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		while(l1 != NULL && l2 != NULL){
			if(l1->val < l2->val){
				if(l3 == NULL) l3 = p = l1;
				else{
					p->next = l1;
					p = l1;
				}
				l1 = l1->next;
			}
			else{
				if(l3 == NULL) l3 = p = l2;
				else{
					p->next = l2;
					p = l2;
				}
				l2 = l2->next;
			}
		}
		p->next = NULL;
		if(l1 != NULL) p->next = l1;
		else if(l2 != NULL) p->next = l2;
		else p->next = NULL;
		return l3;
	}
	//Still超时
    ListNode* _mergeKLists(vector<ListNode*>& lists) {
        ListNode *mergeHead = NULL, *p = NULL, *minp = NULL;
		int idx = -1;
		bool done = false;
		if(lists.size() == 0) return mergeHead;
		while(!done){
			done = true;
			for(int i = 0; i < lists.size(); i++){
				if(lists[i] != NULL){
					if(minp == NULL || minp->val > lists[i]->val){
						minp = lists[i];
						idx = i;
					}
					done = false;
				}
			}
			if(!done){
				lists[idx] = lists[idx]->next;
				if(p == NULL) mergeHead = p = minp;
				else{
					p->next = minp;
					p = minp;
				}
				minp = NULL;
			}
		}
		if(p != NULL) p->next = NULL;
		return mergeHead;
    }
//O(nlogk)
    ListNode* __mergeKLists(vector<ListNode*>& lists){
        if(lists.size()==0) return NULL;
        int sz = lists.size();
        int end = sz-1;
        while (end > 0) {
            int begin = 0;
            while (begin < end) {//一次归并两张链表，直到剩下一个链表为止
                lists[begin] = mergeTwoLists(lists[begin], lists[end]);
                ++begin;
                --end;
            }
        }
        return lists[0];
    }
};

int main(){
	Solution c;
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(3);
	l1->next->next = new ListNode(4);
	ListNode *l2 = new ListNode(4);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(8);
	ListNode *l3 = new ListNode(1);
	l3->next = new ListNode(7);
	l3->next->next = new ListNode(9);
	vector<ListNode* > list;
	list.push_back(l1);
	list.push_back(l2);
	list.push_back(l3);
	ListNode *p = c.__mergeKLists(list);
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}
