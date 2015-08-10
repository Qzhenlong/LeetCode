#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 

Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A),

write a program to output the skyline formed by these buildings collectively (Figure B).

The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates 

of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 

0 < Hi ≤ INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. 

A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to

 mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part 
 
 of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...]

 is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
Credits:
Special thanks to @stellari for adding this problem, creating these two awesome images and all test cases.

解析：题目比较长，意思就是给定一个数组来表示多个建筑，确定这些建筑所构成的轮廓，每个建筑用一个三元级[Li, Ri, Hi]表示, Li, Ri表示建筑的左右位置，
     就是坐标轴上的两个横坐标，Hi表示高度。输出一个点构成的数组，这些点唯一确定一条轮廓线，每个横坐标所在直线上只需要一个点，纵坐标所在直线上可能
	 有多个点，但是不连续，也可以说是每个水平线段的左端点，最后一个点则是最后一个建筑的终点位置（即在x轴上，高度为0），此外，两个建筑之间的地面
	 也是轮廓线的一部分。
一些给定条件：
输入建筑的坐标数字范围在[0,10000]， 给定的输入数组按Li的升序排列，输出的数组也必须以横坐标排序，输出不能连续出现高度相等的水平线，如果出现则需要将其
归并成一个点。

思路：
（1）这里为了区分左右边界，将左边界的高度存为负数，这样遇到左边界就存入堆中，遇到右边界就删掉，
    然后看当前状态有无改变，改变了话就把左边界和当前的高度存入结果中
multiset数据结构，其好处在于其中的元素是按堆排好序的，插入新元素进去还是有序的，而且执行删除元素也可方便的将所有相同的元素删掉。

	只要当前的最高建筑高度发生变化，则那么必然出现新的轮廓点，使用一个哈希表记录高度，
*/
class Solution {
public:
	vector<pair<int, int> > getSkyline(vector<vector<int > >& buildings) {
        vector<pair<int, int> > h, res;
		map<int, int> hcount; //记录高度，及其出现次数
        int pre = 0, cur = 0;
        for (int i = 0; i < buildings.size(); ++i) {
            h.push_back(make_pair(buildings[i][0], -buildings[i][2])); //插入左位置，将左起点高度设置为负数用来区分
            h.push_back(make_pair(buildings[i][1], buildings[i][2]));
        }
		sort(h.begin(), h.end()); //统一排序
		hcount[0] = 1; //出现地面时，点的纵坐标为0的情况
		for(int i = 0; i < h.size(); ++i){
			int x = h[i].first, y = h[i].second;
			if(y < 0) ++hcount[-y];
			else{ //建筑的右边界出现，说明其轮廓点已经记录了，可将其高度在哈希表中删除了
				if(hcount[y] <= 1) hcount.erase(y);  
				else --hcount[y];
			}
			cur = hcount.rbegin()->first; //逆向迭代器，取最后一个元素
			if(cur != pre){ //每当最大高度发生变化时，
				res.push_back(make_pair(x, cur));
				pre = cur;
			}
		}
		return res;
	}
/*
    vector<pair<int, int> > getSkyline(vector<vector<int > >& buildings) {
        vector<pair<int, int> > h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]}); //插入左位置，将左起点高度设置为负数用来区分
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());  //将左右起点统一排序
        m.insert(0); //最后一个轮廓点的纵坐标
        for (auto &a : h) {
            if (a.second < 0) m.insert(-a.second); //左起点
            else m.erase(m.find(a.second)); //找到右起点，则删掉相应的左起点
            cur = *m.rbegin(); //取最后一个位置的高度
            if (cur != pre) { //如果高度和上一位置的高度不同，则加入
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
*/
};

int main(){
	Solution c;
	vector<vector<int > > b;
	vector<int > cur;
	cur.push_back(2); cur.push_back(9); cur.push_back(10); 
	b.push_back(cur); cur.clear();
	cur.push_back(3); cur.push_back(7); cur.push_back(15);
	b.push_back(cur); cur.clear();
	cur.push_back(5); cur.push_back(12); cur.push_back(12); 
	b.push_back(cur); cur.clear();
	cur.push_back(15); cur.push_back(20); cur.push_back(10); 
	b.push_back(cur); cur.clear();
	cur.push_back(19); cur.push_back(24); cur.push_back(8); 
	b.push_back(cur); cur.clear();
	vector<pair<int, int > > ans = c.getSkyline(b);
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}
