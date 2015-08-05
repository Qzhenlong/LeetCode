#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

解析：有N个孩子站在一条线上，每个孩子分配的个级别值，这孩子们分糖果，规则如下：
1. 每个孩子至少一个糖果
2. 级别值高的孩子比其相邻的孩子拿到更多的糖果
3. 你至少要发出多少糖果

思路：
(1) 将孩子们按级别值排序，从0到N编号，同时并记录其原来的位置，按从低到高依次分发糖果，
	当发到第i个孩子时，如果0到i-1个孩子中有原来与i相邻的孩子，则第i个孩子分发的糖果数必须大于其之前相邻的孩子
	使用容器m1存储孩子们的级别值及原本位置的编号，并按级别值排序，使用哈希表m2存储已经分发完成的孩子编号及其分发的糖果数
	特殊情况：级别值相同且相邻的孩子，拥有的糖果数是互不相关的， 那么连续相邻的孩子拥有相同级别值的时候，只需要处理两边边界即可
	思路不对，应该采用贪心算法！
(2) 和之前求装水量那个题Trapping Rain Water 有点像, 从左向右，增加就加1，减小就减1，
	初始化数组dp，数组成员均为1 ，每个孩子先分配一个糖果
	从左向右遍历，如果第i个孩子比第i - 1孩子等级高，则dp[i] = dp[i - 1] + 1, 这样一次扫描就只剩下连续的级别值相等的孩子情况没有处理了
	从右向左遍历，如果第i个孩子比第i + 1孩子等级高并且糖果比i+1糖果少，则dp[i] = dp[i + 1] + 1

*/

class Solution {
public:
	int _candy(vector<int >& ratings){
		int n = ratings.size();
		vector<int > dp(n, 1);
		for(int i = 1; i < n; ++i)
			if(ratings[i] > ratings[i-1]) dp[i] = dp[i-1]+1;
		for(int i = n-2; i >= 0; --i)
			if(ratings[i] > ratings[i+1] && dp[i] <= dp[i+1]) dp[i] = dp[i+1]+1;
		int ans = 0;
		for(int i = 0; i < n; ++i) ans += dp[i];
		return ans;
	}
    int candy(vector<int >& ratings) {
		if(ratings.empty()) return 0;
        vector<pair<int, int> > m1;
		int prev = -1, count = 0, ans = 0;
		for(int i = 0; i < ratings.size(); ++i){
			if(ratings[i] != prev){
				m1.push_back(make_pair(ratings[i], i));
				if(count > 0){
					ans += (count-1);
					m1.push_back(make_pair(prev, i-1));
				}
				count = 0;
			}
			else count++;
			prev = ratings[i];
		}
		if(count > 0) ans += count;
		sort(m1.begin(), m1.end());
		map<int, pair<int, int> > m2;
		for(vector<pair<int, int> >::iterator it = m1.begin(); it != m1.end(); ++it){
			int candy = 0, rating = INT_MIN;
			if(m2.find(it->second-1) != m2.end()){
				rating = max(rating, m2[it->second-1].second); //处理级别值相同的情况,也可以小于相邻孩子
				candy = max(candy, m2[it->second-1].first);
			}
			if(m2.find(it->second+1) != m2.end()){
				rating = max(rating, m2[it->second+1].second);
				candy = max(candy, m2[it->second+1].first);				
			}
			m2[it->second] = (rating == it->first) ? make_pair(candy, it->first) : make_pair(candy+1, it->first);
			ans += m2[it->second].first;
			//cout << m2[it->second].first << endl;
		}
		return ans;
    }
};

int main(){
	Solution c;
	vector<int > ratings;
	ratings.push_back(1);
	ratings.push_back(2);
	ratings.push_back(2);
	ratings.push_back(1);
	ratings.push_back(3);
	cout << c._candy(ratings);
	return 0;
}
