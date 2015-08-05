#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

��������ʹ�ó˷���������ȡģ���㣬����������Ľ��

˼·��
��1������ʹ�ó˳��������Կ���ʹ����λ���Ӷ�����������Գ���divisor�����ƣ������ڱ�����ʱ����¼��ǰ������
	 ���ڵ�ǰ��������������Ҫ�Ľ��������Ҫ��ȥ�����Ĳ����������ı���������ѭ��ѹ������
	 ע��������⣬��ʹ��long long�ͱ�ʾ��AC
	 
��2������Ľⷨ������࣬����˼·��࣬ http://www.2cto.com/kf/201408/323125.html
	�κ�һ���������Ա�ʾ����2����Ϊ�׵�һ�����������ϣ���num=a_0*2^0+a_1*2^1+a_2*2^2+...+a_n*2^n��
	�������������ʽ�Լ�����һλ�൱�ڳ���2���������ó�������ֱ�����ڱ�����֮ǰ�õ�һ�����Ļ�n��ֵ��
	˵�������������ٰ���2^n��������Ȼ���ȥ����������������ҵ�n-1��...��1��ֵ�������еĻ�����Ӽ��ɵõ������
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
		if(divisor == 0) return INT_MAX;
		if(dividend == 0) return 0;
		int isPositive = (dividend > 0) ^ (divisor > 0); //��������
		//dividend = abs(dividend); divisor = abs(divisor); //��Fraction to Recurring Decimalһ�������һ�������ֲ��ܱ�ʾ��ֵ
		long long int _dividend = dividend, _divisor = divisor, value = 0, verify_dividend = dividend;
		_dividend = abs(_dividend); _divisor = abs(_divisor);
		if(_dividend < _divisor) return 0;
		long long int ans = 0,  count = 0;  //ע�ⶼ����long long ��
		while(_dividend >= _divisor){
			long long int tmp = 1,cur = _divisor; //ע������Ҫ��long long�ͣ�����cur����INT_MAXʱ��������ѭ��
			while(cur < _dividend){
				cur = cur << 1;
				tmp = tmp << 1; //ָ����������
			}
			if(count % 2 == 0){
				ans += tmp;
				value += cur;
			}
			else{
				ans -= tmp; //����Ӽ�����
				value -= cur;
			}
			count++;
			_dividend = cur - _dividend;
		}
		//��Ҫ����һ��
		if(value > abs(verify_dividend)) ans--; //���Ҫ��һЩ������Ҫ��С1
		if(isPositive) return (-ans < INT_MIN) ? INT_MIN : -ans;
		return (ans > INT_MAX) ? INT_MAX : ans;
    }
    int _divide(int dividend, int divisor) {
        assert(divisor != 0);
        int res=0;
        int flag=1;
        if((dividend<0 && divisor>0)||(dividend>0 && divisor<0))
            flag=-1;

        long long divid=abs((long long)dividend);//���Ƕ������С����ȡģ�����
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
            divid-=(temp>>1); //����Ƚϴ�����������һλ���������ҵ���ô�鷳
        }
        return (int)res*flag; //������Ľ������AC����
    }
	//����дһ����һ��ģ�AC
    int __divide(int dividend, int divisor) {
		if(divisor == 0) return INT_MAX;
		if(dividend == 0) return 0;
		int isPositive = (dividend > 0) ^ (divisor > 0); //��������
		long long int _dividend = dividend, _divisor = divisor, value = 0, verify_dividend = dividend;
		_dividend = abs(_dividend);
		_divisor = abs(_divisor);
		if(_dividend < _divisor) return 0;
		long long int ans = 0,  count = 0;  //ע�ⶼ����long long ��
		while(_dividend >= _divisor){
			long long int tmp = 1,cur = _divisor; //ע������Ҫ��long long�ͣ�����cur����INT_MAXʱ��������ѭ��
			while(cur <= _dividend){
				cur = cur << 1;
				tmp = tmp << 1; //ָ����������
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
