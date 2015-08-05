#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
/*
��Ŀ��
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

�����������������ļ��ϣ������ص�������ϲ�

˼·��
(1)��ÿ�����������յ�ͳһ��ǣ�Ȼ����������յ�һ��������ͨ����Ӧ�ı�ǽ��л��֣��磺
���䣺1, 3, 2, 6, 8, 10, 15, 18
��ǣ�0, 0, 1, 1, 2, 2,  3,  3

����1, 2, 3, 6, 8, 10, 15, 18
      0, 1, 0, 1, 2, 2,  3,  3

�趨һ�����ϣ��洢���ֵ����������ɨ�裬�����г�����ֵͬ���򽫸�ֵ�Ӽ������޳���ÿ������Ϊ��ʱ��˵���ҵ�һ�����䣬�磺
a.��ʼɨ�裬��0���뼯��{0},��¼������ʼֵstart = 1, 
b.ɨ��ڶ���Ԫ�أ���1���뼯��{0,1}
c.ɨ�赽������Ԫ�ض�Ӧ���Ϊ0, �ڼ����У���¼��ǰ�յ�ֵend = 3, �����0�޳����õ�{1}
d.ɨ����ĸ�Ԫ�ض�Ӧ���Ϊ1�� �ڼ����У� ���µ�ǰ�յ�ֵend = 6�� �����0�޳����õ�{}���ռ���˵���õ�һ���⣬�洢
e.����ͬ���Ĺ��̣�������
ע����������������������ͬ��ֵ��ʱ����Ҫ����ֵͬ�ı�Ƕ����뵽�����С�

��һ��set���洢������ʼ���ǵ�ӳ���ϵ�������򼴿�ִ�����Ϲ��̣� ʱ�临�Ӷȶ�ΪO(n)��ʱ�临�Ӷ�O(nlogn);

��2������Ľⷨ��https://github.com/leetcoders/LeetCode/blob/master/MergeIntervals.h
    ֱ�Ӱ������start��������
*/

/**
 * Definition for an interval.*
**/
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
//���ضԱȺ���
 bool mycompare(Interval a, Interval b)
{
	return a.start < b.start;
}

class Solution {
public:
    //һ��AC��
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0) return intervals;
		vector<pair<int, int> > m;
		set<int > end_set; //�����յ㼯��
		vector<Interval > ans;
		for(int i = 0; i < intervals.size(); i++){ //����ǣ����Զ�����
			m.push_back(make_pair(intervals[i].start, i));
			m.push_back(make_pair(intervals[i].end, i));
		}
		sort(m.begin(), m.end());
		int x = 0, y = INT_MIN, prev = 0; 
		for(int i = 0; i < m.size(); i++){
			//cout << m[i].first << ", " << m[i].second << endl;
			if(end_set.empty()){
				if(i > 0 && m[i].first == prev){
					end_set.insert(m[i].second); //����ֵ��ͬ�����
					continue;
			    }
				if(i > 0) ans.push_back(Interval(x, y)); //�ܿ���һ�ν���
				x = m[i].first;
				y = INT_MIN;
			}
			if(end_set.find(m[i].second) == end_set.end()) end_set.insert(m[i].second);
			else{
				end_set.erase(m[i].second);
				y = max(y, m[i].first);
			}

			prev = m[i].first;
		}
		ans.push_back(Interval(x, y)); //���һ��
		return ans;
    }

//����Ĵ��룺�ռ临�Ӷ�O(1)
    vector<Interval> _merge(vector<Interval> &intervals) {
        int N = intervals.size();
        if (N <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), mycompare); //��start����
        vector<Interval> res;
        Interval last = intervals[0]; //�Ա��յ�
        for (int i = 1; i < N; ++i) 
        {
            if (intervals[i].start > last.end) { //�Ա���һ��������յ�����һ���������Ƿ��н���
                res.push_back(last);
                last = intervals[i];
            } else {
                last.end = max(last.end, intervals[i].end); //��¼�ϴ�ֵ��Ϊ�����յ�
            }
        }
        res.push_back(last);
        return res;
    }

};

int main(){
	Solution c;
	vector<Interval > in;
	in.push_back(Interval(1,3));
	in.push_back(Interval(2,7));
	in.push_back(Interval(6,10));
	in.push_back(Interval(1,18));
	vector<Interval > ans = c._merge(in);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].start << ", " << ans[i].end << endl;
	return 0;
}
