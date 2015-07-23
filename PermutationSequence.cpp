#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��
The set [1,2,3,��,n] contains a total of n! unique permutations.

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

����������һ��n��һ��k�����ؽ�1-n������������а����ţ����ص�k�����е��ַ���

˼·��
��1�����ι�����ȱ������㣬�趨һ����������������kʱ���ض�Ӧ����ʱ
��2��Next Permutation��⣬ִ��k�Σ����ɣ���ʱ
��3���о����ɣ����ڵ�һλΪ�ض����ֿ�ͷ�����ж��У�n-1���������У����n���������Թ���n�������С�
     �Դ����ƣ��ڶ�λÿһ������ͷ���У�n-2���������С���ô������ѹ����Ӧ���еķ�Χ������Ծ�
	 ����Ϊs1s2...sn�� ��
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
	//��ʱ�����ñ�������
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
	//���ǳ�ʱ
	string _getPermutation(int n, int k) {
        string ans = "";
		vector<int > nums;
		for(int i = 1; i <= n; i++) nums.push_back(i);
		for(int i = 0; i < k-1; i++) nextPermutation(nums);
		for(int i = 0; i < n; i++) ans += (nums[i]+'0');
		return ans;
    }
	//ʹ��Next Permutation���
	 void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n-1, j = i;
		while(i > 0 && nums[i] <= nums[i-1]) i--;
		if(i == 0) sort(nums.begin(), nums.end());
		else{
			while(j > 0 && nums[j] <= nums[i-1]) j--;
			int tmp = nums[j];
			nums[j] = nums[i-1];
			nums[i-1] = tmp;
			//��ת����Ԫ��
			for(int k = 0; k < (n-i)/2; k++){
				tmp = nums[i+k];
				nums[i+k] = nums[n-k-1];
				nums[n-k-1] = tmp;
			}
		}
    }
 
	string __getPermutation(int n, int k){
		vector<int > fac(n+1, 1);
		vector<int > nums(n, 0); //ʹ�ù��ľ�ȥ��
		string ans = "";
		for(int i = 2; i <= n; i++) fac[i] = fac[i-1] * i;
		for(int i = 0; i < n; i++) nums[i] = i+1;
		k--;
		for(int i = 1; i <= n; i++){
			int s = k / fac[n-i];
			k = k % fac[n-i];
			ans += (nums[s] + '0');
			nums.erase(nums.begin()+s); //ȥ���ù���Ԫ��
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
