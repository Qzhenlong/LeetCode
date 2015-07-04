#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

������N�ʺ����⣬�����������������͵�һ����һ����˼·, ��ʵûʲô��Ҫ
*/

class Solution {
public:
    int totalNQueens(int n) {
        int total = 0;
		if(n <= 0) return total;
		vector<int > pos;
		fun(pos, total, n);
		return total;
    }
	void fun(vector<int > &pos, int &total, int n){
		int r = pos.size();
		if(r >= n){
			total++;
			return;
		}
		vector<bool > isValid(n, true);
		for(int i = 0; i < r; i++){
			isValid[pos[i]] = false;
			if(pos[i]-(r-i) >= 0) isValid[pos[i]-(r-i)] = false;
			if(pos[i]+(r-i) < n) isValid[pos[i]+(r-i)] = false;
		}
		for(int i = 0; i < n; i++){
			if(isValid[i]){
				pos.push_back(i);
				fun(pos, total, n);
				pos.pop_back();
			}
		}
	}
};


int main(){
	Solution c;
	for(int i = 0; i <= 20; i++){
		cout << c.totalNQueens(i) << endl;
	}
	return 0;
}
