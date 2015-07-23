#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

����������һ�������ʾ��Ʊĳһ��ļ۸��ҳ�������棬������k�ν��ף���ͬһ�����������

˼·���汾�ı�ǰ�������汾�Ѻܶ࣬������k�ν��ף���k���ص�����Ӷκͣ���̬�滮˼·��

�������Ƚ��������Խ���k�ν��׵��㷨��Ȼ����������������ֻ��Ҫ��kȡ��2���ɡ����ǻ���ʹ�á��ֲ����ź�ȫ�����Žⷨ����
����ά����������һ���ǵ�ǰ�����i�����������j�ν��ף���õ������Ƕ��٣�global[i][j]������һ���ǵ�ǰ�����i�죬
���ɽ���j�ν��ף��������һ�ν����ڵ�����������õ������Ƕ��٣�local[i][j]��������������������ʽ��ȫ�ֵıȽϼ򵥣�

global[i][j]=max(local[i][j],global[i-1][j])��

Ҳ����ȥ��ǰ�ֲ���õģ��͹���ȫ����õ��д���Ǹ�����Ϊ���һ�ν������������ǰ��һ���ھֲ���õ����棬����һ���ڹ���ȫ�����ŵ����棩��
���ھֲ�������ά��������ʽ��
local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)��
Ҳ���ǿ�����������һ����ȫ�ֵ�i-1�����j-1�ν��ף�Ȼ����Ͻ���Ľ��ף����������׬Ǯ�Ļ���Ҳ����ǰ��ֻҪj-1�ν��ף����һ�ν���ȡ��ǰ�죩��
�ڶ���������ȡlocal��i-1��j�ν��ף�Ȼ����Ͻ���Ĳ�ֵ��������Ϊlocal[i-1][j]���������i-1�������Ľ��ף��������ڱ�ɵ�i��������
���������ӽ��״�����������������diff�ǲ��Ǵ���0��һ��Ҫ���ϣ���Ϊ����Ͳ�����local[i][j]���������һ�������������ˣ���

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
