#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
/*
��Ŀ��
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.

����������������start��end,��һ���ʵ䣬�ҳ���start�任��end�����ת�����ȣ�ÿ��ֻ�ܱ任һ�����ʣ�
	  �����������ת��·���ϵ���
	  
˼·��
��1��������ȱ���,  Time Limit Exceeded
��2��������ȱ���
*/

class Solution {
public:
    //������ȱ����ɽ⣬�� Time Limit Exceeded
    vector<vector<string > > findLadders(string start, string end, set<string> &dict) {
        int minLen = 0;
		vector<string > path;
		vector<vector<string > > ans;
		set<string > dfs_visited;
		if(start.size() != end.size() || start.compare(end) == 0) return ans;
		path.push_back(start);
		dfs(minLen, start, end, 1, dict, dfs_visited, path, ans);
		vector<vector<string > > res;
		for(int i = 0; i < ans.size(); i++)
			if(ans[i].size() == minLen) res.push_back(ans[i]);
		return res;
	}
	void dfs(int &minLen, string word, string endword, int curLen, set<string >& wordDict, set<string > &dfs_visited, vector<string > &path, vector<vector<string > > &ans){
		for(int i = 0; i < word.size(); i++){
			for(char c = 'a'; c <= 'z'; c++){
				string tmp = word;
				if(tmp[i] == c) continue;
				tmp[i] = c;				
				if(tmp.compare(endword) == 0){
					path.push_back(tmp);
					ans.push_back(path);
					minLen = (minLen > curLen+1 || minLen == 0) ? curLen+1 : minLen;
					path.pop_back();
					continue;
				}
				else if(dfs_visited.find(tmp) == dfs_visited.end() && wordDict.find(tmp) != wordDict.end()){
				    dfs_visited.insert(tmp);
					path.push_back(tmp);
					dfs(minLen, tmp, endword, curLen+1, wordDict, dfs_visited, path, ans);
					path.pop_back();
					dfs_visited.erase(tmp);
				}
			}
		}
	}
	//������ȱ�����ÿ��Ӧ�ü�¼ǰ��,Memory Limit Exceeded
    vector<vector<string > > _findLadders(string start, string end, set<string> &dict) {
		vector<string > path;
		vector<vector<string > > ans;
		set<string > visited;
		map<string, vector<string> > prev; //��¼ǰ��
		queue<string > q;
		int minLen = 0, curMin = 1, levelcount = 1; //levelcount��ʾ�������һ�������������ַ�����
		if(start.size() != end.size() || start.compare(end) == 0) return ans;
		q.push(start);
		while(!q.empty()){
			string cur = q.front();
			q.pop(); levelcount--;
			for(int i = 0; i < cur.size(); i++){
				for(char c = 'a'; c <= 'z'; c++){
					string tmp = cur;
					if(tmp[i] == c) continue;
					tmp[i] = c;
					if(tmp.compare(end) == 0){
						if(minLen == 0) minLen = curMin;
						prev[tmp].push_back(cur);
						continue;
					}
					else if(visited.find(tmp) == visited.end() && dict.find(tmp) != dict.end()){
						prev[tmp].push_back(cur); //��¼ǰ��
						q.push(tmp); 
						visited.insert(tmp);
					}
				}
			}
			if(levelcount == 0){
				curMin++;
				levelcount = q.size();
				if(minLen != 0) break; //������ж�����һ�㣬���Խ���������
			}
		}
		//ͨ��ǰ����������·��
		if(minLen > 0){
			path.push_back(end);
			dfs_scan(path, ans, start, end, prev);
		}
		return ans;
	}
	void dfs_scan(vector<string > &path, vector<vector<string > > &ans, string start, string cur, map<string, vector<string> > prev){
		if(start.compare(cur) == 0){
			reverse(path.begin(), path.end());
			ans.push_back(path);
			reverse(path.begin(), path.end());
			return;
		}
		for(int i = 0; i < prev[cur].size(); i++){
			 path.push_back(prev[cur][i]);
			 dfs_scan(path, ans, start, prev[cur][i], prev);
			 path.pop_back();
		}
	}
};

int main(){
	Solution c;
	set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	vector<vector<string > > ans = c._findLadders("hit", "cog", dict);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}

