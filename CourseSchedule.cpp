#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
原题：
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

解析：
一共有n门需要选择的课程，标号为0到n-1。有些课程可能会有先修课程，例如想要选择课程0，你必须首先选过课程1，可以表述为配对：[0,1]
给定课程总数和一组先修课程配对，判断是否可以修完所有的课程。

思路：判断一个有向图中是否存在环，存在环则无法完全所有课程，否则可以。通过拓扑排序实现
定义：在有向图中，每次找到一个没有前驱节点的节点，然后把它指向其他节点的边都去掉，重复这个过程（BFS），
直到所有节点已被找到，或者如果图中有环存在,则没有符合条件的节点。

1）采用邻接表存储图
2）记录每个节点的入度
3）采用BFS遍历图，每找到一个入度为0的节点，则去除它所指向的其它节点的边；
4）成功遍历每一个节点，则返回true,否则返回false

*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int > >& prerequisites) {
		map<int, vector<int > > g; //采用哈希结构还存储邻接表
		vector<int > inDegree(numCourses, 0);
		for(int i = 0; i < prerequisites.size(); i++)
			g[prerequisites[i].second].push_back(prerequisites[i].first); //注意pair元素放入的顺序
		for(map<int, vector<int > > :: iterator it = g.begin(); it != g.end(); it++)
			for(int i = 0; i < it->second.size(); i++) inDegree[it->second[i]]++;
		for(int i = 0; i < numCourses; i++) {
			int c = 0; 
			while(c < numCourses){ //查找入度为0的节点
				if(inDegree[c] == 0) break;
				c++;
			}
			if(c == numCourses) return false; //未找到说明有环
			inDegree[c] = -1; //去除已扫描节点
			//去除入度为0的节点的后继边
			for(int j = 0; j < g[c].size(); j++) inDegree[g[c][j]]--;
		}
		return true;
    }
};

int main()
{
	Solution c;
	vector<pair<int, int > > test;
//	test.push_back(make_pair(1,0));
//	test.push_back(make_pair(0,1));
	cout << c.canFinish(1, test);
	return 0;
}
