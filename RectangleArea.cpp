#include<iostream>
using namespace std;
/*
原题：Find the total area covered by two rectilinear rectangles in a 2D plane.
解析：计算两个长方形覆盖的面积，（A,B)(C,D)确定一个长方形，（E，F）（G，H）确定另一个长方形
思路：由于两点要确定一个长方形，所以必然是一个规则的长方形，四点坐标为(A,B),(C,B),(C,D),(A,D)
	  将两个长方形面积相加再减去重叠的区域面积即可。
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (D-B)*(C-A);
		int area2 = (H-F)*(G-E);
		int total = area1 + area2;
		//两个长方形不重叠
		if(A >= G || B >= H || E >= C || F >= D) return total;
		//两个长方形有重叠
		int bottom = max(B,F);
		int left   = max(A,E);
		int right  = min(C,G);
		int top    = min(D,H);
		total -= (top-bottom)*(right-left);
		return total;
    }
};

int main(){
	Solution c;
	cout << c.computeArea(-3,0,3,4,0,-1,9,2);
	return 0;
}
