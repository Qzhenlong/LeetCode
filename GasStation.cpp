#include<iostream>
#include<vector>
using namespace std;
/*
����diff[i] = gas[i] - cost[i] ��ʾ�ӵ�ǰվ�����������һ��վ���ʣ���������
˼·һ��
��diff[i] + diff[i+1] + ... + diff[k] < 0�� 
��ôdiff[k]<= 0, ��diff[i]��ȻΪ��������û��Ҫ��i��ʼ�ߣ�
��ôdiff[i+1] + ... + diff[k] < 0, ���ο�֪û��Ҫ��i �� k ��Ϊ������
����ÿ�ε�diff[i] + diff[i+1] + ... + diff[k] < 0ʱ������k��Ϊ�����㼴�ɣ�
Ȼ��ͨ��һ���ܺ�����ʾ�Ƿ��н⣬���򷵻ص�ǰ��k+1,���򷵻�-1��
˼·����
diff����������������������

�ο���http://www.cnblogs.com/felixfang/p/3814463.html
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
    //���������
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
