#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
原题：
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

解析：通过队列实现栈的基本操作，只能使用队列的基本操作。

思路：剑指offer上的一道题目，仔细想一下可知用一个队列不可能实现栈的所有基本操作，采用两个队列即，记为q1和q2, 用于进栈，一个出栈，分析一下基本过程:
假设栈有如下操作，a,b,c进栈，两次出栈, d进栈
（1）a,b,c进入q1, c->b->a; 
（2）a在队首，c要出栈，得把a,b移走，则a,b入q2, c为q1队首，可出栈
（3）b要出栈，a入队q1， b出栈
（4）d进栈，找一个非空的队进入即可，q1,q2都空，则随意。

可得出结论，每次操作结束后，都至少有一个空队，用于出栈缓冲区，进栈直接进非空队列即可
*/

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
		if(q1.empty()) q2.push(x); //找非空队列进
		else q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q1.empty() && q2.empty()) return; //栈空
		if(q1.empty()){ //将q2元素全部移入q1
			while(!q2.empty()){
				if(q2.size() == 1){ q2.pop(); break; }
				q1.push(q2.front());
				q2.pop();
			}
		}
		else{
			while(!q1.empty()){
				if(q1.size() == 1){ q1.pop(); break; }
				q2.push(q1.front());
				q1.pop();
			}
		}
    }

    // Get the top element.
    int top() {
		int ans = -1;
        if(q1.empty() && q2.empty()) return ans; //栈空
		if(q1.empty()){ //将q2元素全部移入q1
			while(!q2.empty()){
				ans = q2.front();
				q1.push(q2.front());
				q2.pop();
			}
		}
		else{
			while(!q1.empty()){
				ans = q1.front();
				q2.push(q1.front());
				q1.pop();
			}
		}
		return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return (q1.empty() && q2.empty());
    }
private:
	queue<int > q1;
	queue<int > q2;
};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.push(4);
	cout << s.top() << endl;
	cout << s.empty() <<endl;
}

