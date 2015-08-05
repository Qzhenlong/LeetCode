#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

解析：不使用乘法，除法及取模运算，求两数相除的结果

思路：
（1）不能使用乘除法，可以考虑使用移位，从而求出倍数，对除数divisor逐渐左移，当大于被除数时，记录当前倍数，
	 由于当前倍数大于我们想要的结果，于是要减去超出的部分所产生的倍数，这样循环压缩即可
	 注意溢出问题，都使用long long型表示，AC
	 
（2）大神的解法，更简洁，不过思路差不多， http://www.2cto.com/kf/201408/323125.html
	任何一个整数可以表示成以2的幂为底的一组基的线性组合，即num=a_0*2^0+a_1*2^1+a_2*2^2+...+a_n*2^n。
	基于以上这个公式以及左移一位相当于乘以2，我们先让除数左移直到大于被除数之前得到一个最大的基n的值，
	说明被除数中至少包含2^n个除数，然后减去这个基数，再依次找到n-1，...，1的值。将所有的基数相加即可得到结果。
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
		if(divisor == 0) return INT_MAX;
		if(dividend == 0) return 0;
		int isPositive = (dividend > 0) ^ (divisor > 0); //负负得正
		//dividend = abs(dividend); divisor = abs(divisor); //和Fraction to Recurring Decimal一题的问题一样，出现不能表示的值
		long long int _dividend = dividend, _divisor = divisor, value = 0, verify_dividend = dividend;
		_dividend = abs(_dividend); _divisor = abs(_divisor);
		if(_dividend < _divisor) return 0;
		long long int ans = 0,  count = 0;  //注意都得用long long 型
		while(_dividend >= _divisor){
			long long int tmp = 1,cur = _divisor; //注意这里要用long long型，否则当cur超出INT_MAX时会陷入死循环
			while(cur < _dividend){
				cur = cur << 1;
				tmp = tmp << 1; //指数倍数增长
			}
			if(count % 2 == 0){
				ans += tmp;
				value += cur;
			}
			else{
				ans -= tmp; //交替加减倍数
				value -= cur;
			}
			count++;
			_dividend = cur - _dividend;
		}
		//需要修正一下
		if(value > abs(verify_dividend)) ans--; //结果要大一些，倍数要减小1
		if(isPositive) return (-ans < INT_MIN) ? INT_MIN : -ans;
		return (ans > INT_MAX) ? INT_MAX : ans;
    }
    int _divide(int dividend, int divisor) {
        assert(divisor != 0);
        int res=0;
        int flag=1;
        if((dividend<0 && divisor>0)||(dividend>0 && divisor<0))
            flag=-1;

        long long divid=abs((long long)dividend);//考虑对最大最小整数取模的情况
        long long divi=abs((long long)divisor);
        long long temp=0;
 
        while(divi<=divid)
        {
            int cnt=1;
            temp=divi;
 
            while((temp<<=1)<=divid)
            {
                cnt<<=1;
            }
            res+=cnt;
            divid-=(temp>>1); //这个比较聪明，往回跳一位，不用像我的那么麻烦
        }
        return (int)res*flag; //大神给的解答有误，AC不了
    }
	//重新写一个简单一点的，AC
    int __divide(int dividend, int divisor) {
		if(divisor == 0) return INT_MAX;
		if(dividend == 0) return 0;
		int isPositive = (dividend > 0) ^ (divisor > 0); //负负得正
		long long int _dividend = dividend, _divisor = divisor, value = 0, verify_dividend = dividend;
		_dividend = abs(_dividend);
		_divisor = abs(_divisor);
		if(_dividend < _divisor) return 0;
		long long int ans = 0,  count = 0;  //注意都得用long long 型
		while(_dividend >= _divisor){
			long long int tmp = 1,cur = _divisor; //注意这里要用long long型，否则当cur超出INT_MAX时会陷入死循环
			while(cur <= _dividend){
				cur = cur << 1;
				tmp = tmp << 1; //指数倍数增长
			}
			ans += (tmp >> 1);
			_dividend -= (cur >> 1);
		}

		if(isPositive) return (-ans < INT_MIN) ? INT_MIN : -ans;
		return (ans > INT_MAX) ? INT_MAX : ans;
    }
};

int main(){
	Solution c;
	//for(int i = 0; i < 100; i++)
		//cout << c.divide(i, 5) << " " << (i / 5) << endl;
	cout << c.__divide(-200, 1);
	return 0;
}
