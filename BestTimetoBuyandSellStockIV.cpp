#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

解析：给定一个数组表示股票某一天的价格，找出最大收益，最多进行k次交易，可同一天买进再卖出

思路：版本四比前面三个版本难很多，最多进行k次交易，求k不重叠最大子段和，动态规划思路：

里我们先解释最多可以进行k次交易的算法，然后最多进行两次我们只需要把k取成2即可。我们还是使用“局部最优和全局最优解法”。
我们维护两种量，一个是当前到达第i天可以最多进行j次交易，最好的利润是多少（global[i][j]），另一个是当前到达第i天，
最多可进行j次交易，并且最后一次交易在当天卖出的最好的利润是多少（local[i][j]）。下面我们来看递推式，全局的比较简单，

global[i][j]=max(local[i][j],global[i-1][j])，

也就是去当前局部最好的，和过往全局最好的中大的那个（因为最后一次交易如果包含当前天一定在局部最好的里面，否则一定在过往全局最优的里面）。
对于局部变量的维护，递推式是
local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)，
也就是看两个量，第一个是全局到i-1天进行j-1次交易，然后加上今天的交易，如果今天是赚钱的话（也就是前面只要j-1次交易，最后一次交易取当前天），
第二个量则是取local第i-1天j次交易，然后加上今天的差值（这里因为local[i-1][j]比如包含第i-1天卖出的交易，所以现在变成第i天卖出，
并不会增加交易次数，而且这里无论diff是不是大于0都一定要加上，因为否则就不满足local[i][j]必须在最后一天卖出的条件了）。

*/

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (k >= prices.size())
            return maxProfit2(prices);
            
        vector<int> release(k+1);
        vector<int> hold(k, INT_MIN);
        
        for (int p = 0; p < prices.size(); p++) {
            for (int i=0; i<k; i++) {
                release[i] = max(release[i], hold[i]+prices[p]);
                hold[i] = max(hold[i], release[i+1]-prices[p]);
            }
        }
        
        return release[0];
    }
    
    int maxProfit2(vector<int> &prices) {
        int profit = 0;
        for (int i=0; i<(int)prices.size()-1; i++) {
            if (prices[i+1] > prices[i])
                profit += prices[i+1] - prices[i];
        }
        
        return profit;
    }
};

int main(){
	Solution c;
	int A[] = {1,3,5,8};
	vector<int > p;
	for(int i = 0; i < sizeof(A)/4; i++)
		p.push_back(A[i]);
	cout << c.maxProfit(2,p);
	return 0;
}
