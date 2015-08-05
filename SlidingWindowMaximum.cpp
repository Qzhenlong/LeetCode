#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
/*
��Ŀ��
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 �� k �� input array's size for non-empty array.

�������󻬶����ڵ����ֵ

˼·��
��1������ʹ��һ�������У�������Сջ˼�룩����һ�������������ӳ��ӣ���һ�����д洢���ֵ�����˼·����
��2��Ӧ��ʹ��˫����У����״洢��ǰ���ֵ��ţ���β���ڲ���������ֵ�����˶��ɳ��ӣ�����ֻ�Ӷ�β��ӣ�ÿ�����ʱ��
     ���βԪ����ȣ����С�ڵ�ǰԪ�����βԪ�س��ӣ�ֱ���ҵ��ȵ�ǰԪ�ش��λ�ã�����ǰԪ����ӡ�
	 ����ÿ�����ڵ����ֵʱ��������Ԫ�س��Ӽ��ɣ����ڴ��ڻ�������Ҫ�Ա�i-k�Ƿ������Ԫ������Ƿ���ȣ���˵������Ԫ���Ѳ��ڴ����ڣ����Գ�����

*/
class MaxQueue{
public:
	void push(int x){
		if(max_qu.empty() || max_qu.front() <= x) max_qu.push(x);
		qu.push(x);
	}
	void pop(){
		int tmp = qu.front();
		qu.pop();
		if(tmp >= max_qu.back()) max_qu.pop();
	}
	int getMax(){
		return max_qu.back();
	}
private:
	queue<int > qu;
	queue<int > max_qu;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MaxQueue mq;
		vector<int > ans;
		if(nums.size() == 0 || k <= 0) return ans;
		for(int i = 0; i < nums.size(); ++i){
			if(i+1 >= k){
				ans.push_back(mq.getMax());
				mq.pop();
			}
			mq.push(nums[i]);
		}
		return ans;
    }
	//�ο�����
    vector<int> _maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};

int main(){
	Solution c;
	int A[] = {3,3,3,-3,5,3,6,7};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; ++i) nums.push_back(A[i]);
	vector<int > ans = c.maxSlidingWindow(nums,3);
	for(int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
	return 0;
}
