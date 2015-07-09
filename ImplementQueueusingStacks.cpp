#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��Ŀ��
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

������ʹ��ջʵ�ֶ��У�����ʹ��ջ��������������÷���

˼·����ָOffer�ϵ�һ����Ŀ��ʹ������ջ����ʵ�ֶ��в�����һ��ջs1������Ӳ�����һ��ջs2���ڳ��Ӳ�����
	������ջs2��ʱ����s1ȫ������s2������ջ��Ϊ�գ������Ϊ�ա�
*/

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!s2.empty()) s2.pop();
		else{
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			if(!s2.empty()) return s2.pop();
		}
    }

    // Get the front element.
    int peek(void) {
        if(!s2.empty()) return s2.top();
		else{
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			if(!s2.empty()) return s2.top();
		}
		return -1;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
private:
	stack<int > s1;
	stack<int > s2;
};

int main(){
	Queue q;
	q.push(2);
	q.push(3);
	cout << q.peek() << endl;
	q.pop();
	cout << q.peek() << endl;
	q.pop();
	cout << q.empty() << endl;
}
