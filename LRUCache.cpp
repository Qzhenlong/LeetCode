#include<iostream>
#include<map>
#include<vector> 
using namespace std;
/*
����+��ϣ��
����Cache��СΪ5���������У�4��7��0��7��1��0��1��2��1��2��6
4
4-7
4-7-0
4-0-7
4-0-7-1
4-7-1-0
4-7-0-1
4-7-0-1-2
7-0-1-2-6
ʹ��˫����������¼���Ϲ��̣�ͷָ���ʾ�����Ԫ�أ�βָ��ָ��������ù���Ԫ�أ�
ʹ�ù�ϣ�����cache���ݣ�key����Ӧ�ڵ�
��ѯ������ʱ���ڵ�ŵ�����β��ע��߽����
���룺
1���ռ�δ����Ԫ�ش��ڣ�����ȡֵ�������ڵ�ŵ�����β;
2���ռ�δ���ҹ�Ԫ�ز����ڣ���Ԫ�طŵ�����β���������ϣ��ע��߽������
3���ռ�������Ԫ�ش��ڣ���1����ͬ
4���ռ�������Ԫ�ز����ڣ���������ͷָ����Ϣ�������ڵ�ŵ�����β��
*/
struct LRU_ListNode{
	int val;
	int key;
	LRU_ListNode *prior;
	LRU_ListNode *next;
};
class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
		used = 0;
    }
    void insert(LRU_ListNode* &p)
	{
		if(p == LRU_T || LRU_T == LRU_H) return;
		if(p == LRU_H){
		    LRU_H = p->next;
			p->next->prior = LRU_H;
			LRU_T->next = p;
			p->prior = LRU_T;
			p->next = NULL;
			LRU_T = p;
		}
		else{
			p->prior->next = p->next;
			p->next->prior = p->prior;
			LRU_T->next = p;
			p->prior = LRU_T;
			LRU_T = p;
		}
	}
    int get(int key) {
        if(!isExist(key)) return -1;
        else{
		    LRU_ListNode *p = cache[key];
            insert(p);
			return cache[key]->val;
        }
    }
    
    void set(int key, int value) {
		if(used < cap){
		    if(isExist(key)){
				LRU_ListNode *p = cache[key];
				p->val = value;
				insert(p);
			}
			else{
				LRU_ListNode *s = (LRU_ListNode *)malloc(sizeof(LRU_ListNode));
				s->key = key;
				s->val = value;
				if(used == 0) LRU_H = LRU_T = s;
				else{
					LRU_T->next = s;
					s->prior = LRU_T;
					LRU_T = s;
				}
				cache[key] = s;
				used++;
			}
		}
		else{
			if(isExist(key)){
				LRU_ListNode *p = cache[key];
				p->val = value;
				insert(p);				
			}
			else{
				LRU_ListNode *p = LRU_H;
				map<int, LRU_ListNode*>::iterator m_it;
				m_it = cache.find(p->key);
				cache.erase(m_it);
				p->key = key;
				p->val = value;
				insert(p);
				cache[key] = p;
			}
		}
    }
    
    bool isExist(int key)
    {
        return ( cache.find(key) != cache.end() );
    }
private:
    int cap;
    int used;
    map<int, LRU_ListNode*> cache;
	LRU_ListNode* LRU_H; //ͷ����¼�����Ԫ��
	LRU_ListNode* LRU_T; //β
	
}; 

int main()
{
    LRUCache c(2);   
    c.set(2,1);
    c.set(2,2);
    cout << c.get(2) << " ";
    c.set(1,1);
    c.set(4,1);
    cout << c.get(2) << " ";
    while(1);
    return 0;
}
