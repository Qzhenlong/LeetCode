#include<iostream>
#include<vector>
using namespace std;
/*
题目：
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. 

Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or 

contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	 3
-5	   -10	 1
10	   30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

解析：骑士通过地牢救公主，骑士有一个初始血值，如果血值小于0就挂掉，每个地牢有可能增加或者消耗他的血，他决定只从右或下走，计算骑士能到达右下角终点的最小初始血值

思路：
(1)递归，复杂度比较高，应该会超时 
	使用一个变量存储当前所剩血量curHea，另一个变量存储所需要的初始血量iniHea，每当curHea <= 0 时iniHea需要增加abs(curHea)+1

(2)动态规划, dp[i][j] = (ch, ih) 表示从起点到达(i,j)所需要的最小初始血量和当前血值，则状态转移方程：
	dp[i][j] =  (
	a. 如果：dp[i-1][j]->ch + dungeon[i][j]) > (dp[i][j-1]->ch + dungeon[i][j]) 且  dp[i-1][j]->ch + dungeon[i][j]) > 0, 
	则dp[i][j] = (dp[i-1][j]->ch + dungeon[i][j], dp[i-1][j]->ih)， < 0,则 dp[i][j] = (1, dp[i-1][j]->ih + abs(dp[i-][j]->ch + dungeon[i][j])+1)
	b. 另一个情况相似
	
	不能至上而下考虑，因为当前点所需的起始血量最少的情况，还取决取当前剩余血量
	这题的动态规划应该从下自上, 从终点往回看，可以确定到达当前点所需要的血值的最小值
	dp[i][j]表示从(i,j)到终点(m-1,n-1)需要的最小生命值, dp[i][j]的值仅取决于右方或者下方的位置到达终点的最小值
	dp[i][j] = max(min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j], 0)

*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int > >& dungeon) {
        if(dungeon.empty()) return 1;
		int minHea = INT_MAX;
		dfs(dungeon, 0, 0, 0, 0, minHea);
		return minHea;
    }
	//Time Limit Exceeded
	void dfs(vector<vector<int > > dungeon, int x, int y, int curHea, int iniHea, int &minHea){
		if(x < 0 || x >= dungeon.size() || y < 0 || y >= dungeon[0].size()) return;
		curHea += dungeon[x][y];
		if(curHea <= 0){
			iniHea += (abs(curHea)+1);
			curHea = 1;
		}
		if(x == dungeon.size()-1 && y == dungeon[0].size()-1){
			minHea = min(minHea, iniHea);
			return;
		}
		dfs(dungeon, x+1, y, curHea, iniHea, minHea); //向下
		dfs(dungeon, x, y+1, curHea, iniHea, minHea); //向右
	}
	//自上而下，行不通
    int _calculateMinimumHP(vector<vector<int > >& dungeon) {
        if(dungeon.empty()) return 1;
		int m = dungeon.size(), n = dungeon[0].size();
		vector<vector<pair<int, int> > > dp(m, vector<pair<int, int> >(n));
		int ih = dungeon[0][0] > 0 ? 1 : abs(dungeon[0][0])+1;
		int ch = dungeon[0][0] > 0 ? dungeon[0][0]+1 : 1;
		dp[0][0] = make_pair(ch, ih);
		for(int i = 1; i < m; ++i){
			ch = dp[i-1][0].first + dungeon[i][0];
			dp[i][0] = ch > 0 ? make_pair(ch, dp[i-1][0].second) : make_pair(1, dp[i-1][0].second + abs(ch) +1 );
		}
		for(int j = 1; j < n; ++j){
			ch = dp[0][j-1].first + dungeon[0][j];
			dp[0][j] = ch > 0 ? make_pair(ch, dp[0][j-1].second) : make_pair(1, dp[0][j-1].second + abs(ch) + 1);
		}
		for(int i = 1; i < m; ++i)
			for(int j = 1; j < n; ++j){
				int ch1 = dp[i-1][j].first + dungeon[i][j];
				int ch2 = dp[i][j-1].first + dungeon[i][j];
				int ih1 = (ch1 > 0) ? dp[i-1][j].second : (dp[i-1][j].second + abs(ch1) + 1);
				int ih2 = (ch2 > 0) ? dp[i][j-1].second : (dp[i][j-1].second + abs(ch2) + 1);
				ch1 = (ch1 <= 0) ? 1 : ch1;
				ch2 = (ch2 <= 0) ? 1 : ch2;
				dp[i][j] = (ih1 > ih2) ?  make_pair(ch1, ih1) : make_pair(ch2, ih2);
			}
		
		return dp[m-1][n-1].second;
    }
	//自下而上
    int __calculateMinimumHP(vector<vector<int > >& dungeon) {
        if(dungeon.empty()) return 1;
		int m = dungeon.size(), n = dungeon[0].size();
		vector<vector<int > > dp(m, vector<int >(n, 0));
		//初始化
		dp[m-1][n-1] = max(0 - dungeon[m-1][n-1], 0); //如果最后一个位置为正值，则不需要消耗血
		for(int i = m-2; i >= 0; i--){
		  dp[i][n-1] = max(dp[i+1][n-1] - dungeon[i][n-1], 0); //如果当前位置为正值， 则所需要的血量减少，否则增加
		}
		for(int i = n-2; i >= 0; i--){
		  dp[m-1][i] = max(dp[m-1][i+1] - dungeon[m-1][i], 0);
		}
		//从下向上，从右向左填表
		//dp方程为  dp[i][j] = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j] 再和0取最大
		for(int i = m-2; i >= 0; i--){
		  for(int j = n-2; j >= 0; j--){
			dp[i][j] = max(min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j], 0);
		  }
		}
		return dp[0][0] + 1;	
		}
};

int main(){
	Solution c;
	vector<int > num;
	vector<vector<int > > d;
	num.push_back(1); num.push_back(-3); num.push_back(3);
	d.push_back(num); num.clear();
	num.push_back(0); num.push_back(-2); num.push_back(0);
	d.push_back(num); num.clear();
	num.push_back(-3); num.push_back(-3); num.push_back(-3);
	d.push_back(num); num.clear();
	cout << c.__calculateMinimumHP(d);
	return 0;
}
