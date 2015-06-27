#include<iostream>
#include<vector>
using namespace std;
/*
原题：
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

思路：先将整数数组转为字符串数组，然后字符串数组进行排序，最后依次输出字符串数组即可。
这里注意的是字符串的比较函数需要重新定义，不是比较a和b，而是比较ab与 ba。
如果ab < ba，则a < b；如果ab > ba，则a > b；如果ab = ba，则a = b。
事实上就是定义一个新的对比函数，将字符串进行排序即可

*/

class Solution {
public:
    static bool cmp(const string &s1, const string &s2) { //重载对比函数
        return (s1 + s2) > (s2 + s1);
    }
    string largestNumber(vector<int> &nums) {
        vector<string> s_num(nums.size());
		string ans = "";
		bool zero = true;
        for (int i = 0; i < nums.size(); ++i) {
            //s_num[i] = to_string(nums[i]); //转换为字符串
			s_num[i] = int2string(nums[i]);
			if(nums[i] != 0 && zero) zero = false;
        }
		if(zero) return "0"; //全0
        sort(s_num.begin(), s_num.end(), cmp);

		for(int i = 0; i < nums.size(); i++){
			if(s_num[i] != "0" && !zero) zero = true;
			if(zero) ans += s_num[i]; //去除高位0
		}
        return ans;
    }
	string int2string(int number)
	{
		   string s1,s2;
		   s1 = "";
		   int tmp = abs(number);
		   
		   while(tmp){
						 s1 += (tmp%10+'0');
						 tmp /= 10;
		   }
		   
		   s2 = "";
		   if(number == 0) s2 = "0";
		   if(number < 0) s2 += '-';
		   for(int i = s1.size()-1; i >= 0; i--) 
				   s2 += s1[i];
		   return s2;
	}

};

int main(){
	Solution c;
	int A[] = {0,0,1};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.largestNumber(nums);
	return 0;
}
