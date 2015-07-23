#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

����������һ��ֻ�������ֵ��ַ������������п��ܵ�IP��ַ���

˼·��
(1)����12λ�Ͳ����ܹ�����Ч��IP��ַ����ʱ���ַ����в����������壬ÿ������������һ�����֣�����3�����֣���ÿ�������ڵ�ֵ������255,
   ����ÿ�������ھ�3���������ô�ܹ��Ŀ������಻�ᳬ��81�֣�3^4=81,���Լ�¼��81����ϣ�ÿ���жϼ����ж���Щ��������������ļ��ɡ�
(2)��ͬ�Ĺ��̿�������������������ݹ�ʵ��
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string > ans;
		if(s.size() > 12) return ans;
		vector<vector<int > > com = getCom();
		for(int i = 0; i < com.size(); i++){
			string cur = "";
			if(com[i][0]+com[i][1]+com[i][2]+com[i][3] != s.size()) continue; //�ܳ��Ȳ����
			int step = 0, j = 0;
			for(j = 0; j < 4; j++){
				string tmp = s.substr(step, com[i][j]);
				if(string2int(tmp) > 255) break; //ֵ����255������������ 
				if(tmp.size() > 1 && tmp[0] == '0') break;  //00��01�����ַ���������
				if(j < 3) cur += (tmp + ".");
				else cur += tmp;
				step += com[i][j];
			}
			if(j == 4) ans.push_back(cur);
		}
		return ans;
    }
	//��¼�������
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
			if(string2int(tmp) > 255) continue; //ֵ����255������������ 
			if(tmp.size() > 1 && tmp[0] == '0') continue;  //00��01�����ַ���������
			if(step < 3) ip += (tmp + ".");
			else ip += tmp;
			dfs(ans, s, ip, i+j, step+1);
			ip.erase(len, j+1); //�ع�
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
