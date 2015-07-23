#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Implement int sqrt(int x).

Compute and return the square root of x.

������ʵ�ֿ�ƽ��������ʹ��y^2= x,

˼·��
��1�����ַ�����[0, x / 2 + 1]��Χ�ڽ��ж��ֲ���
��2��ţ�ٵ�������http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
*/

class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
		long long high = x/2+1;
		while(low <= high){
			long long mid = (low+high)/2;
			if(mid*mid == x) return mid;
			else if(mid*mid < x) low = mid+1;
			else high = mid-1;
		}
		return high;
    }
};

int main(){
	Solution c;
	for(int i = 100; i < 1000; i += 100)
		cout << c.mySqrt(i) << " " << endl;
	return 0;
}
