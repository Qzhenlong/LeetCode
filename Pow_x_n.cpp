#include<iostream>
#include<math.h>
using namespace std;
/*
最简单的办法是根据n进行循环并计算乘积，但是这样的时间开销比较大。最好能够再减少循环次数，
例如n^4可以表示成（n^2）^2。将n表示成二进制的格式便能够轻松知道如何减少循环次数。
*/
class Solution {
public:
    double myPow(double x, int n) {
        double ans = x;
		if(n == 0) return 1;
		if(x == 1 || x == 0) return ans;
		for(int i = 1; i < abs(n); i++) ans *= x;
		if(n < 0) ans = 1/ans;		
		return ans;
    }
	double myPow1(double x, int n) {
        double ans = x;
		if(n == 0) return 1;
		if(x == 1 || x == 0) return ans;
		if(n < 0) x = 1/x;
		n = abs(n);
		ans = 1;
		while(n > 0){  //计算 (x^y)^y1...
			if(n % 2 == 1) ans *= x;
			n /= 2;
			x *= x;
		}
		return ans;
    }
	//递归求，二分法，$x^n = x^{n/2} * x^{n/2} * x^{n\%2}$
	double myPow2(double x, int n){
		if(n < 0)
			return 1.0 / _pow(x,-n);
		else 
			return _pow(x, n);
	}
	double _pow(double x, int n){
		if (n == 0) return 1;
		double v = _pow(x, n / 2);
		if (n % 2 == 0) return v * v;
		else return v * v * x;
	}
};

int main()
{
	Solution c;
	cout << c.myPow2(2, 7) << endl;
	while(1);
	return 0;
}
