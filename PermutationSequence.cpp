#include<iostream>
#include<vector>
using namespace std;
/*
题目：
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

解析：给定一个n和一个k，返回将1-n中所有排序进行按序编号，返回第k个排列的字符串

思路：
（1）依次广度优先遍历计算，设定一个计数器，当到达k时返回对应，超时
（2）Next Permutation求解，执行k次，即可，超时
（3）研究规律，对于第一位为特定数字开头的序列都有（n-1）！个序列，因此n个数字所以共有n！个序列。
     以此类推，第二位每一个数开头都有（n-2）！个序列。那么可以逐渐压缩对应排列的范围，假设对就
	 序列为s1s2...sn， 则
	 s1 = k / (n-1)!
	 k1 = k % (n-1)!
	 s2 = k1 / (n-2)!
	 ...
	 
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
		int c = 0;
		vector<int > cur;
		getPer(ans, c, n, k, cur);
		return ans;
    }
	//超时，不用遍历所有
	void getPer(string &ans, int &counter, int n, int k, vector<int > &cur){
		if(cur.size() == n){
			counter++;
			if(counter == k){
				for(int i = 0; i < cur.size(); i++)
					ans += (cur[i]+'0');
			}
			return;
		}
		for(int i = 1; i <= n; i++){
			bool Exist = false;
			for(int j = 0; j < cur.size(); j++)
				if(i == cur[j]) Exist = true;
			if(!Exist){
				cur.push_back(i);
				getPer(ans, counter, n, k, cur);
				cur.pop_back();
			}
		}
	}
	//还是超时
	string _getPermutation(int n, int k) {
        string ans = "";
		vector<int > nums;
		for(int i = 1; i <= n; i++) nums.push_back(i);
		for(int i = 0; i < k-1; i++) nextPermutation(nums);
		for(int i = 0; i < n; i++) ans += (nums[i]+'0');
		return ans;
    }
	//使用Next Permutation求解
	 void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n-1, j = i;
		while(i > 0 && nums[i] <= nums[i-1]) i--;
		if(i == 0) sort(nums.begin(), nums.end());
		else{
			while(j > 0 && nums[j] <= nums[i-1]) j--;
			int tmp = nums[j];
			nums[j] = nums[i-1];
			nums[i-1] = tmp;
			//翻转后序元素
			for(int k = 0; k < (n-i)/2; k++){
				tmp = nums[i+k];
				nums[i+k] = nums[n-k-1];
				nums[n-k-1] = tmp;
			}
		}
    }
 
	string __getPermutation(int n, int k){
		vector<int > fac(n+1, 1);
		vector<int > nums(n, 0); //使用过的就去掉
		string ans = "";
		for(int i = 2; i <= n; i++) fac[i] = fac[i-1] * i;
		for(int i = 0; i < n; i++) nums[i] = i+1;
		k--;
		for(int i = 1; i <= n; i++){
			int s = k / fac[n-i];
			k = k % fac[n-i];
			ans += (nums[s] + '0');
			nums.erase(nums.begin()+s); //去掉用过的元素
		}
		return ans;
	}
};
int main(){
	Solution c;
	//for(int i = 1; i <= 6; i++)
		cout << c.__getPermutation(6,502) << endl;
	return 0;
}
