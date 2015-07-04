#include<iostream>
#include<vector>
using namespace std;
/*
The n-queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
������N�ʺ����⣬��֤�����ϵ�N���ʺ��޷����๥��
˼·����1��N��ȫ������ȥ�������������Ŀ��ܼ��ɣ� ��һ�������¼ÿһ�лʺ��λ�ã�(i, pos[i])��ʾ��i�лʺ�λ�ڵ�pos[i]����
�ų��ķ�����
�赱ǰ��Ϊr, ��֮ǰ���еĻʺ��뵱ǰ��ĳ�ͻ��λ��������pos[i], pos[i]-(r-i), pos[i]+(r-i),���������ܲ��������ڣ�����Ҫ�ж�һ�¡�
*/

class Solution {
public:
    vector<vector<string > > solveNQueens(int n) {
        vector<vector<string > > ans;
		vector<int > pos;
		if(n <= 0) return ans;
		fun(ans, pos, n);
		return ans;
    }
	void fun(vector<vector<string > > &ans, vector<int > &pos, int n){ //rΪ��ǰ�к�
		int r = pos.size();
		if(r >= n){ //�ҵ�һ����
		    vector<string > OneAns;
			string cur = "";
			for(int i = 0; i < n; i++) cur += '.'; //��ʼ��Ϊȫ.
			for(int i = 0; i < n; i++){
				if(i == 0) cur[pos[i]] = 'Q';
				else{
					cur[pos[i-1]] = '.';
					cur[pos[i]] = 'Q';
				}
				OneAns.push_back(cur);
			}
			ans.push_back(OneAns);
			return;
		}
		vector<bool > isValid(n, true); //�Ƿ�Ϊ��Чλ��
		for(int i = 0; i < r; i++){
			isValid[pos[i]] = false;
			if((pos[i]-(r-i)) >= 0) isValid[pos[i]-(r-i)] = false;
			if((pos[i]+(r-i)) < n) isValid[pos[i]+(r-i)] = false;
		}
		for(int i = 0; i < n; i++){
			if(isValid[i]){
				pos.push_back(i);
				fun(ans, pos, n);
				pos.pop_back();
			}
		}
		
	}
};

int main(){
	Solution c;
	vector<vector<string > > ans = c.solveNQueens(4);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << endl;
		}
		cout << "***********************************" << endl;
	}
	cout << "Total Number: " << ans.size() << endl;
	return 0;
}
