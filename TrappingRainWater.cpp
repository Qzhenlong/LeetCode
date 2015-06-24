#include<iostream>
#include<vector>
using namespace std;
/*
ԭ�⣺Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

����������һ��Ǹ�����ÿ����������һ�����Ϊ1��դ���������ܹ����Խ�ס����ˮ����1��0��2�����ۻ�1��λˮ�����������п����ۻ�6����λ��ˮ
˼·����ˮ����Ϊtotol
��1����a,i)��¼��ǰդ���ĸ߶ȼ������ꣻ
��2����b,j)��¼i֮����δ������߶ȴ��ڵ���a��դ��֮ǰ���߶���ߵ�դ��;
��3��c��¼i��j֮��դ����ռ�Ŀռ�
��4����������a���߻���ȵ�դ��������һ��ˮ����total += a*(j-i-1)-c,���µ�ǰ��a,i����(b,j)
��5���ظ����Ϲ��̣�ֱ��j�����յ�; 
��6����j�����յ�ʱ�����û�д���a��դ������total += b*(j-i-1)-c.
ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1);
����˼·����ԭ����û�п���������5,4,1,2�������

˼·����
����ÿ�����ӣ��ҵ�������������ߵ����ӣ������������ɵ�������� min(max_left,
max_right) - height�����ԣ�
1. ��������ɨ��һ�飬����ÿ�����ӣ���ȡ������ֵ��
2. ��������ɨ��һ�飬����ÿ�����ӣ��������ֵ��
3. ��ɨ��һ�飬ÿ��������ʢˮ�Ĵ�СΪ�����������ֵ�еĽ�Сֵ�뵱ǰ����֮�

˼·����
1. ɨ��һ�飬�ҵ���ߵ����ӣ�������ӽ������Ϊ���룻
2. �������һ�룬����ɨ�裬��ǰ������ʢˮ�����ڵ�ǰ�����������߶�֮�
3. �����ұ�һ�룬�������������2��ͬ��

*/
class Solution {
public:
    int trap(vector<int >& height) {
		int total = 0;
		if(height.size() <= 2) return total; //ֻ������դ�����޷��ۻ�ˮ
		int a=0,b=0,c=0,i,j;
		for(int k = 0; k < height.size(); k++)
			if(height[k] > 0){
				a = height[k];
				i = k;
				break;
			}
		int cur_c = 0;
		for(int k = i+1; k < height.size(); k++){
			if(height[k] >= b){
				b = height[k];
				j = k;
				c = cur_c;
			}
			if(a <= b){
				total += (a*(j-i-1)-c);
				c = 0;
				cur_c = 0;
				a = b;
				i = j;
				b = -1;
			}
			else cur_c += height[k];
			
		}
		if(b != -1) //���һ��դ��������
			total += b*(j-i-1)-c;		
		return total;
    }
	//ʱ��ռ䶼ΪO(n)
	int trap1(vector<int > &height){
		int n = height.size(), total = 0;
		vector<int > maxL(n, 0); //��ǰդ����ߵ����ֵ
		vector<int > maxR(n, 0); //��ǰդ���ұߵ����ֵ
		for(int i = 1; i < n; i++){
			maxL[i] = max(height[i-1], maxL[i-1]);
			maxR[n-i-1] = max(height[n-i], maxR[n-i]);
		}
		for(int i = 0; i < n; i++){
			int cur = min(maxL[i], maxR[i]);
			if(cur > height[i]) total += (cur-height[i]);
		}
		return total;
	}
	//ʱ��O(n)���ռ�O(1)
	int trap2(vector<int > &height){
		int maxI = 0, n = height.size(),total = 0;
		for(int i = 1; i < n; i++)
			if(height[i] > height[maxI]) maxI = i;
		int peak1 = 0, peak2 = 0;
		for(int i = 0; i < maxI; i++){
			if(peak1 < height[i]) peak1 = height[i];
			else total += (peak1-height[i]);
		}
		for(int i = n-1; i > maxI; i--){
			if(peak2 < height[i]) peak2 = height[i];
			else total += (peak2-height[i]);			
		}
		return total;
	}
};

int main(){
	Solution c;
	vector<int > h;
	int A[] = {5,4,1,2};
	for(int i = 0; i < sizeof(A)/4; i++) h.push_back(A[i]);
	cout << c.trap2(h);
	return 0;
}
