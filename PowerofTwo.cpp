#include<iostream>
#include<vector>
using namespace std;
/*
题目：Given an integer, write a function to determine if it is a power of two.

解析：给定一个整数，判断它是不是2的次方

思路：
(1)每次除2，直到小于1，等于1则是，否则不是, 应该会超时
(2)判断该数二进制的最高位是否为1， 如果将其减去1，则会使得最高位为0，后面的低位全为1，则两数相与为0

*/

class Solution {
public:
	//O(logn) 居然AC了
    bool isPowerOfTwo(int n) {
		if(n == 0) return false;
		if(n == 1) return true;
        //n为整数，说明不用考虑2的负数次方		
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
