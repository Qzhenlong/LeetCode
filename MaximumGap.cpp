#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

����������һ��δ��������飬�ҳ����������������Ԫ�ص�������ֵ��Ҫ������ʱ����ռ䣬�������С������Ԫ���򷵻�0���ٶ�������ȫΪ����

˼·��û�����������һ�´𰸣�Ӧ��ʹ��Ͱ����
˼·�������ģ���������N��Ԫ�أ���С��Ԫ��Ϊmin������Ԫ��Ϊmax����ô���ļ�ཫ��С��ceil((max-min)/(N-1))�������У�ceil(x)ָ���ǲ�С��x����С��������
����ƽ�����Ϊgap=ceil((max-min)/(N-1))�������е�Ԫ�طŽ�N-1��Ͱ���k(0<=k<=N-2)��Ͱ�������λ������[min+k*gap, min+(k+1)*gap)�ڵ�Ԫ�ء�
��˳�������Ԫ��max����С��Ԫ��min�������N-2��Ԫ�ض����Ž���N-1��Ͱ����������һ��Ͱ�ǿյģ�����ֻ��Ҫ�洢ÿ��Ͱ������Ԫ�غ���С
��Ԫ�ؾͿ���������ļ���Ƕ��١�
ע��һ��������Ԫ�صĲ��첻�ᳬ��gap, �������첻��С��gap�� ͬʱ��һ��������ֵ����һ�������Сֵ�����������б�Ȼ������
*/

class Solution {
public:
int maximumGap(vector<int> &nums) {
        if (nums.empty() || nums.size() == 1) return 0;
 
        int min = nums[0], max = nums[0];
        for(int i = 0; i < nums.size(); i++)  {
            if (nums[i] < min) min = nums[i];
            if (nums[i] > max) max = nums[i];
        }
 
        int gap = (max - min - 1) / (nums.size() - 1) + 1; //ƽ�����
        vector<int> bucketMins(nums.size() - 1, INT_MAX); //���ڽ����������ֵ����Сֵ��Ͱ
        vector<int> bucketMaxs(nums.size() - 1, INT_MIN);
 
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] != min && nums[i] != max) {
                int bucketIdx = (nums[i] - min) / gap;
                if (nums[i] < bucketMins[bucketIdx]) bucketMins[bucketIdx] = nums[i];
                if (nums[i] > bucketMaxs[bucketIdx]) bucketMaxs[bucketIdx] = nums[i];
            }
        }
 
        int maxGap = INT_MIN, prev = min;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (bucketMins[i] == INT_MAX && bucketMaxs[i] == INT_MIN) continue;
            if (bucketMins[i] - prev > maxGap) maxGap = bucketMins[i] - prev;
            prev = bucketMaxs[i];
        }
 
        return std::max(max - prev, maxGap);
    }
};

int main(){
	Solution c;
	int A[] = {5,7,4,3};
	vector<int > numss;
	for(int i = 0; i < sizeof(A)/4; i++) numss.push_back(A[i]);
	cout << c.maximumGap(numss);
	return 0;
}
