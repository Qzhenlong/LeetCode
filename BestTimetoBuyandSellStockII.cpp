#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

���������һ���汾���㷨�������������ν��ף������������Ʊǰ�����������õ�������档

˼·��̰���㷨�����������ڲ�ֵ����0��������������ɡ�
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
