#include<stdio.h>
#include<iostream>
using namespace std;
//O(log(m+n))
double findKth(int A[], int B[], int m, int n, int k)
{
	//假设A的长度小于等于B
	if(m > n) return findKth(B, A, n, m, k);
	if(m == 0) return B[k-1];
	if(k == 1) return A[0] < B[0] ? A[0] : B[0];
	
	//分成两个部分
	int ia = k / 2 < m ? k / 2 : m;
	int ib = k - ia;
	if(A[ia-1] < B[ib-1]){
		return findKth(A+ia, B, m-ia, n, k-ia);
	}
	else if(A[ia-1] > B[ib-1]){
	   return findKth(A, B+ib, m, n-ib, k-ib);
	}
	else return A[ia-1];
	 
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  		int n = nums1Size+nums2Size;
		if(n % 2 == 1)
			return findKth(nums1, nums2, nums1Size, nums2Size, n/2 + 1);
		else
			return (double)(findKth(nums1, nums2,  nums1Size, nums2Size, n/2) + findKth(nums1, nums2,  nums1Size, nums2Size, n/2 + 1)) / 2;
		  
}



int main()
{
	int A[] = {1,2,2};
	int B[] = {1,2,3};
	cout << findMedianSortedArrays(A,sizeof(A)/4, B,
	sizeof(B)/4) << endl;
	
	while(1);
	return 0;
}