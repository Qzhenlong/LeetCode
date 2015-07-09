#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
题目：
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

解析：使用栈实现队列，不能使用栈正常操作以外的用法。

思路：剑指Offer上的一个题目，使用两个栈可以实现队列操作，一个栈s1用于入队操作，一个栈s2用于出队操作，
	当出队栈s2空时，则将s1全部放入s2，两个栈都为空，则队列为空。
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
