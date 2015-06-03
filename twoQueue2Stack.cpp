#include<iostream>
#include<queue>
using namespace std;
/*
其中一个队列负责输出栈顶元素，即有一个队列一直为空，交替存入栈。
*/
class Solution{
public:
	Solution();
	~Solution();
	void _push(int e)
	{
		if(q1.empty()) q2.push(e);
		else q1.push(e);
	}
	bool _pop(int &e)  
	{
		if(q1.empty() && q2.empty()) return false;
		else if(q1.empty() && !q2.empty())
		{
			while(!q2.empty()){
				e = q2.front();
				q2.pop();
				if(!q2.empty()) q1.push(e);
			}
			return true;
		}
		else if(!q1.empty() && q2.empty())
		{
			while(!q1.empty()){
				e = q1.front();
				q1.pop();
				if(!q1.empty()) q2.push(e);
			}
			return true;
		}
		return false;
	}
private:
	queue<int > q1;
	queue<int > q2; 
};

int main()
{
	return 0;
}
