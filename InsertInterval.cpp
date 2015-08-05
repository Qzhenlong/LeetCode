#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

����������һ��û���ص������伯�ϣ������������У�����һ���µ����䵽�����У������Ҫ������Ҫ���ص��Ĳ��ֹ鲢

˼·��
��1��ͬ�����Բ���merge Intervals�еķ�����ֱ������������뵽ԭ�м��ϣ�Ȼ��ִ�кϲ�, ���Ӷ�O(n)
��2�����ö��������Ͻ������򣬲��ö��ֲ��ҵķ������ɽ����븴�ӶȽ�ΪO(logn), ����ԭ���ϻ����ص�����˲��������ֻ��ǰ�󸽽�����������ص�
     ����ҲҪ�漰��ԭ���ϵ�ɾ������룬����ܵĸ��ӶȻ���O(n),����û��Ҫʹ�ö��ֲ����ˡ�

*/
/**
 * Definition for an interval.
 * */
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};
bool mycompare(Interval a, Interval b){
	return a.start < b.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       /// intervals.push_back(newInterval);
		//if(intervals.size() == 1) return intervals;
		vector<Interval > ans;
		//sort(intervals.begin(), intervals.end(), mycompare); �Ѿ��������������ˣ�����������뼴��, ���Ӷ�O(n)
		int insertIndex = 0, i = 0;
		for(i = 0; i < intervals.size(); ++i)
			if(intervals[i].start > newInterval.start){ insertIndex = i; break; }
		if(i == intervals.size()) intervals.push_back(newInterval);
		else intervals.insert(intervals.begin()+insertIndex, newInterval);
		Interval tmp(intervals[0].start, intervals[0].end);
		for(i = 1; i < intervals.size(); ++i){
			if(tmp.end < intervals[i].start){
				ans.push_back(tmp);
				tmp = intervals[i];
			}
			else tmp.end = max(tmp.end, intervals[i].end);
		}
		ans.push_back(tmp);
		return ans;
    }

};

int main(){
	Solution c;
	vector<Interval > in;
	in.push_back(Interval(1,5));
	/*in.push_back(Interval(3,5));
	in.push_back(Interval(6,7));
	in.push_back(Interval(8,10));
	in.push_back(Interval(12,16));*/
	vector<Interval > ans = c.insert(in, Interval(2,3));
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].start << ", " << ans[i].end << endl;
	return 0;
}

