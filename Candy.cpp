#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

��������N������վ��һ�����ϣ�ÿ�����ӷ���ĸ�����ֵ���⺢���Ƿ��ǹ����������£�
1. ÿ����������һ���ǹ�
2. ����ֵ�ߵĺ��ӱ������ڵĺ����õ�������ǹ�
3. ������Ҫ���������ǹ�

˼·��
(1) �������ǰ�����ֵ���򣬴�0��N��ţ�ͬʱ����¼��ԭ����λ�ã����ӵ͵������ηַ��ǹ���
	��������i������ʱ�����0��i-1����������ԭ����i���ڵĺ��ӣ����i�����ӷַ����ǹ������������֮ǰ���ڵĺ���
	ʹ������m1�洢�����ǵļ���ֵ��ԭ��λ�õı�ţ���������ֵ����ʹ�ù�ϣ��m2�洢�Ѿ��ַ���ɵĺ��ӱ�ż���ַ����ǹ���
	�������������ֵ��ͬ�����ڵĺ��ӣ�ӵ�е��ǹ����ǻ�����صģ� ��ô�������ڵĺ���ӵ����ͬ����ֵ��ʱ��ֻ��Ҫ�������߽߱缴��
	˼·���ԣ�Ӧ�ò���̰���㷨��
(2) ��֮ǰ��װˮ���Ǹ���Trapping Rain Water �е���, �������ң����Ӿͼ�1����С�ͼ�1��
	��ʼ������dp�������Ա��Ϊ1 ��ÿ�������ȷ���һ���ǹ�
	�������ұ����������i�����ӱȵ�i - 1���ӵȼ��ߣ���dp[i] = dp[i - 1] + 1, ����һ��ɨ���ֻʣ�������ļ���ֵ��ȵĺ������û�д�����
	������������������i�����ӱȵ�i + 1���ӵȼ��߲����ǹ���i+1�ǹ��٣���dp[i] = dp[i + 1] + 1

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
				rating = max(rating, m2[it->second-1].second); //������ֵ��ͬ�����,Ҳ����С�����ں���
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
