#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

����������һ���������飬�ҳ�����С��·����ÿ��һ��Ԫ�أ�ÿһ��ֻ������һ�е�����λ������ȥ
	 �Ӷ�ά�����Ͽ�
  [2],
  [3,4],
  [6,5,7],
  [4,1,8,3]
��һ�е�Ԫ�ص���һ��Ԫ��һ��λ�����Ϸ��������Ϸ�
  
˼·����̬�滮������Ԫ�ؼ�Ϊt[i][j], dp[i][j]��ʾ�ӿ�ʼ����i�е�j��Ԫ�ص���С��
dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) +t[i][j] 

ע��
��һ��Ԫ�� dp[i][j] = dp[i-1][j] +t[i][j]
ĩβԪ��   dp[i][j] = dp[i-1][j-1] + t[i][j]
dp[0][0] = t[i][j];

�����ǿռ������£���ҪO(n^2)���Ӷȣ����ǹ������飬�ɽ��ռ併��O(n)
*/

class Solution {
public:
	//O(n^2)�ռ�
    int minimumTotal(vector<vector<int > >& triangle) {
        if(triangle.size() == 0) return 0;
		int n = triangle.size(), ans = INT_MAX;
		vector<vector<int > > dp(n, vector<int >(n, INT_MAX));
		dp[0][0] = triangle[0][0]; //��һ��Ԫ��
		if(n == 1) return dp[0][0];
		for(int i = 1; i < n; i++){
			for(int j = 0; j <= i; j++){
				if(j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j]; //��һ��
				else if(j == i) dp[i][j] = dp[i-1][j-1] + triangle[i][j]; //ĩβԪ��
				else dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]; //�м�Ԫ��
			    
				if(i == n-1 && ans > dp[i][j]) ans = dp[i][j];
			}
		}
		return ans;
    }
	//���ù������齵�Ϳռ临�Ӷ�
    int minimumTotal1(vector<vector<int > >& triangle) {
        if(triangle.size() == 0) return 0;
		int n = triangle.size(), ans = INT_MAX;
		vector<int > dp(n, INT_MAX);
		dp[0] = triangle[0][0]; //��һ��Ԫ��
		if(n == 1) return dp[0];
		for(int i = 1; i < n; i++){
			for(int j = i; j >= 0; j--){ //��֤ǰ����Ҫ�õ�Ԫ��û���ı�
				if(j == 0) dp[j] = dp[j] + triangle[i][j]; //��һ��, dp[i][j] = dp[i-1][j] +t[i][j]
				else if(j == i) dp[j] = dp[j-1] + triangle[i][j]; //ĩβԪ��, dp[i][j] = dp[i-1][j-1] + t[i][j]
				else dp[j] = min(dp[j-1], dp[j]) + triangle[i][j]; //�м�Ԫ��
			    
				if(i == n-1 && ans > dp[j]) ans = dp[j];
			}
		}
		return ans;
    }	
};

int main(){
	Solution c;
	vector<vector<int > > t;
	vector<int > cur;
	cur.push_back(2); t.push_back(cur); cur.clear();
	cur.push_back(3); cur.push_back(4); t.push_back(cur); cur.clear();
	cur.push_back(6); cur.push_back(5); cur.push_back(7); t.push_back(cur); cur.clear();
	cur.push_back(4); cur.push_back(1); cur.push_back(8); cur.push_back(3); t.push_back(cur); cur.clear();
	cout << c.minimumTotal1(t) << endl;
	return 0;
}
