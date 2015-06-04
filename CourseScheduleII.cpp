#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
ԭ�⣺
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

������
��Course Schedule���ƣ�ֻ�����Ƿ���һ���������У��޷���������ֱ�ӷ�������

˼·��

1�������ڽӱ�洢ͼ
2����¼ÿ���ڵ�����
3������BFS����ͼ��ÿ�ҵ�һ�����Ϊ0�Ľڵ㣬��ȥ������ָ��������ڵ�ıߣ�
4���ɹ�����ÿһ���ڵ㣬�洢��ȷ��������

*/

class Solution {
public:
   vector<int > findOrder(int numCourses, vector<pair<int, int > >& prerequisites) {
		map<int, vector<int > > g; //���ù�ϣ�ṹ���洢�ڽӱ�
		vector<int > inDegree(numCourses, 0);
		vector<int > ans;
		for(int i = 0; i < prerequisites.size(); i++)
			g[prerequisites[i].second].push_back(prerequisites[i].first); //ע��pairԪ�ط����˳��
		for(map<int, vector<int > > :: iterator it = g.begin(); it != g.end(); it++)
			for(int i = 0; i < it->second.size(); i++) inDegree[it->second[i]]++;
		for(int i = 0; i < numCourses; i++) {
			int c = 0; 
			while(c < numCourses){ //�������Ϊ0�Ľڵ�
				if(inDegree[c] == 0) break;
				c++;
			}
			if(c == numCourses){ ans.clear(); return ans; } //δ�ҵ�˵���л�
			inDegree[c] = -1; //ȥ����ɨ��ڵ�
			ans.push_back(c);
			//ȥ�����Ϊ0�Ľڵ�ĺ�̱�
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
