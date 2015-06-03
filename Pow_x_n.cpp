#include<iostream>
#include<math.h>
using namespace std;
/*
��򵥵İ취�Ǹ���n����ѭ��������˻�������������ʱ�俪���Ƚϴ�����ܹ��ټ���ѭ��������
����n^4���Ա�ʾ�ɣ�n^2��^2����n��ʾ�ɶ����Ƶĸ�ʽ���ܹ�����֪����μ���ѭ��������
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
		while(n > 0){  //���� (x^y)^y1...
			if(n % 2 == 1) ans *= x;
			n /= 2;
			x *= x;
		}
		return ans;
    }
	//�ݹ��󣬶��ַ���$x^n = x^{n/2} * x^{n/2} * x^{n\%2}$
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
