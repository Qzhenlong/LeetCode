#include<iostream>
using namespace std;
/*
ԭ�⣺Find the total area covered by two rectilinear rectangles in a 2D plane.
�������������������θ��ǵ��������A,B)(C,D)ȷ��һ�������Σ���E��F����G��H��ȷ����һ��������
˼·����������Ҫȷ��һ�������Σ����Ա�Ȼ��һ������ĳ����Σ��ĵ�����Ϊ(A,B),(C,B),(C,D),(A,D)
	  �������������������ټ�ȥ�ص�������������ɡ�
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (D-B)*(C-A);
		int area2 = (H-F)*(G-E);
		int total = area1 + area2;
		//���������β��ص�
		if(A >= G || B >= H || E >= C || F >= D) return total;
		//�������������ص�
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
