#include<iostream>
#include<vector>
using namespace std;
/*
原题：Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

解析：与第一个版本的算法区别在于允许多次交易，但重新买进股票前必须卖出，得到最大收益。

思路：贪心算法，把所有相邻差值大于0的收益加起来即可。
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) { 
		if(prices.size()<=1) return 0;
		int ans = 0;
		for(int i = 1; i < prices.size(); i++){
			int dif = prices[i]-prices[i-1];
			if(dif > 0) ans += dif;
		}
		return ans;
	}
};

int main(){
	Solution c;
	int A[] = {1,10,5,8};
	vector<int > p;
	for(int i = 0; i < sizeof(A)/4; i++)
		p.push_back(A[i]);
	cout << c.maxProfit(p);
	return 0;
}
