#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

解析：给定一个数组表示股票某一天的价格，找出最大收益，最多进行两次交易

思路：还是贪心算法，定义头尾两个指针i,j, f(i)表示到i为至所能得到的最大收益，即第一个版本题的解法，
	 g(j)表示j之后的最大收益，然后找出i在j之前，两者之和的最大值即可


*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.size() == 0) return 0;
		int preMin = prices[0], postMax = prices[prices.size()-1];
		vector<int > f(prices.size(), 0);
		vector<int > g(prices.size(), 0);
		for(int i = 1; i < prices.size(); i++){
			f[i] = max(f[i-1], prices[i]-preMin);
			preMin = min(preMin, prices[i]);
		}
		for(int j = prices.size()-2; j >= 0; j--){
			g[j] = max(g[j+1], postMax-prices[j]);
			postMax = max(prices[j], postMax);
		}
		int ans = 0;
		for(int i = 0; i < prices.size(); i++)
			ans = max(ans, g[i]+f[i]);
		
		return ans;
    }

};

int main(){
	Solution c;
	int A[] = {1,3,5,8};
	vector<int > p;
	for(int i = 0; i < sizeof(A)/4; i++)
		p.push_back(A[i]);
	cout << c.maxProfit(p);
	return 0;
}
