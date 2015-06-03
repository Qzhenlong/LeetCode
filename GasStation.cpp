#include<iostream>
#include<vector>
using namespace std;
/*
假设diff[i] = gas[i] - cost[i] 表示从当前站点出发，到下一个站点后剩余的油量。
思路一：
若diff[i] + diff[i+1] + ... + diff[k] < 0， 
那么diff[k]<= 0, 且diff[i]必然为正，否则没必要从i开始走，
那么diff[i+1] + ... + diff[k] < 0, 依次可知没必要把i 到 k 作为出发点
于是每次当diff[i] + diff[i+1] + ... + diff[k] < 0时，即从k作为出发点即可，
然后通过一个总和来表示是否有解，有则返回当前的k+1,否则返回-1。
思路二：
diff数组的最大连续子序列问题

参考：http://www.cnblogs.com/felixfang/p/3814463.html
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur_sum = 0, total = 0, start = 0;
		for(int i = 0; i < gas.size(); i++)
		{
			cur_sum += (gas[i] - cost[i]);
			total += (gas[i] - cost[i]);
			if(cur_sum < 0)
			{
				cur_sum = 0;
				start = i+1;
			}
		}
		return total >= 0 ? start : -1;
    }
    //最大子序列
	int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
        int diff, total = 0, start = 0;
		if(gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size()) return -1;
		int Max = gas[0] - cost[0];
		total = Max;
		for(int i = 1; i < gas.size(); i++)
		{
			diff = (gas[i] - cost[i]);
			total += diff;
			if(Max < 0){
				Max = diff;
				start = i;
			}
			else 
				Max += diff;
		}
		return total >= 0 ? start : -1;
    }
};


int main()
{
	Solution c;
	vector<int > gas, cost;
	gas.push_back(2);
	cost.push_back(3);
	cout << c.canCompleteCircuit1(gas, cost) << endl;
	while(1);
	return 0;
}
