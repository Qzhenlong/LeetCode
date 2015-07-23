#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

�������鲢k������ĵ���������һ���������������临�Ӷ�

˼·��
��1��ÿ�ι鲢������������k�ι鲢�����ɣ���Ҫ�ظ�ɨ����,��ʱ
��2��һ�ι鲢k������ÿ���ҳ���С��㣬 ���Ӷ�O(k*n)����Ȼ��ʱ
��3���Զ����¹鲢����鲢����ⷨһ�����������Ϲ鲢�����ǵ��ù鲢����������㷨�����Ӷ�ΪO(nlogk)

*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    //��ʱ
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
	//Still��ʱ
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
            while (begin < end) {//һ�ι鲢��������ֱ��ʣ��һ������Ϊֹ
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
