#include<iostream>
#include<vector>
using namespace std;
/*
原题：Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

解析：题目意思有点容易弄错，大致意思是整个过程中只能买一只股票然后卖出，得到最大收益。

思路：找到买进和卖出时正向差异最大的两天。

*/

class Solution {
public:
	//O(n^2)算法，超时，动态规划问题
    int maxProfit(vector<int>& prices) { 
        if(prices.size() <= 1) return 0; //只有一天，无收益
		int ans = prices[1]-prices[0];
		for(int i = 0; i < prices.size(); i++){
			for(int j = i+1; j < prices.size(); j++){
				if(ans < (prices[j]-prices[i])) ans = prices[j]-prices[i];
			}
		}
		return ans;
    }
	//O(n)算法，AC，贪心算法 ，遍历时记录之前序列中的最小值即可
	int maxProfit1(vector<int>& prices) { 
		if(prices.size()<=1) return 0;
		int ans = 0, cur_min = prices[0];
		for(int i = 1; i < prices.size(); i++){
			ans = max(ans, prices[i]-cur_min);
			cur_min = min(cur_min, prices[i]);
		}
		return ans;
	}
};

int main(){
	Solution c;
	int A[] = {1,3,5,8};
	vector<int > p;
	for(int i = 0; i < sizeof(A)/4; i++)
		p.push_back(A[i]);
	cout << c.maxProfit1(p);
	return 0;
}
