#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;
/*
��Ŀ������һ������ͼ
�ҵ�˼·��
1����ͳ������ͼ�����н��������Ȼ�����´������ڵ�,(��Ҫ��������ͼ��ʹ��ջ����������ȱ�����
2) ͨ��һ����ϣ������¼ԭͼ�ڵ�����ͼ�ڵ�Ķ�Ӧ��ϵ
3������ԭͼ����ϣ�������ӹ�ϵ���ơ�
*/
/**
 * Definition for undirected graph.*/
struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == NULL) return NULL;
		map<UndirectedGraphNode *, UndirectedGraphNode * > M;
		map<UndirectedGraphNode *, bool > visited; //��ǽڵ��Ƿ���ʹ�
		stack<UndirectedGraphNode * > s;
		s.push(node);
		visited[node] = true;
		while(!s.empty())
		{
			UndirectedGraphNode * cur = s.top();
			s.pop();
			for(int i = 0; i < cur->neighbors.size(); i++)
			{
				if(visited.find(cur->neighbors[i]) == visited.end()){
					s.push(cur->neighbors[i]);
					visited[cur->neighbors[i]] = true;
				}
			}
		}
		for(map<UndirectedGraphNode *, bool >::iterator it = visited.begin(); it != visited.end(); it++)
		{
			//UndirectedGraphNode * newNode = (UndirectedGraphNode *)malloc(sizeof(UndirectedGraphNode));
			UndirectedGraphNode * newNode = new UndirectedGraphNode(it->first->label); //��new�ؼ��֣���malloc�޷���������vector�ռ�
			//�ȴ����½ڵ㣬���������ڽڵ�����
			M[it->first] = newNode; //�����±�
		}
		for(map<UndirectedGraphNode *, bool >::iterator it = visited.begin(); it != visited.end(); it++)
		{
			for(int i = 0; i < it->first->neighbors.size(); i++)
				M[it->first]->neighbors.push_back(M[it->first->neighbors[i]]);
		}
		return M[node];
    }
};

int main()
{
	Solution c;
	UndirectedGraphNode * newNode0 = new UndirectedGraphNode(-1);
	UndirectedGraphNode * newNode1 = (UndirectedGraphNode *)malloc(sizeof(UndirectedGraphNode));
    newNode1->label = -1;
	cout << newNode0->neighbors.size() << endl;  //Output: 0 //��new�ؼ����������
    cout << newNode1->neighbors.size() << endl;  //Output: 193186655
	//newNode1->label = 1;
	//newNode2->label = 2;
	//newNode1->neighbors.push_back(newNode0); newNode1->neighbors.push_back(newNode2);
	//newNode0->neighbors.push_back(newNode1); newNode0->neighbors.push_back(newNode2);
	//newNode2->neighbors.push_back(newNode0); newNode2->neighbors.push_back(newNode1);newNode2->neighbors.push_back(newNode2);
	c.cloneGraph(newNode0);

	return 0;
}
