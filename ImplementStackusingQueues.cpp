#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
ԭ�⣺
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

������ͨ������ʵ��ջ�Ļ���������ֻ��ʹ�ö��еĻ���������

˼·����ָoffer�ϵ�һ����Ŀ����ϸ��һ�¿�֪��һ�����в�����ʵ��ջ�����л��������������������м�����Ϊq1��q2, ���ڽ�ջ��һ����ջ������һ�»�������:
����ջ�����²�����a,b,c��ջ�����γ�ջ, d��ջ
��1��a,b,c����q1, c->b->a; 
��2��a�ڶ��ף�cҪ��ջ���ð�a,b���ߣ���a,b��q2, cΪq1���ף��ɳ�ջ
��3��bҪ��ջ��a���q1�� b��ջ
��4��d��ջ����һ���ǿյĶӽ��뼴�ɣ�q1,q2���գ������⡣

�ɵó����ۣ�ÿ�β��������󣬶�������һ���նӣ����ڳ�ջ����������ջֱ�ӽ��ǿն��м���
*/

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
		if(q1.empty()) q2.push(x); //�ҷǿն��н�
		else q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q1.empty() && q2.empty()) return; //ջ��
		if(q1.empty()){ //��q2Ԫ��ȫ������q1
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
        if(q1.empty() && q2.empty()) return ans; //ջ��
		if(q1.empty()){ //��q2Ԫ��ȫ������q1
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

