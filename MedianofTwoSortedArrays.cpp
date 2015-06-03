#include<iostream>
#include<vector>
using namespace std;
/*
�����㷨��ת��Ϊ���K��Ԫ�����⣬��϶��ַ�
�������������ҵ�K��Ԫ�ص�˼·��
��������A�Ĵ�СС�ڵ���B�Ĵ�С�����򽻻�λ�õݹ飩
1.��A��B�ĵ�k��Ԫ�أ��Ա����ߵĵ�k/2��Ԫ��
1��A[k/2-1] < B[k/2-1]; ���K��Ԫ�ر�Ȼ����A��ǰk/2��Ԫ���У�ֱ��ȥ��ǰ�벿�֣�����������������ʣ�ಿ�ֵĵ�k/2��Ԫ��
2��A[k/2-1] > B[k/2-1]; ��1����ͬ
3��A[k/2-1] = B[k/2-1]; ����
2.�����ݹ����
....
ʵ��ʱӦ����ia = min(A.size(), k/2), ib = k - ia; ��A��B�ĳ��ȶ�����k/2����ֱ����k/2
*/

class Solution {
public:

    //O(log(m+n))
	double findKth(vector<int > &A, vector<int > &B, int k)
	{
		//����A�ĳ���С�ڵ���B
		if(A.size() > B.size()) return findKth(B, A, k);
		if(A.size() == 0) return B[k-1];
		if(k == 1) return A[0] < B[0] ? A[0] : B[0];
		
		//�ֳ���������
        int ia = k / 2 < A.size() ? k / 2 : A.size();
		int ib = k - ia;
		if(A[ia-1] < B[ib-1]){
		    vector<int > t_A;
			t_A.insert(t_A.begin(), A.begin()+ia, A.end());
			//A.erase(A.begin(), A.begin() + ia);
			return findKth(t_A, B, k-ia);
		}
		else if(A[ia-1] > B[ib-1]){
		   vector<int > t_B;
			t_B.insert(t_B.begin(), B.begin()+ib, B.end());
		  // B.erase(B.begin(), B.begin() + ib);
		   return findKth(A, t_B, k-ib);
		}
		else return A[ia-1];
		 
	}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size() + nums2.size();
		if(n % 2 == 1)
			return findKth(nums1, nums2, n/2 + 1);
		else
			return (double)(findKth(nums1, nums2, n/2) + findKth(nums1, nums2, n/2 + 1)) / 2;
		
	}
	//O(nlogn)
	double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2)
	{
		nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
		sort(nums1.begin(), nums1.end());
		int n = nums1.size();
		return (n % 2 == 1) ? nums1[n/2] : (double)(nums1[n/2]+nums1[n/2-1])/2; 
	}
	//O(m+n)
	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int > nums;
		int n = nums1.size() + nums2.size();
		int i = 0, j = 0;
		while(i < nums1.size() && j < nums2.size())
		{
			if(nums1[i] < nums2[j]) nums.push_back(nums1[i++]);
			else nums.push_back(nums2[j++]);
		}
		while(i < nums1.size()) nums.push_back(nums1[i++]);
		while(j < nums2.size()) nums.push_back(nums2[j++]);
		return (n % 2 == 1) ? nums[n/2] : (double)(nums[n/2]+nums[n/2-1])/2; 
	}	
};

int main()
{
	Solution c;
	vector<int > n1, n2;
	n1.push_back(1);
	n1.push_back(2);
	n1.push_back(2);
	for(int i = 0; i < 3; i++)
	{
		//n1.push_back(i+2);
		n2.push_back(i+1);
	}
	cout << c.findMedianSortedArrays(n1,n2) << endl;
	
	while(1);
	return 0;
}
