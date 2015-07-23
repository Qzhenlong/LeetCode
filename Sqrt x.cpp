#include<iostream>
#include<vector>
using namespace std;
/*
题目：
Implement int sqrt(int x).

Compute and return the square root of x.

解析：实现开平方函数，使得y^2= x,

思路：
（1）二分法，在[0, x / 2 + 1]范围内进行二分查找
（2）牛顿迭代法：http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
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
