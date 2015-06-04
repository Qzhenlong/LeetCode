#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
ԭ�⣺
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

������
һ����n����Ҫѡ��Ŀγ̣����Ϊ0��n-1����Щ�γ̿��ܻ������޿γ̣�������Ҫѡ��γ�0�����������ѡ���γ�1�����Ա���Ϊ��ԣ�[0,1]
�����γ�������һ�����޿γ���ԣ��ж��Ƿ�����������еĿγ̡�

˼·���ж�һ������ͼ���Ƿ���ڻ������ڻ����޷���ȫ���пγ̣�������ԡ�ͨ����������ʵ��
���壺������ͼ�У�ÿ���ҵ�һ��û��ǰ���ڵ�Ľڵ㣬Ȼ�����ָ�������ڵ�ı߶�ȥ�����ظ�������̣�BFS����
ֱ�����нڵ��ѱ��ҵ����������ͼ���л�����,��û�з��������Ľڵ㡣

1�������ڽӱ�洢ͼ
2����¼ÿ���ڵ�����
3������BFS����ͼ��ÿ�ҵ�һ�����Ϊ0�Ľڵ㣬��ȥ������ָ��������ڵ�ıߣ�
4���ɹ�����ÿһ���ڵ㣬�򷵻�true,���򷵻�false

*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int > >& prerequisites) {
		map<int, vector<int > > g; //���ù�ϣ�ṹ���洢�ڽӱ�
		vector<int > inDegree(numCourses, 0);
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
			if(c == numCourses) return false; //δ�ҵ�˵���л�
			inDegree[c] = -1; //ȥ����ɨ��ڵ�
			//ȥ�����Ϊ0�Ľڵ�ĺ�̱�
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
