#include <iostream>
#include <vector>
#include <map>
//#include <hash_map>
using namespace std;
/*
��Ŀ��
Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

�������ҳ����ִ�������һ���Ԫ��
˼·��
��1��ֱ���ù�ϣ��洢������ʱ��Ϳռ䶼ΪO(n)
��2�����ù�ϣ���ݴ�һ��Ԫ��cur������ֵĴ�������������ɨ�裬���ɨ�赽��Ԫ�ص���curʱ��������1�������1������Ϊ0ʱ������cur
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
