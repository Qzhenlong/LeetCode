#include<iostream>
#include<vector>
#include<map>
using namespace std;

// Definition for a point.
struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
};
 
class Solution {
public:
    int maxPoints(vector<Point >& points) {
        int max = 1;
		if(points.size() <= 1) return points.size();
		map<double, int> slope; //统计斜率数量
		int slopey = 0; //斜率不存在的情况
		int copy = 0; //相同点
		for(int i = 0; i < points.size(); i++)
		{
			int tmp_max = 0;
			Point base = points[i];
			slope.clear();
			slopey = 0;
			copy = 1; //加上自身
			for(int j = 0; j < points.size(); j++)
			{
				if(i == j) continue;
				if(base.x-points[j].x == 0 && base.y-points[j].y == 0){ copy++; continue;} //注意上下都为0的情况
				else if(base.x-points[j].x == 0){ slopey++; continue;}
				else{
					double s = (double)(base.y-points[j].y) / (base.x - points[j].x);
					if(slope.find(s) == slope.end()) slope[s] = 1;
					else slope[s]++;
				}
			}
			for(map<double, int>::iterator it = slope.begin(); it != slope.end(); it++)
				if(tmp_max < it->second) tmp_max = it->second;
			tmp_max = (tmp_max < slopey) ? slopey : tmp_max;
			tmp_max += copy;
			max = (max < tmp_max) ? tmp_max : max;
			if(max == points.size()) break; //已经达到总数，不用循环了
		}
		return max;
    }
};

int main()
{
	Solution c;
	vector<Point > points;
	Point t1(1,1);
	Point t2(1,1);
	Point t3(1,1);
	Point t4(1,1);
	points.push_back(t1);
	points.push_back(t2);
	points.push_back(t3);
	points.push_back(t4);
	cout << c.maxPoints(points);
	return 0;
}
