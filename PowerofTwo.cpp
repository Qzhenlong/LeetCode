#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��Given an integer, write a function to determine if it is a power of two.

����������һ���������ж����ǲ���2�Ĵη�

˼·��
(1)ÿ�γ�2��ֱ��С��1������1���ǣ�������, Ӧ�ûᳬʱ
(2)�жϸ��������Ƶ����λ�Ƿ�Ϊ1�� ��������ȥ1�����ʹ�����λΪ0������ĵ�λȫΪ1������������Ϊ0

*/

class Solution {
public:
	//O(logn) ��ȻAC��
    bool isPowerOfTwo(int n) {
		if(n == 0) return false;
		if(n == 1) return true;
        //nΪ������˵�����ÿ���2�ĸ����η�		
		while(n > 1){
			if(n % 2 != 0) return false;
			n /= 2;
		}
		if(n == 1) return true;
		return false;
    }
	//O(1)
	bool isPowerOfTwo1(int n){
		return (n > 0) && !(n&(n-1));
	}
};

int main(){
	Solution c;
	for(int i = 0; i <= 20; i++)
		cout << c.isPowerOfTwo1(i) << endl;
	return 0;
}
