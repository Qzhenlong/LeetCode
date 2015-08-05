#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
/*
题目：
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

解析：给定多个区间的集合，将有重叠的区间合并

思路：
(1)将每个区间起点和终点统一标记，然后将所有起点终点一起排序，再通过对应的标记进行划分，如：
区间：1, 3, 2, 6, 8, 10, 15, 18
标记：0, 0, 1, 1, 2, 2,  3,  3

排序：1, 2, 3, 6, 8, 10, 15, 18
      0, 1, 0, 1, 2, 2,  3,  3

设定一个集合，存储标记值，从左至右扫描，集合中出现相同值，则将该值从集合中剔除，每当集合为空时，说明找到一个区间，如：
a.开始扫描，将0加入集合{0},记录区间起始值start = 1, 
b.扫描第二个元素，将1放入集合{0,1}
c.扫描到第三个元素对应标记为0, 在集合中，记录当前终点值end = 3, 将标记0剔除，得到{1}
d.扫描第四个元素对应标记为1， 在集合中， 更新当前终点值end = 6， 将标记0剔除，得到{}，空集，说明得到一个解，存储
e.继续同样的过程，到结束
注：特殊情况就是区间出现相同的值的时候，需要将相同值的标记都加入到集合中。

用一个set来存储区间起始与标记的映射关系，再排序即可执行以上过程， 时间复杂度都为O(n)，时间复杂度O(nlogn);

（2）大神的解法，https://github.com/leetcoders/LeetCode/blob/master/MergeIntervals.h
    直接按区间的start进行排序，
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
 
//重载对比函数
 bool mycompare(Interval a, Interval b)
{
	return a.start < b.start;
}

class Solution {
public:
    //一次AC！
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0) return intervals;
		vector<pair<int, int> > m;
		set<int > end_set; //区间终点集合
		vector<Interval > ans;
		for(int i = 0; i < intervals.size(); i++){ //做标记，并自动排序
			m.push_back(make_pair(intervals[i].start, i));
			m.push_back(make_pair(intervals[i].end, i));
		}
		sort(m.begin(), m.end());
		int x = 0, y = INT_MIN, prev = 0; 
		for(int i = 0; i < m.size(); i++){
			//cout << m[i].first << ", " << m[i].second << endl;
			if(end_set.empty()){
				if(i > 0 && m[i].first == prev){
					end_set.insert(m[i].second); //处理值相同的情况
					continue;
			    }
				if(i > 0) ans.push_back(Interval(x, y)); //避开第一次进入
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
		ans.push_back(Interval(x, y)); //最后一组
		return ans;
    }

//大神的代码：空间复杂度O(1)
    vector<Interval> _merge(vector<Interval> &intervals) {
        int N = intervals.size();
        if (N <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), mycompare); //按start排序
        vector<Interval> res;
        Interval last = intervals[0]; //对比终点
        for (int i = 1; i < N; ++i) 
        {
            if (intervals[i].start > last.end) { //对比上一个区间的终点与下一区间的起点是否有交叉
                res.push_back(last);
                last = intervals[i];
            } else {
                last.end = max(last.end, intervals[i].end); //记录较大值作为区间终点
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
