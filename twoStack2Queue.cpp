#include<iostream>
#include<stack>
using namespace std;
/*
s2����������ף���Ϊ�ռ������,Ϊ����s1����Ԫ�ص���s2
s1�������
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
