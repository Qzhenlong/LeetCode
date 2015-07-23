#include <iostream>
#include <vector>
#include <map>
//#include <hash_map>
using namespace std;
/*
题目：
Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

解析：找出出现次数超过一半的元素
思路：
（1）直接用哈希表存储次数，时间和空间都为O(n)
（2）不用哈希表，暂存一个元素cur及其出现的次数，从左向右扫描，如果扫描到的元素等于cur时，次数加1，否则减1，次数为0时，重置cur
*/
class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> IntMap;
        int major;
        for(int i = 0; i < num.size(); i++) IntMap[num[i]] = 0;
        for(int i = 0; i < num.size(); i++) IntMap[num[i]]++;
        for(int i = 0; i < num.size(); i++)
                if(IntMap[num[i]] > num.size()/2){ 
                             major = num[i];
                             break;
                             }
        return major;
    }
	int _majorityElement(vector<int> &num) {
		int cur = 0, count = 0;
		for(int i = 0; i < num.size(); i++){
			if(count == 0){
				cur = num[i];
				count++;
			}
			else{
				if(cur == num[i]) count++;
				else count--;
			}
		}
		return cur;
	}
};
int main()
{
  Solution c;
  int el[] = {1,1,1,2,5,5,5,5,5};
  int n = 9;
  vector<int > num;
  for(int i = 0; i < n; i++) num.push_back(el[i]);
  printf("%d\n", c.majorityElement(num));
  printf("%d\n", c._majorityElement(num));
  return 1;   
}
