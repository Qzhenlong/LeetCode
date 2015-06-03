#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;
/*
题目：复制一张无向图
我的思路：
1）先统计无向图中所有结点数量，然后重新创建各节点,(需要遍历无向图，使用栈进行深度优先遍历）
2) 通过一个哈希表来记录原图节点与新图节点的对应关系
3）根据原图及哈希表，将连接关系复制。
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
		map<UndirectedGraphNode *, bool > visited; //标记节点是否访问过
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
			UndirectedGraphNode * newNode = new UndirectedGraphNode(it->first->label); //用new关键字，用malloc无法正常分配vector空间
			//先创建新节点，再生成相邻节点向量
			M[it->first] = newNode; //构建新表
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
	cout << newNode0->neighbors.size() << endl;  //Output: 0 //用new关键字输出正常
    cout << newNode1->neighbors.size() << endl;  //Output: 193186655
	//newNode1->label = 1;
	//newNode2->label = 2;
	//newNode1->neighbors.push_back(newNode0); newNode1->neighbors.push_back(newNode2);
	//newNode0->neighbors.push_back(newNode1); newNode0->neighbors.push_back(newNode2);
	//newNode2->neighbors.push_back(newNode0); newNode2->neighbors.push_back(newNode1);newNode2->neighbors.push_back(newNode2);
	c.cloneGraph(newNode0);

	return 0;
}
