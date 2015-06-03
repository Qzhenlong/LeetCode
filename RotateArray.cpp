#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        int tmp,i,j;
        k = k % n; // k > n; important
        if(n == 0 || k == 0 || n == 1) return;
        for(i = 0, j=n-k-1; i < (n-k)/2; i++, j--){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
        }
        for(i = 0, j = n-1; i < k/2; i++, j--){
                tmp = nums[i+n-k];
                nums[i+n-k] = nums[j];
                nums[j] = tmp;
        }
        for(i = 0, j = n-1; i < n/2; i++, j--){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
        }
    }
};
int main()
{
  Solution c;
  int n = 7, k = 3;
  int nums[] = {1,2,3,4,5,6,7};
  c.rotate(nums,n,k);
  for(int i = 0; i < n; i++){
                  printf("%d ",nums[i]);
  }
  while(1);
  return 1;   
}
