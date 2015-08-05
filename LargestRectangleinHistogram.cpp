#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��Ŀ��
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

����������n���Ǹ�����������n�����Ϊ1�����ҳ�����״ͼ�����ĳ��������

˼·��
��1���������ϼ�����������ÿһ��������������Ӷ�ΪO(n^2),�ɽ⣬��ʱ
��2����ջʵ�֣�ά��һ��������ջ��ÿ��ջ�������ߴ��ڣ���ǰ���ߣ�˵�����Գ�ջ�ˣ�ֱ���ҵ��ȵ�ǰ����Ҫ�͵�Ԫ�أ����ɽ���ǰԪ����ջ
     ��ջ�洢������ż��ɡ�

*/

class Solution {
public:
    //Time Limit Exceeded
    int largestRectangleArea(vector<int >& height) {
        int ans = 0, n = height.size();
		if(n <= 0) return 0;
		for(int i = 0; i < n; i++){
			int cur_max = 0, area = 0;
			for(int j = 0; j < n; j++){
				if(height[j] >= height[i]) area += height[i];
				else{
					cur_max = max(cur_max, area);
					area = 0;
				}
			}
			cur_max = max(cur_max, area); //��i���������
			ans = max(ans, cur_max);
		}
		return ans;
    }
    int _largestRectangleArea(vector<int >& height) {
        height.push_back(0); //������βԪ��
		int ans = 0, n = height.size(), i = 0;
		if(n <= 0) return 0;
		stack<int > s;
		while(i < n){
			if(s.empty() || height[i] > height[s.top()]) s.push(i++);
			else{
				int j = s.top(); s.pop();
				ans = max(ans, height[j] * (s.empty() ? i : i-s.top()-1));
			}
		}
		return ans;
    }
};

int main(){
	Solution c;
	int A[] = {1};
	vector<int > h;
	for(int i = 0; i < sizeof(A)/4; i++) h.push_back(A[i]);
	cout << c._largestRectangleArea(h);
	return 0;
}
