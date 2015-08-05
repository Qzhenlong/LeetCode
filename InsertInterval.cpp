#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

解析：给定一个没有重叠的区间集合，集合有序排列，插入一个新的区间到集合中，如果需要，有需要则将重叠的部分归并

思路：
（1）同样可以采用merge Intervals中的方法，直接在新区间加入到原有集合，然后执行合并, 复杂度O(n)
（2）不用对整个集合进行排序，采用二分查找的方案，可将插入复杂度降为O(logn), 由于原集合互不重叠，因此插入的区间只与前后附近的区间可能重叠
     但是也要涉及对原集合的删除与插入，因此总的复杂度还是O(n),所以没必要使用二分插入了。

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
		//sort(intervals.begin(), intervals.end(), mycompare); 已经有序，无需排序了，将新区间插入即可, 复杂度O(n)
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

