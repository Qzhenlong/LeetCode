#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*
给定一个整数数组nums与一个整数k，当且仅当存在两个不同的下标i和j满足| nums[i]-nums[j] | <= t并且| i - j | <= k 时返回true，否则返回false。
我的思路：
设定一个满足条件情况的记数器c,初始化为0
对数组按值排序，记录原始下标，pair
定义两个i,j对数组进行扫描，找出是否有满足条件的情况，有则返回true,否则继续

//题意理解错误：不用唯一存在一对，只要存在即可，可以直接利用原来的思路，
用哈希表存在值与对应的下标，如果存在重复时则删除
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if(nums.size() <= 1) return false;
		vector<pair<long long, int > > pv;
		int c = 0;
		for(int i = 0; i < nums.size(); i++) pv.push_back(make_pair(nums[i], i));
		sort(pv.begin(), pv.end());
		//for(vector<pair<int, int > >::iterator it = pv.begin(); it != pv.end(); it++)
			//cout << it->first << ", " << it->second << endl;
		vector<pair<long long, int > >::iterator i = pv.begin(), j = pv.begin()+1;
		while(i != pv.end())
		{
			long long div = (j->second > i->second) ? (j->first - i->first) : (i->first - j->first);
			if(j != pv.end() && abs(div) <= t){
				//cout << abs(j->first - i->first) <<  ","  << abs(j->second - i->second) << endl;
				if(abs(j->second - i->second) <= abs(k)) return true;; //理解错误，存在即可，不用唯一存在
				j++;
			}
			else{ 
				i++; 
				if(i != pv.end()) j = i+1; 
			}
		}
		//if(c == 1) return true;
		return false;        
    }
	bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k && m[nums[j]] == j) m.erase(nums[j++]);
            auto a = m.lower_bound(nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
	Solution c;
	vector<int > nums;
	int A[] = {-1,2147483647};
	for(int i = 0; i < sizeof(A)/4; i++)
		nums.push_back(A[i]);
	
	cout << (c.containsNearbyAlmostDuplicate(nums,1,2147483647)? "true" : "false") << endl;
	return 0;
}
