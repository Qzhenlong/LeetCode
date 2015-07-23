#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

解析：给定一个只包含数字的字符串，返回所有可能的IP地址组合

思路：
(1)超过12位就不可能构成有效的IP地址，就时往字符串中插入三个隔板，每个隔板内至少一个数字，至多3个数字，则每个隔板内的值不超过255,
   由于每个隔板内就3种情况，那么总共的可能种类不会超过81种，3^4=81,可以记录这81种组合，每次判断即可判断这些组合里满足条件的即可。
(2)相同的过程可以用深度优先搜索，递归实现
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string > ans;
		if(s.size() > 12) return ans;
		vector<vector<int > > com = getCom();
		for(int i = 0; i < com.size(); i++){
			string cur = "";
			if(com[i][0]+com[i][1]+com[i][2]+com[i][3] != s.size()) continue; //总长度不相等
			int step = 0, j = 0;
			for(j = 0; j < 4; j++){
				string tmp = s.substr(step, com[i][j]);
				if(string2int(tmp) > 255) break; //值大于255，不满足条件 
				if(tmp.size() > 1 && tmp[0] == '0') break;  //00，01这类字符串不符合
				if(j < 3) cur += (tmp + ".");
				else cur += tmp;
				step += com[i][j];
			}
			if(j == 4) ans.push_back(cur);
		}
		return ans;
    }
	//记录所有组合
	vector<vector<int > > getCom(){
		vector<int > cur;
		vector<vector<int > > com;
		for(int i = 1; i <= 3; i++)
			for(int j = 1; j <= 3; j++)
				for(int k = 1; k <= 3; k++)
					for(int l = 1; l <= 3; l++){
						cur.push_back(i); cur.push_back(j); cur.push_back(k); cur.push_back(l);
						com.push_back(cur); cur.clear();
					}
		return com;
	}
	int string2int(string s){
		int ans = 0;
		for(int i = 0; i < s.size(); i++)
			ans = ans*10 + (s[i]-'0');
		return ans;
	}
	vector<string> _restoreIpAddresses(string s) {
		vector<string > ans;
		if(s.size() > 12) return ans;
		string ip = "";
		dfs(ans, s, ip, 0, 0);
		return ans;
	}
	void dfs(vector<string > &ans, string s, string &ip, int i, int step){
		if(i == s.size() && step == 4){
			ans.push_back(ip);
			return;
		}
		for(int j = 1; j <= 3; j++){
			if(i+j > s.size()) continue;
			string tmp = s.substr(i, j);
			int len = ip.size();
			if(string2int(tmp) > 255) continue; //值大于255，不满足条件 
			if(tmp.size() > 1 && tmp[0] == '0') continue;  //00，01这类字符串不符合
			if(step < 3) ip += (tmp + ".");
			else ip += tmp;
			dfs(ans, s, ip, i+j, step+1);
			ip.erase(len, j+1); //回滚
		}	
	}
};

int main(){
	Solution c;
	vector<string > ans = c._restoreIpAddresses("11111");
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
