#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
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

��������ʿͨ�����ξȹ�������ʿ��һ����ʼѪֵ�����ѪֵС��0�͹ҵ���ÿ�������п������ӻ�����������Ѫ��������ֻ���һ����ߣ�������ʿ�ܵ������½��յ����С��ʼѪֵ

˼·��
(1)�ݹ飬���ӶȱȽϸߣ�Ӧ�ûᳬʱ 
	ʹ��һ�������洢��ǰ��ʣѪ��curHea����һ�������洢����Ҫ�ĳ�ʼѪ��iniHea��ÿ��curHea <= 0 ʱiniHea��Ҫ����abs(curHea)+1

(2)��̬�滮, dp[i][j] = (ch, ih) ��ʾ����㵽��(i,j)����Ҫ����С��ʼѪ���͵�ǰѪֵ����״̬ת�Ʒ��̣�
	dp[i][j] =  (
	a. �����dp[i-1][j]->ch + dungeon[i][j]) > (dp[i][j-1]->ch + dungeon[i][j]) ��  dp[i-1][j]->ch + dungeon[i][j]) > 0, 
	��dp[i][j] = (dp[i-1][j]->ch + dungeon[i][j], dp[i-1][j]->ih)�� < 0,�� dp[i][j] = (1, dp[i-1][j]->ih + abs(dp[i-][j]->ch + dungeon[i][j])+1)
	b. ��һ���������
	
	�������϶��¿��ǣ���Ϊ��ǰ���������ʼѪ�����ٵ��������ȡ��ȡ��ǰʣ��Ѫ��
	����Ķ�̬�滮Ӧ�ô�������, ���յ����ؿ�������ȷ�����ﵱǰ������Ҫ��Ѫֵ����Сֵ
	dp[i][j]��ʾ��(i,j)���յ�(m-1,n-1)��Ҫ����С����ֵ, dp[i][j]��ֵ��ȡ�����ҷ������·���λ�õ����յ����Сֵ
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
		dfs(dungeon, x+1, y, curHea, iniHea, minHea); //����
		dfs(dungeon, x, y+1, curHea, iniHea, minHea); //����
	}
	//���϶��£��в�ͨ
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
	//���¶���
    int __calculateMinimumHP(vector<vector<int > >& dungeon) {
        if(dungeon.empty()) return 1;
		int m = dungeon.size(), n = dungeon[0].size();
		vector<vector<int > > dp(m, vector<int >(n, 0));
		//��ʼ��
		dp[m-1][n-1] = max(0 - dungeon[m-1][n-1], 0); //������һ��λ��Ϊ��ֵ������Ҫ����Ѫ
		for(int i = m-2; i >= 0; i--){
		  dp[i][n-1] = max(dp[i+1][n-1] - dungeon[i][n-1], 0); //�����ǰλ��Ϊ��ֵ�� ������Ҫ��Ѫ�����٣���������
		}
		for(int i = n-2; i >= 0; i--){
		  dp[m-1][i] = max(dp[m-1][i+1] - dungeon[m-1][i], 0);
		}
		//�������ϣ������������
		//dp����Ϊ  dp[i][j] = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j] �ٺ�0ȡ���
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
