#include<iostream>
#include<stack>
using namespace std;
/*
s2负责输出队首，不为空即可输出,为空则将s1所有元素导入s2
s1负责入队
*/
class Solution{
public:
	Solution();
	~Solution();
	void appendTail(int e)
	{
		s1.push(e);
	}
	bool deleteHead(int &e)  
	{
		if(!s2.empty())
		{
			e = s2.top();
			s2.pop();
			return true;
		}
		else
		{
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			if(!s2.empty())
			{
				e = s2.top();
				s2.pop();
				return true;
			}
		}
		return false;
	}
private:
	stack<int > s1;
	stack<int > s2; 
};

int main()
{
	return 0;
}
