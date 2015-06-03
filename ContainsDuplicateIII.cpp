#include<iostream>
#include<map>
#include<vector>
using namespace std;
/*
����һ����������nums��һ������k�����ҽ�������������ͬ���±�i��j����| nums[i]-nums[j] | <= t����| i - j | <= k ʱ����true�����򷵻�false��
�ҵ�˼·��
�趨һ��������������ļ�����c,��ʼ��Ϊ0
�����鰴ֵ���򣬼�¼ԭʼ�±꣬pair
��������i,j���������ɨ�裬�ҳ��Ƿ���������������������򷵻�true,�������

//���������󣺲���Ψһ����һ�ԣ�ֻҪ���ڼ��ɣ�����ֱ������ԭ����˼·��
�ù�ϣ�����ֵ���Ӧ���±꣬��������ظ�ʱ��ɾ��
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
				if(abs(j->second - i->second) <= abs(k)) return true;; //�����󣬴��ڼ��ɣ�����Ψһ����
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
