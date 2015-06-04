#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
原题：
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

解析：
与Course Schedule相似，只不过是返回一种拓扑序列，无法完成完成则直接返回数组

思路：

1）采用邻接表存储图
2）记录每个节点的入度
3）采用BFS遍历图，每找到一个入度为0的节点，则去除它所指向的其它节点的边；
4）成功遍历每一个节点，存储正确拓扑序列

*/

class Solution {
public:
   vector<int > findOrder(int numCourses, vector<pair<int, int > >& prerequisites) {
		map<int, vector<int > > g; //采用哈希结构还存储邻接表
		vector<int > inDegree(numCourses, 0);
		vector<int > ans;
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
			if(c == numCourses){ ans.clear(); return ans; } //未找到说明有环
			inDegree[c] = -1; //去除已扫描节点
			ans.push_back(c);
			//去除入度为0的节点的后继边
			for(int j = 0; j < g[c].size(); j++) inDegree[g[c][j]]--;
		}
		return ans;
    }
};

int main()
{
	Solution c;
	vector<pair<int, int > > test;
	test.push_back(make_pair(1,0)); //[1,0],[2,0],[3,1],[3,2]
	test.push_back(make_pair(2,0));
	test.push_back(make_pair(3,1));
	test.push_back(make_pair(3,2));
	vector<int > ans = c.findOrder(4, test);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}
